#include <kipr/botball.h>

void blackleft (int integer);
int main()
{
create_connect();
blackleft (1);
create_stop();
create_disconnect();
return (0);
}
void blackleft (int integer)
    {
	while (get_create_lcliff_amt()>1950)
	{
	create_drive_direct(200,200);
	msleep(integer*10);
	create_stop();
	}
    }