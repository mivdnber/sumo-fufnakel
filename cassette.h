#ifndef CASSETTE_H
#define	CASSETTE_H

#define START PORTBbits.RB0
#define START_DIR TRISBbits.RB0
#define STOP  PORTBbits.RB1
#define STOP_DIR TRISBbits.RB1

#define STOPPED     0
#define PLAYING     1
#define BACKWARDS   2

#define SETUP_DELAY      1000
#define SCREAM_DURATION  5000

typedef int cassette_state;

void cs_init();
void cs_play(int ms);
void cs_stop();
cassette_state cs_state();
#endif	/* CASSETTE_H */

