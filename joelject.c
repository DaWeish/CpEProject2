#include <REG932.H>
#include <stdlib.h>

sbit RED1=P2^4;			     	 	// LED (TOP LEFT)
sbit AMBER1=P0^6;			 		// LED (LEFT MIDDLE)
sbit YELLOW1=P2^5;		     		// LED (BOTTOM LEFT)
sbit YELLOW2=P0^5;		      		// LED (TOP CENTER)
sbit BLUE=P1^6;			      		// LED (MIDDLE)
sbit GREEN1=P0^7;			  		// LED (BOTTOM CENTER)
sbit GREEN2=P2^7;			  		// LED (TOP RIGHT)
sbit RED2=P0^4;		     	  		// LED (RIGHT MIDDLE)
sbit AMBER2=P2^6;			  		// LED (BOTTOM RIGHT)
sbit SPEAKER= P1^7;			  		// SPEAKER
sbit SW1 = P2^0;
sbit SW2 = P0^2;
sbit SW3 = P2^1;
sbit SW4 = P0^1;
sbit SW5 = P1^4;
sbit SW6 = P0^3;
sbit SW7 = P2^3;
sbit SW8 = P0^0;
sbit SW9 = P2^2;

/////////////////////////////FUNCTION PROTOTYPES///////////////////////////////

/////////////////////////////////////////////DELAY/////////////////////////////////////////////////////
//                                 THIS FUNCTION CREATES A DELAY          			                 //
///////////////////////////////////////////////////////////////////////////////////////////////////////
void durlay(unsigned char x);

///////////////////////////////////////PLAY A C6 NOTE//////////////////////////////////////////////////
//                 THIS FUNCTION MAKES THE SPEAKER PLAY A C NOTE IN THE 6TH OCTAVE					 //
///////////////////////////////////////////////////////////////////////////////////////////////////////
void playC6(char durC);

///////////////////////////////////////PLAY A D6 NOTE//////////////////////////////////////////////////
//                 THIS FUNCTION MAKES THE SPEAKER PLAY A D NOTE IN THE 6TH OCTAVE					 //
///////////////////////////////////////////////////////////////////////////////////////////////////////
void playD6(char durD);

///////////////////////////////////////PLAY AN F6 NOTE/////////////////////////////////////////////////
//                 THIS FUNCTION MAKES THE SPEAKER PLAY AN F NOTE IN THE 6TH OCTAVE					 //
///////////////////////////////////////////////////////////////////////////////////////////////////////
void playF6(char durD);

///////////////////////////////////////PLAY A G6 NOTE//////////////////////////////////////////////////
//                 THIS FUNCTION MAKES THE SPEAKER PLAY A G NOTE IN THE 6TH OCTAVE					 //
///////////////////////////////////////////////////////////////////////////////////////////////////////
void playG6(char durD);

///////////////////////////////////////PLAY AN A6 NOTE/////////////////////////////////////////////////
//                 THIS FUNCTION MAKES THE SPEAKER PLAY AN A NOTE IN THE 6TH OCTAVE					 //
///////////////////////////////////////////////////////////////////////////////////////////////////////
void playA6(char durD);

///////////////////////////////////////PLAY AN E6 NOTE/////////////////////////////////////////////////
//                 THIS FUNCTION MAKES THE SPEAKER PLAY AN E NOTE IN THE 6TH OCTAVE					 //
///////////////////////////////////////////////////////////////////////////////////////////////////////
void playE6(char durD);

/////////////////////////////////////////////PAUSE/////////////////////////////////////////////////////
//                            THIS FUNCTION MAKES A PAUSE BETWEEN NOTES			                     //
///////////////////////////////////////////////////////////////////////////////////////////////////////
void playBreath(char durD);

////////////////////////////////////////////STOP TIMER/////////////////////////////////////////////////
//                    THIS FUNCTION STOPS THE TIMER AFTER MUSIC IS DONE PLAYING		        		 //
///////////////////////////////////////////////////////////////////////////////////////////////////////
void playREST();

///////////////////////////////TWINKILE TWINKLE LITTLE STAR////////////////////////////////////////////
//                 THIS FUNCTION PLAYS A SERIES OF NOTES THAT CREATE A SONG							 //
///////////////////////////////////////////////////////////////////////////////////////////////////////
void playSong();

///////////////////////////////////////TURN ON ALL THE LIGHTS//////////////////////////////////////////
//                 THIS FUNCTION TURNS ON ALL OF THE ACTIVE-LOW LIGHTS							     //
///////////////////////////////////////////////////////////////////////////////////////////////////////
void allon();                 //turns all LEDs on

///////////////////////////////////////TURN OFF ALL THE LIGHTS/////////////////////////////////////////
//                 THIS FUNCTION TURNS OFF ALL OF THE ACTIVE-LOW LIGHTS							     //
///////////////////////////////////////////////////////////////////////////////////////////////////////
void alloff();                //turns all LEDs off

