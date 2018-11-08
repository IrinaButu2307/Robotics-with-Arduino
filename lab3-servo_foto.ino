
#define PHOTO_PIN A0
#define SERVO_PIN 7

#include <Servo.h>
Servo myservo;

int servo_position = 0;
int lightLevel;
int adjustedLightLevel;

void setup() {
  myservo.attach(SERVO_PIN);
  Serial.begin(9600);
  pinMode(PHOTO_PIN, INPUT);
}

void loop(){
  lightLevel = analogRead(PHOTO_PIN);
  Serial.println(lightLevel);

  adjustedLightLevel = map(lightLevel, 0, 1023, 0, 180); //transformare analog->digital
 
  myservo.write(adjustedLightLevel); //aici se modifica miscarea
}
