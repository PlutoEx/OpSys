#include <stdio.h>
#include <fcntl.h>
#include <linux/input.h> 

int main ()
{
	const char *path = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    struct input_event events[3000];
    while (1)
    {
        int val = read (open (path, O_RDONLY), events, sizeof (events));
        for (int i = 0; i < (int) (val / sizeof (struct input_event)); i ++)
        {
        	if (events[i].type == EV_KEY)
           	{
            	if (events[i].value == 1)
                	printf ("PRESS 0xn%x (%d)\n", events[i].code, events[i].code);
              	if (events[i].value == 0)
                  	printf ("RELEASE 0x%x (%d)\n", events[i].code, events[i].code);
            }
        }
    }
}