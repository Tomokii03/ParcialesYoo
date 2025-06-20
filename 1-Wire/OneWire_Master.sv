module OneWire_Master #(
    parameter CLK_FREQ = 100_000_000
)(
    input  logic clk,
    input  logic rst,

    // ---- Interfaz de Comandos ----
    input  logic       op_start,
    input  logic [1:0] op_type,
    input  logic [7:0] byte_to_write,
    output logic [7:0] byte_read,
    output logic       op_done,
    output logic       presence,
    output logic       error,
    
    // ---- Pin físico ----
    inout  logic dq
);

    // ---- Definición de Operaciones ----
    localparam OP_IDLE       = 2'b00;
    localparam OP_RESET      = 2'b01;
    localparam OP_WRITE_BYTE = 2'b10;
    localparam OP_READ_BYTE  = 2'b11;
    
    // ---- Lógica de control del bus ----
    logic dq_out_en_reset, dq_out_en_write, dq_out_en_read;
    logic dq_out_en;
    logic dq_in;
    assign dq = dq_out_en ? 1'b0 : 1'bz;
    assign dq_in = dq;
    assign dq_out_en = dq_out_en_reset || dq_out_en_write || dq_out_en_read;
    
    // ---- Estados de la FSM principal ----
    typedef enum logic [3:0] { 
        IDLE, 
        CMD_START, 
        RESET_START, RESET_WAIT, 
        WRITE_START, WRITE_WAIT, 
        READ_START,  READ_WAIT,
        FINISH 
    } state_t;
    state_t state, next_state;
    
    // ---- Señales de control internas ----
    logic [7:0] byte_write_reg, byte_read_reg;
    logic [2:0] bit_cnt;
    logic       sub_op_start, sub_op_done;
    logic       sub_bit_in, sub_bit_out;
    logic       internal_presence;
    logic [1:0] saved_op_type;

    // ---- Instancias de los módulos primitivos ----
    OneWire_Reset reset_inst (
        .clk(clk), .rst(rst), .start(sub_op_start), .dq_in(dq_in), 
        .dq_out_en(dq_out_en_reset), .presence_detected(internal_presence), .done(sub_op_done)
    );
    OneWire_WriteBit writebit_inst (
        .clk(clk), .rst(rst), .start(sub_op_start), .bit_in(sub_bit_in),
        .dq_out_en(dq_out_en_write), .done(sub_op_done)
    );
    OneWire_ReadBit readbit_inst (
        .clk(clk), .rst(rst), .start(sub_op_start), .dq_in(dq_in),
        .dq_out_en(dq_out_en_read), .bit_out(sub_bit_out), .done(sub_op_done)
    );

    // ---- Lógica de la FSM (Combinacional) ----
    always_comb begin
        next_state = state;
        sub_op_start = 1'b0;
        sub_bit_in = 1'b0;
        op_done = 1'b0;

        case (state)
            IDLE: begin
                if (op_start) begin
                    next_state = CMD_START;
                end
            end
            CMD_START: begin
                case (saved_op_type)
                    OP_RESET:      next_state = RESET_START;
                    OP_WRITE_BYTE: next_state = WRITE_START;
                    OP_READ_BYTE:  next_state = READ_START;
                    default:       next_state = IDLE;
                endcase
            end
            RESET_START: begin
                sub_op_start = 1'b1;
                next_state = RESET_WAIT;
            end
            RESET_WAIT: begin
                if (sub_op_done) begin
                    next_state = FINISH;
                end
            end
            WRITE_START: begin
                sub_op_start = 1'b1;
                sub_bit_in = byte_write_reg[bit_cnt];
                next_state = WRITE_WAIT;
            end
            WRITE_WAIT: begin
                if (sub_op_done) begin
                    if (bit_cnt == 7) begin
                        next_state = FINISH;
                    end else begin
                        next_state = WRITE_START;
                    end
                end
            end
            READ_START: begin
                sub_op_start = 1'b1;
                next_state = READ_WAIT;
            end
            READ_WAIT: begin
                if (sub_op_done) begin
                    if (bit_cnt == 7) begin
                        next_state = FINISH;
                    end else begin
                        next_state = READ_START;
                    end
                end
            end
            FINISH: begin
                op_done = 1'b1;
                next_state = IDLE;
            end
        endcase
    end
    
    // ---- Lógica Secuencial (Registros) ----
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            state <= IDLE;
            byte_write_reg <= '0;
            byte_read_reg  <= '0;
            bit_cnt        <= '0;
            presence       <= 1'b0;
            error          <= 1'b0;
            byte_read      <= '0;
            saved_op_type  <= OP_IDLE;
        end else begin
            state <= next_state;
            
            // Lógica de captura y actualización
            if (state == IDLE && next_state == CMD_START) begin
                saved_op_type  <= op_type;
                byte_write_reg <= byte_to_write;
                byte_read_reg  <= '0;
                bit_cnt        <= '0;
                error          <= 1'b0;
            end
            
            if (state == WRITE_WAIT && sub_op_done && bit_cnt < 7) begin
                bit_cnt <= bit_cnt + 1;
            end
            
            if (state == READ_WAIT && sub_op_done) begin
                byte_read_reg[bit_cnt] <= sub_bit_out;
                if (bit_cnt < 7) begin
                    bit_cnt <= bit_cnt + 1;
                end
            end

            if (state == FINISH) begin
                byte_read <= byte_read_reg;
                presence  <= internal_presence;
                if (saved_op_type == OP_RESET && !internal_presence) begin
                    error <= 1'b1;
                end
            end
        end
    end

endmodule
