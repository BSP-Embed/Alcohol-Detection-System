//DEFINE MAIN HEADER FILE
#ifndef MAIN_H
#define MAIN_H

//INCLUDE DEFINITION OF HEADER FILE
#include "includes.h"


//DEFINE PORTS/PINS
#define SWITCH_PIN 			P1_7
#define ALCOHOL_SEN_PIN		P1_0
#define MOTOR_APIN			P0_2
#define MOTOR_CPIN			P0_3


//DEFINE CONSTANT
#define NOT_PRESSED			0
#define PRESSED				1


//DEFINE PROJECT TITLE
#define PROJECT_NAME	"ALCOHOL DET SYS"

//DEFINE MACROS
#define motor_on()				MOTOR_APIN = HIGH; MOTOR_CPIN = LOW
#define motor_off()				MOTOR_APIN = LOW; MOTOR_CPIN = LOW


#define ADCGetTemp(x)		((100 - (adc8get(x) * 0.39)) * 1.4)

#define starttmr()			TR0 = 1
#define stoptmr()			TR0 = 0

//FUNCTION PROTOTYPES
void 	init		(void);
void	tmr0_init	(void);
void 	disp_title	(void);
void 	alcohol_sens_init(void);

#endif

