#include <stdio.h>
#include <stdlib.h>

#include "translate_to_morse.h"
#include "devmem.h"
#include "cv1800b.h"
#include "blink_led.h"

void setup(){
    set_gpio_mode();

    volatile unsigned* swporta_dr_value = &GPIO2->SWPORTA_DR;
}

int main(){

    char text[] = "hElLo";

    uint8_t* morseCodePhrase = phraseToTranslate(text);

    blink_led(morseCodePhrase);
    return 0;
}