#ifndef TRANSLATE_TO_MORSE_H
#define TRANSLATE_TO_MORSE_H

#include <stdint.h>

#define HASH_ERROR 254

#ifdef MORSE_DEBUG
    #define debug(fmt,args...)	printf(fmt ,##args)
#else
    #define debug(fmt,args...)
#endif /* MORSE_DEBUG */


typedef struct CharacterList {
    uint8_t character;
    uint8_t* morseCodeTranslation;
    struct CharacterList* next;
    //CharacterList* prev; //Do I want to be able to traverse it backwards? Idfk
} CharacterList;

extern uint8_t* phraseToTranslate(uint8_t* phrase);

#endif /*TRANSLATE_TO_MORSE_H*/