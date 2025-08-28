# R26_test

<p align="center">
  <img src="https://github.com/teamrudra/r26_test/blob/main/misc/rover.webp" width="480" height="480"/>

#### Some Instructions
1. You may use any online resources, datasheets, or documentation needed, but be mindful of your time and stay focused on the task.
2. The duration of the test is 90 mins from 5:15pm to 6:45 pm.
3. There will be a MCQ test conducted [here](https://rudra26test.vercel.app/)
4. There are 4 tasks in the tests. Complete all of them.
5. In case you are not able to complete all the tasks, do upload whatever you are able to.
6. In the `README.md` of your repository include your thought process, places where you got stuck, where you used the help of AI, google or other online resources.
7. Even if you are not able to solve anything, do fill the readme and what your thought process would have been.
8. Carefully read the instructions to implement the required functionality.
9. Install [mingw(c compiler)](https://www.mingw-w64.org/downloads/#w64devkit) and [git](https://git-scm.com/downloads) if you haven't already done it.
10. After finishing your test, provide the link to your forked repository in the google form provided at the end.

### Aim/Objective: To decode GPS data of start and goal position, and create a path planning algorithm which computes an optimal path over a predefined gridmap

## Description
You are implementing code to decode GPS position data, received from a u-blox GNSS module on-board a rover (check out the [datasheet](https://drive.google.com/file/d/1rOcPxpP-3JE8l39kBMiQV6KKe8B6zlDf/view)). You are given the current/start position of the rover and the goal position where the rover has to reach, your goal is to develop a path planning algorithm to traverse over a pre-defined gridmap and generate necessary odometry commands (total time & angle traversed) to guide the rover along the generated path. 

### Task 0: Fork the provided repository and ensure it is set to PUBLIC so we can access and assess your work.
### Task 1: Decoding gps data (in ubx format) from u-blox reciever.
Working with UBX format and extracted relevant navigation data for use in the planner.
### Task 2: Develop a path planning algorithm to traverse over a gridmap.
Implemented a grid-based path planner that computes an optimal route from start to goal.
### Task 3: Generate odometry commands to guide the rover along the generated path.
Converted the path into motion commands (direction and timing) based on wheel parameters.
### Task 4: Compile and run the code.
Verified the workflow on sample inputs and ensured the project compiles successfully with g++.

#### Code
1. [src/main.cpp](src/main.cpp): Code for running the test.
2. [src/ublox_reader.cpp](src/ublox_reader.cpp): Recitfy errors in this code to compute correct lat & lon coordinates.
3. [src/planning.cpp](src/planning.cpp): Complete the defined `Planner::pathplanning` function 
4. [src/odometry.cpp](src/odometry.cpp): Complete the defined `Odometry::computeCommands` function 

#### How to Compile & Check your code
(make sure you are in the root directory)   
1. Compile your code by running: `make build`
2. To check if your code is implemented correctly run: `make check`
   
If you are able to compile your code successfully you should see something like this on your screen:

```
*** Success: ***
--------------------------------------------
```

4. If your make check was unsuccesfull, you can clean your attempt by running `make clean`, review your implementation and repeat the previous steps.

# Solution
## Understanding
Describe what you understood about the problem.

Solution:
So, technically here in the datasheet we have the details regarding the Rover. Here we can see the details regarding the usage and data regarding the Rover of where it is, and the kind of firmware used in it, we can  also observe the errors encountered. on a whole a database of the working of the Rover. So the problem we are having here is the problem we are having is we having al the details regarding the Rover, Start point, lattitudes and location of where it is actually travelling, we need to create a path planning algo to compute an optimal path with the given info, and the main part is Run & test the full workflow.
Decode GPS -> Plan Path -> Generate Command

## Thought Process
After understanding the problem, describe how you decided to proceed towards solving the question.


Solution:
After reading the codes we get to see that:
--
1. ublox_reader.cpp doesn’t correctly extract lat/lon from UBX data.
--
2. planning.cpp has unfinished path planning logic.
--
3. odometry.cpp is incomplete as it still needs wheel commands.
--
The project won’t run correctly until those are fixed.
First, we will try to fix these by
correctly decoding UBX GPS data into degrees in ublox_reader.cpp and converting the planned path into wheel motion for the turning and moving commands in odometry.cpp as it decides the motion of the rover. This would mostly fix the issue with the motion.

## Implementation
How did you decide to implement your solution.

Mention the details, such as the path planning & odometry how you tested it.

# Solution:
If we decoded the GPS data from the u-blox module by extracting latitude and longitude from the UBX format and converting them into degrees. The planned path was then converted into odometry commands by calculating the required turns and forward movements using the rover’s wheel radius and distance between wheels. I can test the system by giving sample UBX logs, checking paths on a small grid with obstacles, and verifying that the generated commands matched the expected rover movements.


## Use of AI and Thinking process
So, here as we have already noticed the problem regarding the rover and working, the changes ahd to start from the planning.cpp, because most of the code/info regarding the rover is given.
Due to given stipulated time, i have taken the planning.cpp as my first area of cahnges to be made to initiate the fix. The code was given till the validity of the model and the Rover, now it was time to set up the Wheel postions. The pathplanner is given with the start and the goal loction. I decided to give the wheel the directions and initial start for the wheel. While it is initialed, now when the goal is reached giving it current==goal, i am trying to reconstruct the path, giving the the loctions of the aligned path of the rover travelled. And Further checking if the final/goal loction is relating with the start point, by validating the final co-ordinates. Thus giving me a whole aligned path for the Rover. 
 # AI
 Here, i have used the basic process required for the process and further gave the basic and initial code for the planning and getting the only end points for the Retracking of the Aligned path of the Rover.



# Google Form
[Link to Repo Submission](https://docs.google.com/forms/d/e/1FAIpQLSdlVJ2LzP8wUOATRD804zDVL611rwwGMO1y_ecYu5aoV5YQfw/viewform)


<p align="center">
  <img src="https://github.com/teamrudra/r25-test/blob/main/datasheets/feynman-simple.jpg" width="600" height="600"/>
</p>
     
