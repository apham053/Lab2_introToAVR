/*	Author: apham053
 *  Partner(s) Name: Steven Rodriguez
 *	Lab Section:
 *	Assignment: Lab #2  Exercise #2
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
 	DDRA = 0x00; 
 	DDRC = 0xFF; 
	PORTA = 0xFF;
	PORTC = 0x00;
	
	unsigned char cntAvail = 0x04; // 4 parking spaces total
	
 	while(1) {
		//unsigned char A7 = PINA & 0x80; // reads PA7
		unsigned char A3 = PINA & 0x08;   // reads PA3
		unsigned char A2 = PINA & 4;      // this works too
		unsigned char A1 = PINA & 0x02;
		unsigned char A0 = PINA & 0x01;   // reads PA0
		
 		if (A3 == 0x08) { //(true if PA3 is 1) 
 			cntAvail = cntAvail -1;
 		}

 		if (A2 == 0x04) {
 			cntAvail = cntAvail -1;
 		}

 		if (A1 == 0x02) {
 			cntAvail = cntAvail -1;
 		}

 		if (A0 == 0x01) {
 			cntAvail = cntAvail -0x01; // this works too
 		}
 		
 		if (cntAvail == 0x00) { // if parking lot full (cntAvail equals 0000 0000)
			cntAvail = 0x80;    // set cntAvail equal to 0x80 (PA7, 1000 0000)
		}                       // 0x0F is only case where parking lot is full

 		PORTC = cntAvail;
 		cntAvail = 0x04; // reset to 4 parking spaces open
 	}
	return 0;
}


