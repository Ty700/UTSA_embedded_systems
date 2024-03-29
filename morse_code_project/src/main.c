#include <stdio.h>
#include <stdlib.h>

#include "translate_to_morse.h"
#include "devmem.h"
#include "cv1800b.h"
#include "blink_led.h"

// void setup(){
//     set_gpio_mode();

//     volatile unsigned* swporta_dr_value = &GPIO2->SWPORTA_DR;
// }

int main(){

    char text[] = "SOS";

    uint8_t* translation = phraseToTranslate(text);

    /* Spaced over to match with debug in blink_led*/
    debug("Phrase in main:     %s\n", translation);
    
    blink_led(translation);
    return 0;
}