#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include <stdio.h>
// #include "comms.h"
// #include <esp_wifi.h>
// #include <esp_event.h>
// #include <esp_log.h>
// #include <esp_system.h>
// #include <nvs_flash.h>
// #include <sys/param.h>
// #include "esp_netif.h"
// #include "esp_eth.h"
// #include "C:\Users\byron\esp\esp-idf\examples\common_components\protocol_examples_common\include\protocol_examples_common.h"
// #include <esp_http_server.h>

#define CYCLETIME 1000

void comms(void);
