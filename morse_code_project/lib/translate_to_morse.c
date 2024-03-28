#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "translate_to_morse.h"

/*
* isAlphaNumberic -> Determines if a character is in the English alphabet or a number 0-9
*
* @INPUTS:
*   A character... dyh
*
* @RETURNS:
*   1: Character is in the alphabet | a number
*   0: Character is NOT in the alphabet | a number
*/

static uint32_t isAlphaNumeric(const uint8_t* c){
    //ASCII stuff, "It just works" - Todd Howard
    if( (*c >= 'A' && *c <= 'Z') ||
        (*c >= 'a' && *c <= 'z') ||
        (*c >= '0' && *c <= '9')) 
        {
            return 1;
        }

        return 0;
}

/*
* toLowercase -> To avoid importing an entire lib for tolower, I have made this.
*   Simply alters a character to be lowercase
* 
* @INPUTS:
*   A character
*       - an alphabetical character
*       - HAS BEEN CHECKED ALREADY
*
* @RETURNS:
*   VOID => Alters character in place to avoid passing by copy
*/

static void toLowercase(uint8_t* c){
    //Check if upper
    if(*c >= 'A' && *c <= 'Z'){
        *c += 32;
    }
}

/*
* characterToIndexHash() -> calculates an index representing the position of a character's Morse code in an array
*
* @INPUTS:
*   Can you guess? That's right! A frog!
*   THIS FROG CAN NOT BE CHANGED
*   FROG HAS BEEN CHECKED AND IS A VALID FROG. 
*   It's name is most likely kermit.
*
* @RETURNS:
*   HASH_ERROR => Default 254. Hashing error.
*   An int between 0 and 36 that corresponds with the character's morse code index in the array.
*
*
* TODO:
*   Figure out a new ret value for hash error.
*   254 should be impossible to reach but I have been wrong before.
*/
static uint8_t characterToIndexHash(const uint8_t* c){
    if(*c >= 'a' && *c <= 'z'){
        /*Maps  a => 0
        *       b => 1
        *       c => 2
        * *     ...
        */
        return (*c - 97);
    } else if (*c >= '0' && *c <= '9'){
        /*
            Numbers start 26 characters in, so a buffer of 26 is added
                '0' - '0' + 26 = 26
                '1' - '0' + 26 = 27
                ...

                26th index of morseCode => '0' in morse code
        */
        return (*c - '0' + 26);
    } else {
        //Dead code. Should never get here since c is already checked, but prelim caution just in-case
        return HASH_ERROR;
    }
}


/*
* charToTranslate() -> Translates a character (usually passed by a helper function) to morse code
* 
* @INPUTS:
*    A character... any character.  
*
* @RETURNS:
*    50                  => Non-valid characters | Hashing Error
*                           -stderr will tell user which it is
*   
*    Non-empty string   => For when character passed is a valid character
*/

static uint8_t* charToTranslate(uint8_t* c){

    static uint8_t* morseCode[37] = {
        /*A*/   ".-",   
        /*B*/   "-...",
        /*C*/   "-.-.", 
        /*D*/   "-..",
        /*E*/   ".",
        /*F*/   "..-.",
        /*G*/   "--.",
        /*H*/   "....",
        /*I*/   "..",
        /*J*/   ".---",
        /*K*/   "-.-",
        /*L*/   ".-..",
        /*M*/   "--",
        /*N*/   "-.",
        /*O*/   "---",
        /*P*/   ".--.",
        /*Q*/   "--.-",
        /*R*/   ".-.",
        /*S*/   "...",
        /*T*/   "-",
        /*U*/   "..-",
        /*V*/   "...-",
        /*W*/   ".--",
        /*X*/   "-..-",
        /*Y*/   "-.--",
        /*Z*/   "--..",
        
        /*0*/   "-----",
        /*1*/   ".----",
        /*2*/   "..---",
        /*3*/   "...--",
        /*4*/   "....-",
        /*5*/   ".....",
        /*6*/   "-....",
        /*7*/   "--...",
        /*8*/   "---..",
        /*9*/   "----.",

        /* */   "/",
    };

    //Handles spaces
    if(*c == 32){
        debug("%c in morse code: %s\n", *c, morseCode[36]);
        return morseCode[36];
    }

    //Checks if character passed is valid
    if(!isAlphaNumeric(c)){
        
        debug("\n%c: Character is not alphabetical nor a number 0-9.\n", *c);

        return c;
    }

    debug("   Before: %c\n", *c);

    //Converts the character to lowercase
    toLowercase(c);

    debug("   After: %c\n", *c);

    uint8_t characterIndex = characterToIndexHash(c);

    debug("   %c index in morseCode: %d\n", *c, characterIndex);

    debug("   %c in morse code: %s\n", *c, morseCode[characterIndex]);

    //Error check
    if(characterIndex == HASH_ERROR){
        fprintf(stderr, "Error hashing character.\n");
        return NULL; 
    }

    return morseCode[characterIndex];
}

CharacterList* createNewCharacterNode(){
    CharacterList* new_node = calloc(1, sizeof(*new_node));

    if(!new_node){
        fprintf(stderr, "Error: Couldn't calloc memory for new_node.\n");
    }

    return new_node; 
}

void freeMorseCodeList(CharacterList* head){
    if(head == NULL){
        fprintf(stderr, "You passed a NULL head. RIP.\n");
        return;
    }

    while(head != NULL){
        CharacterList* delete = head;
        head = head->next;
        free(delete);
    }
}

/*
* phraseToTranslate() -> Translates a phrase to morse code
* 
* @INPUTS:
*    -A phrase
*
* @RETURNS:
*    NULL => Phrase containts non-valid characters
*
*    Non-empty string   => For when phrase passed is valid
* 
* Designing this so each character is a node in a linked list.
*   Why? Because I don't want to have a buffer limit (capping the phrase character limit)... bad idea? Probably. Esp for a small milk boy.
*/

// Modify the function signature to return a string instead of a linked list
extern uint8_t* phraseToTranslate(uint8_t* phrase) {
    // Count the number of characters in the phrase
    uint32_t phrase_length = 0;
    while (phrase[phrase_length] != '\0') {
        phrase_length++;
    }

    // Calculate the maximum possible size needed for the resulting Morse code translation
    uint32_t max_result_size = phrase_length * 5; // Maximum 5 Morse code characters per English character
    uint32_t result_size = 0;

    // Allocate memory for the resulting Morse code translation
    uint8_t* result = calloc(max_result_size + 1, sizeof(uint8_t)); // +1 for null terminator
    if (result == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for Morse translation.\n");
        return NULL;
    }

    // Concatenate the Morse code translations of each character into the result string
    uint8_t* result_ptr = result;

    while (*phrase != '\0') {
        uint8_t* morse_translation = charToTranslate(phrase);
        
        if (morse_translation != NULL) {
            // Copy Morse code translation to the result string
            uint32_t morse_length = 0;
            
            while (morse_translation[morse_length] != '\0') {
                result_ptr[result_size++] = morse_translation[morse_length++];
            }

            // Add space between characters except for the last one
            if (*(phrase + 1) != '\0') {
                result_ptr[result_size++] = ' ';
            }
        }
        phrase++;
    }

    // Null terminate the result string
    result[result_size] = '\0';

    return result;
}