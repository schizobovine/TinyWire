/*
 * i2c.cpp - Routines for handling i2c boilerplate.
 */

#include <TinyWireS.h>
#include "i2c.h"

// Initial/current register values
volatile uint8_t i2c_regs[] = {
    0xDE, 
    0xAD, 
    0xBE, 
    0xEF, 
};

// Register mem block size
const uint8_t reg_size = sizeof(i2c_regs);

// Tracks the current register pointer position
volatile uint8_t reg_position;

/**
 * This is called for each read request we receive, never put more than one
 * byte of data (with TinyWireS.send) to the send-buffer when using this
 * callback.
 */
void requestEvent() {  

    TinyWireS.send(i2c_regs[reg_position]);

    // Increment the reg position on each read, and loop back to zero
    reg_position++;
    if (reg_position >= reg_size) {
        reg_position = 0;
    }

}

/**
 * The I2C data received handler
 *
 * This needs to complete before the next incoming transaction (start, data,
 * restart/stop) on the bus does so be quick, set flags for long running tasks
 * to be called from the mainloop instead of running them directly.
 */
void receiveEvent(uint8_t howMany) {

    // Sanity-checks
    if (howMany < 1 || howMany > reg_size) {
        return;
    }

    // Get register position to read/write to
    reg_position = TinyWireS.receive();
    howMany--;

    // This write was only to set the buffer for next read
    if (howMany == 0) {
        return;
    }

    // If more bytes remaining, write with wrapping
    while(howMany > 0) {
        i2c_regs[reg_position] = TinyWireS.receive();
        reg_position++;
        if (reg_position >= reg_size) {
            reg_position = 0;
        }
    }

}

// vi: syntax=arduino
