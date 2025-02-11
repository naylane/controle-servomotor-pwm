#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22 // Pino para controle do servomotor (Wowki)
#define LED_PIN 12 // Pino para experimento de PWM na BitDogLab

#define PWM_FREQ 50 // Frequência do PWM (Hz)
#define PWM_PERIOD 20 // Período do PWM (ms)

#define DIV_PWM 100
#define WRAP_PWM 25000 // WRAP do PWM (25 MHZ)

// Definição de funções
void setup_pwm();

/**
* @brief Função Principal
*/
int main() {
    stdio_init_all();
    
    setup_pwm();

    while (true) {
        printf("Hello, Wokwi!\n");
        sleep_ms(5000);
    }
}

void setup_pwm() {
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM); // Configura o SERVO_PIN para função PWM
    uint slice = pwm_gpio_to_slice_num(SERVO_PIN); // Obtém o slice do PWM associado ao SERVO_PIN
    pwm_set_clkdiv(slice, DIV_PWM);  // Define o divisor de clock do PWM
    pwm_set_wrap(slice, WRAP_PWM); // Define o valor de wrap
    pwm_set_enabled(slice, true); // Habilita o PWM
}