#include "cv1800b.h"
#include "devmem.h"
#include "blink_led.h"
#include "translate_to_morse.h"

#include <stdint.h>
#include <stdio.h>

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#define LOW (0)
#define HIGH (1 << 24)

void set_gpio_mode()
{
    /* Sets SWPORTA to output */
    volatile unsigned* swporta_ddr_value = &GPIO2->SWPORTA_DDR;

    //Reads current value in reg
    uint32_t val = dev_mem_read((unsigned long)swporta_ddr_value);

    debug("Intializing gpio: current val %u\n", val);

    /*Sets 24th bit to high*/
    val |= (HIGH);
    debug("Intializing gpio: updated val %u\n", val);

    //Write new value into reg
    dev_mem_write((unsigned long)swporta_ddr_value, val);
}

void free_resources()
{
    /* Powers off LED when exe is stopped */
    volatile unsigned* swporta_dr_value = &GPIO2->SWPORTA_DR;
    dev_mem_write((unsigned long)swporta_dr_value, LOW);

    /* Resets GPIO to default input mode */
    volatile unsigned* const swporta_ddr_value = &GPIO2->SWPORTA_DDR;

    /* Current_mode = current value in SWPORTA_DDR reg */
    uint32_t current_mode = dev_mem_read((unsigned long)swporta_ddr_value);

    /* Need to reset high bit */
    current_mode &= ~(HIGH);
    
    debug("Reset gpio: update val %u\n", current_mode);

    /* Write mode back into register */
    dev_mem_write((unsigned long)swporta_ddr_value, current_mode);
}

void handle_sigint(int sig)
{
    debug("Interupt caught: %d\n", sig);
    free_resources();

    exit(0);
}

/*
* blink_led() -> Translates a phrase to morse code
* 
* @INPUTS:
*    - Morse Code char array
*
* @RETURNS:
*    uint32_t => For Unit Testing
*
*
*   TODO: ADD IRQ FOR NEW ENGLISH PHRASE???
*/

extern uint32_t blink_led(uint8_t* code){
#ifdef MORSE_DEBUG
    fprintf(stdout, "Blink_led recieved: ");
    uint32_t codeLength = 0;
    while(code[codeLength] != '\0'){
        printf("%c", code[codeLength]);
        codeLength += 1;
    }
    printf("\n");
#endif

    uint32_t time_unit_count = 0;

    while(*code != '\0'){
        
        switch(*code){
            
            case('.'):
                //blink logic
                debug("ON: 1 Time Unit\n");
                time_unit_count += 1;
                
                if(*(code + 1) == ' ' || *(code + 1) == '\0'){
                    break;
                }

                debug("OFF: 1 Time Unit\n");
                time_unit_count += 1;
                break;

            case('-'):
                debug("ON: 3 Time Unit\n");
                time_unit_count += 3;
                
                if(*(code + 1) == ' ' || *(code + 1) == '\0'){
                    break;
                }
                
                debug("OFF: 1 Time Unit\n");
                time_unit_count += 1;
                break;

            case('/'):
                if(*(code + 1) == '\0'){
                    break;
                }
                debug("WORD SPACE: 7 Time Unit\n");
                time_unit_count += 7;
                break;

            case(' '):
                if(*(code + 1) == '/' || *(code - 1) == '/' || *(code + 1) == '\0'){
                    break;
                }
                debug("LETTER SPACE: 3 Time Unit\n");
                time_unit_count += 3;
                break;

            default:
                break;
        }
        code++;
    }
    printf("Total Time Units: %d\n", time_unit_count);
}