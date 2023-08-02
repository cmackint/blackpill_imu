
#ifndef CAM_UART_LOGGER_H
#define CAM_UART_LOGGER_H
#include "stm32f4xx_hal_uart.h"

typedef struct {
    UART_HandleTypeDef *uart;
} CamLogger;

void cam_logger_init(CamLogger *logger, UART_HandleTypeDef *uart);

void cam_logger_write(CamLogger *logger, char *message);

#endif