/////////////////////////////////////////////DURATION//////////////////////////////////////////////////
//               	THIS FUNCTION CREATES A DURATION FOR THE NOTE TO BE PLAYED                       //  //////////////////////GET CALCULATIONS OUT OF BOOK////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
void sixteenth(int mulofsixteenth);

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////GAME ONE//////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//DESCRIPTION: Function that generates a random number between 0 and 10, and
//			   stores this number in variable "randnum". The function then
//			   waits for a button press from the user. Button/Switch 7 is
//             pressed to increment the user's guess, which is stored in
//             "guessnum", as they are attempting to match their guess with the
//             random number in randnum. As their guess increments, LEDs light,
//             in order, to visualize the count increasing. The function also
//             waits for a Button/Switch 5 press, which then maintains
//             conditional loops, and calls a function to compare the guess
//             with the random number. If the user correctly guess the random
//             number, the Switch 5 loop throws an exit flag to signal success.
//             The user has a total of three possible attempts to guess the
//             correct number.
//PRE: Must be called by the user on a button press.
//POST: A problem is output to the screen and a prompt for input.
//      User input is compared to the correct answer and an exit flag is thrown
//      if the user correctly guesses the number. Also, a function is called to
//      evaluate the correctness of the user's guess.
void game1();

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////GAME TWO//////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//DESCRIPTION: Function that randomizes a switch out of 9 total switched, and
//			   waits for a button press from the user. Ifthe right button is pressed
//			   all of the lights flash. Otherwise, the correct button flashes.
//             The user only has one attempt.
//PRE: Must be called by the user on a button press.
//POST: A problem is output to the screen and a prompt for input.
//      User input is compared to the correct answer and an exit flag is thrown
void game2();

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////GAME THREE////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//DESCRIPTION: Function that generates a random number between 0 and 1, and
//			   stores this number in variable "map". If value in "map" is 0, 
//			   the function operates in the map 0 layout, if the value in "map"
//			   is 1, the function operates in map 1 layout.	Each map layout
//			   have a starting point, an exit, and a "bomb" waiting to be
//			   stepped on. For this project, the starting point and exit will
//			   always be the same, while the bomb will change places depending
//			   on map layout. When the game starts, one of the LED(Bottom Right)
//             will light up indicating that is the starting point of the user.
//			   The function then waits for a button press from the user. At
//			   every point on the "map", there is only a few moves that is
//			   available for the user to make, which are only adjacent buttons
//			   but not diagonal ones. This means the user cannot jump all over
//			   the map. Once the user make a move (by pressing any of the
//			   adjacent buttons from the starting point), the LED from that
//		       switch will light up while turning off all other previous ones.
//			   Each time the user make a move, a value will be stored in a
//			   variable "current" to indicate the user is currently at that 
//			   point on the map. And while the user is at whichever current
//			   point on the map, the user can only move to adjacent points.
//			   If the user "step" on the bomb, then the game make a loud buzz
//			   indicating the bomb has been set off (we all know what happens
//			   when you step on a landmine). Afterwards, the game sends the
//			   user back to game menu. However if the user does found the exit
//			   without ever stepping on the bomb, then the game will play
//			   a happy sound indicating the exit have been found and the user
//			   successfully found the correct pathing. Afterwards, the game
//			   sends the user back to game menu and can choose the next game.
//			   NOTE: Since we ran out of space, we have to limit the game to
//			   only one map layout instead of 2 or 3, or more. 
void game3();

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////GAME ONE COMPARE//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//DESCRIPTION: Function that compares the user's guess, and the random number.
//             If the guess is correct, all lights flash, and the winning tune
//             sounds a number of times equal to the random number. If the
//             user's guess is greater than the random number, a high note will
//             play, and an H will appear in LEDs on the board, signaling the
//             guess was too high. If the user's guess is less than  the random
//             number, a low note will play, and an L will appear on the
//             on-board LEDs, signaling the guess was too low. 
//PRE: Must be passed two characters, one representing the random number value
//     "r", and one for the guess "g". This is to only be called in game1().
//POST: User input "g" is compared to the correct answer "r" and outcome 
//      specific actions, descibed above, are carried out.
void g1compare(char r, char g);

void buzz();

void buzzwin();

//////////////////////////////////CONSTANTS////////////////////////////////////
unsigned char R0,R1,R2,R3,R4;
char randnum, guessnum, attempts, win,current;
bit donesig = 0;              // SIGNALS WHEN GUESS IS MADE IN GAME 1
bit exit = 0;                 // USED TO EXIT LOOP IN GAME 1 ON CORRECT GUESS

void T_ISR(void) interrupt 1
{
 	SPEAKER=!SPEAKER;
 	TH0=R3;
	TL0=R4;
 	return;
}

