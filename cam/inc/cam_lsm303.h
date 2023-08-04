#ifndef CAM_LSM303_H
#define CAM_LSM303_H

#include "stm32f4xx_hal.h"
#include "cam_uart_logger.h"

typedef enum {
    CAM_LSM303_MODE_NORMAL = 0,  // 10-bit resolution
    CAM_LSM303_MODE_HIGH = 1, // 12-bit resolution
    CAM_LSM303_MODE_LOW = 2 // 8-bit resolution (unsure about this)
} CamLsm303Mode;

typedef enum {
    CAM_LSM303_RANGE_2 = 0x0, // +- 2g
    CAM_LSM303_RANGE_4 = 0x1, // +- 4g
    CAM_LSM303_RANGE_8 = 0x2, // +- 8g
    CAM_LSM303_RANGE_16 = 0x3 // +- 16g
} CamLsm303Range;

typedef struct {
    I2C_HandleTypeDef *i2c;
    CamLogger *logger;
    CamLsm303Mode mode;
    CamLsm303Range range;
} CamLsm303;

typedef struct {
    float x;
    float y;
    float z;
} CamLsm303AccelData;

void cam_lsm303_init(
    CamLsm303 *dev, 
    I2C_HandleTypeDef *i2c,
    CamLogger *logger,
    CamLsm303Mode mode,
    CamLsm303Range range
);

void cam_lsm303_get_event(CamLsm303 *dev, CamLsm303AccelData *event);


#endif