// include the servo library
#include <Servo.h>

// make a new servo object
Servo servo;

//define the pins
int trigPin = 9;
int echoPin = 8;

// defines variables
long duration = 0;
int distance = 0;

void setup() {
  servo.attach(7); //attach the servo to pin 7
  servo.write(0);
  delay(2000);

  // Sets the trigPin as an Output
  pinMode(trigPin, OUTPUT);
  // Sets the echoPin as an Input 
  pinMode(echoPin, INPUT);
  // Starts the serial communication 
  Serial.begin(9600);
}

void loop() {
  
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  if (distance <= 25) // Change Distance according to Ultrasonic Sensor Placement
  {
    servo.write(0);
    delay(3000);
  } else {
    servo.write(90);
  }
}
