/* 	led_test.c
 * 	###############################################################################
 *
 * 	A simple software application to test the functionality of the led_controller
 * 	IP core. The value of a counter is output to the LEDs.
 *
 * 	###############################################################################
 * 	v1.0 -- 25/10/2013
 * 	############################################################################### */

/* Generated driver function for led_controller IP core */
#include "led_controller.h"
#include "xparameters.h"

// Define maximum LED value (2^8)-1 = 255
#define LED_LIMIT 255
// Define delay length
#define DELAY 10000000

/* 	Define the base memory address of the led_controller IP core */
#define LED_BASE XPAR_LED_CONTROLLER_0_S00_AXI_BASEADDR

/* main function */
int main(void){
	/* unsigned 32-bit variables for storing current LED value */
	u32 led_val = 0;
	int i=0;

	xil_printf("led_controller IP test begin.\r\n");
	xil_printf("--------------------------------------------\r\n\n");

	/* Loop forever */
	while(1){
			while(led_val<=LED_LIMIT){
				/* Print value to terminal */
				xil_printf("LED value: %d\r\n", led_val);
				/* Write value to led_controller IP core using generated driver function */
				LED_CONTROLLER_mWriteReg(LED_BASE, 0, led_val);
				/* increment LED value */
				led_val++;
				/* run a simple delay to allow changes on LEDs to be visible */
				for(i=0;i<DELAY;i++);
			}
			/* Reset LED value to zero */
			led_val = 0;
		}
	return 1;
}
