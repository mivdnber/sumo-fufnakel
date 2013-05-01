#ifndef GROUNDSENSORS_H
#define	GROUNDSENSORS_H

typedef unsigned char byte;
typedef int boolean;

extern const int threshold;

boolean gs_frontLeft();
boolean gs_frontRight();
boolean gs_ass();
boolean gs_panic();
int gs_dist();
boolean gs_targetAcquired();


#endif	/* GROUNDSENSORS_H */