void T1_ISR(void) interrupt 3
{
 	TF1 = 0;
 	return;
}

void main()
{
	srand(NULL);
	P0M1=0x00;
 	P1M1=0x00;
	P2M1=0x00;
 	TMOD=0x11;
 	ET1 = 1;
	ET0=1;
	EA=1;
	TR0=1;
	playSong();					
	while(1)					//GAME MENU STARTS HERE, AFTER SONG
	{
		allon();

		if(SW7 == 0)                                                                                
		{   
			do                                                                                         
			{
				durlay(20);             //debounce delay                                                 
			}while(SW7 == 0);  

			alloff();
			game1();                                                                                   
		}                                                                                            

		if(SW8 == 0)                                                                                
		{                                                                                            
			do                                                                                         
			{                                                                                          
				durlay(20);             //debounce delay                                                 
			}while(SW8 == 0);                                                                         
			alloff();
			game2();
		}

		if(SW9 == 0)
		{
			do
			{
				durlay(20);             //debounce delay
			}while(SW9 == 0);
			alloff();
			game3();
		}

		alloff();
	}

}


void playSong()  //Notes Used: C, G, F, A, D, E
{
	playC6(50);
	playBreath(20);			//This function creates a pause between notes
	playC6(50);
	playBreath(20);
	playG6(50);
	playBreath(20);
	playG6(50);
	playBreath(20);
	playA6(50);
	playBreath(20);
	playA6(50);
	playBreath(20);
	playG6(50);
	playBreath(35);		    //Longer pause here
	playF6(50);
	playBreath(20);
	playF6(50);
	playBreath(20);
	playE6(50);
	playBreath(20);
	playE6(50);
	playBreath(20);
	playD6(50);
	playBreath(20);
	playD6(50);
	playBreath(20);
	playC6(50);
	playBreath(35);			//Longer pause here
	playG6(50);
	playBreath(20);
	playG6(50);
	playBreath(20);
	playF6(50);
	playBreath(20);
	playF6(50);
	playBreath(20);
	playE6(50);
	playBreath(20);
	playE6(50);
	playBreath(20);
	playD6(50);
	playBreath(35);			//Longer pause here
	playG6(50);
	playBreath(20);
	playG6(50);
	playBreath(20);
	playF6(50);
	playBreath(20);
	playF6(50);
	playBreath(20);
	playE6(50);
	playBreath(20);	
	playE6(50);
	playBreath(20);
	playD6(50);
	/*playBreath(35);			//Longer pause here
	playC6(50);
	playBreath(20);
	playC6(50);
	playBreath(20);
	playG6(50);
	playBreath(20);
	playG6(50);
	playBreath(20);
	playA6(50);
	playBreath(20);
	playA6(50);
	playBreath(20);
	playG6(50);
	playBreath(35);			//Longer pause here
	playF6(50);
	playBreath(20);
	playF6(50);
	playBreath(20);
	playE6(50);
	playBreath(20);
	playE6(50);
	playBreath(20);
	playD6(50);
	playBreath(20);
	playD6(50);
	playBreath(20);
	playC6(50);*/
    playREST();				 //Turns off the timer
	SPEAKER=1;				 //Turns off speaker
}

void allon()				 //Function turn all LEDS on
{
		RED1 = 0;
		AMBER1 = 0;
		YELLOW1 = 0;
		YELLOW2 = 0;
		BLUE = 0;
		GREEN1 = 0;
		GREEN2 = 0;
		RED2 = 0;
		AMBER2 = 0;
}

void alloff()				//Function turn all LEDS off
{
		RED1 = 1;
		AMBER1 = 1;
		YELLOW1 = 1;
		YELLOW2 = 1;
		BLUE = 1;
		GREEN1 = 1;
		GREEN2 = 1;
		RED2 = 1;
		AMBER2 = 1;
}

void playC6(char durC)
{
 	RED1=0;				//RED1 is assigned to the C note (LIGHT IS ON)
	R3=0xF2;
	R4=0x3D;
	sixteenth(durC);	//Creates the duration of the note	
 	RED1=1;				//LIGHT IS OFF
 	return;
}

void playD6(char durD)
{
	AMBER1=0;			//AMBER1 is assigned to the D note (LIGHT IS ON)
 	R3=0xF3;
 	R4=0xBE;
 	sixteenth(durD);	//Creates the duration of the note
	AMBER1=1;			//LIGHT IS OFF
	return;
}

void playF6(char durD)
{
	BLUE=0;				//BLUE is assigned to the F note (LIGHT IS ON)
 	R3=0xF5;
 	R4=0xB1;
 	sixteenth(durD);	//Creates the duration of the note
	BLUE=1;				//LIGHT IS OFF
	return;
}

