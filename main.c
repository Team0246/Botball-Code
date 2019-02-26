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
    while (gmpc(0)<(deg*x))
    {
        motor(0, 50);
        motor(3, -50);
    }
}

void reset()
{
    enable_servos();
    set_servo_position(0, 1200);
    set_servo_position(1,2000);
    disable_servos();
}

void scoop()
{
    
    enable_servos();
    set_servo_position(2,700);
    msleep(1000);
    
    motor(2, 50);
    msleep(500);
    ao();
    msleep(2000);
    
    //reverse(10); 
    motor(2, -50);
    msleep(500);
    ao();
    msleep(2000);
    
    set_servo_position(2,1200);
    msleep(1000);
    
    motor(2, 50);
    msleep(500);
    ao();
    msleep(2000);
    
    set_servo_position(2,400);
    msleep(1000);
    disable_servos();
    
    
}

void waterCollection()
{
    reverse(10);
    scoop();
    int x = 0;
    while (x < 3)
    {
        reverse(30);
    	scoop();
        x = x + 1;
    }
}

void untilWall(int dir, int pow)
{
    while (digital(8) == 0) //bumper pressed aginst back wall
    {
        motor(0, (dir * pow) - (1 * dir));
        motor(3, dir * pow);
    }
}

void untilColor(int color)
{
    if(color == 1)
    {
        while (analog(0) < 1600) //Go until black
    	{
            motor(0, 75);
            motor(3, 75);
    	}
        
    }
    else
    {
     	while (analog(0) > 1600) //go until white
    	{
            motor(0, 75);
            motor(3, 75);
    	} 
    }
}

void collectWater()
{
    reset();
    forward(30); // pass start line
    untilColor(1); // go until see black line
    right(90); //turn right
    forward(65); // go to blue
    left(120); // face blue
    waterCollection(); // water collection
    untilWall(-1, 75); // go untill hit far wall
    right(90); // turn toward utility zone
    untilWall(1,75); //go until hit back wall
    left(180); // turn to face playing field
}

void clawUp()
{   
    set_servo_position(0,50);
    msleep(1000);
    set_servo_position(1,1500);
    msleep(1000);
}
void clawDown()
{
    set_servo_position(1,200);
    msleep(1000);
    set_servo_position(0,1000);
    msleep(1000);
}

void setPowerLines()
{
    /*
    while (analog(0) > 1600) //sense grey line
    {
        motor(0, 50);
        motor(3, 50);
    }
    */
    clawUp();
    reverse(10);
    clawDown();
    forward(20);
    clawUp();
    forward(10);
    clawDown();
    left(90);
    forward(30);
    right(90);
    
}

void pickUpValve()
{
    enable_servos();
    set_servo_position(0,1800); //down 560
    msleep(1000);
    set_servo_position(1,1500); //open
    msleep(1000);
    
    disable_servos();
    forward(14);  
    ao();
    enable_servos();

    set_servo_position(1,200); //close
    msleep(1000);
    int i = 1800;
    while (i > 50)
    {
        set_servo_position(0,i); //up
        i = i - .3;
    }    
    msleep(1000);
    
    disable_servos();
    reverse(14);
    ao();
    enable_servos();
    
    set_servo_position(0,560); //down
    msleep(1000);
    disable_servos();
}

void gasValve()
{
    forward(10);
    msleep(1000);
    pickUpValve();
    left(180); //turn around
    forward(50);
    enable_servos();
    set_servo_position(1,1500); //drop
    disable_servos();
}

int main()
{    
    //collectWater();
    //setPowerLines();
    //gasValve();
    //pickUpValve();
    
    scoop();
    
    ao();
    return 0;
}

//***************** Plan ****************
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
