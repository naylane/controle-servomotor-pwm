#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22 // Pino para controle do servomotor (Wowki)
#define LED_PIN 12 // Pino para experimento de PWM na BitDogLab
#define PWM_FREQ 50
#define DIV_PWM 125
#define PWM_WRAP 20000

// Definição de funções
void setup_pwm();

/**
* @brief Função Principal
*/
int main() {
    stdio_init_all();
    
    setup_pwm();

    pwm_set_gpio_level(SERVO_PIN, 2400);
    sleep_ms(5000);
    
    pwm_set_gpio_level(SERVO_PIN, 1470);
    sleep_ms(5000);
    
    pwm_set_gpio_level(SERVO_PIN, 500);
    sleep_ms(5000);

    while (true) {
        for (uint16_t pos = 500; pos <= 2400; pos += 5) {
            pwm_set_gpio_level(SERVO_PIN, pos);
            sleep_ms(10);
        }
        
        for (uint16_t pos = 2400; pos >= 500; pos -= 5) {
            pwm_set_gpio_level(SERVO_PIN, pos);
            sleep_ms(10);
        }
    }
}

void setup_pwm() {
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM); // Configura o SERVO_PIN para função PWM
    gpio_set_function(LED_PIN, GPIO_FUNC_PWM); // Configura o LED_PIN para função PWM
    
    uint slice = pwm_gpio_to_slice_num(SERVO_PIN); // Obtém o slice do PWM associado ao SERVO_PIN
    pwm_set_clkdiv(slice, DIV_PWM);  // Define o divisor de clock do PWM
    pwm_set_wrap(slice, PWM_WRAP); // Define o valor de wrap
    pwm_set_enabled(slice, true); // Habilita o PWM
}
