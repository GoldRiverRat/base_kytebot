#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "C:\Users\byron\esp\esp-idf\components\driver\include\driver/ledc.h"
#include "C:\Users\byron\esp\esp-idf\components\driver\include\driver/gpio.h"

#define LEDC_HS_TIMER LEDC_TIMER_0
#define LEDC_HS_MODE LEDC_HIGH_SPEED_MODE
#define MOTOR_DIR 15
#define MOTOR_PWM 02
#define LEDC_HS_CH0_CHANNEL LEDC_CHANNEL_0
#define LEDC_DUTY_MAX 8200
#define CYCLETIME 100

void PID_motor(void);