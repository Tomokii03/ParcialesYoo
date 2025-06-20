module OneWire_ReadBit (
    input  logic clk,
    input  logic rst,
    input  logic start,
    input  logic dq_in,             //Ahora es una entrada
    output logic dq_out_en,         //Ahora es una salida para pedir control
    output logic bit_out,
    output logic done
);
    typedef enum logic [1:0] { IDLE, INIT_LOW, SAMPLE, RELEASE_WAIT } state_t;
    state_t state;

    logic timer_start, timer_done;
    logic [15:0] delay_us;

    OneWire_Timer timer_inst (
        .clk(clk), .rst(rst), .start(timer_start),
        .delay_us(delay_us), .done(timer_done)
    );

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            state       <= IDLE;
            dq_out_en   <= 0; // Por defecto no pide control
            delay_us    <= 0;
            timer_start <= 0;
            bit_out     <= 0;
            done        <= 0;
        end else begin
            case (state)
                IDLE: begin
                    done <= 0;
                    dq_out_en <= 0; // Asegurar que está bajo
                    if (start) begin
                        dq_out_en   <= 1; // Pide control para bajar la línea
                        delay_us    <= 6;
                        timer_start <= 1;
                        state       <= INIT_LOW;
                    end
                end
                INIT_LOW: begin
                    timer_start <= 0;
                    if (timer_done) begin
                        dq_out_en   <= 0; // Libera el control
                        delay_us    <= 9;
                        timer_start <= 1;
                        state       <= SAMPLE;
                    end
                end
                SAMPLE: begin
                    timer_start <= 0;
                    if (timer_done) begin
                        bit_out     <= dq_in; // Lee desde la entrada dq_in
                        delay_us    <= 55;
                        timer_start <= 1;
                        state       <= RELEASE_WAIT;
                    end
                end
                RELEASE_WAIT: begin
                    timer_start <= 0;
                    if (timer_done) begin
                        done  <= 1;
                        state <= IDLE;
                    end
                end
            endcase
        end
    end
endmodule
