# CE-Project

The CE was done during the last semester of CEGEP at Dawson College for Engineering Physics class (January to June 2021). 
I was inspired by the Engineering Physics labs where the class worked with Arduino to make a car as well as performimg simulations on the Virtual Lab.
The project took me around 2 months. I did the physical simulations before doing the super challenge at the end. 


-------------------------------------------------------------
**Part 1: Navigating the Arduino car around a square perimeter.**
-------------------------------------------------------------
_Refer to square_main.ino for the code._

The task for this part was to program an Arduino car that could navigate its way around the square perimeter and move to the exit gap.  

The simulation setup was done in one half of the room that only had an office table as the unmovable furniture. The square perimeter was built with cardboard in the corner of the room with side lengths of 1m. It was 80 cm away from the table with a gap underneath it that was 75 cm wide to use as the exit. 

The robot car was an Arduino-powered car, equipped with two servos motors to move it and two ultrasound sensors (HC-SR04) that could calculate distances from the front of the car and on its left. 

The simulation will start with the car moving towards the perimeter. When it reaches 40 cm close to the square's base and remains 40-100 cm away from the left wall, it will make a 90° right turn to become parallel to it. It will move along the perimeter until reaching the square's bottom right vertex. At this point, the car will be 60 cm away from the table at its front.  From the left, it will be greater than 60 cm away. It will make a 90° left turn to become parallel to the right perimeter of the square and cover some more distance. It will move straight until it is 50 cm away from the top wall, causing it to make a 90° right turn and then move towards the exit gap and finishing the task.
____________________________________________________________________________________________________________________________________________




-------------------------------------------------------------
**Part 2: Super Challenge**
-------------------------------------------------------------
_Refer to super_challenge.ino for the code_

Link to environemnt: https://englab.dawsoncollege.qc.ca/robot/5-%20Super%20Challenge.html

The task for this part was to solve the Super Challenge created as a continuation to the Class Challenge. The challenge was to create a single program that would run successfully in 4 different virtual environments. They differed in gap sizes from the top wall and the right wall. 

The program was divided into two parts, one to program the movement when the car was moving along the top wall and the other to program the motion along the right wall. The simulation will start by steering the car, 142 cm away from the top wall, towards the set of coins. When it reaches a certain distance, it will curve in line with the first set of coins before moving straight to collect the coins. It will eventually arrive at the gap to make a 90° right turn, thus bringing the end to the first part. 

In the second part, the car will have to evaluate how far it is from the right wall. If it is far, it will have to make a 90° left turn to return to a position parallel to the top wall and move a small distance forward before having to make another 90° right turn. It will again evaluate the distance from the right wall. If still far, it will keep doing a series of 90° turns and slowly moving forward before it reaches sufficiently close to collect the second set of coins, situated 70 cm from the right wall. There could be a chance for the car to be too close to the right wall. For that, it will move to do similar 90° turns to get into the perfect range.
____________________________________________________________________________________________________________________________________________
