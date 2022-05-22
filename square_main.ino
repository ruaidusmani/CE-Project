//Setup the Servo library and the ultrasound sensors' pins//
#include <Servo.h>
Servo leftservo;  
Servo rightservo;  
const int pingPin = 2; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 3; // Echo Pin of Ultrasonic Sensor
const int pingPin2 = 5; // Trigger Pin of Ultrasonic Sensor 2
const int echoPin2 = 6; // Echo Pin of Ultrasonic Sensor 2

void setup() {
  leftservo.attach(9);  
  rightservo.attach(10);
   //set up the Serial
  Serial.begin(9600);
  //setupt the pin modes  
  pinMode(pingPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pingPin2, OUTPUT);
  pinMode(echoPin2, INPUT);  
  leftservo.write(90);
  rightservo.write(90);
}

//Loop to run the program//
void loop() {
  long duration; //duration for ultrasonic wave travel from the left
  long distance; //distance from the left
  long duration2; //duration for ultrasonic wave travel from the front
  long distance2; //distance from the front

  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  
  //get the left pulse duration in microseconds and compute left distance
  duration = pulseIn(echoPin, HIGH); 
  distance = (0.034*duration)/2;

  digitalWrite(pingPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin2, LOW);
  
  //get the front pulse duration in microseconds and compute front distance
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (0.034*duration2)/2;

  //printing distances & durations//
  Serial.print("Side Duration = ");
  Serial.println(duration);
  Serial.print("Side Distance = ");
  Serial.println(distance);
  Serial.print("Front Duration = ");
  Serial.println(duration2);
  Serial.print("Front Distance = ");
  Serial.println(distance2);  
  
  //movement//
  int a=40; //threshold front distance from the base of the square 
  int b=50; //minimum left distance threshold position from the left wall before reaching the bottom perimeter
  int c=80; //maximum left distance threshold position from the left wall before reaching the bottom perimeter
  
  int d=60; //threshold front distance from the table before turning to right perimeter
  int e=100; //side length of the square

  int f=10; //minimum left distance threshold of the car from the right perimeter

  int g=0; //for zero distance errors


// approaching the perimeter
  if (distance2>a and distance<b) //moving straight towards the bottom perimeter
    leftservo.write(150);
    rightservo.write(60); 
  }
  
  else if (distance2<a and (distance<a and distance<c)) //turning right to be parallel to the bottom perimeter
  {
    //stop the car to prevent slipping
    leftservo.write(93);
    rightservo.write(93);
    delay(200);
    //right turn
    leftservo.write(120);
    rightservo.write(110);
    delay(450);
    ////stop the car to prevent slipping
    leftservo.write(93);
    rightservo.write(93);
    delay(1000);
  }

//bottom perimeter
  if (distance2>d and distance<d) //moving along the bottom perimeter
  {
    leftservo.write(115);
    rightservo.write(20);
  }

  else if (distance2<d and distance>e) //turing left to be parallel to the right perimeter
  {
    //stop the car to prevent slipping
    leftservo.write(93);
    rightservo.write(93);
    delay(200);
    //left turn
    leftservo.write(70);
    rightservo.write(45);
    delay(390);
    //stop the car to prevent slipping
    leftservo.write(93);
    rightservo.write(93);
    delay(1000);
  }

// right perimeter
  if (distance2>b and distance>e) //moving along the right perimeter
  {
    leftservo.write(160);
    rightservo.write(40);
  }

  else if (distance2<b and distance>f) //turning right to exit the perimeter and go to the gap
  {
    //stop the car to prevent slipping
    leftservo.write(93);
    rightservo.write(93);
    delay(200);
    //right turn
    leftservo.write(120);
    rightservo.write(110);
    delay(450);
    //stop the car to prevent slipping
    leftservo.write(93);
    rightservo.write(93);
    delay(1000);
  }

  if (distance2==g and distance==g) //stop the car if zero error occurs 
  {
    leftservo.write(93);
    rightservo.write(93);
    delay(1000);
  }

  delay(50); //loop to run at 50 microseconds
}
