module OneWire_Timer #(
    parameter CLK_FREQ = 100_000_000  // Frecuencia del reloj del sistema en Hz
)(
    input  logic        clk,
    input  logic        rst,
    input  logic        start,
    input  logic [15:0] delay_us,     // Tiempo de retardo en microsegundos
    output logic        done
);
    localparam integer CYCLES_PER_US = CLK_FREQ / 1_000_000;

    logic [31:0] counter;
    logic running;

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            counter <= 0;
            running <= 0;
            done    <= 0;
        end else begin
            if (start && !running) begin
                // Inicia el temporizador
                counter <= delay_us * CYCLES_PER_US;
                running <= 1;
                done    <= 0;
            end else if (running) begin
                if (counter == 0) begin
                    running <= 0;
                    done    <= 1;
                end else begin
                    counter <= counter - 1;
                end
            end else begin
                done <= 0;  // Limpieza del pulso
            end
        end
    end
endmodule
