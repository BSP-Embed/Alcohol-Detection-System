/* main application program : Measure body temperature and heart beat */
#include"main.h"
 
extern int8u lcdptr;
 
void main(void)
{
	bit switch_state = NOT_PRESSED;

	init();

	do {
		if (SWITCH_PIN == LOW) {
			dlyms(20);
			if (SWITCH_PIN == LOW) 
				switch_state = PRESSED;
		}
	} while (switch_state == NOT_PRESSED);

	motor_on();
	beep(1,150);

	while (ALCOHOL_SEN_PIN == HIGH);

	motor_off();
	lcdr2();
	lcdws("    DETECTED");
	
	for(;;)	 {
		beep(2,150);
		dlyms(2500);
	}

}
static void disp_title(void)
{
	lcdclr();
	lcdws(PROJECT_NAME);
}
static void init(void)
{
	beep(2,75);
	tmr0_init();
	lcdinit();
	alcohol_sens_init();
	disp_title();
	starttmr();
}
static void tmr0_init(void)
{
	TMOD = TMOD & 0xf0 | 0x01;		/* TMR0 in mode1*/
	TH0 = 0x4B;
	TL0 = 0xFD;
	EA = ET0 = 1;
} 
static void tmr0ISR() interrupt 1 using 2
{
	static int8u i,j;

	TH0 = 0x4B;
	TL0 = 0xFD;
		
	if (++i >= 2) {
		i = 0;
		if (++j >= 50) j = 0;
		switch(j) {
			case 0: case 2: ledon();  break;
			case 1: case 3: ledoff(); break;
		}
	}
} 

void alcohol_sens_init(void)
{
	lcdclrr(1);
	lcdws("Alcohol Sens:");

	while (ALCOHOL_SEN_PIN == LOW);

	lcdws("OK");

	dlyms(500);
}
