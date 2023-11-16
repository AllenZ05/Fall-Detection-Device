#include <mpu6050.h>
#include <main.h>
#include <stdio.h>

extern I2C_HandleTypeDef hi2c1;

void mpu6050_init()
{
	  HAL_StatusTypeDef ret = HAL_I2C_IsDeviceReady(&hi2c1, (DEVICE_ADDRESS <<1) + 0, 1, 100);
	  if (ret == HAL_OK)
	  {
		  printf("The device is ready \n");
	  }
	  else
	  {
		  printf("The device is not ready. Check cables \n");
	  }

	  uint8_t temp_data = FS_GYRO_500;
	  ret = HAL_I2C_Mem_Write(&hi2c1, (DEVICE_ADDRESS <<1) + 0, REG_CONFIG_GYRO, 1, &temp_data, 1, 100);
	  if (ret == HAL_OK)
	  {
		  printf("Configuring gyroscope \n");
	  }
	  else
	  {
		  printf("Failed to configure gyroscope \n");
	  }

	  temp_data = FS_ACC_4G;
	  ret = HAL_I2C_Mem_Write(&hi2c1, (DEVICE_ADDRESS <<1) + 0, REG_CONFIG_ACC, 1, &temp_data, 1, 100);
	  if (ret == HAL_OK)
	  {
		  printf("Configuring accelerometer \n");
	  }
	  else
	  {
		  printf("Failed to configure accelerometer \n");
	  }

	  temp_data = 0;
	  ret = HAL_I2C_Mem_Write(&hi2c1, (DEVICE_ADDRESS <<1) + 0, REG_USR_CTRL, 1, &temp_data, 1, 100);
	  if (ret == HAL_OK)
	  {
		  printf("Exiting from sleep mode \n");
	  }
	  else
	  {
		  printf("Failed to exit from sleep mode \n");
	  }
}

void mpu6050_read()
{
//	uint8_t data[2];
//	int16_t x_acc;
//	HAL_I2C_Mem_Read(&hi2c1, (DEVICE_ADDRESS <<1) + 1, REG_DATA, 1, data, 2, 100);
//    x_acc = ((int16_t)data[0] << 8) + data[1];
//    printf("x axis acceleration: %d \n", x_acc);

	uint8_t data[6];
	int16_t x_acc;
	int16_t y_acc;
	int16_t z_acc;

	HAL_I2C_Mem_Read(&hi2c1, (DEVICE_ADDRESS <<1) + 1, REG_DATA, 1, data, 6, 100);

    x_acc = ((int16_t)data[0] << 8) | data[1];
    y_acc = ((int16_t)data[2] << 8) | data[3];
    z_acc = ((int16_t)data[4] << 8) | data[5];

    printf("----------------------------------\n");
    printf("X axis acceleration: %d \n", x_acc);
    printf("Y axis acceleration: %d \n", y_acc);
    printf("Z axis acceleration: %d \n", z_acc);
}
