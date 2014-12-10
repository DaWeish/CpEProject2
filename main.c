#include "reg932.h"
#include "uart.h"

#include "note_periods.h"

#define OSCFREQ 7372800

#define TICK_HIGH 0xfe
#define TICK_LOW 0x8f

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
unsigned char tempo;
unsigned int note_durr_factor;

sbit speaker = P1^7;


unsigned char* note_ptr;
unsigned char* durr_ptr;

unsigned char songSize = 0;
unsigned char currNote = 0;

unsigned int noteTime = 0;

unsigned char mode = 0;

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
	light = 0;
	tempo = 60;
	note_durr_factor  = (60*10000)/(32*tempo);

	
//	uart_init();
	
	switch(mode)
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
	
	TH0 = -(TICK_HIGH);
	TL0 = -(TICK_LOW);
	noteTime = note_durr_factor * durr_ptr[currNote];
	TH1 = notes[note_ptr[currNote]] >> 8;
	TL1 = notes[note_ptr[currNote]] & 0x00ff;
	
	TR0 = 1;
	TR1 = 1;
}


