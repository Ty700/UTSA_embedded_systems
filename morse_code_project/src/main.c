#include <stdio.h>
#include <stdlib.h>

#include "translate_to_morse.h"

int main(){

    char text[] = "hElLo";

    uint8_t* morseCodePhrase = phraseToTranslate(text);

    debug("%s\n", morseCodePhrase);

    /*
        TODO:
            Start on the Milk Duo logic... Eh, another day.
    */
    return 0;
}