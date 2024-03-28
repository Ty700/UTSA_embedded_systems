#include "cv1800b.h"
#include "devmem.h"
#include "blink_led.h"

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

extern void blink_led(uint8_t* code){
    /* 
        Will do the following:
            Go through each morse code character
            switch(chraracter)
                if dit
                    preform dit light up logic
                if dot
                    preform dot light up logic
                if /
                    preform space light up logic

            Will have an IRQ for new phrases
                if new phrase, rerun morse code translation
                return here to preform blink logic
                (this will probably in main though not sure yet)
    */

#ifdef MORSE_DEBUG
    fprintf(stdout, "Blink_led recieved: ");
    uint32_t codeLength = 0;
    while(code[codeLength] != '\0'){
        printf("%c", code[codeLength]);
        codeLength += 1;
    }
    printf("\n");
#endif

}