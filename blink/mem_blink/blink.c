#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#include "devmem.h"
#include "cv1800b.h"

#define LOW 0
#define HIGH 1 << 24

void set_gpio_mode()
{
    // set gpio to output mode
    reg32_t *swporta_ddr_value = &GPIO2->SWPORTA_DDR;
    uint32_t val = dev_mem_read((unsigned long)swporta_ddr_value);
    printf("Intializing gpio: current val %u\n", val);

    val |= 1 << 24;
    printf("Intializing gpio: updated val %u\n", val);
    dev_mem_write((unsigned long)swporta_ddr_value, val);
}

void free_resources()
{
    // reset led
    reg32_t *swporta_dr_value = &GPIO2->SWPORTA_DR;
    dev_mem_write((unsigned long)swporta_dr_value, LOW);

    // reset gpio to input mode
    reg32_t *swporta_ddr_value = &GPIO2->SWPORTA_DDR;
    uint32_t val = dev_mem_read((unsigned long)swporta_ddr_value);
    printf("Reset gpio: current val %u\n", val);

    val &= ~(1 << 24);
    printf("Reset gpio: update val %u\n", val);
    dev_mem_write((unsigned long)swporta_ddr_value, val);
}

void handle_sigint(int sig)
{
    printf("Caught signal now %d\n", sig);
    free_resources();

    exit(0);
}

int main()
{
    signal(SIGINT, handle_sigint);

    set_gpio_mode();

    reg32_t *swporta_dr_value = &GPIO2->SWPORTA_DR;
    while (1)
    {
        printf("setting high: %u\n", HIGH);
        dev_mem_write((unsigned long)swporta_dr_value, HIGH);
        sleep(1);

        printf("setting low: %u\n", LOW);
        dev_mem_write((unsigned long)swporta_dr_value, LOW);
        sleep(1);
    }
}