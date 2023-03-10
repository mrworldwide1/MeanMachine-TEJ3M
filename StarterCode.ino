/*This code will allow you to detect whether the distance sensor is detecting a close object and moving the servo to a new position if it's far or close */

#include <Servo.h>

int pos = 0;

Servo servo_9;

int inches = 0;

int cm = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  servo_9.attach(9, 500, 2500);
  
  pos = 180;
  servo_9.write(pos);
  delay(100);
  Serial.println("Ready");
}

void loop()
{

   getDistance();
  
  if(cm < 30 ){
    if( pos < 175){
        pos += 5;
       servo_9.write(pos);
    }
    else{
      Serial.println("At position");
    }
  }
  else{
    if(pos > 5){
        pos -= 5;
       servo_9.write(pos);
    }
    else{
      Serial.println("At position");
    }
  }

  delay(20);
}

void getDistance(){
  cm = 0.01723 * readUltrasonicDistance(2, 2);
  Serial.print("dist is: ");
  Serial.println(cm);
}
