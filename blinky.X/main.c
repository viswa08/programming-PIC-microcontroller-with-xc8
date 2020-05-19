/*
 * File:   main.c
 * Author: viswa
 *
 * Created on May 12, 2020, 6:09 PM
 */

#include "18F4550_Internal.h"
#include <stdint.h>


void port_init(void);

void main(void) {
    port_init();
    //LED blink
    /*
     while(1){
       LATDbits.LATD1 = 1;
        __delay_ms(1000); 
        LATDbits.LATD1 = 0;
        __delay_ms(1000); 
    }
     */
    
    
    //press switch to blink LED
    /*
     while(1){
        
        if(PORTDbits.RD0 == 0){
            __delay_ms(100);
            if(PORTDbits.RD0 == 0){
                LATDbits.LATD1 = 1;
                __delay_ms(500);
                LATDbits.LATD1 = 0;
                __delay_ms(500);
            }
        }
        else{
            LATDbits.LATD1 = 0;
        }      
        
    }
     */
     
     
    
     
      
     
       
     
    
     //press switch to blink LED
     while(1){  
        int8_t in = PORTDbits.RD0;
        LATDbits.LATD1 = ~in;
     }
     
    
    return;
}

void port_init(){
    internal_8();
    TRISDbits.TRISD1 = 0;
    //LATDbits.LATD1 = 0; // Turn off LED 
    
    //PORTEbits.RDPU = 1; //enabling internal pull up for port D
    TRISDbits.TRISD0 = 1; // Set PIN D0 as input
    INTCON2.7=0
    INTCON2bits.RBPU = 0;
}
 
