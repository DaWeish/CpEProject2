#include "reg932.h"
#include "uart.h"

#include "note_periods.h"

#define OSCFREQ 7372800

#define TICK_HIGH 0xfe
#define TICK_LOW 0x8f //These are calculated to give a 0.0001s period for the timer

//DEFINE all buttons(labeled top left horizantally to buttom right)
#define BUTTON1 P2^0
#define BUTTON2 P0^1
#define BUTTON3 P2^3
#define BUTTON4 P0^2
#define BUTTON5 P1^4
#define BUTTON6 P0^0
#define BUTTON7 P2^1
#define BUTTON8 P0^3
#define BUTTON9 P2^2

// Tempo is beats per minute
// Note duration is specified in 32nd notes
unsigned int tempo;
unsigned int note_durr_factor;
unsigned int noteTime;

sbit speaker = P1^7;

bit looping = 0;

unsigned char* note_ptr;
unsigned char* durr_ptr;

unsigned char songSize;
unsigned char currNote;

unsigned char mode = 0;
	
void timer1_tone(void) interrupt 3 using 3
{
	TH1 = notes[note_ptr[currNote]] >> 8;
	TL1 = notes[note_ptr[currNote]] & 0x00ff;
	speaker = ~speaker;

}
	
void timer0_durr(void) interrupt 1 using 3 
{
	TR1 = 0; // stop timers while function runs
	TR0 = 0;
	
	if (noteTime > 0) // still playing the note, reset timer
	{
		TH0 = TICK_HIGH;
		TL0 = TICK_LOW;
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
		
		TH0 = TICK_HIGH;
		TL0 = TICK_LOW;
		noteTime = note_durr_factor * durr_ptr[currNote];
		TH1 = notes[note_ptr[currNote]] >> 8;
		TL1 = notes[note_ptr[currNote]] & 0x00ff;
	}
	
	TR0 = 1;
	TR1 = 1;
}

void stopSong(); // stops both timers
void playSong(unsigned char* song, unsigned char* durr, unsigned char sizeOfSong);

void keyboardMode(void)
{
		if(BUTTON1 == 0)
		{
			playSong(key1,keyboardQuarter, keySize);//plays C4
		}
		if(BUTTON2 == 0)
		{
			playSong(key2,keyboardQuarter, keySize);//plays C4
		}
		if(BUTTON3 == 0)
		{
			playSong(key3,keyboardQuarter, keySize);//plays C4
		}
		if(BUTTON4 == 0)
		{
			playSong(key4,keyboardQuarter, keySize);//plays C4
		}
		if(BUTTON5 == 0)
		{
			playSong(key5,keyboardQuarter, keySize);//plays C4
		}
		if(BUTTON6 == 0)
		{
			playSong(key6,keyboardQuarter, keySize);//plays C4
		}
}
sbit light = P0^6;

void main()
{
	P0M1 = 0x00;
	P0M2 = 0x00;
	P1M1 = 0x00;
	P1M2 = 0x00;
	looping = 1;
	
	light = 0;
	
	tempo = 60;
	note_durr_factor  = 60*((10000/tempo)/32); //312
	
//	uart_init();
	  
	playSong(song1, durr1, song1Size);

	while (1)
	{
		
	}


/*	switch(mode)
	{
		case 0:
		
			while(1)
			{
					//playSong();
				
				if (BUTTON7 == 0)//get out if the mode button is pressed
				{
					mode++;
					break;
				}
			}
		
			break;
		
		
		case 1:
		{
			while(1)
			{
					//playSong();
				
				if (BUTTON7 == 0)//get out if the mode button is pressed
				{
					mode++;
					break;
				}
			}
		}
		case 2:
		{
			while(1)
			{
					keyboardMode();
				
				if (BUTTON7 == 0)//get out if the mode button is pressed
				{
					mode++;
					break;
				}
			}
		}
			
		default:
			mode = 0;
	}
*/
	
}

void playSong(unsigned char* song, unsigned char* durr, unsigned char sizeOfSong)
{
	// Set up timer and interrupts
	TMOD = 0x11;
	IEN0 = IEN0 | 0x8A;
	currNote = 0;
	songSize = sizeOfSong;
	note_ptr = song;
	durr_ptr = durr;
	
	TH0 = TICK_HIGH;
	TL0 = TICK_LOW;
	noteTime = note_durr_factor * durr_ptr[currNote];
	TH1 = notes[note_ptr[currNote]] >> 8;
	TL1 = notes[note_ptr[currNote]] & 0x00ff;
	
	TR0 = 1;
	TR1 = 1;
}

void stopSong()
{
	TR0 = 0;
	TR1 = 0;
}
