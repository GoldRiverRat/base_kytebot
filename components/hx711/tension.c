#include <inttypes.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <hx711.h>

static const char *TAG = "hx711-example";

extern int left_tension;

void tension(void)
{
    hx711_t dev = {
        .dout = 22,
        .pd_sck = 21,
        .gain = HX711_GAIN_A_64
    };

    // initialize device
    ESP_ERROR_CHECK(hx711_init(&dev));
    ESP_LOGI(TAG, "Hello from HX711 ADC");

    // read from device
    while (1)
    {
        esp_err_t r = hx711_wait(&dev, 100);
        if (r != ESP_OK)
        {
            ESP_LOGE(TAG, "Device not found: %d (%s)\n", r, esp_err_to_name(r));
            continue;
        }

        int32_t data;
        r = hx711_read_average(&dev, 6, &data);
        if (r != ESP_OK)
        {
            ESP_LOGE(TAG, "Could not read data: %d (%s)\n", r, esp_err_to_name(r));
            continue;
        }

        // ESP_LOGI(TAG, "Raw data: %" PRIi32, data);
        left_tension = data;
        vTaskDelay(CYCLETIME / portTICK_PERIOD_MS);
    }
}

