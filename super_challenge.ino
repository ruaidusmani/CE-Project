//Setup servos and ultrasound sensor//
#include <Servo.h>
Servo leftservo;
Servo rightservo;  
const int pingPin = 5; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
void setup() {
  leftservo.attach(9);  
  rightservo.attach(10);

  //set up the Serial
  Serial.begin(9600);

  //setup the pin modes  
  pinMode(pingPin, OUTPUT);
  pinMode(echoPin, INPUT);
  leftservo.write(90);
  rightservo.write(90);
}

int x=0; //counter to use different set of code for car off the top wall and off the right wall
void loop() {
  long duration; //duration for ultrasound wave to travel
  long distance; //duration for distance from car to wall
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);

  //getting the pulse duration in microseconds
  duration = pulseIn(echoPin, HIGH);
  if(duration==0) return;
  distance = (0.034*duration)/2;
  

  //printing distance & durations//
  Serial.print("Duration = ");
  Serial.println(duration);
  Serial.print("Distance = ");
  Serial.println(distance);
  
  //stored constant distances
  int a = 143; //the starting position of the car from the top wall
  int b = 120; //the distance when the car has to start curving into the line
  int c = 100; //the lowest threshold for the car to curve to be in line with first set of coins
  int d = 110; //distance of coins from the top wall
  int e = 196; //largest distance capable of being measured. Used for gaps and distance from the right wall
  int f = 80; //the upper threshold for the car to be away from the right wall to collect the coins
  int g = 50; //the lower threshold for the car to be away from the right wall to collect the coins
  
  
  //movement//

  //this is to program the movement from the top wall until it does the turn at the gap
  if (x==0) 
  {
    if (distance>b and distance<a) //moving close to the wall from starting position
    {
      leftservo.write(125);
      rightservo.write(0);
    }
    else if (distance<b and distance>c) //curving in line with first set of coins
    {
      leftservo.write(180);
      rightservo.write(80);
    }
    else if (distance<=d) //running straight to collect the top wall coins
    {
      leftservo.write(180);
      rightservo.write(0);
    }

    else if (distance>e) //when at gap 
    { 
      //moving forward before turning to get aligned with second set of coins
      leftservo.write(160);
      rightservo.write(0);
      delay(200);

      //turn the car at 90º to the right
      leftservo.write(180);
      rightservo.write(180);
      delay(2600);

      x+=1; //ending the top wall program
    }
  }

  //this is to program the movement off the right wall after the gap turn
  else
  {
    if (distance<=f and distance>=g)//moving straight if between 50-80cm
    {
      leftservo.write(170);
      rightservo.write(0);
    }

    else if (distance<g)// turning left if any lower than 50cm
    {
      //make a 90º left turn
      leftservo.write(0);
      rightservo.write(0);
      delay(2790);

      //slightly head away from the right wall
      leftservo.write(20);
      rightservo.write(180);
      delay(300);

      //make the 90º right turn
      leftservo.write(180);
      rightservo.write(180);
      delay(2790);
    }

    else if (distance>f) //moving right towards the right wall until between reaching 80cm
    {
      Serial.print("Turning distance = ");
      Serial.println(distance);

      //make a 90º left turn
      leftservo.write(0);
      rightservo.write(0);
      delay(2790);

      //slightly head towards the right wall
      leftservo.write(150);
      rightservo.write(0);
      delay(500);

      //make the 90º right turn
      leftservo.write(180);
      rightservo.write(180);
      delay(2790);
    }
  }
  delay(50);  
}
