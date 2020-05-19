  /*
 * File:   18F4550_INternal.c
 * Author: viswa
 *
 * Created on May 11, 2020, 10:57 PM
 */


#include "18F4550_Internal.h"

void internal_8(){
    SCS0 = 0;
    SCS1 = 0;
    IRCF0 = 1;
    IRCF1 = 1;
    IRCF2 = 1;
}
