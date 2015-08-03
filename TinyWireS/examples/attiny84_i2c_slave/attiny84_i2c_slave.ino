/**
 * attiny84_i2c_slave.ino - Example sketch for writing to and reading from a
 * slave in transactional manner
 */

#include <TinyWireS.h>
#include "i2c.cpp"

// 7-bit I2C address (change this when adapting this example)
#define I2C_SLAVE_ADDRESS 0x4

void setup() {

    /**
     * Setup callback for when requests come in
     */
    TinyWireS.begin(I2C_SLAVE_ADDRESS);
    TinyWireS.onReceive(receiveEvent);
    TinyWireS.onRequest(requestEvent);

}

void loop() {
    /**
     * This is the only way we can detect stop condition. It needs to be called
     * in a very tight loop in order not to miss any (REMINDER: Do *not* use
     * delay() anywhere, use tws_delay() instead). It will call the function
     * registered via TinyWireS.onReceive(); if there is data in the buffer on
     * stop.
     *
     * For more info:
     *
     * http://www.avrfreaks.net/index.php?name=PNphpBB2&file=viewtopic&p=984716&sid=82e9dc7299a8243b86cf7969dd41b5b5#984716)
     *
     */
    TinyWireS_stop_check();
}

// vi: syntax=arduino