void playG6(char durD) 
{
	GREEN1=0;			//GREEN1 is assigned to the G note (LIGHT IS ON)
 	R3=0xF6;
 	R4=0xD1;
 	sixteenth(durD);	//Creates the duration of the note
	GREEN1=1;			//LIGHT IS OFF
	return;
}

void playA6(char durD)
{
	YELLOW1=0;			//YELLOW1 is assigned to the A note (LIGHT IS ON)
 	R3=0xF7;
 	R4=0xD1;
 	sixteenth(durD);	//Creates the duration of the note
	YELLOW1=1;			//LIGHT IS OFF
	return;
}

void playE6(char durD)
{
	RED2=0;				//RED2 is assigned to the E note (LIGHT IS ON)			
 	R3=0xF5;
 	R4=0x14;
 	sixteenth(durD);	//Creates the duration of the note
	RED2=1;				//LIGHT IS OFF
	return;
}

void playBreath(char durD)
{
    TR0=0;				//TURN OFF THE TIMER
	sixteenth(durD);	//DELAY
	TR0=1;				//TURN ON TIMER
	return;
}

void playREST()
{
 	R3=0x00;		//Reset the values of the registers
	R4=0x00;
	TR0=0;			//TURN OFF TIMER
	return;
}

void durlay(unsigned char x)
{
	long i=0;
	for(i;i<x;i++);
}

void sixteenth(int mulofsixteenth)				// timer of .1 sec
{
	int psych = 0;
	for(psych;psych<mulofsixteenth;psych++)
	{
 		ET1 = 1;			// enable timer 2;
		TMOD=0x11;			// both timers in mode 1
		TL1=0xFE;			// These values were calculated to obtain a delay of 0.1 sec
		TH1=0x87;
		TR1=1; 				// start timer.
		while(TF1==0); 		// run until TF turns to 1
 		TR1=0; 				// stop timer
		TF1=0; 				// reset the flag
	}
}




void game1()
{
	randnum = rand() % 11;
	attempts = 0;               // NUMBER OF GUESSES MADE
	exit = 0;
	do
	{
			attempts++;
			donesig = 0;
			guessnum = 0;
			while(donesig == 0 && exit == 0)
			{
				//increment button
				if(SW7 == 0)
				{
					do
					{
						durlay(20);             //debounce delay
					}while(SW7 == 0);
					guessnum++;
					if(guessnum == 1) {alloff();
														 RED1 = 0;}
					if(guessnum == 2) {alloff();
														 AMBER1 = 0;}
					if(guessnum == 3) {alloff();
														 YELLOW1 = 0;}
					if(guessnum == 4) {alloff();
														 YELLOW2 = 0;}
					if(guessnum == 5) {alloff();
														 BLUE = 0;}
					if(guessnum == 6) {alloff();
														 GREEN1 = 0;}
					if(guessnum == 7) {alloff();
														 GREEN2 = 0;}
					if(guessnum == 8) {alloff();
														 RED2 = 0;}
					if(guessnum == 9) {alloff();
														 AMBER2 = 0;}
					if(guessnum == 10) allon();
				}
				
				if(SW5 == 0)         // INDICATES THE USER IS FINISHED INCREMENTING
				{
					do
					{
						durlay(20);             //debounce delay
					}while(SW5 == 0);
					if (randnum == guessnum) 
					{
						exit = 1;
						attempts = 3;
					}
					alloff();
					g1compare(randnum,guessnum);
					donesig = 1;
				}
			}
	}while(attempts < 3);
	alloff();

	return;
}
	
