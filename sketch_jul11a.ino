#include <Wire.h>
#include <Servo.h>

Servo baseServo;
Servo shoulderServo;

const int MPU_ADDR = 0x68;

float smoothPitch = 0, smoothRoll = 0;
int baseAngle = 90, shoulderAngle = 90;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  
  // Wake up MPU6050
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);  // power management register
  Wire.write(0x00);  // wake up
  Wire.endTransmission(true);
  delay(100);
  
  // Base on pin 9, shoulder on pin 11 (pin 10 was faulty)
  baseServo.attach(9);
  shoulderServo.attach(11);
  
  baseServo.write(baseAngle);
  shoulderServo.write(shoulderAngle);
  
  Serial.println("Dual servo gesture arm ready.");
}

void loop() {
  int16_t ax, ay, az;
  
  // Read accelerometer
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 6);
  
  if (Wire.available() == 6) {
    ax = Wire.read() << 8 | Wire.read();
    ay = Wire.read() << 8 | Wire.read();
    az = Wire.read() << 8 | Wire.read();
    
    // Calculate pitch and roll
    float pitch = atan2(-ax, sqrt(ay*ay + az*az)) * 180.0 / PI;
    float roll  = atan2(ay, az) * 180.0 / PI;
    
    // Exponential smoothing
    smoothPitch = 0.2 * pitch + 0.8 * smoothPitch;
    smoothRoll  = 0.2 * roll  + 0.8 * smoothRoll;
    
    // Map to target angles
    int targetBase = map(smoothRoll, -80, 80, 0, 180);
    targetBase = constrain(targetBase, 0, 180);
    
    int targetShoulder = map(smoothPitch, -50, 50, 180, 30);
    targetShoulder = constrain(targetShoulder, 30, 150);
    
    // Smooth approach (reduce step size)
    baseAngle += (targetBase - baseAngle) / 4;
    shoulderAngle += (targetShoulder - shoulderAngle) / 4;
    
    // Write both servos with a tiny stagger
    baseServo.write(baseAngle);
    delay(3);   // small gap to let current settle
    shoulderServo.write(shoulderAngle);
    delay(3);
    
    // Debug output
    Serial.print("P:"); Serial.print(smoothPitch);
    Serial.print(" R:"); Serial.print(smoothRoll);
    Serial.print(" B:"); Serial.print(baseAngle);
    Serial.print(" S:"); Serial.println(shoulderAngle);
  }
  
  delay(20); // loop pacing
}