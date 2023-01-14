#include <stdio.h>
#include "comms.h"


static const char *TAG = "COMMS";
void comms(void)
{
    while (1) {
      ESP_LOGI(TAG, "hello from comms");
      vTaskDelay(CYCLETIME / portTICK_PERIOD_MS);
    }
}
