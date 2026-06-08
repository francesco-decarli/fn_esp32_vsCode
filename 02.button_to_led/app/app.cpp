#include "app.h"

#include "driver/gpio.h"
#include "esp_log.h"
#include "esp_timer.h"

#define LED_PIN GPIO_NUM_4
#define BUTTON_PIN GPIO_NUM_13
#define LOOP_DELAY_US 20'000 // 20 ms

void app_setup()
{
    if(gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT) != ESP_OK) {
        ESP_LOGD("Setup", "Failed to set LED_PIN");
        return;
    }
    if(gpio_set_direction(BUTTON_PIN, GPIO_MODE_INPUT) != ESP_OK) {
        ESP_LOGD("Setup", "Failed to set BUTTON_PIN");
        return;
    }
}

void app_run()
{
    while(1)
    {

        // Whenever the button is pressed, turn on the LED
        if(gpio_get_level(BUTTON_PIN) == 0) // Button is active low
        {
            // Delay (for debounce)
            esp_rom_delay_us(LOOP_DELAY_US);
            
            // If the button is still pressed, change the LED state
            if(gpio_get_level(BUTTON_PIN) == 0)
                gpio_set_level(LED_PIN, 1);
        }
        else
        {
            // Delay (for debounce)
            esp_rom_delay_us(LOOP_DELAY_US);

            // If the button is not pressed, change the LED state
            if(gpio_get_level(BUTTON_PIN) == 1)
                gpio_set_level(LED_PIN, 0);
        }
        // Delay
        esp_rom_delay_us(LOOP_DELAY_US);
    }
}