void game2()
{
	int slength = 2000;		//NOISE LENGTH
	char i;					//RANDOM NUMBER TO PICK THE CASE
	char exit=0;			//EXIT FROM THE GAME IF 1
	durlay(10000);			//DELAY
	i = rand() % 4;			//RANDOM NUMBER FROM 0-8
	i++;					//MAKE THE RANDOM NUMBER 1-9 INSTEAD OF 0-8
	if(i==1)				//CASE 1
  	{
		while(SW1!=0 || exit!=1)
		{
		  	if(SW1==0)		//WIN (RIGHT BUTTON IS PRESSED)
		  	{
				allon();	//TURN ON ALL OF THE LIGHT
				while(slength >= 0)		//MAKE NOISE
				{
					SPEAKER = !SPEAKER;
					durlay(20);
					SPEAKER = !SPEAKER;
					durlay(50);
					slength--;
				}
				SPEAKER = 1; //TURN OFF SPEAKER
				alloff();	 //TURN OFF ALL LIGHTS
				return;
			}
			if(SW2==0 || SW3==0 || SW4==0 || SW5==0 || SW6==0 || SW7==0 || SW8==0 || SW9==0)  //LOSE (WRONG BUTTON IS PRESSED)
			{
				RED1=0;		 //SHOW THE CORRECT LIGHT
				while(slength >= 0)	//MAKE NOISE
				{
					SPEAKER = !SPEAKER;
					durlay(35);
					SPEAKER = !SPEAKER;
					durlay(80);
					slength--;
				}
				SPEAKER = 1; //TURN OFF SPEAKER
				alloff();    //TURN OFF ALL LIGHTS
				exit=1;		 //EXIT GAME
				return;
			}
		}	
	}
	/*if(i==2)  //CASE 2
  	{
		while(SW2!=0 || exit!=1)
		{
		  	if(SW2==0)
		  	{
				allon();
				while(slength >= 0)
				{
					SPEAKER = !SPEAKER;
					durlay(20);
					SPEAKER = !SPEAKER;
					durlay(50);
					slength--;
				}
				SPEAKER = 1;
				alloff();
				return;
			}
			if(SW1==0 || SW3==0 || SW4==0 || SW5==0 || SW6==0 || SW7==0 || SW8==0 || SW9==0)
			{
				AMBER1=0;
				while(slength >= 0)
				{
					SPEAKER = !SPEAKER;
					durlay(35);
					SPEAKER = !SPEAKER;
					durlay(80);
					slength--;
				}
				SPEAKER = 1;
				alloff();
				exit=1;
				return;
			}
		}	
	} 
	if(i==3)  //CASE 3
  	{
		while(SW3!=0 || exit!=1)
		{
		  	if(SW3==0)
		  	{
				allon();
				while(slength >= 0)
				{
					SPEAKER = !SPEAKER;
					durlay(20);
					SPEAKER = !SPEAKER;
					durlay(50);
					slength--;
				}
				SPEAKER = 1;
				alloff();
				return;
			}
			if(SW1==0 || SW2==0 || SW4==0 || SW5==0 || SW6==0 || SW7==0 || SW8==0 || SW9==0)
			{
				YELLOW1=0;
				while(slength >= 0)
				{
					SPEAKER = !SPEAKER;
					durlay(35);
					SPEAKER = !SPEAKER;
					durlay(80);
					slength--;
				}
				SPEAKER = 1;
				alloff();
				exit=1;
				return;
			}
		}	
	}
	if(i==4) //CASE 4
  	{
		while(SW4!=0 || exit!=1)
		{
		  	if(SW4==0)
		  	{
				allon();
				while(slength >= 0)
				{
					SPEAKER = !SPEAKER;
					durlay(20);
					SPEAKER = !SPEAKER;
					durlay(50);
					slength--;
				}
				SPEAKER = 1; 
				alloff();
				return;
			}
			if(SW2==0 || SW3==0 || SW1==0 || SW5==0 || SW6==0 || SW7==0 || SW8==0 || SW9==0)
			{
				YELLOW2=0;
				while(slength >= 0)
				{
					SPEAKER = !SPEAKER;
					durlay(35);
					SPEAKER = !SPEAKER;
					durlay(80);
					slength--;
				}
				SPEAKER = 1;
				alloff();
				exit=1;
				return;
			}
		}	
	}
	if(i==5) //CASE 5
  	{
		while(SW5!=0 || exit!=1)
		{
		  	if(SW5==0)
		  	{
				allon();
				while(slength >= 0)
				{
					SPEAKER = !SPEAKER;
					durlay(20);
					SPEAKER = !SPEAKER;
					durlay(50);
					slength--;
				}
				SPEAKER = 1;
				alloff();
				return;
			}
			if(SW2==0 || SW3==0 || SW4==0 || SW1==0 || SW6==0 || SW7==0 || SW8==0 || SW9==0)
			{
				BLUE=0;
				while(slength >= 0)
				{
					SPEAKER = !SPEAKER;
					durlay(35);
					SPEAKER = !SPEAKER;
					durlay(80);
					slength--;
				}
				SPEAKER = 1; 
				alloff();
				exit=1;
				return;
			}
		}	
	}
	if(i==6) //CASE 6
  	{
		while(SW6!=0 || exit!=1)
		{
		  	if(SW6==0)
		  	{
				allon();
				while(slength >= 0)
				{
					SPEAKER = !SPEAKER;
					durlay(20);
					SPEAKER = !SPEAKER;
					durlay(50);
					slength--;
				}
				SPEAKER = 1;
				alloff();
				return;
			}
			if(SW2==0 || SW3==0 || SW4==0 || SW5==0 || SW1==0 || SW7==0 || SW8==0 || SW9==0)
			{
				GREEN1=0;
				while(slength >= 0)
				{
					SPEAKER = !SPEAKER;
					durlay(35);
					SPEAKER = !SPEAKER;
					durlay(80);
					slength--;
				}
				SPEAKER = 1;
				alloff();
				exit=1;
				return;
			}
		}	
	} 
	if(i==7) //CASE 7
  	{
		while(SW7!=0 || exit!=1)
		{
		  	if(SW7==0)
		  	{
				allon();
				while(slength >= 0)
				{
					SPEAKER = !SPEAKER;
					durlay(20);
					SPEAKER = !SPEAKER;
					durlay(50);
					slength--;
				}
				SPEAKER = 1;
				alloff();
				return;
			}
			if(SW2==0 || SW3==0 || SW4==0 || SW5==0 || SW6==0 || SW1==0 || SW8==0 || SW9==0)
			{
				GREEN2=0;
				while(slength >= 0)
				{
					SPEAKER = !SPEAKER;
					durlay(35);
					SPEAKER = !SPEAKER;
					durlay(80);
					slength--;
				}
				SPEAKER = 1;
				alloff();
				exit=1;
				return;
			}
		}	
	}



	if(i==8)	   //Case 8
  	{
		while(SW8!=0 || exit!=1)
		{
		  	if(SW8==0)
		  	{
				allon();
				while(slength >= 0)
				{
					SPEAKER = !SPEAKER;
					durlay(20);
					SPEAKER = !SPEAKER;
					durlay(50);
					slength--;
				}
				SPEAKER = 1; 
				alloff();
				return;
			}
			if(SW2==0 || SW3==0 || SW4==0 || SW5==0 || SW6==0 || SW7==0 || SW1==0 || SW9==0)
			{
				RED2=0;
				while(slength >= 0)
				{
					SPEAKER = !SPEAKER;
					durlay(35);
					SPEAKER = !SPEAKER;
					durlay(80);
					slength--;
				}
				SPEAKER = 1;
				alloff();
				exit=1;
				return;
			}
		}	
	}*/



	if(i==2)   //Case 9
  	{
		while(SW9!=0 || exit!=1)
		{
		  	if(SW9==0)
		  	{
				allon();
				while(slength >= 0)
				{
					SPEAKER = !SPEAKER;
					durlay(20);
					SPEAKER = !SPEAKER;
					durlay(50);
					slength--;
				}
				SPEAKER = 1;
				alloff();
				return;
			}
			if(SW2==0 || SW3==0 || SW4==0 || SW5==0 || SW6==0 || SW7==0 || SW8==0 || SW1==0)
			{
				AMBER2=0;
				while(slength >= 0)
				{
					SPEAKER = !SPEAKER;
					durlay(35);
					SPEAKER = !SPEAKER;
					durlay(80);
					slength--;
				}
				SPEAKER = 1;
				alloff();
				exit=1;
				return;
			}
		}	
	}
	return;
}

