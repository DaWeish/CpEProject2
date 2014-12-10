#ifndef NOTE_PERIODS_H
#define NOTE_PERIODS_H


#define E3 (65536 - 4189)
#define Fb3 (65536 - 4189)
#define F3 (65536 - 4189)
#define Gb3 (65536 - 4189)
#define G3 (65536 - 4189)
#define Ab3 (65536 - 4189)
#define A3 (65536 - 4189)
#define Bb3 (65536 - 4189)
#define B3 (65536 - 4189)
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
#define Db5 (65536 - 4189)
#define D5 (65536 - 4189)
#define Eb5 (65536 - 4189)
#define E5 (65536 - 4189)
#define F5 (65536 - 4189)
#define Gb5 (65536 - 4189)

code unsigned int notes[] = {0,E3,F3,Gb3,G3,Ab3,A3,B3,C4,Db4,D4,Eb4,E4,F4,Gb4,G4,Ab4,A4,Bb4,B4,C5,Db5,D5,Eb5,E5,F5,Gb5};

//only relevant for the keyboard function
code unsigned char quarter[] = {32};
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