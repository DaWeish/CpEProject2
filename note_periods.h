#ifndef NOTE_PERIODS_H
#define NOTE_PERIODS_H

#define E3
#define F3
#define G3
#define Ab3
#define A3
#define Bb3
#define B3
#define C4 (65536 - 7046)
#define Db4 (65536 - 6640)
#define D4 (65536 - 6276)
#define Eb4 (65536 - 5924)
#define E4 (65536 - 5592)
#define F4 (65536 - 5278)
#define Gb4 (65536 - 4982)
#define G4 (65536 - 4702)
#define Ab4 (65536 - 4438)
#define A4 (65536 - 4189)
#define Bb4 (65536 - 3954)
#define B4 (65536 - 3732)
#define C5 (65536 - 3523)

code unsigned int notes[] = {0,C4,D4,E4,F4,G4,A4,B4,C5};

//only relevant for the keyboard function
code unsigned char quarter[] = {8};
code unsigned char key1[] = {1};//C4
code unsigned char key2[] = {2};//D4
code unsigned char key3[] = {3};//E4
code unsigned char key4[] = {4};//F4
code unsigned char key5[] = {5};//G4
code unsigned char key6[] = {6};//A4
code unsigned char keySize = 1;

code unsigned char song1[] = {1,3,5,8};
code unsigned char durr1[] = {32,32,64,32};
code unsigned char song1Size = 4;

#endif