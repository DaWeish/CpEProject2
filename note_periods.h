#ifndef NOTE_PERIODS_H
#define NOTE_PERIODS_H

#define CLOCK	11059200

//note length
#define sixteenth 2
#define eighth 4
#define quarter 8
#define half 16
#define whole 32

#define E3		(65536 - ((CLOCK/24)/164.81))
#define F3		(65536 - ((CLOCK/24)/174.61))
#define Gb3		(65536 - ((CLOCK/24)/185.00))
#define G3		(65536 - ((CLOCK/24)/196.00))
#define Ab3		(65536 - ((CLOCK/24)/207.65))
#define A3		(65536 - ((CLOCK/24)/220.00))
#define Bb3		(65536 - ((CLOCK/24)/233.08))
#define B3		(65536 - ((CLOCK/24)/246.94))
#define C4		(65536 - ((CLOCK/24)/261.63))
#define Db4		(65536 - ((CLOCK/24)/277.18))
#define D4		(65536 - ((CLOCK/24)/293.67))
#define Eb4		(65536 - ((CLOCK/24)/311.13))
#define E4		(65536 - ((CLOCK/24)/329.63))
#define F4		(65536 - ((CLOCK/24)/349.23))
#define Gb4		(65536 - ((CLOCK/24)/369.99))
#define G4		(65536 - ((CLOCK/24)/392.00))
#define Ab4		(65536 - ((CLOCK/24)/415.30))
#define A4		(65536 - ((CLOCK/24)/440.00))
#define Bb4		(65536 - ((CLOCK/24)/466.16))
#define B4		(65536 - ((CLOCK/24)/493.88))
#define C5		(65536 - ((CLOCK/24)/523.25))
#define Db5		(65536 - ((CLOCK/24)/554.37))
#define D5		(65536 - ((CLOCK/24)/587.33))
#define Eb5		(65536 - ((CLOCK/24)/622.25))
#define E5		(65536 - ((CLOCK/24)/659.26))
#define F5		(65536 - ((CLOCK/24)/698.46))
#define Gb5		(65536 - ((CLOCK/24)/739.99))
#define G5		(65536 - ((CLOCK/24)/783.99))
#define Ab5		(65536 - ((CLOCK/24)/830.61))
#define A5		(65536 - ((CLOCK/24)/880.00))
#define Bb5		(65536 - ((CLOCK/24)/932.33))
#define B5		(65536 - ((CLOCK/24)/987.77))
#define C6		(65536 - ((CLOCK/24)/1046.5))
#define Db6		(65536 - ((CLOCK/24)/1108.7))
#define D6		(65536 - ((CLOCK/24)/1174.7))
#define Eb6		(65536 - ((CLOCK/24)/1244.5))
#define E6		(65536 - ((CLOCK/24)/1318.5))
#define F6		(65536 - ((CLOCK/24)/1396.9))
#define Gb6		(65536 - ((CLOCK/24)/1480.0))
#define G6		(65536 - ((CLOCK/24)/1568.0))
#define Ab6		(65536 - ((CLOCK/24)/1661.2))
#define A6		(65536 - ((CLOCK/24)/1760.0))
#define Bb6		(65536 - ((CLOCK/24)/1864.7))
#define B6		(65536 - ((CLOCK/24)/1975.5))
#define C7		(65536 - ((CLOCK/24)/2093.0))
#define Db7     (65536 - ((CLOCK/24)/2217.4))
#define D7		(65536 - ((CLOCK/24)/2349.3))

code unsigned int notes[] = 
//			     1  2   3  4   5  6   7  8
	{0,		  	 E3,F3,Gb3,G3,Ab3,A3,Bb3,B3,
		
// 9  10 11  12 13 14  15 16  17 18 19  20
	C4,Db4,D4,Eb4,E4,F4,Gb4,G4,Ab4,A4,Bb4,B4,
		
//21  22 23  XX 25 26  27 28  29 30  31 32
  C5,Db5,D5,Eb5,E5,F5,Gb5,G5,Ab5,A5,Bb5,B5,
		
//33  34 35  XX 37 38  39 40  41 42  43 44
	C6,Db6,D6,Eb6,E6,F6,Gb6,G6,Ab6,A6,Bb6,B6,
		
//45  46 47
	C7,Db7,D7};
	

//only relevant for the keyboard function
code unsigned char key1[] = {8};//C4
code unsigned char key2[] = {9};//D4
code unsigned char key3[] = {11};//E4
code unsigned char key4[] = {12};//F4
code unsigned char key5[] = {14};//G4
code unsigned char key6[] = {16};//A4
code unsigned char keySize = 1;
code unsigned char quarterNote[] = {quarter};
code unsigned char keyboardName[] = {"Keyboard"};
code unsigned char keyboardNameSize = 8;

unsigned char metroTone[] = {18,0};
code unsigned char metDurr[] = {4,4};
code unsigned char metSize = 2;
code unsigned char metName[] = {"MetroTONE"};
code unsigned char metNameSize = 9;

code unsigned char song1[] = {9,11,13,14,16,18,20,21};
code unsigned char durr1[] = {16,16,16,16,16,16,16,16};
code unsigned char song1Size = 8;
code unsigned char song1Name[] = {"Scale"};
code unsigned char song1NameSize = 5;

code unsigned char songDragonforce[] = { 9,11,12, 9,11,12,14,11, 16,12,14,11,12, 9,11, 8};
code unsigned char durrDragonforce[] = { 8, 8, 8, 8, 8, 8, 8, 8,  8, 8, 8, 8, 8, 8, 8, 8};
code unsigned char songDragonSize = 16;
code unsigned char songNameDragon[] = {"Through the Fire and Flames"};
code unsigned char songNameDragonSize = 27;

code unsigned char songYPC[] = {21,28,21,20,28,20,18,25,24};
code unsigned char durrYPC[] = {16, 8, 8,16, 8, 8,32,16,16};
code unsigned char songYPCSize = 9;
code unsigned char songNameYPC[] = {"Your Prince Charming"};
code unsigned char songNameYPCSize = 20;

code unsigned char songSLMN[] = {23, 0,11,23,30,27,11,23, 18, 0, 6, 0, 0, 0, 6, 0, 16, 0, 4,16,28,27, 4,25, 25,25, 6, 0, 0, 0, 6, 0};
code unsigned char durrSLMN[] = { 8, 4, 8, 4, 8, 4, 8, 4,  8, 4, 8, 4, 8, 4, 8, 4,  8, 4, 8, 4, 8, 4, 8, 4,  8, 4, 8, 4, 8, 4, 8, 4};
code unsigned char songSLMNSize = 32;
code unsigned char songNameSLMN[] = {"She Loves Me (Not)"};
code unsigned char songNameSLMNSize = 18;


#endif