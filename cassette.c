#include "cassette.h"
#include "dwengoBoard.h"

cassette_state CASSETTE_STATE = STOPPED;

void cs_init() {
    START_DIR = 0;
    /* STOP_DIR = 0;*/
    START = 0;
    /*STOP = 0;*/
    CASSETTE_STATE = STOPPED;
}

void cs_play(int ms) {
    if(CASSETTE_STATE == STOPPED) {
        START = 1;
        delay_ms(1000);
        START = 0;
    }
    CASSETTE_STATE = PLAYING;
}

void cs_stop() {
    STOP = 1;
    delay_ms(1000);
    STOP = 0;
    CASSETTE_STATE = STOPPED;
}

cassette_state cs_state() {
    return CASSETTE_STATE;
}