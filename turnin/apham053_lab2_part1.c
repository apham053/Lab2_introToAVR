/*	Author: apham053
 *  Partner(s) Name: Steven Rodriguez
 *	Lab Section:
 *	Assignment: Lab #2  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif		

int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs, initialize to 1s
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char garageDoor = 0x00; // Temporary variable to hold the value of garage door sensor
	unsigned char lightSensor = 0x00; // Temporary variable to hold the value of light sensor
	unsigned char LED = 0x00; // Temporary variable to hold the value of LED
while(1) {
		// 1) Read input
		garageDoor = PINA & 0x01; // reads PA0
		lightSensor = PINA & 0x02; // reads PA1
		
		// 2) Perform computation
		if ((garageDoor == 0x01) && (lightSensor == 0x00)) {
			LED = (LED & 0xFE) | 0x01;
			//LED = 0x01;
		}
		else {
			LED = (LED & 0xFE) | 0x00;
			//LED = 0x00;
		}
		
	    // 3) Write output
		PORTB = LED;	
	}
	return 0;
}


