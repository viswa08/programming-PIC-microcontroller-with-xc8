/*
 * File:   main.c
 * Author: viswa
 *
 * Created on May 12, 2020, 6:09 PM
 */

#include "18F4550_Internal.h"
#include <stdint.h>


void port_init(void);
void timer0_init(void);

void __interrupt () ISR (void)
{
       if(T0IF)
    {
        LATDbits.LATD1^=1;
        TMR0 = 0xE17B;
        T0IF = 0;
    }
}
    

void main(void) {
    port_init();
    timer0_init();
    //LED blink
    
     while(1){
       LATDbits.LATD2 = ~PORTDbits.RD0; 
         
    }
       
    return;
}



void port_init(){
    internal_8();
    TRISDbits.TRISD1 = 0;
    TRISDbits.TRISD2 = 0;
    
    PORTEbits.RDPU = 1; //enabling internal pull up for port D
    TRISDbits.TRISD0 = 1; // Set PIN D0 as input
    LATDbits.LATD1 = 0;
    LATDbits.LATD2 = 0;
    
    
}

void timer0_init(void){
    TMR0 = 0xE17B; //value = resolution - (T*Fosc)/(4*prescale) - 65535 - (1*8000000)/(4*256)) = 57723
    T0CON = 0X87; //timer ON and 356 pre-scale
    INTCONbits.GIE = 1;
    INTCONbits.TMR0IE = 1;
}
 
