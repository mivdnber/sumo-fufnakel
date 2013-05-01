#include "print.h"
#include "groundsensors.h"

void printSensorInfo(int left, int right, int ass, int dist) {
    clearLCD();
    appendIntToLCD(left);
    appendStringToLCD(" ");
    appendIntToLCD(right);
    appendStringToLCD(" ");
    appendIntToLCD(ass);
    appendStringToLCD(" ");
    appendIntToLCD(dist);
}

void readAndPrint() {
    printSensorInfo(gs_frontLeft(), gs_frontRight(), gs_ass(), gs_dist());
}