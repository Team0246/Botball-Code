#include <kipr/botball.h>
Functions:
blackleft (Left cliff sensor detects black tape)
blackright (Right cliff sensor detects black tape)
scorefire (Servo moves back and forth to score firefighters)
lturn90 (90 degree turn left)
rturn90 (90 degree turn right)
camerafind (find non burning medical center and go to it)
drive (drive forward using encoders)
closescoop (sets claw servos to closed position)
armup (servo moves arm up)
armdown (servo moves down)
int main()
Before Start:
//1. Wait for light
0-15 seconds: Collect ambulance and medical supplies
//2. Shutdown in x seconds
//3. Connect to create
//4. Turn on arm servo
//5. Raise arm down 
//6. Turn off arm servo
//7. Create While loop until robot detects first black tape use left cliff sensor
//8. Turn 90 degrees right
//9. Move robot forward for x amount using encoders
//10. Grab ambulance
//11. Turn left 90 degrees
//12. Create a while loop until the robot detects the black tape use left cliff sensor
//13. Turn left 90 degrees
15-30 seconds: Finish picking up medical supplies and close scoop
//14. Create while loop until sensors detect black tape use left cliff sensor
//15. Stop robot
//16. Turn on all servos
//17. Close scoop
30-45 seconds: Find and go to non-burning medical center
//18. Turn on camera
//19. Create if and else statements to determine location of burning and non-burning medical centers. If the left medical center is burning, turn 90 degrees opposite (right) to go to the non-burning medical center, go x amount using encoders, turn left 90 degrees, and move forward for x amount using encoders. If the right medical center is burning, go forward for x amount using encoders. 
45-60 seconds: Release ambulance and medical supplies and raise are up
//20. Inside the if and else statements:
Right non-burning medical center
Open scoop, raise arm up, move back x amount using encoders, and turn left 90 degrees
Left non-burning medical center
Open scoop, raise arm up, move back x amount using encoders, and turn left 90 degrees
//21. Turn off camera
60-75 seconds: Go to firefighter pole
//22. Create while loop until robot detects black tape use right cliff sensor
//23. Turn right 90 degrees
//24. Put arm down
75-90 seconds: Use arm to push firefighters into fire station
//25. Repeat action of moving the scoop servo left to right for 6 times
//26. Turn off all servos
//27. Stop the create
//28. Disconnect create
//29. Return to zero
