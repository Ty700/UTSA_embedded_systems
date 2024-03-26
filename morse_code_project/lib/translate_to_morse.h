#ifndef TRANSLATE_TO_MORSE_H
#define TRANSLATE_TO_MORSE_H

uint32_t isAlphaNumberic(uint8_t c);
uint8_t characterToIndexHash(const char* c);
const uint8_t* charToTranslate(char c);

#endif /*TRANSLATE_TO_MORSE_H*/