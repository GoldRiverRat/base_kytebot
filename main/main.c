#include "encoder.h"
#include "tension.h"
#include "motor.h"
#include "esp_log.h"
#include "freertos/task.h"

static const char *TAG = "Main";

    int move_to = 25;
    int curr_pos = 0;

void app_main(void)
{
  ESP_LOGI(TAG, "hello from main");
   xTaskCreatePinnedToCore(PID_motor, "go to", 4096, NULL, 2, NULL, 1);
   xTaskCreatePinnedToCore(encoder, "position", 4096, NULL, 5, NULL, 1);
   xTaskCreatePinnedToCore(tension, "cuz", 4096, NULL, 4, NULL, 0);
}

