#include <MPU6050.h>         //MPU6050 library file
#include <Wire.h>            //IIC library file
#include "I2Cdev.h"

MPU6050 mpu6050;                    //define MPU6050 class
int16_t ax, ay, az, gx, gy, gz;     //define Variable of triaxial acceleration and variables of Triaxial gyro
float temp_ax,temp_ay,temp_az,temp_gx,temp_gy,temp_gz;
//////////////////////////////////////////////////////////////////
void setup() {
  Wire.begin();                              //init the IIC bus
  Serial.begin(9600);                       //Opening a serial port,Set the baud rate to 9600
  mpu6050.initialize();                      //init MPU6050
}
//////////////////////////loop function//////////////////////////////
void loop() {
    mpu6050.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);     //get MPU6050 ax ay az gx gy gz data
    temp_ax=ax;
    temp_ay=ay;
    temp_az=az;
    temp_gx=gx;
    temp_gy=gy;
    temp_gz=gz;
    Serial.print("a/g:\t");
    Serial.print(temp_ax/16384); Serial.print("\t");
    Serial.print(temp_ay/16384); Serial.print("\t");
    Serial.print(temp_az/16384); Serial.print("\t");
    Serial.print(temp_gx/131); Serial.print("\t");
    Serial.print(temp_gy/131); Serial.print("\t");
    Serial.println(temp_gz/131);
    delay(200);
}
