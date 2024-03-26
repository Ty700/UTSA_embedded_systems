#include <stdio.h>
#include <stdint.h>

/*
* FUNCTION:
*   Determines if a character is in the English alphabet or a number 0-9
*
* INPUT:
*   A character... dyh
*
* RETURNS:
*   1: Character is in the alphabet | a number
*   0: Character is NOT in the alphabet | a number
*/

uint32_t isAlphaNumberic(uint8_t c){
    //ASCII stuff, "It just works" - Todd Howard
    if( (c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z') ||
        (c >= '0' && c <= '9')) 
        {
            return 1;
        }

        return 0;
}

/*
* FUNCTION:
*   To avoid importing an entire lib for tolower, I have made this.
*   Simply alters a character to be lowercase
* 
* INPUTS:
*   A character
*       - an alphabetical character
*       - HAS BEEN CHECKED ALREADY
*
* RETURNS:
*   VOID => Alters character in place to avoid passing by copy
*/

void toLowercase(uint8_t* c){
    //Check if upper
    if(*c >= 'A' && *c <= 'Z'){
        *c += 32;
    }
}

/*
* FUNCTION: 
*   calculates an index representing the position of a character's Morse code in an array
*
* INPUTS:
*   Can you guess? That's right! A frog!
*   THIS FROG CAN NOT BE CHANGED
*   FROG HAS BEEN CHECKED AND IS A VALID FROG. 
*   It's name is most likely kermit.
*
* RETURNS:
*   50 => Hashing error
*   An int between 0 and 36 that corresponds with the character's morse code index in the array.
*/
uint8_t characterToIndexHash(const char* c){
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
        return 50;
    }
}


/*
* FUNCTION: 
*    Translates a character (usually passed by a helper function) to morse code
* 
* INPUTS:
*    A character... any character.  
*
* RETURNS:
*    NULL               => Non-valid characters | Hashing Error
*                           -stderr will tell user which it is
*
*    Non-empty string   => For when character passed is a valid character
*/

const uint8_t* charToTranslate(char c){

    static const uint8_t* morseCode[36] = {
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
    if(!isAlphaNumberic(c)){
        fprintf(stderr, "Character is not alphabetical nor a number 0-9.\n");
        return NULL;
    }

#ifdef DEBUG
    printf("Before: %c\n", c);
#endif/*DEBUG*/

    //Converts the character to lowercase
    toLowercase(&c);

#ifdef DEBUG
    printf("After: %c\n", c);
#endif /*DEBUG*/

    uint8_t characterIndex = characterToIndexHash(&c);
    
#ifdef DEBUG
    printf("%c index in morseCode: %d", c, characterIndex);
#endif /*DEBUG*/

    //Error check
    if(characterIndex == 50){
        fprintf(stderr, "Error hashing character.\n");
        return NULL; //<= So the compiler will shut up
    }

    return morseCode[characterIndex];
}

int main(){
    char testChars[] = {'A', 'B', 'C', '0', '`', 'T'};

    for(int i = 0; i < 6; i++){
        printf("Character: %c => %s\n", testChars[i], charToTranslate(testChars[i]));
    }
}