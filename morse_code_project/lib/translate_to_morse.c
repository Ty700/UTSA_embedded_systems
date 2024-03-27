#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "translate_to_morse.h"

#define OUTFILE "test.txt"

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
*    NULL               => Non-valid characters | Hashing Error
*                           -stderr will tell user which it is
*
*    Non-empty string   => For when character passed is a valid character
*/

static uint8_t* charToTranslate(uint8_t* c){

    static uint8_t* morseCode[36] = {
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
    };

    //Checks if character passed is valid
    if(!isAlphaNumeric(c)){
        
        debug("\n%c: Character is not alphabetical nor a number 0-9.\n", *c);

        #ifndef MORSE_DEBUG //It seems stderr prints before stdout??
        fprintf(stderr, "Character is not alphabetical nor a number 0-9.\n");
        #endif /*MORSE_DEBUG*/
        return NULL;
    }

    debug("\nBefore: %c\n", *c);

    //Converts the character to lowercase
    toLowercase(c);

    debug("\nAfter: %c\n", *c);

    uint8_t characterIndex = characterToIndexHash(c);

    debug("\n%c index in morseCode: %d\n", *c, characterIndex);

    debug("\n%c in morse code: %s\n", *c, morseCode[characterIndex]);

    //Error check
    if(characterIndex == HASH_ERROR){
        fprintf(stderr, "Error hashing character.\n");
        return NULL; //<= So the compiler will shut up
    }

    return morseCode[characterIndex];
}

CharacterList* createNewCharacterNode(){
    CharacterList* new_node = calloc(1, sizeof(*new_node));

    return new_node; 
}

void freeMorseCodeList(CharacterList* head){
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
*    -Phrase Length
*
* @RETURNS:
*    NULL => Phrase containts non-valid characters
*           - TODO: Change this to where it just omits the characters a continues???
*
*    Non-empty string   => For when phrase passed is valid
* 
* Designing this so each character is a node in a linked list.
*   Why? Because I don't want to have a buffer limit (capping the phrase character limit)... bad idea? Probably. Esp for a small milk boy.
*/

extern CharacterList* phraseToTranslate(uint8_t* phrase){
    CharacterList* head = NULL;
    CharacterList* current = NULL;
    
    while(*phrase != '\0'){
        CharacterList* new_character = createNewCharacterNode();
        new_character->character = *phrase;
        new_character->morseCodeTranslation = charToTranslate(phrase);

        if(head == NULL){
            head = new_character;
            current = new_character;
        } else {
            current->next = new_character;
            current = current->next;
        }
        
        phrase++;
    }
    return head;
}

int main(void){
    FILE *fd = fopen(OUTFILE, "w");

    if(!fd){
        fprintf(stderr, "Error opening %s", OUTFILE);
    }

    char phrase[] = "Hello";

    CharacterList* morseCodeHead = phraseToTranslate(phrase);

    while(morseCodeHead != NULL){
        char* code = morseCodeHead->morseCodeTranslation;
        fputs(code, fd);
        fputs(" / ", fd);
        morseCodeHead = morseCodeHead->next;
    }

    fclose(fd);
    freeMorseCodeList(morseCodeHead);
}

void test(){
    printf("Hello World!\n");
}