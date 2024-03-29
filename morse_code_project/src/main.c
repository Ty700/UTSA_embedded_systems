#include <stdio.h>
#include <stdlib.h>

#include "translate_to_morse.h"
#include "devmem.h"
#include "cv1800b.h"
#include "blink_led.h"

int main(){

    char text[] = "hElLo";

    uint8_t* translation = phraseToTranslate(text);

    /* Spaced over to match with debug in blink_led*/
    debug("Phrase in main:     %s\n", translation);
    
    blink_led(translation);
    return 0;
}