#include "reg932.h"
#include "uart.h"
#include "uart.c"
#include "note_periods.h"

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

unsigned char ourNames[] = {"Connor, James, Jake"};

sbit LED1 = P2^4;
sbit LED2 = P0^5;
sbit LED3 = P2^7;
sbit LED4 = P0^6;
sbit LED5 = P1^6;

// Tempo is beats per minute
// Note duration is specified in 32nd notes
unsigned int tempo;
unsigned int note_durr_factor;
unsigned int noteTime;

sbit speaker = P1^7;
sbit speaker2 = P0^4;

unsigned char looping;
unsigned char playing;

unsigned char* note_ptr;
unsigned char* durr_ptr;

unsigned char songSize;
unsigned char currNote;

unsigned char noteHigh;
unsigned char noteLow;

unsigned char mode;
	
unsigned char TRUE = 1;
unsigned char FALSE = 0;

unsigned char currFreq;

void timer1_tone(void) interrupt 3 using 3
{
	TH1 = noteHigh;
	TL1 = noteLow;
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
				playing = FALSE;
			}
		}
		
		TH0 = TICK_HIGH;
		TL0 = TICK_LOW;
		noteTime = note_durr_factor * durr_ptr[currNote];
		noteHigh = notes[note_ptr[currNote]] >> 8;
		noteLow = notes[note_ptr[currNote]] & 0x00ff;
		TH1 = noteHigh;
		TL1 = noteLow;
		
		if (notes[note_ptr[currNote]] == 0)
		{
			TR1 = 0;
		}
		else
		{
			TR1 = 1;
		}

		if (playing == FALSE)
		{
			TR1 = 0;
			TR0 = 0;
		}
	}

	return;
}

void stopSong(); // stops both timers
void playSong(unsigned char* song, unsigned char* durr, unsigned char sizeOfSong, unsigned char loop);
void keyboardMode(void);
void transmitText(unsigned char* text, unsigned char size);
void delay(unsigned int count);


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
	EX0 = 1;
	TCON = TCON | 0x01;

	while (1) {
	switch(mode)
	{
		case 0:
			tempo = 120;
			updateTempo();
			playSong(songDragonforce, durrDragonforce, songDragonSize, TRUE);
			transmitText(songNameDragon, songNameDragonSize);
			LED1 = 0;
			LED2 = 1;
			LED3 = 1;
			LED4 = 1;
			LED5 = 1;
		
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
			tempo = 120;
			updateTempo();

			playSong(songYPC, durrYPC, songYPCSize, TRUE);
			transmitText(songNameYPC, songNameYPCSize);

			LED1 = 1;
			LED2 = 0;
			LED3 = 1;
			LED4 = 1;
			LED5 = 1;

			while(1)
			{
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
		case 2:
		{
			transmitText(keyboardName, keyboardNameSize);
			while(1)
			{	
				keyboardMode();
				LED1 = 1;
				LED2 = 1;
				LED3 = 0;
				LED4 = 1;

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
			tempo = 60;
			updateTempo();
			playSong(metroTone, metDurr, metSize, TRUE);
			transmitText(metName, metNameSize);
			LED1 = 1;
			LED2 = 1;
			LED3 = 1;
			LED4 = 0;
			LED5 = 1;
			while(1)
			{	
				if (BUTTON8 == 0)//slower metronome
				{
					delay(100);
					while (BUTTON8 == 0);
					stopSong();
					tempo -= 5; 
					updateTempo();
					playSong(metroTone, metDurr, metSize, TRUE);
				}
				if (BUTTON9 == 0)// faster metronome
				{
					delay(100);
					while (BUTTON9 == 0);
					stopSong();
					tempo += 5;
					updateTempo();
					playSong(metroTone, metDurr, metSize, TRUE);
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
		case 4: //third song
		{
			tempo = 120;
			updateTempo();
			playSong(songSLMN, durrSLMN, songSLMNSize, TRUE);
			transmitText(songNameSLMN, songNameSLMNSize);
			LED1 = 1;
			LED2 = 1;
			LED3 = 1;
			LED4 = 1;
			LED5 = 0;

			while(1)
			{
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

void playSong(unsigned char* song, unsigned char* durr, unsigned char sizeOfSong, unsigned char loop)
{
	looping = loop;
	playing = TRUE;
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
	noteHigh = notes[note_ptr[currNote]] >> 8;
	noteLow = notes[note_ptr[currNote]] & 0x00ff;
	TH1 = noteHigh;
	TL1 = noteLow;
	
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
		playSong(key1,quarterNote, keySize, FALSE);//plays C4
	}
	if(BUTTON2 == 0)
	{
		delay(100);
		while (BUTTON2 == 0);
		playSong(key2,quarterNote, keySize, FALSE);//plays C4
	}
	if(BUTTON3 == 0)
	{
		delay(100);
		while (BUTTON3 == 0);
		playSong(key3,quarterNote, keySize, FALSE);//plays C4
	}
	if(BUTTON4 == 0)
	{
		delay(100);
		while (BUTTON4 == 0);
		playSong(key4,quarterNote, keySize, FALSE);//plays C4
	}
	if(BUTTON5 == 0)
	{
		delay(100);
		while (BUTTON5 == 0);
		playSong(key5,quarterNote, keySize, FALSE);//plays C4
	}
	if(BUTTON6 == 0)
	{
		delay(100);
		while (BUTTON6 == 0);
		playSong(key6,quarterNote, keySize, FALSE);//plays C4
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

void externalButtonISR(void) interrupt 0 using 1
{

	return;
}	   
