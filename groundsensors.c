#include "groundsensors.h"

const int threshold = 500;

/* Returns true when ground is black. Racist bastard! */
boolean gs_frontLeft() {
    return readADC(1) > threshold;
}

boolean gs_frontRight() {
    return readADC(0) > threshold;
}

boolean gs_ass() {
    return readADC(2) > threshold;
}

int gs_dist() {
    return readADC(3);
}

/* SHUT - DOWN - EVERYTHING!! */
boolean gs_panic() {
    return !(gs_frontLeft() && gs_frontRight() && gs_ass());
}