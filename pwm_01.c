#include <stdio.h> // Biblioteca padrão da linguagem C
#include "pico/stdlib.h" // Subconjunto central de bibliotecas do SDK Pico
#include "hardware/pwm.h" // Biblioteca para controlar o hardware de PWM
#include "hardware/clocks.h" // Biblioteca para acessar configurações de clock

#define PWM_MOTOR 22 // Pino do motor conectado à GPIO como PWM
#define FREQ_PWM 50  // Frequência do PWM (50Hz para servomotor)

// Função para calcular o nível de PWM baseado no tempo ativo (em microssegundos)
uint16_t calcula_nivel_pwm(uint slice, uint32_t tempo_us) {
    uint32_t clock_freq = clock_get_hz(clk_sys) / 64; // Ajuste do clock
    uint16_t wrap = clock_freq / FREQ_PWM;
    return (tempo_us * wrap) / 20000; // Normaliza o tempo ativo para a frequência de 50Hz
}

// Função para movimentação suave do servo entre os ciclos ativos
void movimento_suave_servo(uint slice, int inicio, int fim, int incremento) {
    int atual = inicio;
    while (atual != fim) {
        pwm_set_gpio_level(PWM_MOTOR, calcula_nivel_pwm(slice, atual));
        sleep_ms(10); // Atraso para ajuste suave
        atual += (inicio < fim) ? incremento : -incremento;
    }
}

int main() {
    stdio_init_all(); // Inicializa o sistema padrão de I/O
    gpio_set_function(PWM_MOTOR, GPIO_FUNC_PWM); // Habilitar o pino GPIO como PWM
    uint slice = pwm_gpio_to_slice_num(PWM_MOTOR); // Obter o canal PWM da GPIO

    // Configuração do PWM para 50Hz
    pwm_set_clkdiv(slice, 64.0);
    pwm_set_wrap(slice, 3905);
    pwm_set_enabled(slice, true);

    while (true) {
        // Movimento entre 0° (500µs) e 180° (2500µs)
        movimento_suave_servo(slice, 500, 2500, 10); // 0° a 180°
        movimento_suave_servo(slice, 2500, 500, 10); // 180° a 0°
        sleep_ms(1000); // Pausa entre ciclos
    }

    return 0;
}


