#include "reg932.h"
#include "uart.h"

#include "note_periods.h"

#define OSCFREQ 7372800

// Tempo is beats per minute
#define TEMPO 60
#define NOTE_DUR_FACTOR ((((60/TEMPO)/16)/177)*10000) 

sbit speaker = P1^7;

unsigned char* note_ptr;
unsigned char* durr_ptr;

unsigned char songSize = 0;
unsigned char currNote = 0;

unsigned int noteTime = 0;
unsigned 

void timer1_tone(void) interrupt 3 using 3;

void main()
{
	// Test playing a few note song
}

void timer1_tone(void) interrupt 3 using 3
{
	
}

void timer0_durr(void) interrupt 1 using 3 // need to plan out better
{
	
}