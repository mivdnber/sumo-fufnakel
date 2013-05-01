#include "util.h"

#include <dwengoBoard.h>

void activationSequence() {
    int started = FALSE, i;
    appendStringToLCD("(S)tart me");
    while (!started) {
        stopMotors();
        if (SW_S == PRESSED) {
            started = TRUE;
        } else {
            delay_ms(50);
        }
    }
    // 5 seconds waiting
    clearLCD();
    appendStringToLCD("Start counting");
    LEDS = 0;
    for (i = 0; i < 5; i++) {
        LEDS *= 2;
        LEDS += 1;
        delay_s(1);
    } // end of starting procedure
}