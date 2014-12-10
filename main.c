#include "reg932.h"
#include "uart.h"

#include "note_periods.h"

#define OSCFREQ 7372800

#define TICK_HIGH 0xfe
#define TICK_LOW 0x8f

// Tempo is beats per minute
// Note duration is specified in 32nd notes
unsigned char tempo;
unsigned int note_durr_factor;

sbit speaker = P1^7;

unsigned char* note_ptr;
unsigned char* durr_ptr;

unsigned char songSize = 0;
unsigned char currNote = 0;

unsigned int noteTime = 0;

bit looping = 0;
	
void timer1_tone(void) interrupt 3 using 3
{
	TH1 = notes[note_ptr[currNote]] >> 8;
	TL1 = notes[note_ptr[currNote]] & 0x00ff;
	speaker = ~speaker;
}
	
void timer0_durr(void) interrupt 1 using 3 
{
	if (noteTime > 0) // still playing the note, reset timer
	{
		TH0 = -(TICK_HIGH);
		TL0 = -(TICK_LOW);
		noteTime--;
	}
	else
	{
		if (currNote >= songSize)
		{
			currNote = 0;
			if (!looping)
			{
				TR1 = 0;
				TR0 = 0;
			}
		}
		else
		{
			currNote++;
		}
		
		TH0 = -(TICK_HIGH);
		TL0 = -(TICK_LOW);
		noteTime = note_durr_factor * durr_ptr[currNote];
		TH1 = notes[note_ptr[currNote]] >> 8;
		TL1 = notes[note_ptr[currNote]] & 0x00ff;
	}
}

void playSong(unsigned char* song, unsigned char* durr, unsigned char sizeOfSong, bit loop);

void main()
{
	tempo = 60;
	note_durr_factor  = (60*10000)/(32*tempo);
	
	uart_init();
	
	playSong(song1, durr1, song1Size, 1);
}

void playSong(unsigned char* song, unsigned char* durr, unsigned char sizeOfSong, bit loop)
{
	// Set up timer and interrupts
	TMOD = 0x11;
	IEN0 = IEN0 | 0x8A;
	looping = loop;
	currNote = 0;
	songSize = sizeOfSong;
	note_ptr = song;
	durr_ptr = durr;
	
	TH0 = -(TICK_HIGH);
	TL0 = -(TICK_LOW);
	noteTime = note_durr_factor * durr_ptr[currNote];
	TH1 = notes[note_ptr[currNote]] >> 8;
	TL1 = notes[note_ptr[currNote]] & 0x00ff;
	
	TR0 = 1;
	TR1 = 1;
}


