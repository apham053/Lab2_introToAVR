/*	Author: apham053
 *  Partner(s) Name: Steven Rodriguez
 *	Lab Section:
 *	Assignment: Lab #2  Exercise #4 (Challenge)
 *	Exercise Description: [An amusement park kid ride cart has three seats, with 8-bit weight sensors connected to ports A, B, and C 
 *      (measuring from 0-255 kilograms). Set PD0 to 1 if the cart's total passenger weight exceeds the maximum of 140 kg. 
 *	Also, the cart must be balanced: Set port PD1 to 1 if the difference between A and C exceeds 80 kg. 
 *	Can you also devise a way to inform the ride operator of the approximate weight using the remaining bits on D?]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
 
#include <avr/io.h>
#include <stdlib.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
 	DDRA = 0x00;  // 0 is input
	DDRB = 0x00;
	DDRC = 0x00; 
	DDRD = 0xFF;  // 1 is output
	PORTA = 0xFF; // initialize ports A-C to 1's
	PORTB = 0xFF;
	PORTC = 0xFF;
	PORTD = 0x00; // initialize port D to 0's
	
	unsigned char D = 0x00;
	
 	while(1) {
		unsigned char A = PINA & 0xFF;
		unsigned char B = PINB & 0xFF;
		unsigned char C = PINC & 0xFF;
		
		if ((A+B+C) > 0x8C) {
			D = D | 0x01;
		}
		
		if (abs(A - C) > 0x50) {
			D = D | 0x02;
		}

		D = D | (A + B + C);
		
		PORTD = D;
		D = 0x00;	
 	}


	return 0;
}


