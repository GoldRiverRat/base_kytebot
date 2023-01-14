#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_log.h"
#include "C:/Users/byron/esp/esp-idf/components/driver/include/driver/pulse_cnt.h"

#define EXAMPLE_PCNT_HIGH_LIMIT 10000
#define EXAMPLE_PCNT_LOW_LIMIT  -10000
#define ENCODER_GPIO_A 17
#define ENCODER_GPIO_B 5
#define CYCLETIME 1000

void encoder(void);
