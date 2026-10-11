#include "mpu6050.h"

#define g 9.81

const int READING_RANGE = 65536;
const int ACCEL_RANGE = 4;
const int GYRO_RANGE = 500;

const int READ_DATA_LEN = 6;
const int RAW_DATA_LEN = 3;

void MPU6050_Init(void) {
	uint8_t data = 0x00;

	//HAL_I2C_Mem_Read(&hi2c1, MPU6050_ADDR, WHO_AM_I_REG, 1, &data, 1, HAL_MAX_DELAY);

	HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, PWR_MGMT_1_REG, 1, &data, 1,
	HAL_MAX_DELAY);

}

void MPU6050_Read(float *accel_data, float *gyro_data) {
	uint8_t read_data[READ_DATA_LEN];
	int16_t raw_data[RAW_DATA_LEN];

	HAL_I2C_Mem_Read(&hi2c1, MPU6050_ADDR, ACCEL_XOUT_H_REG, 1, read_data,
			READ_DATA_LEN, HAL_MAX_DELAY);

	for (int i = 0; i < RAW_DATA_LEN; i++) {
		raw_data[i] = (int16_t) (read_data[i * 2] << 8 | read_data[i * 2 + 1]);
		accel_data[i] = (float) raw_data[i] / READING_RANGE * ACCEL_RANGE * g;
	}

	HAL_I2C_Mem_Read(&hi2c1, MPU6050_ADDR, GYRO_XOUT_H_REG, 1, read_data,
			READ_DATA_LEN, HAL_MAX_DELAY);

	for (int i = 0; i < RAW_DATA_LEN; i++) {
		raw_data[i] = (int16_t) (read_data[i * 2] << 8 | read_data[i * 2 + 1]);
		gyro_data[i] = (float) raw_data[i] / READING_RANGE * GYRO_RANGE;
	}
}
