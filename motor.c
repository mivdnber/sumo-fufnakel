#include "motor.h"

#include <dwengoMotor.h>

#define MAX_SPEED_DIFF (400);

int targetSpeedLeft = 0;
int targetSpeedRight = 0;

int speedLeft = 0;
int speedRight = 0;

void setMotorLeftSpeed(short speed) {
    setSpeedMotor1(-speed);
}

void setMotorRightSpeed(short speed) {
    setSpeedMotor2(-speed);
}

void rotateLeft(short degrees) {
    setMotorRightSpeed(500);
    setMotorLeftSpeed(-500);
    delay_ms((int) FULL_TURN / 360 * degrees);
    //stopMotors();
}

void rotateRight(short degrees) {
    setMotorRightSpeed(-500);
    setMotorLeftSpeed(500);
    delay_ms((int) FULL_TURN  / 360 * degrees);
    //stopMotors();
}