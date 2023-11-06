#include <ESP32Encoder.h>


ESP32Encoder frontL;
ESP32Encoder frontR;
ESP32Encoder rearL;
ESP32Encoder rearR;

#define FRONT_LEFT 0
#define FRONT_LEFT_QUAD_A   13
#define FRONT_LEFT_QUAD_B   12
#define FRONT_LEFT_PWM      16
#define FRONT_LEFT_DIR      17

#define FRONT_RIGHT 1
#define FRONT_RIGHT_QUAD_A  14
#define FRONT_RIGHT_QUAD_B  27
#define FRONT_RIGHT_PWM     5
#define FRONT_RIGHT_DIR     18

#define BACK_LEFT 2
#define BACK_LEFT_QUAD_A    26
#define BACK_LEFT_QUAD_B    25
#define BACK_LEFT_PWM       19
#define BACK_LEFT_DIR       21

#define BACK_RIGHT 3
#define BACK_RIGHT_QUAD_A   33
#define BACK_RIGHT_QUAD_B   32
#define BACK_RIGHT_PWM      22
#define BACK_RIGHT_DIR      23

void setup(){
	
	Serial.begin(115200);

  //Set up motor encoders
  setupEncoders();

  //Set up motor drives
  setupMotors();

  //TODO: Create PID loops
}

#define SPEED 30

void loop(){
	// Loop and read the count
	Serial.println("Encoder count = " + String((int32_t)frontL.getCount()) + " " + String((int32_t)frontR.getCount()) + " " + String((int32_t)rearL.getCount()) + " " + String((int32_t)rearR.getCount()));
	delay(100);
 
 if(millis() < 6000) {
 writeMotor( 0, SPEED);
 writeMotor( 1, SPEED);
 writeMotor( 2, SPEED);
 writeMotor( 3, SPEED);
}
 else if(millis() < 12000) {
 writeMotor( 0, -SPEED);
 writeMotor( 1, -SPEED);
 writeMotor( 2, -SPEED);
 writeMotor( 3, -SPEED);
}

 else if(millis() < 18000) {
 writeMotor( 0, SPEED);
 writeMotor( 1, -SPEED);
 writeMotor( 2, SPEED);
 writeMotor( 3, -SPEED);
}

 else if(millis() < 24000) {
 writeMotor( 0, -SPEED);
 writeMotor( 1, SPEED);
 writeMotor( 2, -SPEED);
 writeMotor( 3, SPEED);
}
else {
  writeMotor( 0, 0);
  writeMotor( 1, 0);
  writeMotor( 2, 0);
  writeMotor( 3, 0);
}
}

void setupMotors() {
  //Init PWM interrupts
  ledcSetup(0, 5000, 8);
  ledcSetup(1, 5000, 8);
  ledcSetup(2, 5000, 8);
  ledcSetup(3, 5000, 8);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(FRONT_LEFT_PWM,  0);
  ledcAttachPin(FRONT_RIGHT_PWM, 1);
  ledcAttachPin(BACK_LEFT_PWM,   2);
  ledcAttachPin(BACK_RIGHT_PWM,  3);

  //Init all motors to speed 0
  ledcWrite(FRONT_LEFT,  0);
  ledcWrite(FRONT_RIGHT, 0);
  ledcWrite(BACK_LEFT,   0);
  ledcWrite(BACK_RIGHT,  0);

  //Set motor direction pins to output
  pinMode(FRONT_LEFT_DIR,  OUTPUT);
  pinMode(FRONT_RIGHT_DIR, OUTPUT);
  pinMode(BACK_LEFT_DIR,   OUTPUT);
  pinMode(BACK_RIGHT_DIR,  OUTPUT);

  //Set motor direction to forwards
  digitalWrite(FRONT_LEFT_DIR, LOW);
  digitalWrite(FRONT_RIGHT_DIR, LOW);
  digitalWrite(BACK_LEFT_DIR, LOW);
  digitalWrite(BACK_RIGHT_DIR, LOW);
}

void setupEncoders() {
  // Enable the weak pull down resistors

  //ESP32Encoder::useInternalWeakPullResistors=DOWN;
  // Enable the weak pull up resistors
  ESP32Encoder::useInternalWeakPullResistors=UP;

  //Attach quadrature encoder pin inputs
  frontL.attachHalfQuad(FRONT_LEFT_QUAD_A, FRONT_LEFT_QUAD_B);
  frontR.attachHalfQuad(FRONT_RIGHT_QUAD_A, FRONT_RIGHT_QUAD_B);
  rearL.attachHalfQuad(BACK_LEFT_QUAD_A, BACK_LEFT_QUAD_B);
  rearR.attachHalfQuad(BACK_RIGHT_QUAD_A, BACK_RIGHT_QUAD_B);

  //Reset tick counts for all encoders
  frontL.clearCount();
  frontR.clearCount();
  rearL.clearCount();
  rearR.clearCount();
}


void writeMotor(uint8_t motor, int speedVector) {
  int speed = min(abs(speedVector), 255);
  bool direction = speedVector < 0;

  switch(motor) {
    case FRONT_LEFT:
      digitalWrite(FRONT_LEFT_DIR, direction);
      ledcWrite(FRONT_LEFT, speed);
      return;
    case FRONT_RIGHT:
      digitalWrite(FRONT_RIGHT_DIR, direction);
      ledcWrite(FRONT_RIGHT, speed);
      return;
    case BACK_LEFT:
      digitalWrite(BACK_LEFT_DIR, direction);
      ledcWrite(BACK_LEFT, speed);
      return;
    case BACK_RIGHT:
      digitalWrite(BACK_RIGHT_DIR, direction);
      ledcWrite(BACK_RIGHT, speed);
      return;
    default:
      return;
  }
}

void differentialDrive(int speed, int distance, int turnPercent) {
  writeMotor(0, 0);
} 
