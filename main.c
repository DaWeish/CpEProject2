#include "reg932.h"
#include "uart.h"

#define OSCFREQ 7372800

sbit speaker = P1^7;

void timer1_tone(void) interrupt 3 using 3;

void main()
{
	// Test playing a few note song
}

void timer1_tone(void) interrupt 3 using 3
{
	TH1 = -((*note_ptr) >> 8);
	TL1 = -((*note_ptr) & 0x00ff);
	speaker = ~speaker;
}

void timer0_durr(void) interrupt 1 using 3 // need to plan out better
{
	if (timeLeft)
		timeLeft -= 1;

	else
	{
		currNote += 1;
		if (currNote >= songSize)
			currNote = 0;
		
		
		
	}
}