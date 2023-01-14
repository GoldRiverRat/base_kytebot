#include "encoder.h"
#include "hx711.h"
#include "motor.h"
#include "comms.h"
#include "esp_log.h"
#include "freertos/task.h"

static const char *TAG = "Main";

    int move_to = 25;
    int curr_pos = 0;
    int left_tension = 0;

void app_main(void)
{
  ESP_LOGI(TAG, "hello from main");
   xTaskCreatePinnedToCore(PID_motor, "goo", 4096, NULL, 2, NULL, 1);
   xTaskCreatePinnedToCore(comms, "go to", 4096, NULL, 3, NULL, 0);
   xTaskCreatePinnedToCore(encoder, "position", 4096, NULL, 5, NULL, 1);
   xTaskCreatePinnedToCore(tension, "cuz", 4096, NULL, 4, NULL, 0);
}

