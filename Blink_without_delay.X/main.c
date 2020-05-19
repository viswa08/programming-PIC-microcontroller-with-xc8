/*
 * File:   main.c
 * Author: viswa
 *
 * Created on May 19, 2020, 4:24 PM
 */


#include <xc.h>
#include <stdint.h>
#include "18F4550_Internal.h"

void port_init(void);
void timer1_delay(void);


void main(void) {
    port_init();
    
    while(1){
        LATDbits.LATD1 ^= 1; //toggle LED
        timer1_delay();        
        
    }
    return;
}



void port_init(void){
    internal_8();
    TRISDbits.TRISD1 = 0; //D1 as output
    LATDbits.LATD1 = 0; // Turn off LED 
    
    //PORTEbits.RDPU = 1; //enabling internal pull up for port D
    //TRISDbits.TRISD0 = 1; // Set PIN D0 as input
    //INTCON2.7=0    
}

void timer1_delay(void){
    int count = 0;
    while(count != 500){
    T1CON=0x80;             /* Enable 16-bit TMR1 register, No pre-scale, internal clock,timer OFF */
    TMR1=0xf830;            /* Load count for generating delay of 1ms */
    T1CONbits.TMR1ON=1;  	/* Turn ON Timer1 */
    while(PIR1bits.TMR1IF==0); 	/* Wait for Timer1 overflow interrupt flag */
    
    TMR1ON=0;  			/* Turn OFF timer */
    TMR1IF=0;  			/* Make Timer1 overflow flag to '0' */
    count++;
    }
    
    
}


