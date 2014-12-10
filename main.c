#include "reg932.h"
#include "uart.h"

#include "note_periods.h"

#define OSCFREQ 7372800


// Tempo is beats per minute
#define TEMPO 60
#define NOTE_DUR_FACTOR ((((60/TEMPO)/16)/177)*10000) 


//DEFINE all buttons(labeled top left horizantally to buttom right)
sbit B1 P2^0;
sbit B2 P0^1;
sbit B3 P2^3;
sbit B4 P0^2;
sbit B5 P1^4;
sbit B6 P0^0;
sbit B7 P2^1;
sbit B8 P0^3;
sbit B9 P2^2;

sbit speaker = P1^7;

unsigned char* note_ptr;
unsigned char* durr_ptr;

unsigned char songSize = 0;
unsigned char currNote = 0;

unsigned int noteTime = 0;

unsigned char mode = 0;

void ModeInterupt(void) interupt 1;

void timer1_tone(void) interrupt 3 using 3;

void main()
{
	TMOD = 0x11;//pretty sure this isnt right

	switch(mode)
	{
		case 0:
			for(;;)
			{
				playSong1();
				
				if(B7)
				{//get out if the mode button is pressed
					mode++;
					B7 = 0; //clear the button
					break;
				}
			}
			break;
			
			case 1:
				for(;;)
				{
					playSong2();
					
					if(B7)
					{//get out if the mode button is pressed
						mode++;
						B7 = 0; //clear the button
						break;
					}
				}
			
			case 2:
				for(;;)
				{
					playSong3();
					
					if(B7)
					{//get out if the mode button is pressed
						mode++;
						B7 = 0; //clear the button
						break;
					}
				}
			default:
				mode = 0;
		}
	
	
	}

	return;
}



void timer1_tone(void) interrupt 3 using 3
{
	
}

void timer0_durr(void) interrupt 1 using 3 // need to plan out better
{
	
}