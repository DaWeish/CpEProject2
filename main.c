#include "reg932.h"
#include "uart.h"
#include "uart.c"
#include "note_periods.h"

#define TRUE 1
#define FALSE 0

#define TICK_HIGH 0xfe
#define TICK_LOW 0x8f //These are calculated to give a 0.0001s period for the timer

//DEFINE all buttons(labeled top left horizantally to buttom right)
sbit BUTTON1 = P2^0;
sbit BUTTON2 = P0^1;
sbit BUTTON3 = P2^3;
sbit BUTTON4 = P0^2;
sbit BUTTON5 = P1^4;
sbit BUTTON6 = P0^0;
sbit BUTTON7 = P2^1;
sbit BUTTON8 = P0^3;
sbit BUTTON9 = P2^2;

// Tempo is beats per minute
// Note duration is specified in 32nd notes
unsigned int tempo;
unsigned int note_durr_factor;
unsigned int noteTime;

sbit speaker = P1^7;

bit looping = 0x21;
bit playing = 0x22;

unsigned char* note_ptr;
unsigned char* durr_ptr;

unsigned char songSize;
unsigned char currNote;

unsigned char mode;
	
void timer1_tone(void) interrupt 3 using 3
{
	TH1 = notes[note_ptr[currNote]] >> 8;
	TL1 = notes[note_ptr[currNote]] & 0x00ff;
	speaker = ~speaker;

	return;
}
	
void timer0_durr(void) interrupt 1 using 3 
{	

	if (noteTime > 0) // still playing the note, reset timer
	{
		TH0 = TICK_HIGH;
		TL0 = TICK_LOW;
		noteTime--;
	}
	else
	{
		currNote++;
		
		if (currNote >= songSize)
		{
			currNote = 0;
			if (looping == FALSE)
			{
				TR1 = 0;
				TR0 = 0;
				playing = FALSE;
			}
		}
		
		TH0 = TICK_HIGH;
		TL0 = TICK_LOW;
		noteTime = note_durr_factor * durr_ptr[currNote];
		TH1 = notes[note_ptr[currNote]] >> 8;
		TL1 = notes[note_ptr[currNote]] & 0x00ff;
		
		if (notes[note_ptr[currNote]] == 0)
		{
			TR1 = 0;
		}
		else
		{
			TR1 = 1;
		}
	}

	return;
}

void stopSong(); // stops both timers
void playSong(unsigned char* song, unsigned char* durr, unsigned char sizeOfSong, bit loop);
void keyboardMode(void);
void delay(unsigned int count);
void transmitText(unsigned char* text, unsigned char size);
void updateTempo(); // call after changing tempo

void main()
{
	P0M1 = 0x00;
	P0M2 = 0x00;
	P1M1 = 0x00;
	P1M2 = 0x00;
	P2M1 = 0x00;
	P2M2 = 0x00;
	
	mode = 0;
	
	tempo = 60;
	updateTempo();

	//initialize UART
	uart_init();
	EA = 1;

	while (1) {
	switch(mode)
	{
		case 0:
			playSong(song1, durr1, song1Size, TRUE);
			transmitText(song1Name, song1NameSize);
		
			while(1)
			{
				if (BUTTON7 == 0)//get out if the mode button is pressed
				{
				  delay(100);
					while (BUTTON7 == 0);
					mode++;
					stopSong(); // Call to stop song since looping is True
					break;
				}
			}
		
			break;
		
		case 1:
		{
			playSong(key1, quarter, keySize, FALSE);

			while(1)
			{
				if (BUTTON7 == 0)//get out if the mode button is pressed
				{
					delay(100);
					while (BUTTON7 == 0);
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
					delay(100);
					while (BUTTON7 == 0);
					mode++;
					stopSong();
					break;
				}
			}
		}
		
		case 3: //metronome mode
			{
			playSong(key1, quarter, keySize, TRUE);
			while(1)
			{	
				if (BUTTON8 == 0)//slower metronome
				{
					tempo -= 5; 
					updateTempo();
				}
				if (BUTTON9 == 0)// faster metronome
				{
					tempo += 5;
					updateTempo();
				}
				if (BUTTON7 == 0)//get out if the mode button is pressed
				{
					delay(100);
					while (BUTTON7 == 0);
					mode++;
					stopSong();
					break;
				}
			}
		}
			
		default:
			mode = 0;
	}
	}

}

void playSong(unsigned char* song, unsigned char* durr, unsigned char sizeOfSong, bit loop)
{
	looping = loop;
	// Set up timers and interrupts
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
//TR1 = 1;
	
	if (notes[note_ptr[currNote]] == 0)
	{
		TR1 = 0;
	}
	else
	{
		TR1 = 1;
	}
}

void updateTempo()
{
	note_durr_factor  = 60*((10000/tempo)/32); //312 for 60 bpm
}

void stopSong()
{
	TR0 = 0;
	TR1 = 0;
}

void delay(unsigned int count)
{
  unsigned int i;
  for (i = 0; i < 100*count; i++);
}

void keyboardMode(void)
{
	if(BUTTON1 == 0)
	{
		delay(100);
		while (BUTTON1 == 0);
		playSong(key1,quarter, keySize, FALSE);//plays C4
	}
	if(BUTTON2 == 0)
	{
		delay(100);
		while (BUTTON2 == 0);
		playSong(key2,quarter, keySize, FALSE);//plays C4
	}
	if(BUTTON3 == 0)
	{
		delay(100);
		while (BUTTON3 == 0);
		playSong(key3,quarter, keySize, FALSE);//plays C4
	}
	if(BUTTON4 == 0)
	{
		delay(100);
		while (BUTTON4 == 0);
		playSong(key4,quarter, keySize, FALSE);//plays C4
	}
	if(BUTTON5 == 0)
	{
		delay(100);
		while (BUTTON5 == 0);
		playSong(key5,quarter, keySize, FALSE);//plays C4
	}
	if(BUTTON6 == 0)
	{
		delay(100);
		while (BUTTON6 == 0);
		playSong(key6,quarter, keySize, FALSE);//plays C4
	}
}

void transmitText(unsigned char* text, unsigned char size)
{
	unsigned char i;
	for (i = 0; i < size; i++)
	{
		uart_transmit(text[i]);
	}
}
