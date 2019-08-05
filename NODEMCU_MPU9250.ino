#include <Wire.h>


const int MPU=0x68;
int16_t AcX,AcY,AcZ,Tmp,GyX, GyY, GyZ;

void setup() {

  Wire.begin(4,5); //SDA, SCL **TAKE NOTE OF NODEMCU 8266 PIN DEFINITIONS D1 = GPIO5, D2 = GPIO4
  Wire.beginTransmission(MPU);
  Wire.write(0x6B); // PWR_MGMT_1 register
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(19200);
  while(!Serial);
  Serial.println("Setup Completed...");
}

void loop() {
  Wire.beginTransmission(MPU);
  Wire.write(0x3B); // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,14,true);
  AcX=Wire.read()<<8|Wire.read();
  AcY=Wire.read()<<8|Wire.read();
  AcZ=Wire.read()<<8|Wire.read();
  Tmp=Wire.read()<<8|Wire.read();
  Serial.print("AcX = "); Serial.print(AcX);
  Serial.print(" | AcY = "); Serial.print(AcY);
  Serial.print(" | AcZ = "); Serial.print(AcZ);
  Serial.print(" | Tmp = "); Serial.println(Tmp/340.00+36.53);

  delay(333);
  
  

}
