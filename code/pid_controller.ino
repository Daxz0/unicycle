#include <Wire.h>

#define SDA_PIN         8
#define SCL_PIN         9
#define A4988_RESET_SLP 6
#define A4988_ENABLE    7
#define A4988_STEP      10
#define A4988_DIR       11

#define MPU_ADDR        0x68
#define PWR_MGMT_1      0x6B
#define ACCEL_XOUT_H    0x3B
#define GYRO_XOUT_H     0x43


const float SAFETY_ANGLE = 35.0;



float KP = 1.0;
float KI = 0.0;
float KD = 0.0;




void setup() {
  Serial.begin(115200);
  delay(200);

  pinMode(A4988_RESET_SLP, OUTPUT);
  pinMode(A4988_ENABLE, OUTPUT);
  pinMode(A4988_STEP, OUTPUT);
  pinMode(A4988_DIR, OUTPUT);

  digitalWrite(A4988_RESET_SLP, HIGH);
  disableDriver();

  Wire.begin(SDA_PIN, SCL_PIN);
  Wire.setClock(400000);

  initIMU();

  lastFilterUpdateUs = micros();
  lastPidUpdateUs = micros();
  lastStepUs = micros();

  Serial.println("initialized");
}

void loop() {
  int16_t ax, ay, az;
  int16_t gx, gy, gz;

  readIMU(ax, ay, az, gx, gy, gz);

  float axg = ax / 16384.0;
  float azg = az / 16384.0;

  float angle = atan2(axg, azg) * 180.0 / PI;

  if (abs(angle) < SAFETY_ANGLE && !driverEnabled) {
    enableDriver();
  } 
  else {
    disableDriver();
  }

  delay(10);
}


void initIMU() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(PWR_MGMT_1);
  Wire.write(0x00);
  Wire.endTransmission(true);
  delay(100);
}

void readIMU(int16_t &ax, int16_t &ay, int16_t &az, int16_t &gx, int16_t &gy, int16_t &gz) {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(ACCEL_XOUT_H);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 14, true);

  ax = (Wire.read() << 8) | Wire.read();
  ay = (Wire.read() << 8) | Wire.read();
  az = (Wire.read() << 8) | Wire.read();
  Wire.read(); Wire.read();  // temperature
  gx = (Wire.read() << 8) | Wire.read();
  gy = (Wire.read() << 8) | Wire.read();
  gz = (Wire.read() << 8) | Wire.read();
}


void enableDriver() {
  digitalWrite(A4988_ENABLE, LOW);
  driverEnabled = true;
}

void disableDriver() {
  digitalWrite(A4988_ENABLE, HIGH);
  driverEnabled = false;
  currentStepRate = 0.0;
}
