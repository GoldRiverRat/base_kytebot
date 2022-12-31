#include <C:\Users\byron\esp\esp-idf\components\driver\include\driver/gpio.h>
#include <stdbool.h>
#include <esp_err.h>

#define CYCLETIME 100

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

/**
 * @brief Initialize device
 *
 * Prepare GPIO pins, power up device and set gain
 *
 * @param dev Device descriptor
 * @return `ESP_OK` on success, `ESP_ERR_TIMEOUT` if device not found
 */
esp_err_t hx711_init(hx711_t *dev);

/**
 * @brief Set device power up/down
 *
 * @param dev Device descriptor
 * @param down Set device power down if true, power up otherwise
 * @return `ESP_OK` on success
 */
esp_err_t hx711_power_down(hx711_t *dev, bool down);

/**
 * @brief Set device gain and channel
 *
 * @param dev Device descriptor
 * @param gain Gain + channel value
 * @return `ESP_OK` on success, `ESP_ERR_TIMEOUT` if device not found
 */
esp_err_t hx711_set_gain(hx711_t *dev, hx711_gain_t gain);

/**
 * @brief Check if device ready to send data
 *
 * @param dev Device descriptor
 * @param[out] ready true if data ready
 * @return `ESP_OK` on success
 */
esp_err_t hx711_is_ready(hx711_t *dev, bool *ready);

/**
 * @brief Wait for device to become ready
 *
 * @param dev Device descriptor
 * @param timeout_ms Maximum time to wait, milliseconds
 * @return `ESP_OK` on success
 */
esp_err_t hx711_wait(hx711_t *dev, size_t timeout_ms);

/**
 * @brief Read raw data from device.
 *
 * Please call this function only when device is ready,
 * otherwise communication errors may occur
 *
 * @param dev Device descriptor
 * @param[out] data Raw ADC data
 * @return `ESP_OK` on success
 */
esp_err_t hx711_read_data(hx711_t *dev, int32_t *data);

/**
 * @brief Read average data
 *
 * @param dev Device descriptor
 * @param times Count of samples to read
 * @param[out] data Average ADC data
 * @return `ESP_OK` on success
 */
esp_err_t hx711_read_average(hx711_t *dev, size_t times, int32_t *data);

