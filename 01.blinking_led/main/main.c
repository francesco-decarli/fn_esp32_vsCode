#include <stdio.h>
// #include "sdkconfig.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "esp_timer.h"

#define LED_PIN 4
#define BLINKING_PERIOD_US 1'000'000    // in microseconds

static const char *DEBUG = "debug";

void app_main(void)
{
    // Setting LED_PIN as only ourput
    if(gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT) != ESP_OK)
    {
        ESP_LOGI(DEBUG, "Failed to set GPIO direction");
        return;
    }

    esp_timer_early_init();

    ESP_LOGI(DEBUG, "Blinking start!");
    int64_t timestamp_us = esp_timer_get_time();    // It's in microseconds
    // LED blinking loop
    while(1)
    {
        gpio_set_level(LED_PIN, 1); // Turn LED on

        // Wating for BLINKING_PERIOD_US
        while(esp_timer_get_time() - timestamp_us < BLINKING_PERIOD_US) {};   // Wait for 1 second
        timestamp_us = esp_timer_get_time();

        gpio_set_level(LED_PIN, 0); // Turn LED off

        // Wating for BLINKING_PERIOD_US
        while(esp_timer_get_time() - timestamp_us < BLINKING_PERIOD_US) {};   // Wait for 1 second
        timestamp_us = esp_timer_get_time();
    }
}
