#include "cam_uart_logger.h"
#include <stdint.h>

void cam_logger_init(CamLogger *logger, UART_HandleTypeDef *uart) {
    logger->uart = uart;
}

void cam_logger_write(CamLogger *logger, char *message) {
    HAL_UART_Transmit_IT(&logger->uart, (uint8_t*) message, strlen(message));

}

