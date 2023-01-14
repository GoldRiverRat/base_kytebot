#include <C:\Users\byron\esp\esp-idf\components\driver\include\driver/gpio.h>
#include "esp_log.h"
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <C:\Users\byron\esp\esp-idf\components\esp_timer\include\esp_timer.h>
#include <C:\Users\byron\esp\esp-idf\uncleRemus\esp-idf-lib\components\esp_idf_lib_helpers\ets_sys.h>
#include <stdbool.h>
#include <esp_err.h>
#include <inttypes.h>

#define CYCLETIME 1000

void tension(void);

/**
 * Gain/channel
 */
typedef enum {
    HX711_GAIN_A_128 = 0, //!< Channel A, gain factor 128
    HX711_GAIN_B_32,      //!< Channel B, gain factor 32
    HX711_GAIN_A_64       //!< Channel A, gain factor 64
} hx711_gain_t;

/**
 * Device descriptor
 */
typedef struct
{
    gpio_num_t dout;
    gpio_num_t pd_sck;
    hx711_gain_t gain;
} hx711_t;


esp_err_t hx711_init(hx711_t *dev);

esp_err_t hx711_power_down(hx711_t *dev, bool down);

esp_err_t hx711_set_gain(hx711_t *dev, hx711_gain_t gain);

esp_err_t hx711_is_ready(hx711_t *dev, bool *ready);

esp_err_t hx711_wait(hx711_t *dev, size_t timeout_ms);

esp_err_t hx711_read_data(hx711_t *dev, int32_t *data);

esp_err_t hx711_read_average(hx711_t *dev, size_t times, int32_t *data);

