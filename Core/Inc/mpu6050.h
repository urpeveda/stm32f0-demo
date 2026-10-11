#ifndef MPU6050_H
#define MPU6050_H

#include "main.h"

#define MPU6050_ADDR (0x68 << 1)

#define PWR_MGMT_1_REG 0x6B
#define ACCEL_XOUT_H_REG 0x3B
#define GYRO_XOUT_H_REG 0x43
#define WHO_AM_I_REG 0x75

void MPU6050_Init(void);
void MPU6050_Read(float *accel_data, float *gyro_data);

#endif
