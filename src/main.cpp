/**
 * ----------------------------------------------------------------------------------------------------
 * Includes
 * ----------------------------------------------------------------------------------------------------
 */
 
#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>
#include "pico/stdlib.h"

/**
 * ----------------------------------------------------------------------------------------------------
 * led_task
 * ----------------------------------------------------------------------------------------------------
 */
void led_task()
{
    const TickType_t xDelay = 1000 / portTICK_PERIOD_MS;
    const uint LED_PIN = 25; //Pico 2 internal LED
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (true)
    {
        gpio_put(LED_PIN, 1);
        vTaskDelay(xDelay);
        gpio_put(LED_PIN, 0);
        vTaskDelay(2*xDelay);
    }
}

/**
 * ----------------------------------------------------------------------------------------------------
 * main
 * ----------------------------------------------------------------------------------------------------
 */
int main()
{
    stdio_init_all();
    xTaskCreate((TaskFunction_t)led_task, "LED_Task", 256, NULL, 1, NULL);
    vTaskStartScheduler();
}
