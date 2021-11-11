#include <stdio.h>
#include <linux/input.h>
#include <fcntl.h>     

int hotkeysNumbers[3][3] = {{18, 25, -1}, {25, 30, 46}, {18, 30, -1}};
int pressedHotkeys[3][3];

int main ()
{
    const char *path ="/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    struct input_event events[3000];
    while (1)
    {
        int val = read (open(path, O_RDONLY), events, sizeof(events));
        for (int i = 0; i < (int) (val / sizeof(struct input_event)); i ++)
        {
            if (events[i].type == EV_KEY)
            {
            	if (events[i].value == 0)
                    for (int j = 0; j < 3; j ++)
                        for (int k = 0; k < 3; k ++)
                            if ((int)(events[i].code) == hotkeysNumbers[j][k])
                                pressedHotkeys[j][k] = 0;
                if (events[i].value == 1)
                {
                    for (int j = 0; j < 3; j ++)
                        for (int k = 0; k < 3; k ++)
                            if ((int)(events[i].code) == hotkeysNumbers[j][k] || hotkeysNumbers[j][k] == -1)
                                pressedHotkeys[j][k] = 1;
                    if (pressedHotkeys[0][0] == pressedHotkeys[0][1] && pressedHotkeys[0][0] == pressedHotkeys[0][2] && pressedHotkeys[0][0] == 1)
                    	printf("I passed the Exam!\n");
                    if (pressedHotkeys[1][0] == pressedHotkeys[1][1] && pressedHotkeys[1][0] == pressedHotkeys[1][2] && pressedHotkeys[1][0] == 1)
                    	printf("Get some cappuccino!\n");
                    if (pressedHotkeys[2][0] == pressedHotkeys[2][1] && pressedHotkeys[2][0] == pressedHotkeys[2][2] && pressedHotkeys[2][0] == 1)
                    	printf("Hello World!\n");
                }
            }
        }
    }
}