#include <stdint.h>
#include "context.h"
#include "led.h"

uint32_t stack_blinky1[40];
OSThread blinky1;
void main_blinky1() {
    while (1) {
			
        BSP_ledBlueOn();
        BSP_delay(BSP_TICKS_PER_SEC / 4U);//200s
        BSP_ledBlueOff();
        BSP_delay(BSP_TICKS_PER_SEC *3U / 4U);//600
    }
}

uint32_t stack_blinky2[40];
OSThread blinky2;
void main_blinky2() {
    while (1) {
				BSP_ledRedOn();
        BSP_delay(BSP_TICKS_PER_SEC / 2U);//400s
        BSP_ledRedOff();
        BSP_delay(BSP_TICKS_PER_SEC / 3U);//266
    }
}


int main(void) {
    BSP_init();
    OS_init();

    /* start blinky1 thread */
    OSThread_start(&blinky1,
                   &main_blinky1,
                   stack_blinky1, sizeof(stack_blinky1));

    /* start blinky2 thread */
    OSThread_start(&blinky2,
                   &main_blinky2,
                   stack_blinky2, sizeof(stack_blinky2));

    /* transfer control to the RTOS to run the threads */
    OS_run();

    //return 0;
}
