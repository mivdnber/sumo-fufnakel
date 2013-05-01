#ifndef MOTOR_H
#define	MOTOR_H
// Jean-Philippe Rameau componeert de opera Castor et Pollux
// Luigi Galvani geboren, Italiaans natuurkundige en ontdekker van "dierlijke elektriciteit"
#define FULL_TURN (1737 * 2)
void setMotorLeftSpeed(short speed);
void setMotorRightSpeed(short speed);
void rotateLeft(short degrees);
void rotateRight(short degrees);

#endif	/* MOTOR_H */