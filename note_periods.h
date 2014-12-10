#ifndef NOTE_PERIODS_H
#define NOTE_PERIODS_H

#define CLOCK	7372800

//note length
#define sixteenth 2
#define eighth 4
#define quarter 8
#define half 16
#define whole 32

#define E3		((CLOCK/4)/164.81)
#define F3		((CLOCK/4)/174.61)
#define G3		((CLOCK/4)/196.00)
#define Ab3		((CLOCK/4)/207.65)
#define A3		((CLOCK/4)/220.00)
#define Bb3		((CLOCK/4)/233.08)
#define B3		((CLOCK/4)/246.94)
#define C4		((CLOCK/4)/261.63)
#define Db4		((CLOCK/4)/277.18)
#define D4		((CLOCK/4)/293.67)
#define Eb4		((CLOCK/4)/311.13)
#define E4		((CLOCK/4)/329.63)
#define F4		((CLOCK/4)/349.23)
#define Gb4		((CLOCK/4)/369.99)
#define G4		((CLOCK/4)/392.00)
#define Ab4		((CLOCK/4)/415.30)
#define A4		((CLOCK/4)/440.00)
#define Bb4		((CLOCK/4)/466.16)
#define B4		((CLOCK/4)/493.88)
#define C5		((CLOCK/4)/523.25)
#define Db5		((CLOCK/4)/554.37)
#define D5		((CLOCK/4)/587.33)
#define Eb5		((CLOCK/4)/622.25)
#define E5		((CLOCK/4)/659.26)
#define F5		((CLOCK/4)/698.46)
#define Gb5		((CLOCK/4)/739.99)
#define G5		((CLOCK/4)/783.99)
#define Ab5		((CLOCK/4)/830.61)
#define A5		((CLOCK/4)/880.00)
#define Bb5		((CLOCK/4)/932.33)
#define B5		((CLOCK/4)/987.77)
#define C6		((CLOCK/4)/1046.5)
#define Db6		((CLOCK/4)/1108.7)
#define D6		((CLOCK/4)/1174.7)
#define Eb6		((CLOCK/4)/1244.5)
#define E6		((CLOCK/4)/1318.5)
#define F6		((CLOCK/4)/1396.9)
#define Gb6		((CLOCK/4)/1480.0)
#define G6		((CLOCK/4)/1568.0)
#define Ab6		((CLOCK/4)/1661.2)
#define A6		((CLOCK/4)/1760.0)
#define Bb6		((CLOCK/4)/1864.7)
#define B6		((CLOCK/4)/1975.5)
#define C7		((CLOCK/4)/2093.0)
#define D7		((CLOCK/4)/2349.3)

code unsigned int notes[] = 
	{0,						E3,F3,Gb3,G3,Ab3,A3,Bb3,B3,
	C4,Db4,D4,Eb4,E4,F4,Gb4,G4,Ab4,A4,Bb4,B4,
	C5,Db5,D5,Eb5,E5,F5,Gb5,G5,Ab5,A5,Bb5,B5,
	C5,Db6,D6,Eb6,E6,F6,Gb6,G6,Ab6,A6,Bb6,B6,
	C6,Db7,D7};


//only relevant for the keyboard function
code unsigned char key1[] = {8};//C4
code unsigned char key2[] = {10};//D4
code unsigned char key3[] = {12};//E4
code unsigned char key4[] = {13};//F4
code unsigned char key5[] = {15};//G4
code unsigned char key6[] = {17};//A4
code unsigned char keySize = 1;

code unsigned char song1[] = {8,10,12,15};
code unsigned char durr1[] = {32,32,64,32};
code unsigned char song1Size = 4;
code unsigned char song1Name[] = {"Scale"};
code unsigned char song1NameSize = 5;

#endif