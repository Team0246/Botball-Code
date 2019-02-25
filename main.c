#include <kipr/botball.h>

void forward(int cm)
{
    cmpc(0);
    int x = 88.8;
    while (gmpc(0)<(cm*x))
    {
        motor(0, 49);
        motor(3, 50);
    }
}
void reverse(int cm)
{
    cmpc(0);
    int x = 88.8;
    while (-(gmpc(0))<(cm*x))
    {
        motor(0, -50);
        motor(3, -50);
    }
}
void right(int deg)
{
    cmpc(0);
    int x = 10;
    while (gmpc(0)>-(deg*x))
    {
        motor(0, -50);
        motor(3, 50);
    }
}
void left(int deg)
{
    cmpc(0);
    int x = 10;
    while (gmpc(0)>-(deg*x))
    {
        motor(0, 50);
        motor(3, -50);
    }
}

int main()
{
    /*
    Start in Start box facing firehouse
    Drive forward until black detected
    Pick up up water reclamation unit
    Turn right 90
    Drive forward 80 cm
    Turn right 90
    Start water collection
    Drive forward following blue line
    Stop when hit wall
    Turn right 90
    Drive forward until bumper hit on wall
    Turn left 90
    Set water down
    Drive forward until bumper hit on wall
    Turn left 90
    Drive until sense grey line
    Raise claw
    Drive backward x amount setting line
    Lower claw
    Drive forward x amount
    Raise claw
    Drive  forward x amount setting line
    Lower claw
    Drive forward using color sensor on orange gas valve
    Follow black line in
    Pick up gas valve
    Turn left 180
    Drive forward until wall hit
    Set down gas valve
    Stop
    */
    //pick up water unit
    forward(10); // pass start line
    while (analog(0) < 1600) //color is white
    {
        motor(0, 50);
        motor(3, 50);
    }
    right(90); //turn
    forward(80); // go to blue
    right(90);
    /*
    int x = 0;
    while (x == 0) //line follow with bumper
    {
        if (analog(0) > 1600) 
        {
            motor(0, 50); 
        	motor(3, 100);
        }
        else
        {
            motor(0, 100);
        	motor(3, 50);
        }
    }
    right(90);
    while (digital(8) == 0) //bumper be pressed
    {
        motor(0, 50);
        motor(3, 50);
    }
    left(90);
    while (digital(8) == 0) //bumper be pressed
    {
        motor(0, 50);
        motor(3, 50);
    }
    left(90);
    //set water down
    while (analog(0) > 1600) //sense grey line
    {
        motor(0, 50);
        motor(3, 50);
    }
    //claw up
    reverse(10);
    //claw down
    forward(20);
    //claw up
    forward(10);
    //claw down
    left(90);
    forward(30);
    right(90);
    */
    /*
    while() //line follow in
    {
        
    }
    //pick up gas valve
    left(180);
    while() //drivw till wall hit
    {
        
    }
    left(90);
    while() //drivw till wall hit
    {
        
    }
    //set down gas valve
    //stop
    */
    return 0;
    ao();
}