void game3()					//Pathfinding Game
{

	char map= rand() % 2;	   	//Initialize variable map, random number between 0 & 1
	AMBER2=0;	   				//Turn on LED (Bottom Right)
	current = 9;   				//Initialize current positions, 
				   				//there are 9 positions on the map(board)
    win = 0;	   				//Initialize win variable, used to indicate
				   				//if the user has found the exit.
	map = 0;					//Since we ran out of space, we have to limit
								//the game to only one map layout.
	if(map==0)					//map layout 0
	{
		do
		{
			
			if(current==9)		//current position is at SW9
			{
				do
				{
					if(SW8==0)				 //If SW8 is pressed
					{
						alloff();			 //Turns all previous LEDS off
						do
						{
							durlay(20);		//debounce delay	
						}while(SW8==0);	
						RED2=0;				//Turns on red LED for current position
						current=8;			//sets current position to SW8
					}
				    if(SW6==0)				//If SW6 is pressed
					{
						alloff();			//Turns all previous LEDS off
						do
						{	
							durlay(20);		//debounce delay
						}while(SW6==0);	
						GREEN1=0;			//Turns on green LED for current position
						current=6;			//sets current position to SW6
					}
					durlay(20);
				}while(current == 9);
			}
			if(current==8)				  	//current position is at SW8
			{
				do
				{
					if(SW7==0)			 	//If SW7 is pressed
					{
						alloff();		 	//Turns all previous LEDS off
						do
						{
							durlay(20);		//debounce delay	
						}while(SW7==0);	
						GREEN2=0;			//Turns on green LED for current position
						current=7;			//sets current position to SW7
					}
					if(SW5==0)				
					{
						alloff();
						do
						{
							durlay(20);		
						}while(SW5==0);	
						BLUE=0;
						current=5;
					}
					if(SW9==0)
					{
						alloff();
						do
						{
							durlay(20);		
						}while(SW9==0);	
						AMBER2=0;
						current=9;
					}
					durlay(20);
				}while(current == 8);
			}
			if(current==7)					//Similar conditions are applied for positions 1-9
			{
				do
				{
					if(SW4==0)
					{
						alloff();
						do
						{	
							durlay(20);		
						}while(SW4==0);	
						YELLOW2=0;
						current=4;
					}
					if(SW8==0)
					{
						alloff();
						do
						{
							durlay(20);		
						}while(SW8==0);	
						RED2=0;
						current=8;
					}
					durlay(20);
				}while(current == 7);
			}
			if(current==6)
			{
				do
				{
					if(SW9==0)
					{
						alloff();
						do
						{
							durlay(20);		
						}while(SW9==0);	
						AMBER2=0;
						current=9;
					}
					if(SW5==0)
					{
						alloff();
						do
						{
							durlay(20);		
						}while(SW5==0);	
						BLUE=0;
						current=5;
					}
					
					if(SW3==0)
					{
						alloff();
						do
						{	
							durlay(20);		
						}while(SW3==0);	
						YELLOW1=0;
						current=3;
					}
					durlay(20);
				}while(current == 6);
			}
			if(current==4)
			{
				do
				{
					if(SW7==0)
					{
						alloff();
						do
						{
							durlay(20);		
						}while(SW7==0);	
						GREEN2=0;
						current=7;
					}
					if(SW5==0)
					{
						alloff();
						do
						{
							durlay(20);		
						}while(SW5==0);	
						BLUE=0;
						current=5;
					}
					if(SW1==0)
					{
						alloff();
						RED1=0;
						do{
						durlay(20);
						}while(SW1==0);
						buzzwin();
						current=1;	
					}
					durlay(20);
				}while(current == 4);
			}
			if(current==3)
			{
				do
				{
					if(SW2==0)
					{
						alloff();
						do
						{	
							durlay(20);		
						}while(SW2==0);	
						AMBER1=0;
						current=2;
					}
					if(SW6==0)
					{
						alloff();
						do
						{	
							durlay(20);		
						}while(SW6==0);	
						GREEN1=0;
						current=6;
					}
					durlay(20);
				}while(current == 3);
			}
			if(current==2)
			{
				do
				{
					if(SW1==0)
					{
						alloff();
						RED1=0;
						do{
						durlay(20);
						}while(SW1==0);
						buzzwin();
						current=1;	
					}
					if(SW5==0)
					{
						alloff();
						do
						{
							durlay(20);		
						}while(SW5==0);	
						BLUE=0;
						current=5;
					}
					if(SW3==0)
					{
						alloff();
						do
						{	
							durlay(20);		
						}while(SW3==0);	
						YELLOW1=0;
						current=3;
					}
					durlay(20);
				}while(current == 2);
			}	
		  	if(current==1)						 //If current position is 1
		  	{
			 		alloff();					 //Turns previous LEDS off
					do{							 
					durlay(20);					 //Debounce delay
					}while(SW1==0);				 
					RED1 = 0;					 //Turns on RED1 LED
					buzzwin();					 //Call a function to generate happy sound
					win = 1;					 //Set the flag for winning the game
			}
			if(current==5)						 //If current position is 5
		  	{
			 		alloff();
					do{
					durlay(20);
					}while(SW5==0);
					BLUE = 0;
					buzz();						 //Plays loud buzz
					return;						 //Return to game menu
			}
							
		}while(win==0);							 //Loop until win flag is raised.
	}
	/*if(map==1)								 //Map lay out 1
	{
		do
		{
			
			if(current==9)
			{
				do
				{
					if(SW8==0)
					{
						alloff();
						do
						{
							durlay(20);		
						}while(SW8==0);	
						RED2=0;
						current=8;
					}
				    if(SW6==0)
					{
						alloff();
						do
						{	
							durlay(20);		
						}while(SW6==0);	
						GREEN1=0;
						current=6;
					}
					durlay(20);
				}while(current == 9);
			}
			if(current==8)
			{
				do
				{
					if(SW7==0)
					{
						alloff();
						do
						{
							durlay(20);		
						}while(SW7==0);	
						GREEN2=0;
						current=7;
					}
					if(SW5==0)
					{
						alloff();
						do
						{
							durlay(20);		
						}while(SW5==0);	
						BLUE=0;
						current=5;
					}
					if(SW9==0)
					{
						alloff();
						do
						{
							durlay(20);		
						}while(SW9==0);	
						AMBER2=0;
						current=9;
					}
					durlay(20);
				}while(current == 8);
			}
			if(current==7)
			{
				do
				{
					if(SW4==0)
					{
						alloff();
						do
						{	
							durlay(20);		
						}while(SW4==0);	
						YELLOW2=0;
						current=4;
					}
					if(SW8==0)
					{
						alloff();
						do
						{
							durlay(20);		
						}while(SW8==0);	
						RED2=0;
						current=8;
					}
					durlay(20);
				}while(current == 7);
			}
			if(current==6)
			{
				do
				{
					if(SW9==0)
					{
						alloff();
						do
						{
							durlay(20);		
						}while(SW9==0);	
						AMBER2=0;
						current=9;
					}
					if(SW5==0)
					{
						alloff();
						do
						{
							durlay(20);		
						}while(SW5==0);	
						BLUE=0;
						current=5;
					}
					
					if(SW3==0)
					{
						alloff();
						do
						{	
							durlay(20);		
						}while(SW3==0);	
						YELLOW1=0;
						current=3;
					}
					durlay(20);
				}while(current == 6);
			}
			if(current==5)
			{
				do
				{
				  	if(SW8==0)
					{
						alloff();
						do
						{
							durlay(20);		
						}while(SW8==0);	
						RED2=0;
						current=8;
					}
					if(SW4==0)
					{
						alloff();
						do
						{	
							durlay(20);		
						}while(SW4==0);	
						YELLOW2=0;
						current=4;
					}
					if(SW6==0)
					{
						alloff();
						do
						{	
							durlay(20);		
						}while(SW6==0);	
						GREEN1=0;
						current=6;
					}
					if(SW2==0)
					{
						alloff();
						do
						{	
							durlay(20);		
						}while(SW2==0);	
						AMBER1=0;
						current=2;
					}
					durlay(20);
				}while(current == 5);
			}
			if(current==4)
			{
				do
				{
					if(SW7==0)
					{
						alloff();
						do
						{
							durlay(20);		
						}while(SW7==0);	
						GREEN2=0;
						current=7;
					}
					if(SW5==0)
					{
						alloff();
						do
						{
							durlay(20);		
						}while(SW5==0);	
						BLUE=0;
						current=5;
					}
					if(SW1==0)
					{
						alloff();
						RED1=0;
						do{
						durlay(20);
						}while(SW1==0);
						buzzwin();
						current=1;	
					}
					durlay(20);
				}while(current == 4);
			}
			if(current==3)
			{
				do
				{
					if(SW2==0)
					{
						alloff();
						do
						{	
							durlay(20);		
						}while(SW2==0);	
						AMBER1=0;
						current=2;
					}
					if(SW6==0)
					{
						alloff();
						do
						{	
							durlay(20);		
						}while(SW6==0);	
						GREEN1=0;
						current=6;
					}
					durlay(20);
				}while(current == 3);
			}
		  	if(current==1)
		  	{
			 		alloff();
					do{
					durlay(20);
					}while(SW1==0);
					RED1 = 0;
					buzzwin();
					win = 1;
			}
			if(current==2)
		  	{
			 		alloff();
					do{
					durlay(20);
					}while(SW2==0);
					AMBER1 = 0;
					buzz();
					return;
			}
							
		}while(win==0);
	}*/
	return;							  //Return to game menu
	
}

