#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22  // GPIO para o PWM do servo
#define LED_PIN 12    // GPIO para o LED RGB
#define PWM_FREQ 50   // Frequência de 50Hz (período de 20ms)
#define STEP_DELAY 10 // Atraso de 10ms para transição suave

void set_servo_pulse(uint slice_num, uint channel, uint16_t pulse_width)
{
    pwm_set_chan_level(slice_num, channel, pulse_width);
}

void set_led_brightness(uint slice_num, uint channel, uint16_t brightness)
{
    pwm_set_chan_level(slice_num, channel, brightness);
}

int main()
{
    stdio_init_all();
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    gpio_set_function(LED_PIN, GPIO_FUNC_PWM);

    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);
    uint channel = pwm_gpio_to_channel(SERVO_PIN);

    uint led_slice = pwm_gpio_to_slice_num(LED_PIN);
    uint led_channel = pwm_gpio_to_channel(LED_PIN);

    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 125.0f); // Ajuste do clock divisor para 50Hz
    pwm_config_set_wrap(&config, 20000);    // Período de 20ms (20000 ciclos @ 1MHz)

    pwm_config led_config = pwm_get_default_config();
    pwm_config_set_clkdiv(&led_config, 125.0f);
    pwm_config_set_wrap(&led_config, 1000); // Ajuste do LED para brilho de 0-1000

    pwm_init(slice_num, &config, true);
    pwm_init(led_slice, &led_config, true);

    while (true)
    {
        // 180 graus (2.400µs)
        set_servo_pulse(slice_num, channel, 2400);
        set_led_brightness(led_slice, led_channel, (2400 - 500) * 1000 / 1900);
        sleep_ms(5000);

        // 90 graus (1.470µs)
        set_servo_pulse(slice_num, channel, 1470);
        set_led_brightness(led_slice, led_channel, (1470 - 500) * 1000 / 1900);
        sleep_ms(5000);

        // 0 graus (500µs)
        set_servo_pulse(slice_num, channel, 500);
        set_led_brightness(led_slice, led_channel, 0);
        sleep_ms(5000);

        // Movimentação suave entre 0 e 180 graus
        for (uint16_t pulse = 500; pulse <= 2400; pulse += 5)
        {
            set_servo_pulse(slice_num, channel, pulse);
            set_led_brightness(led_slice, led_channel, (pulse - 500) * 1000 / 1900);
            sleep_ms(STEP_DELAY);
        }
        for (uint16_t pulse = 2400; pulse >= 500; pulse -= 5)
        {
            set_servo_pulse(slice_num, channel, pulse);
            set_led_brightness(led_slice, led_channel, (pulse - 500) * 1000 / 1900);
            sleep_ms(STEP_DELAY);
        }
    }
}
