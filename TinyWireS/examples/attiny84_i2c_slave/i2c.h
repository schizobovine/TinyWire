/*
 * i2c.h - Routines for handling i2c boilerplate.
 */

// Current register values
//volatile uint8_t *i2c_regs;

// Register mem block size
//const byte reg_size = sizeof(i2c_regs);

// Tracks the current register pointer position
//volatile byte reg_position;

/**
 * This is called for each read request we receive, never put more than one
 * byte of data (with TinyWireS.send) to the send-buffer when using this
 * callback.
 */
void requestEvent();

/**
 * The I2C data received handler
 *
 * This needs to complete before the next incoming transaction (start, data,
 * restart/stop) on the bus does so be quick, set flags for long running tasks
 * to be called from the mainloop instead of running them directly.
 */
void receiveEvent(uint8_t howMany);

// vi: syntax=arduino