void buzz()							  //Function generate loud sound
{
	int slength = 1000;				 //Length of sound
   while(slength >= 0)
		{
			SPEAKER = !SPEAKER;
			durlay(70);
			slength--;
		}
		durlay(1000);
		SPEAKER = 1; 
	return;

}
void buzzwin()						//Function generate happy sound
{
	int slength = 1000;
   while(slength >= 0)
		{
			SPEAKER = !SPEAKER;
			durlay(35);
			slength--;
		}
		durlay(1000);
		SPEAKER = 1; 
	return;

}	

void g1compare(char r, char g)
{
	int slength = 2000;      // DURATION OF SOUNDS MADE IN GAME 1
	unsigned int q = 0;
	char gue = g;

	if(r == g)           //winning sound and display
	{
		while(gue>0)         //will flash lights and make sound based on the number
		{
			q = 0;
			slength = 100;
			allon();
			durlay(5000);
			while(slength >= 0)
			{
				SPEAKER = !SPEAKER;
				durlay(50);
				SPEAKER = !SPEAKER;
				durlay(100);
				slength--;
			}
			SPEAKER = 1;
			durlay(5000);
			alloff();
			gue--;
			for(q;q<50000;q++);
		}
		return;
	}

	if(r > g)            //too low sound and lights
	{
		RED1 = 0;
		AMBER1 = 0;
		YELLOW1 = 0;
		GREEN1 = 0;
		AMBER2 = 0;
		while(slength >= 0)
		{
			SPEAKER = !SPEAKER;
			durlay(100);
			slength--;
		}
		durlay(1000);
		SPEAKER = 1; 
		RED1 = 1;
		AMBER1 = 1;
		YELLOW1 = 1;
		GREEN1 = 1;
		AMBER2 = 1;
	}

	if(r < g)             //too high sound and lights
	{
		RED1 = 0;
		AMBER1 = 0;
		YELLOW1 = 0;
		BLUE = 0;
		GREEN2 = 0;
		RED2 = 0;
		AMBER2 = 0;
		while(slength >= 0)
		{
			SPEAKER = !SPEAKER;
			durlay(10);
			slength--;
		}
		durlay(1000);
		SPEAKER = 1;
		RED1 = 1;
		AMBER1 = 1;
		YELLOW1 = 1;
		BLUE = 1;
		GREEN2 = 1;
		RED2 = 1;
		AMBER2 = 1;
	}

	return;
}
	
	
	
	
	
	