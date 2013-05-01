#include <dwengoConfig.h>
#include <dwengoBoard.h>
#include <dwengoDelay.h>
#include <dwengoADC.h>
#include <dwengoMotor.h>

#include "groundsensors.h"
#include "cassette.h"
#include "print.h"
#include "util.h"
#include "motor.h"

const int AVOIDANCE_TIME = 300;
//#define SKIP_COUNTDOWN

void main(void) {
    int i = 0;
    // start of initializations: DO NOT EDIT
    PORTBbits.RB0 = 0;
    TRISBbits.RB0 = 0;
    initBoard();
    initADC();
    initMotor();
    cs_init();
    backlightOn();
    stopMotors();
    //cs_stop();
    delay_ms(10); // wait a bit after initialisation
    // end of initializations

    #ifndef SKIP_COUNTDOWN
    activationSequence();
    #endif /* SKIP_COUNTDOWN*/
    
    setMotorLeftSpeed(900);
    setMotorRightSpeed(900);
    delay_ms(400);
    while (TRUE) { // do forever
        int frontLeft, frontRight, ass, dist;
        frontLeft = gs_frontLeft();
        frontRight = gs_frontRight();
        ass = gs_ass();
        dist = gs_dist();

        printSensorInfo(frontLeft, frontRight, ass, dist);
        if(!frontLeft || !frontRight || !ass) {
            setMotorLeftSpeed(-500);
            setMotorRightSpeed(-500);

            if(!frontLeft && !frontRight) {
                printStringToLCD("both avoid", 1, 0);
                setMotorLeftSpeed(-800);
                setMotorRightSpeed(-800);
                delay_ms(AVOIDANCE_TIME);
                rotateLeft(180);
            } else if(!frontLeft) {
                printStringToLCD("left avoid", 1, 0);
                setMotorLeftSpeed(-900);
                setMotorRightSpeed(-450);
                delay_ms(AVOIDANCE_TIME);
                rotateLeft(120);
            } else if(!frontRight) {
                printStringToLCD("right avoid", 1, 0);
                setMotorLeftSpeed(-450);
                setMotorRightSpeed(-900);
                delay_ms(AVOIDANCE_TIME);
                rotateRight(120);
            } else if(!ass) {
                printStringToLCD("ass avoid", 1, 0);
                setMotorLeftSpeed(1023);
                setMotorRightSpeed(1023);
                delay_ms(600);
            }
        } else {
            search();
            destroy();
        }
        if(SW_W) {
            cs_play(1000);
        }

        delay_ms(25);
    }
}

