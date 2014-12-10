#ifndef NOTE_PERIODS_H
#define NOTE_PERIODS_H

#define E3
#define F3
#define G3
#define Ab3
#define A3
#define Bb3
#define B3
#define C4 7046
#define Db4 6640
#define D4 6276
#define Eb4 5924
#define E4 5592
#define F4 5278
#define Gb4 4982
#define G4 4702
#define Ab4 4438
#define A4 4189
#define Bb4 3954
#define B4 3732
#define C5 3523

code int notes[] = {0,C4,D4,E4,F4,G4,A4,B4,C5};

//only relevant for the keyboard function
code unsigned char keyboardQuarter[] = {8};
code unsigned char key1[] = {1};//C4
code unsigned char key2[] = {2};//D4
code unsigned char key3[] = {3};//E4
code unsigned char key4[] = {4};//F4
code unsigned char key5[] = {5};//G4
code unsigned char key6[] = {6};//A4
code unsigned char keySize = 1;

code unsigned char song1[] = {1,3,5,8};
code unsigned char durr1[] = {32,32,128,32};
code unsigned char song1Size = 4;

#endif