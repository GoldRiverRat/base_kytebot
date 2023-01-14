#include <stdio.h>
#include "comms.h"


static const char *TAG = "COMMS";
void comms(void)
    {
        ESP_LOGI(TAG, "hello from comms");
        while (1) {
          vTaskDelay(CYCLETIME / portTICK_PERIOD_MS);
        }
    }
