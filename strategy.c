#include "strategy.h"
#include "groundsensors.h"
#include "motor.h"
#include "print.h"
#include "cassette.h"

const int targetThreshold = 95;
const int DIE_MOTHERFUCKER = 630;

boolean ramming = 0;

boolean targetAcquired() {
    return gs_dist() > targetThreshold;
}


void search(int dist) {
    int range = 15, inc;
    clearLCD();
    readAndPrint();
    printStringToLCD("search", 1, 0);
    while(!targetAcquired()) {
        readAndPrint();
        range += 15;
        for(inc = 5; inc <= range; inc += 5) {
            rotateLeft(inc);
            if(gs_panic() || targetAcquired()) {
                return;
            }
        }
        readAndPrint();
        if(!targetAcquired()) {
            range += 15;
            for(inc = 5; inc <= range; inc += 5) {
                rotateRight(inc);
                if(gs_panic() || targetAcquired()) {
                    return;
                }
            }
        }
    }
}

void destroy(int dist) {
    clearLCD();
    readAndPrint();
    printStringToLCD("destroy", 1, 0);
    while(targetAcquired() && !gs_panic()) {
        cs_play(0);
        readAndPrint();
        printStringToLCD("destroy", 1, 0);
        dist = gs_dist();
        setMotorLeftSpeed(900);
        setMotorRightSpeed(900);
        if(ramming || dist > DIE_MOTHERFUCKER) {
            printStringToLCD("DIE! DIE! DIE!", 1, 0);
            ramming = 1;
            setMotorLeftSpeed(1023);
            setMotorRightSpeed(1023);
        }
        delay_ms(25);
    }
    ramming = 0;
}