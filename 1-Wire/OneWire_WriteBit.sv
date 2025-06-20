module OneWire_WriteBit (
    input  logic clk,
    input  logic rst,
    input  logic start,
    input  logic bit_in,          // El bit a escribir (0 o 1)
    output logic dq_out_en,       // Petición de control del bus
    output logic done
);
    typedef enum logic [1:0] { IDLE, LOW_PULSE, HIGH_WAIT } state_t;
    state_t state;

    logic timer_start, timer_done;
    logic [15:0] delay_us;

    OneWire_Timer #(.CLK_FREQ(100_000_000)) timer_inst (
        .clk(clk), .rst(rst), .start(timer_start),
        .delay_us(delay_us), .done(timer_done)
    );

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            state       <= IDLE;
            dq_out_en   <= 0;
            delay_us    <= 0;
            timer_start <= 0;
            done        <= 0;
        end else begin
            case (state)
                IDLE: begin
                    done <= 0;
                    dq_out_en <= 0;
                    if (start) begin
                        dq_out_en   <= 1; // Pide control para bajar la línea
                        // Para escribir '0': pulso bajo de ~60µs
                        // Para escribir '1': pulso bajo de ~6µs
                        delay_us    <= bit_in ? 6 : 60; 
                        timer_start <= 1;
                        state       <= LOW_PULSE;
                    end
                end
                LOW_PULSE: begin
                    timer_start <= 0;
                    if (timer_done) begin
                        dq_out_en   <= 0; // Libera la línea
                        // Tiempo de recuperación para completar el slot de ~70µs
                        delay_us    <= bit_in ? 64 : 10;
                        timer_start <= 1;
                        state       <= HIGH_WAIT;
                    end
                end
                HIGH_WAIT: begin
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
