#include <stdio.h>
#include <stdlib.h>

#include "translate_to_morse.h"

int main(){
    char text[] = "Hello World!";

    uint8_t* morseCodePhrase = phraseToTranslate(text);

    printf("%s\n", morseCodePhrase);
    return 0;
}