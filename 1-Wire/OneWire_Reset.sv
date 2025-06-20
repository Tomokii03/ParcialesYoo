module OneWire_Reset (
    input  logic clk,
    input  logic rst,
    input  logic start,
    input  logic dq_in,
    output logic dq_out_en,
    output logic presence_detected,
    output logic done
);
    typedef enum logic [1:0] { IDLE, PULSE_LOW, WAIT_PRESENCE, WAIT_RELEASE } state_t;
    state_t state;
    logic timer_start, timer_done;
    logic [15:0] delay_us;

    OneWire_Timer timer_inst (.clk(clk), .rst(rst), .start(timer_start), .delay_us(delay_us), .done(timer_done));

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            state             <= IDLE;
            dq_out_en         <= 0;
            timer_start       <= 0;
            delay_us          <= 0;
            presence_detected <= 0;
            done              <= 0;
        end else begin
            timer_start <= 0; // Por defecto, el timer no se reinicia
            case (state)
                IDLE: begin
                    done <= 0;
                    dq_out_en <= 0;
                    if (start) begin
                        dq_out_en   <= 1;
                        delay_us    <= 500; // CAMBIO: Aumentado de 480 a 500 para mayor robustez
                        timer_start <= 1;
                        state       <= PULSE_LOW;
                    end
                end
                PULSE_LOW: begin
                    if (timer_done) begin
                        dq_out_en   <= 0;
                        delay_us    <= 70;
                        timer_start <= 1;
                        state       <= WAIT_PRESENCE;
                    end
                end
                WAIT_PRESENCE: begin
                    if (timer_done) begin
                        presence_detected <= ~dq_in;
                        delay_us          <= 410;
                        timer_start       <= 1;
                        state             <= WAIT_RELEASE;
                    end
                end
                WAIT_RELEASE: begin
                    if (timer_done) begin
                        done  <= 1;
                        state <= IDLE;
                    end
                end
            endcase
        end
    end
endmodule
