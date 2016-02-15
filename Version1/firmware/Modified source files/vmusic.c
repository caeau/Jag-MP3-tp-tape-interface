#include <system.h>
#include <boostc.h>
//#include <icd2.h>

#define JagHeadUnit


#ifdef _PIC16F877
#pragma DATA _CONFIG, _CP_OFF & _PWRTE_OFF & _WDT_OFF & _HS_OSC & _LVP_OFF & _DEBUG_OFF & _BODEN_OFF
#pragma CLOCK_FREQ 20000000
#else
#ifdef _PIC16F628A
#pragma DATA _CONFIG, _CP_OFF & _PWRTE_OFF & _WDT_OFF & _HS_OSC & _LVP_OFF & _BODEN_OFF & _MCLRE_OFF
#pragma CLOCK_FREQ 20000000
#else
#ifdef _PIC18F4520
#pragma DATA _CONFIG2L, _BOREN_OFF_2L & _PWRT_ON_2L
#pragma DATA _CONFIG4L, _STVREN_OFF_4L & _LVP_OFF_4L & _DEBUG_ON_4L & _XINST_OFF_4L
#pragma DATA _CONFIG5L, _CP0_OFF_5L & _CP1_OFF_5L & _CP2_OFF_5L & _CP3_OFF_5L
#pragma DATA _CONFIG6L, _WRT0_OFF_6L & _WRT1_OFF_6L & _WRT2_OFF_6L & _WRT3_OFF_6L
#pragma DATA _CONFIG7L, _EBTR0_OFF_7L & _EBTR1_OFF_7L & _EBTR2_OFF_7L & _EBTR3_OFF_7L
#pragma	CLOCK_FREQ 4000000
#else
#ifdef _PIC18F2550                                                                    
#pragma DATA _CONFIG1L, _PLLDIV_1_1L & _CPUDIV_OSC1_PLL2_1L                           // 4 mhz crystal 4 mhz cpu clock
#pragma DATA _CONFIG1H, _FOSC_XT_XT_1H                                                //    "     "      "    "    " 
#pragma DATA _CONFIG2L, _VREGEN_OFF_2L & _BOR_OFF_2L & _PWRT_ON_2L                    //ok
#pragma DATA _CONFIG3H, _PBADEN_OFF_3H
#pragma DATA _CONFIG4L, _STVREN_OFF_4L & _LVP_OFF_4L & _DEBUG_OFF_4L & _XINST_OFF_4L  //ok
#pragma DATA _CONFIG5L, _CP0_OFF_5L & _CP1_OFF_5L & _CP2_OFF_5L & _CP3_OFF_5L         //ok
#pragma DATA _CONFIG6L, _WRT0_OFF_6L & _WRT1_OFF_6L & _WRT2_OFF_6L & _WRT3_OFF_6L     //ok
#pragma DATA _CONFIG7L, _EBTR0_OFF_7L & _EBTR1_OFF_7L & _EBTR2_OFF_7L & _EBTR3_OFF_7L //ok
#pragma	CLOCK_FREQ 4000000
#else
#ifdef _PIC18F4550                                                                    
//#pragma DATA _CONFIG1L, _PLLDIV_1_1L & _CPUDIV_OSC1_PLL2_1L                         // 4 mhz crystal 4 mhz cpu clock
//#pragma DATA _CONFIG1H, _FOSC_XT_XT_1H                                              //    "     "      "    "    " 
//#pragma DATA _CONFIG1L, _PLLDIV_5_1L & _CPUDIV_OSC4_PLL6_1L                         // 20 mhz crystal 5 mhz cpu clock
//#pragma DATA _CONFIG1L, _PLLDIV_2_1L & _CPUDIV_OSC3_PLL4_1L                           // 8 mhz crystal 24 mhz cpu clock 
//#pragma DATA _CONFIG1H, _FOSC_HS_1H                                                   //    "     "      "    "    " 
#pragma DATA _CONFIG1L, _PLLDIV_1_1L & _CPUDIV_OSC3_PLL4_1L                           // 4 mhz crystal 24 mhz cpu clock 
#pragma DATA _CONFIG1H, _FOSC_HSPLL_HS_1H                                             //    "     "      "    "    " 

//#pragma DATA _CONFIG1L, _PLLDIV_5_1L & _CPUDIV_OSC1_PLL2_1L                           // 20 mhz crystal 20 mhz cpu clock 
//#pragma DATA _CONFIG1H, _FOSC_HS_1H                                                   //    "     "      "    "    " 
#pragma DATA _CONFIG2L, _VREGEN_OFF_2L & _BOR_OFF_2L & _PWRT_ON_2L                    //ok
#pragma DATA _CONFIG2H, _WDT_OFF_2H  & _WDTPS_4096_2H                                  // WDT reenabled 21/11/09 V1.0030 ~16SEC
#pragma DATA _CONFIG3H, _PBADEN_OFF_3H                                                //portB digital io
#pragma DATA _CONFIG4L, _STVREN_OFF_4L & _LVP_OFF_4L & _DEBUG_OFF_4L & _XINST_OFF_4L   //ok  debug turned on 25/11/09
#pragma DATA _CONFIG5L, _CP0_OFF_5L & _CP1_OFF_5L & _CP2_OFF_5L & _CP3_OFF_5L         //ok
#pragma DATA _CONFIG6L, _WRT0_OFF_6L & _WRT1_OFF_6L & _WRT2_OFF_6L & _WRT3_OFF_6L     //ok
#pragma DATA _CONFIG7L, _EBTR0_OFF_7L & _EBTR1_OFF_7L & _EBTR2_OFF_7L & _EBTR3_OFF_7L //ok
//#pragma	CLOCK_FREQ 4000000
//#pragma	CLOCK_FREQ 20000000
#pragma CLOCK_FREQ 24000000  //for 4 and 8mhz crystal
// #pragma	CLOCK_FREQ 5000000
   
#else
#ifdef _PIC18F452
#pragma DATA _CONFIG2L, _BOR_OFF_2L & _PWRT_ON_2L
#pragma DATA _CONFIG4L, _STVR_OFF_4L & _LVP_OFF_4L & _DEBUG_OFF_4L
#pragma DATA _CONFIG5L, _CP0_OFF_5L & _CP1_OFF_5L & _CP2_OFF_5L & _CP3_OFF_5L
#pragma DATA _CONFIG6L, _WRT0_OFF_6L & _WRT1_OFF_6L & _WRT2_OFF_6L & _WRT3_OFF_6L
#pragma DATA _CONFIG7L, _EBTR0_OFF_7L & _EBTR1_OFF_7L & _EBTR2_OFF_7L & _EBTR3_OFF_7L
#pragma	CLOCK_FREQ 4000000
#else
#error "Only _PIC16F628A _PIC16F877 _PIC18F4520 _PIC18F2550 _PIC18F4550 and _PIC18F452 devices supported"
#endif // _PIC16F628A
#endif // _PIC16F877
#endif // _PIC18F452
#endif // _PIC18F4520
#endif // _PIC18F2550
#endif // _PIC18F4550

#include "LCD.h"
#include "monitor.h"
#include "tape_emu.h"

rom char *msgBanner1 = "VIPER MP3 V1.100";
rom char *msgBanner2  = "18F4550 @ 24MHZ   ";
rom char *msgError6 = "ERROR ";
rom char *msgNoDisk = "N O  D I S K !  ";
rom char *msgPlay8 = "Playing ";
rom char *msgStop8 = "Stopped ";
rom char *msgPause8 = "Paused  ";
rom char *msgPowerDown10 = "Power Down";
rom char *msgPowerUp8 = "Power Up";
rom char *msgNoFirmware = "No FW file found";
rom char *msgFirmware =   "Updating F/Ware ";

// timer to ensure file information scrolls at good speed
#define STATUS_TIMER 6000	//1000 for 4MHZ 4000 for 16MHZ 5000 for 20MHZ 6000 for 24MHZ
// wait for a prompt to be received before scanning input lines
#define STATUS_WAITPROMPT 0
// wait for both R.in and R.in lines to be released before scanning buttons
#define STATUS_WAITCONTROL 1
// device is playing
#define STATUS_PLAY       2
// end of file information in bufInfo reached
#define STATUS_SCROLLEND  3
// reset file information display
#define STATUS_RESET      4
// playing side 
#define STATUS_SIDE      5
// USB stick has been ejected
#define STATUS_BEEN_ASLEEP    6

char bufInfo[64],data,current;
unsigned char opStatus ,side = 0,cassetteStatus = 0x04, button_press = 0; //cassetteStatus =04 = cassteetStatus.IGN = ON
unsigned int play_type = SEQUENTIAL;  // 0 = normal play 1 = random
unsigned long key_press_time = 0;


//***************************************************************************


void checkForUpdate()
{
  unsigned char fileName[] = {1,2,3,4,5,6,7,8};
  unsigned char *pfileName = &fileName[0];
  unsigned char monCount = sizeof(fileName); //8;
  monWrite(CMD_DIR);
	if (monCount--)
	{
		monWrite(' ');
		monWrite(*pfileName++);
		while (monCount--)
		{
		 monWrite(*pfileName++);
		};
	}
	monWrite(0x0d);
  
}


//***************************************************************************
//
// Name: intfaceInit
//
// Description: Init the Jag radio interface board.
//
// Parameters: None
//
// Returns: None.
//
// Comments: 
//
//***************************************************************************
void intfaceInit()
{
#ifdef _PIC18F4550
	  // following 2 lines disable USB on PIC18 and allow C4 and C5 to be input  
    ucfg.UTRDIS = 1;
    ucon.3 = 0;
#endif
    adcon1 = 0x0F;   // make all port a digital i/o


      // set port direction
 //   TRIS_CASSETTE_CUE_PLAY = IN;      //cue/play H = cue L= play
    TRIS_CASSETTE_PAUSE = OUT;      // pause
    TRIS_CASSETTE_RUN_DET_F = OUT;	  // run det f	
    TRIS_CASSETTE_MODE = OUT;      // mode
    TRIS_CASSETTE_RUN_DET_R = OUT;      // run det r
    TRIS_CASSETTE_F_IN = IN;      // F.In
    TRIS_CASSETTE_R_IN = IN;      // R.In
    TRIS_VINCULUM_POWER = OUT;	  // Make E0 output vinculum power
  //  TRIS_VINCULUM_RI = OUT;
    TRIS_CASSETTE_FOR_REW = IN;      // For/Rew H = side2 L = side1
    TRIS_CASSETTE_PACK_IN = OUT;
    TRIS_CASSETTE_MUSIC_DET = OUT;
    // TRIS_MOTOR_O no tris statement for porte.3
   
      //Init output ports
    VINCULUM_POWER = VINCULUM_ON;
  //  VINCULUM_RI = 0;
    CASSETTE_PAUSE = PAUSED;		//cassette paused
  	CASSETTE_MODE = IDLE;				// mode idle = H
    CASSETTE_PACK_IN = PACK_UNLOAD;
    CASSETTE_RUN_DET_F = 1;			//start H make f and r out of phase
    CASSETTE_RUN_DET_R = 0;         //start L
    CASSETTE_MUSIC_DET = 0;
    
    // Set up timer 0 approx 170ms
    clear_bit(t0con,TMR0ON);	// stop timer 0
    clear_bit(t0con,T08BIT);	// 16 bit timer
    clear_bit(t0con,T0CS);		// int clock
    clear_bit(t0con,PSA);		// prescaler on
    set_bit(t0con,T0PS0);		//set prescale 1:16 170ms approx with 24mhz clock
    set_bit(t0con,T0PS1);		//     "
    clear_bit(t0con,T0PS2);		//     "
    tmr0l = 0x00;		    // set low byte
    tmr0h = 0x00;           // set high byte
         
    side = SIDE1;
     // enable interrupts
	set_bit(intcon,TMR0IE); //enable TMR0 overflow bit    
	set_bit(intcon,INT0IE); //enable INT0 
	set_bit(intcon,INTEDG0); //int on riseing edge (when ign turned on)
	set_bit(intcon,GIE);
     
    clear_bit(osccon,IDLEN);   // PIC go to sleep mode on sleep command
    set_bit(wdtcon,SWDTEN);    // Set WDT on by software
}

//***************************************************************************
//
// Name: changeSideStatus
//
// Description: 
//
// Parameters: None
//
// Returns: None.
//
// Comments: 
//
//***************************************************************************
void changeSideStatus()
{
   if (side == SIDE1)
     {
       side = SIDE2;
     }
     else if (side == SIDE2)
     {
       side = SIDE1;
     }
}


//***************************************************************************
//
// Name: powerDown
//
// Description: Powers down when ign switched off and no disk
//
// Parameters: None
//
// Returns: None.
//
// Comments: Puts PIC to sleep and turns off power to Vinculum , wakes PIC and
//           repowers Vinculum when ign switched back on. Disk must be re inserted.
//           Has no effect if disk not removed.
//
//***************************************************************************
void powerDown()
  {
       char i;

	lcdInsWrite(LCD_CLR);
	delay_ms(2);

	lcdInsWrite(LCD_LINE1);
	for (i = 0; i < 10; i++)
	{
		lcdDataWrite(msgPowerDown10[i]);
	}

	// zero out remaining space in buffer
	for (i = 0; i < 64; i++)
	{
		bufInfo[i] = '\0';
	};
    delay_s(5);
      
	  VINCULUM_POWER= VINCULUM_OFF;
	  clear_bit(intcon,GIE);          //disable interrupts, so code continues here after sleep
	  clear_bit(wdtcon,SWDTEN);       // turn WDT off so it does not wakeup pic
	  sleep();                        // pic to sleep
	  VINCULUM_POWER = VINCULUM_ON;
	  set_bit(intcon,GIE);            //reenable interrupts, when wakeup
	  set_bit(opStatus,STATUS_BEEN_ASLEEP);
      reset();
      set_bit(wdtcon,SWDTEN);         //turn WDT on
    lcdInsWrite(LCD_CLR);
	delay_ms(2);

	lcdInsWrite(LCD_LINE1);
	for (i = 0; i < 8; i++)
	{
		lcdDataWrite(msgPowerUp8[i]);
	}

	// zero out remaining space in buffer
	for (i = 0; i < 64; i++)
	{
		bufInfo[i] = '\0';
	};
    delay_s(5);  
  }



//***************************************************************************
//
// Name: SideOnefastForwardEmu
//
// Description: Forward to next file in folder when FF button pressed, side1
//
// Parameters: None
//
// Returns: None.
//
// Comments: 
//
//***************************************************************************
void sideOnefastForwardEmu()
{
         delay_ms(500);
	     CASSETTE_MUSIC_DET = HIGH;
	     delay_ms(250);
	     CASSETTE_MUSIC_DET = LOW;
	     delay_ms(250); 
	     CASSETTE_MUSIC_DET = HIGH;
	     delay_ms(250);
	     CASSETTE_MUSIC_DET = LOW; 
	     delay_ms(250);
	     CASSETTE_MUSIC_DET = HIGH;
	     delay_ms(250);
	     CASSETTE_MUSIC_DET = LOW;     
	       while (!CASSETTE_F_IN)   //wait for fin to go high
	          {
	          }
	       stopFastReelPulses();
	       delay_ms(100);
	       CASSETTE_MODE = LOW;
	       delay_ms(160);
	       CASSETTE_MODE = HIGH;    
	       delay_ms(50);
	         while(CASSETTE_R_IN )     //wait for rin to go low
	                 {
	                 }              
	           startFastReelPulses();
	           delay_ms(500);
	           CASSETTE_MUSIC_DET = HIGH;
	           delay_ms(250);
	           CASSETTE_MUSIC_DET = LOW;
	           delay_ms(250);
	           CASSETTE_MUSIC_DET = HIGH;
	           delay_ms(250);
	           CASSETTE_MUSIC_DET = LOW; 
	           delay_ms(250);
	           CASSETTE_MUSIC_DET = HIGH;
	           delay_ms(250);
	           CASSETTE_MUSIC_DET = LOW;
	             while (!CASSETTE_F_IN)    // wait for fin to go high
	                {
	                }
	             stopFastReelPulses();
	             delay_ms(70);
	             CASSETTE_MODE = LOW;
	             delay_ms(120);
	             CASSETTE_MODE = HIGH;
	             delay_ms(60);
	             CASSETTE_MODE = LOW;
	             delay_ms(90);
	             CASSETTE_MODE = HIGH;
	             delay_ms(50);
	                while (CASSETTE_R_IN)
	                  {
	                  }
	               startReelPulses();
	               delay_ms(100);
	               CASSETTE_MUSIC_DET = HIGH;
	               delay_ms(600);
	               CASSETTE_MUSIC_DET =LOW;  
	                 // send skip forward to play next track
					monCmdSend(CMD_VSF);
					opStatus.STATUS_WAITPROMPT = 1;
					opStatus.STATUS_WAITCONTROL = 1;
					opStatus.STATUS_RESET = 1;  
}



//***************************************************************************
//
// Name: SideTwofastForwardEmu
//
// Description: Forward to next file in folder when FF button pressed, side1
//
// Parameters: None
//
// Returns: None.
//
// Comments: 
//
//***************************************************************************
void sideTwofastForwardEmu()
{
         delay_ms(500);
	     CASSETTE_MUSIC_DET = HIGH;
	     delay_ms(250);
	     CASSETTE_MUSIC_DET = LOW;
	     delay_ms(250); 
	     CASSETTE_MUSIC_DET = HIGH;
	     delay_ms(250);
	     CASSETTE_MUSIC_DET = LOW; 
	 //    delay_ms(250);
	 //    CASSETTE_MUSIC_DET = HIGH;
	 //    delay_ms(250);
	 //    CASSETTE_MUSIC_DET = LOW;   
     while (!CASSETTE_R_IN)     //wait for rin to go high
       {
       }
     stopFastReelPulses();
     delay_ms(60);
     CASSETTE_MODE = LOW;
     delay_ms(180);
     CASSETTE_MODE = HIGH;
       while (!CASSETTE_F_IN)
         {
         }
       while (CASSETTE_F_IN)
          {
          }
       startFastReelPulses();
  //     delay_ms(100);         //09/10 was 500
      CASSETTE_MUSIC_DET = HIGH;
        while (!CASSETTE_F_IN)
            {
            }
         delay_ms(20);
         stopFastReelPulses();
         delay_ms(80);
         CASSETTE_MODE = LOW;
         delay_ms(160);
         CASSETTE_MODE = HIGH;
         delay_ms(80);
         CASSETTE_MODE = LOW;
         delay_ms(120);
         CASSETTE_MODE = HIGH;
            while (CASSETTE_F_IN)
              {
              }
            startReelPulses();
            delay_ms(50);        //09/10 was 500
            CASSETTE_MUSIC_DET = LOW;
     
       /*   removed 09/10 seems ok
            delay_ms(100);       //09/10 was 500
            CASSETTE_MUSIC_DET =HIGH;
            delay_ms(100);       //09/10 was 400
            CASSETTE_MUSIC_DET = LOW;
        */
                      // send skip forward to play next track
					monCmdSend(CMD_VSF);
					opStatus.STATUS_WAITPROMPT = 1;
					opStatus.STATUS_WAITCONTROL = 1;
					opStatus.STATUS_RESET = 1;  
	                      
}

//***************************************************************************
//
// Name: FastRewindEmu
//
// Description: Back to previous file in folder when FR button pressed.
//
// Parameters: None
//
// Returns: None.
//
// Comments: This routine is used for both side1 and side 2 FR
//
//***************************************************************************
void fastRewindEmu()
{
    startFastReelPulses();
     delay_s(1);
     CASSETTE_MUSIC_DET = HIGH;
	       while (!CASSETTE_F_IN)   //wait for fin to go high
	          {
	          }
	       stopFastReelPulses();
	       delay_ms(100);
	       CASSETTE_MODE = LOW;
	       delay_ms(120);
	       CASSETTE_MODE = HIGH;    
	       delay_ms(60);
	       CASSETTE_MODE = LOW;
	       delay_ms(100);
	       CASSETTE_MODE = HIGH;
	  //        while(CASSETTE_R_IN )     //wait for rin to go low
	   //               {
	   //               }              
	          
	           startReelPulses();
	           delay_ms(500);
	           CASSETTE_MUSIC_DET = LOW;
	           delay_ms(250);
	           CASSETTE_MUSIC_DET = HIGH;
	           delay_ms(250);
	           CASSETTE_MUSIC_DET = LOW; 
	           delay_ms(250);
	           CASSETTE_MUSIC_DET = HIGH;
	           delay_ms(250);
	           CASSETTE_MUSIC_DET = LOW;
	           
	                 // send skip backward to play previous track
					monCmdSend(CMD_VSB);     //skip to beginning of current track
					delay_ms(500);
					monCmdSend(CMD_VSB);     //skip to beginning of previous track
					opStatus.STATUS_WAITPROMPT = 1;
					opStatus.STATUS_WAITCONTROL = 1;
					opStatus.STATUS_RESET = 1;  
	                
}





//***************************************************************************
//
// Name: cassette Load Emulation
//
// Description: Emulates a cassette being inserted into player.
//
// Parameters: None.
//
// Returns: None
//
// Comments:  1) Raise pack in (pin 12)(processor pin LOW) when USB drive inserted (cassette inserted)
//            2) Look for F.In to go high, followed by R.In going high.
//            3) Take mode line (pin4) low.
//            4) Look for F.In and R.In to both go low.
//            5) Look for R.In to go high.
//            6) Wait 120ms raise mode line  (pin4).
//            7) Look for Motor.o to go high, Turn timer 0 on Turn off when Motor.o goes low.
//            8) Wait for Motor.o to go high then turn timer 0 on, when it goes low again turn timer 0 off.
//            9) Look for F.In to go high, wait 140ms, take mode low for 80ms, high for 80ms
//               low for 170ms, high for 80ms, low for 110 ms, high for 80ms then low for 90ms
//           10) Wait for Motor.o to go high, then turn timer 0 on.               
//  
//***************************************************************************
void cassetteLoadEmu()
{
	CASSETTE_PACK_IN = PACK_LOAD;		//pack in line high, pack in switched open, cassette inserted.
	 while (!CASSETTE_F_IN);			//wait for F.IN to go high, load motor forward.
	    {
	    }
	   delay_ms(900);
	   CASSETTE_PAUSE = PLAYING;		//take pause line high, cassette loaded
	   delay_ms(20);
	   CASSETTE_MODE = 0;			//mode line low, mode switch position 1
	   while (!CASSETTE_R_IN);			//wait for R.IN to go high, brake load motor.
	       {
	       }
             while (CASSETTE_F_IN && CASSETTE_R_IN);
	             {
	             }
	               while (!CASSETTE_R_IN);	//wait for R.IN to go high, load motor reverse.
	                  {
	                  }
	                     delay_ms(40);
	                     CASSETTE_MODE = 1;			//mode line high, mode position 1
	                       delay_ms(80);		    //short delay
	                       CASSETTE_PAUSE = PAUSED;	//pause line low, pause switch now closed.
	                      while (!CASSETTE_MOTOR_O);	//wait for motor on command
	                          {
	                          }
	                            while(CASSETTE_MOTOR_O);
	                              startReelPulses();
	                              // set_bit(t0con,TMR0ON);		//turn timer 0 on to simulate reel pulses while motor.o high 
	                               stopReelPulses();
	                               //  clear_bit(t0con,TMR0ON);   //turn off pulses when motor.o goes low
	                                   while (!CASSETTE_MOTOR_O); //wait for motor.o to go high again
	                                     {
	                                     }
	                                   while(CASSETTE_MOTOR_O);
	                                     startReelPulses();
	                                   //  set_bit(t0con,TMR0ON);  	 //keep reel pulses going while motor.o is high
	                                     stopReelPulses();                                   
	                                   // clear_bit(t0con,TMR0ON); 	// stop reel pulses
	                                    while (!CASSETTE_F_IN);		//wait for F.IN to go high, load motor forward
	                                      {
	                                      }
	                                      delay_ms(10);			//20	//short delay (to emulate mechanics moving)
	                                      CASSETTE_PAUSE = PLAYING; //pause line high, tape playing 
	                                      delay_ms(20);		//120	//delay to emulate mechanism
	                                      CASSETTE_MODE = 0;        // next 15 lines simulate the 4 mode switch positions
	                                      delay_ms(10);			//80
	                                      CASSETTE_MODE = 1;
	                                      delay_ms(10);			//80
	                                      CASSETTE_MODE = 0;
	                                      delay_ms(20);		//170
	                                      CASSETTE_MODE = 1;
	                                      delay_ms(10);			//80
	                                      CASSETTE_MODE = 0;
	                                      delay_ms(20);		//110
	                                      CASSETTE_MODE = 1;
	                                      delay_ms(10);			//80
	                                      CASSETTE_MODE =0;
	                                      delay_ms(10);			//90
	                                      CASSETTE_MODE = 1;
	                                         while (!CASSETTE_MOTOR_O)	//wait for motor.on to go high
	                                          {
	                                          }
	                                           startReelPulses();
         	                                      //  set_bit(t0con,TMR0ON); //turn on timer0 to generate reel pulses
 }

//***************************************************************************
//
// Name: cassette Eject Emulation
//
// Description: Emulates a cassette being ejected from player.
//
// Parameters: None.
//
// Returns: None
//
// Comments: Mode line does not need to be pulsed, HU just looks for pause 
//            
//***************************************************************************
/*
void cassetteEjectEmu()
{
	while(!CASSETTE_R_IN)		//wait for R.IN to be high, reverse load motor
	{
	}
	    delay_ms(90);			//90	//short delay (to emulate mechanics moving)
	    CASSETTE_MODE = 0;        // next 15 lines simulate the 4 mode switch positions
	    delay_ms(160);          //160   // assuming we are playing side 1, side 2 would have 3 switch positions 
	    CASSETTE_MODE = 1;
	    delay_ms(80);			//80
	    CASSETTE_MODE = 0;
	    delay_ms(110);			//110
	    CASSETTE_MODE = 1;
	    delay_ms(80);			//80		
	    CASSETTE_MODE = 0;
	    delay_ms(170);			//170
	    CASSETTE_MODE = 1;
	    delay_ms(80);			//80
	    CASSETTE_MODE =0;
	    delay_ms(90);			//90
	    CASSETTE_MODE = 1;
	    delay_ms(20);			//20
	    CASSETTE_PAUSE = PAUSED;
	    stopReelPulses();
	    delay_ms(120);			//120
	    CASSETTE_PACK_IN = PACK_UNLOAD;
	      monCmdSend(CMD_VST);
		  opStatus.STATUS_WAITPROMPT = 1;
		  opStatus.STATUS_WAITCONTROL = 1;
       reset();                  //21/11/09 test to see if we can reset pic with eject button
}
*/

//***************************************************************************
//
// Name: AM/FM button Emulation
//
// Description: Emulates the AM/FM button being pressed.
//
// Parameters: None.
//
// Returns: None
//
// Comments:  
//  
//***************************************************************************
void amfmButtonEmu()
{
	while(!CASSETTE_R_IN)		//wait for R.IN to be high, reverse load motor
	   {
	   }
	    delay_ms(20);			//90	//short delay (to emulate mechanics moving)
	    CASSETTE_MODE = 0;        // next 15 lines simulate the 4 mode switch positions
	    delay_ms(20);          //160   // assuming we are playing side 1, side 2 would have 3 switch positions 
	    CASSETTE_MODE = 1;
	    delay_ms(10);			//80
	    CASSETTE_MODE = 0;
	    delay_ms(20);			//110
	    CASSETTE_MODE = 1;
	    delay_ms(10);			//80		
	    CASSETTE_MODE = 0;
	    delay_ms(20);			//170
	    CASSETTE_MODE = 1;
	    delay_ms(10);			//80
	    CASSETTE_MODE =0;
	    delay_ms(20);			//90
	    CASSETTE_MODE = 1;
	    delay_ms(10);			//20
	    CASSETTE_PAUSE = PAUSED;
	    stopReelPulses();
	    delay_ms(20);			//120
	 //   CASSETTE_PACK_IN = PACK_UNLOAD;
	      monCmdSend(CMD_VP);
		  opStatus.STATUS_PLAY = 0;   //paused
		  opStatus.STATUS_WAITPROMPT = 1;
		  opStatus.STATUS_WAITCONTROL = 1;
}






//***************************************************************************
// Name: rspPlaying
//
// Description: Load file information from Playing message.
//
// Parameters: None.
//
// Returns: None.
//
// Comments: bufInfo filled with available file information.
//           If ID3 tags: Song Name and Artist Name.
//           No ID3 tags: Filename
//
//***************************************************************************
void rspPlaying()
{
	unsigned char i, j;
	char data;

	// load filename from Playing... message
	// include carriage return at position 12
	for (j = 0; j < 13; j++)
	{
		data = spiReadWait();  //read a byte from spi into data 
		if (data == 0x0d)      //if CR break
			break;
		bufInfo[j] = data;     //store data in next byte of buffer
	}

    // load info from ID3 tags
	i = 0;
	
    // track number - ignore
	while (1)
	{
		data = spiReadWait();
		if (data == 0x0d)
			break;
	}

    // song name
	while (1)
	{
		data = spiReadWait();
		if (data == 0x0d)
			break;
		if (i < 64) bufInfo[i++] = data;
	}

	if (i)
	{
		if (i < 64) bufInfo[i++] = ' ';
		if (i < 64) bufInfo[i++] = '-';
		if (i < 64) bufInfo[i++] = ' ';
	}

    // artist name
	while (1)
	{
		data = spiReadWait();
		if (data == 0x0d)
			break;
		if (i < 64) bufInfo[i++] = data;
	}

    // album name - ignore
	while (1)
	{
		data = spiReadWait();
		if (data == 0x0d)
			break;
	}

    // composer - ignore
	while (1)
	{
		data = spiReadWait();
		if (data == 0x0d)
			break;
	}

	// no ID3 tags so use filename instead
	if (!i)
		i = j;

	// zero out remaining space in buffer
	while (i < 64)
	{
		bufInfo[i++] = '\0';
	};
}

//***************************************************************************
// Name: rspTime
//
// Description: Load time information from Time message and update LCD.
//
// Parameters: None.
//
// Returns: None.
//
// Comments: "Playing hh:mm:ss" status information written to LCD.
//
//***************************************************************************
void rspTime()
{
	unsigned char digit;
	unsigned short playTime;
	char i;

	playTime = spiReadWait();
	playTime |= (spiReadWait() << 8);
	// carriage return
	spiReadWait();

	// playing response message - 6 lines of data
	lcdInsWrite(LCD_LINE1);
	for (i = 0; i < 8; i++)
	{
		lcdDataWrite(msgPlay8[i]);
	}

	digit = '0';
	while (playTime >= 36000)
	{
		playTime -= 36000;
		++digit;
	}
	lcdDataWrite(digit);

	digit = '0';
	while (playTime >= 3600)
	{
		playTime -= 3600;
		++digit;
	}
	lcdDataWrite(digit);

	lcdDataWrite(':');

	digit = '0';
	while (playTime >= 600)
	{
		playTime -= 600;
		++digit;
	}
	lcdDataWrite(digit);

	digit = '0';
	while (playTime >= 60)
	{
		playTime -= 60;
		++digit;
	}
	lcdDataWrite(digit);

	lcdDataWrite(':');

	digit = '0';
	while (playTime >= 10)
	{
		playTime -= 10;
		++digit;
	}
	lcdDataWrite(digit);

	digit = '0' + playTime;
	lcdDataWrite(digit);
}

//***************************************************************************
// Name: rspStopped
//
// Description: Update LCD with Stopped message.
//
// Parameters: None.
//
// Returns: None.
//
// Comments: LCD cleared and "Stopped" message written.
//
//***************************************************************************
void rspStopped()
{
	char i;

	lcdInsWrite(LCD_CLR);
	delay_ms(2);

	lcdInsWrite(LCD_LINE1);
	for (i = 0; i < 8; i++)
	{
		lcdDataWrite(msgStop8[i]);
	}

	// zero out remaining space in buffer
	for (i = 0; i < 64; i++)
	{
		bufInfo[i] = '\0';
	};
}

//***************************************************************************
// Name: rspPaused
//
// Description: Update LCD with Paused message.
//
// Parameters: None.
//
// Returns: None.
//
// Comments: "Paused" message written to LCD.
//
//***************************************************************************
void rspPaused()
{
	char i;

	lcdInsWrite(LCD_LINE1);
	for (i = 0; i < 8; i++)
	{
		lcdDataWrite(msgPause8[i]);
	}
}

//***************************************************************************
// Name: rspNoDisk
//
// Description: No Disk message scrolled across LCD.
//
// Parameters: None.
//
// Returns: None.
//
// Comments: "No Disk" message written to LCD.
//           static variable statusPos used to effect scroll left when
//           called repeatedly from main routine.
//
//***************************************************************************
void rspNoDisk()
{
	static char statusPos = 0;
	char i;
	char data;
        
    lcdInsWrite(LCD_LINE1);
	for (i = 0; i < 16; i++)
	{
		data = ((statusPos + i) & 0x0f);  //scroll message on lcd ??????
		lcdDataWrite(msgNoDisk[data]);
	}
	delay_ms(200);
	statusPos++;
}

//***************************************************************************
// Name: opError
//
// Description: Display an error message on the LCD.
//
// Parameters: errNo - error code to display.
//
// Returns: None.
//
// Comments: Displays error as a 2 digit hex code. "ERROR xx"
//
//***************************************************************************
void opError(char errNo)
{
	char i;

	lcdInsWrite(LCD_CLR);
	delay_ms(2); 

	lcdInsWrite(LCD_LINE1);

	for (i = 0; i < 6; i++)
	{
		lcdDataWrite(msgError6[i]);
	}

	if ((errNo>>4) > 9)
		lcdDataWrite((errNo>>4)-10+'A');
	else
		lcdDataWrite((errNo>>4)+'0');

	if ((errNo&0xf) > 9)
		lcdDataWrite((errNo&0xf)-10+'A');
	else
		lcdDataWrite((errNo&0xf)+'0');

	delay_s(1);
}



//***************************************************************************
// Name: opStatus
//
// Description: Display file information on LCD.
//
// Parameters: None.
//
// Returns: None.
//
// Comments: static statusDelay used to time speed of text scrolliong.
//           static statusPos stores position in file information buffer.
//           Scroll holds for 8 counts before shifting data from bufInfo
//           onto LCD.
//
//***************************************************************************
void opStatus()
{
	static unsigned short statusDelay = 0;
	static char statusPos = 0;
	char data;
	char i;

	if (opStatus.STATUS_RESET)
	{
		statusPos = 0;
		statusDelay = 0;
		opStatus.STATUS_RESET = 0;
	    opStatus.STATUS_PLAY = PLAYING;		//cgk 01/10/09
	    opStatus.STATUS_SIDE = SIDE1;       //cgk 01/10/09
	}

	// scroll through information buffer
	if (statusDelay)
	{
		statusDelay--;
	}
	else
	{
		statusDelay = STATUS_TIMER;
		if (bufInfo[0])
		{
			lcdInsWrite(LCD_LINE2);
			opStatus.STATUS_SCROLLEND = 1;

			for (i = 0; i < 16; i++)
			{
				// delay start of scroll by 8 counts to allow
				// time to read information
				if (statusPos < 8)
				{
					data = bufInfo[i];
				}
				else if (i + statusPos < 64 + 8)
				{
					data = bufInfo[i + statusPos - 8];
				}
				else
				{
					data = 0;
				}

				// detect run-on past end of buffer and pad with spaces
				if (!data)
				{
					data = ' ';
					if (i == 0)
					{
						opStatus.STATUS_SCROLLEND = 0;
					}
				}

				lcdDataWrite(data);
			}

			// continue or restart scrolling
			if (opStatus.STATUS_SCROLLEND)
			{
				statusPos++;
			}
			else
			{
				statusPos = 0;
			}
		}
	}
}




//***************************************************************************
// Name: jagControl (Modified opControl for Jaguar XJ8 cassette emulation by C G Kennedy)
//
// Description: Handle F.In and R.In from radio.
//
// Parameters: None.
//
// Returns: None.
//
// Comments: static previous for stored control line state to detect changes.
//           static vol used to store previous volume setting.
//           While stopped: 
//           While playing: 
//                          
//                          
//                          
//
//***************************************************************************
#ifdef JagHeadUnit
void jagControl()
{
	static unsigned char previous = 0x00;
	static unsigned char vol = 0xff;
	char data;
     //*****NOTE*****
     //
     // CURRENT CONTAINS THE CURRENT VALUE OF THE INPUT, AND PREVIOUS CONTAINS THE PREVIOUS VALUE
     //
     //
    // if we have prompt check input on F.in and R.in lines (also motor.o, side , for/rew and cue/play)
	if (!opStatus.STATUS_WAITPROMPT)	//if zero(ie we have a prompt) start checking inputs
	{
		
	    // set volume level in Vinculum
		data = 0x00;		// 00 = loudest ff = softest
		if (vol != data)    //
		{
			monCmdSendByteParam(CMD_VSV, data);
			vol = data;
			opStatus.STATUS_WAITPROMPT = 1;
		}
		else
		{
			// poll for F.in and R.in changes
			current = 0;
			current.CONTROL_FIN = CASSETTE_F_IN;    
			current.CONTROL_RIN = CASSETTE_R_IN;    
  
  // 30/09/09 this routine works ok for reverse motor
  // if playing side1 we are in mode position 4, 5 counting pause position
  if((current.CONTROL_RIN == HIGH) && (previous.CONTROL_RIN == LOW))  //rin has gone high 
	{
	 delay_ms(50);
	 if ((current.CONTROL_FIN == LOW) && (previous.CONTROL_FIN == LOW)) //fin stayed low  
      // load motor reverse	  
	  {
	    
              //***********************************First pulse reverse ***********************************
              //    Used for side skip forward a folder (change from side1 to side2 to side1)
	     
	        CASSETTE_MODE = LOW;    //start first mode pulse
	        delay_ms(110);
	        CASSETTE_MODE = HIGH;   // end first mode pulse, now at position
	        delay_ms(50);           //wait for pulse to settle high 
	          if (CASSETTE_F_IN == HIGH)   // Fin just went high, brake
	           {
	            
	            while (CASSETTE_F_IN);    //wait for fin to go low, motor stop, now at position 3 side2
	               {
	               }
	             cassetteStatus.CURRENT_FOR_REW = CASSETTE_FOR_REW; 
	             if (cassetteStatus.CURRENT_FOR_REW != cassetteStatus.PREVIOUS_FOR_REW)    //side button has been pressed
	                {
	                 if (key_press_time >= 30)			//~5 seconds since last side select pressed
	                   {
	                     monCmdSend(CMD_VSD);           // forward a folder 
			             opStatus.STATUS_WAITPROMPT = 1;
				         opStatus.STATUS_WAITCONTROL = 1;
				         opStatus.STATUS_RESET = 1;
	                     changeSideStatus();        //side = ~side;
	                     cassetteStatus.PREVIOUS_FOR_REW = cassetteStatus.CURRENT_FOR_REW;
	                     key_press_time = 0;
	                     goto finished_r;
	                   }  
	                     if (play_type == SEQUENTIAL)             //if normal play
	                       { 
	                         monCmdSend(CMD_VRR);	//random play		
	                         play_type = RANDOM;
	                       } 
	                         else if(play_type == RANDOM)	//if random play
	                          {
	                            monCmdSend(CMD_VRA);	//normal play
	                            play_type = SEQUENTIAL;
	                          }  
			          opStatus.STATUS_WAITPROMPT = 1;
				      opStatus.STATUS_WAITCONTROL = 1;
				      opStatus.STATUS_RESET = 1;
	                  changeSideStatus();       //side = ~side;
	                  cassetteStatus.PREVIOUS_FOR_REW = cassetteStatus.CURRENT_FOR_REW;
	                  key_press_time = 0;
	                  goto finished_r;
	                }
	              startFastReelPulses();
	              sideTwofastForwardEmu();   //FF pressed on side 2
	              goto finished_r;           
	            }          
	        delay_ms(30);                  //inter pulse gap
                //***********************************Second pulse reverse ***********************************
                //    Used for side1 FR and side2 FR
	        CASSETTE_MODE = LOW;
	        delay_ms(100);
	        CASSETTE_MODE = HIGH;
	        delay_ms(50);
	            if (CASSETTE_F_IN == HIGH)   // Fin just went high, brake
	             {
	               while (CASSETTE_F_IN)        //wait for fin to go low
	                 {
	                 }
	              fastRewindEmu();
	              goto finished_r;
	             }
	        delay_ms(30);                   //inter pulse gap
               //***********************************Third pulse reverse *************************************
               //    Used for side1 FF and side2 pause (AM/FM)
	        stopReelPulses();         // for fast forward emu
	        CASSETTE_MODE = LOW;
	        delay_ms(100);
	        CASSETTE_MODE = HIGH;
	        delay_ms(50);
	         if (side == SIDE1)                //then fastforward, else pause /eject
	           {
	              if (CASSETTE_F_IN == HIGH)   // Fin just went high, brake
	               {
	                while (CASSETTE_F_IN)
	                  {
	                  }
	                startFastReelPulses();
	                sideOnefastForwardEmu();
	                goto finished_r;
	               }
	           } 
	              if (CASSETTE_F_IN == HIGH)
	                {
	                  delay_ms(60);
	                   if (CASSETTE_PAUSE == PAUSED)
	     	            {
	     	              goto finished_r;
	     	            }       
	                   CASSETTE_PAUSE = PAUSED;      //now at pause position
	     	           stopReelPulses();
	                   delay_s(1);
	                  if(CASSETTE_R_IN == HIGH)   //rin has gone high therefore eject
	                   {
	                    CASSETTE_PACK_IN = PACK_UNLOAD;  // all that is needed for eject emulation
	                    monCmdSend(CMD_VST);            //pause = VP  stop = VST
		             //   reset();                  // added 21/11/09***********************
		                goto finished_r;
	                   }			
	                 monCmdSend(CMD_VP);      //rin still low so pause
		             rspPaused();    
		             opStatus.STATUS_WAITPROMPT = 1;
		             opStatus.STATUS_WAITCONTROL = 1;
	               }
	            
	        delay_ms(30);
               //***********************************Fourth pulse reverse ***********************************
               //    Used by side1 eject and pause
	        CASSETTE_MODE = LOW;
	        delay_ms(100);
	        CASSETTE_MODE = HIGH;
	        delay_ms(50);         //middle of fin pulse 02/10/09 was 10ms 
	       	   if (CASSETTE_PAUSE == PAUSED)
	     	      {
	     	        goto finished_r;
	     	      }       
	             CASSETTE_PAUSE = PAUSED;      //now at pause position
	     	     stopReelPulses();
	             delay_s(1);
	             if(CASSETTE_R_IN == HIGH)   //rin has gone high therefore eject
	                 {
	                    CASSETTE_PACK_IN = PACK_UNLOAD;  // all that is  needed for eject emulation
	                    monCmdSend(CMD_VST);            //pause = VP  stop = VST
		               // reset();
		                goto finished_r;
	                 }			
	             monCmdSend(CMD_VP);      //rin still low so pause
		         rspPaused();    
		         opStatus.STATUS_WAITPROMPT = 1;
		         opStatus.STATUS_WAITCONTROL = 1;
	     
	      finished_r:
	      delay_s(1);    //wait for fin and rin to release    
	  }  //fin stayed low
	}    //rin high

    	//**************************load motor forward routine for push buttons on hu****************************************
	    //if paused we are in mode position 0 
	
	else if ((current.CONTROL_FIN == HIGH) && (previous.CONTROL_FIN == LOW))  //fin has gone high 
	  {
	    if ((current.CONTROL_RIN == LOW) && (previous.CONTROL_RIN == LOW)) //rin stayed low 
	     //load motor forward, will only happen to change from side2 to side1
	     {
	      if (CASSETTE_PAUSE = PAUSED)
	        {
	         CASSETTE_PAUSE = PLAYING;  //so we can load disk again with tape button
	        }
                //*********************************First pulse forward**************************************
                //    Used for side change to side1 from side2
	        CASSETTE_MODE = LOW;    //start first mode pulse
	        delay_ms(110);
	        CASSETTE_MODE = HIGH;   // end first mode pulse, now at position
	        CASSETTE_PAUSE = PLAYING;  // to fix eject prob on 44 pin package***********4/12/09
	        delay_ms(50);            // wait till centre of R.IN pulse 02/10/09 was 10
	         if (CASSETTE_R_IN == HIGH)   // Rin just went high, brake,so we are where we should be.
	           {
	           
	            while (CASSETTE_R_IN);    //wait for rin to go low, ie, load motor stop. 
	               {
	               }
	            cassetteStatus.CURRENT_FOR_REW = CASSETTE_FOR_REW; 
	           
	            if (cassetteStatus.CURRENT_FOR_REW != cassetteStatus.PREVIOUS_FOR_REW)    //side button has been pressed
	                {
	                  if (key_press_time >= 30)
	                   {
	                     monCmdSend(CMD_VSD);  
			             opStatus.STATUS_WAITPROMPT = 1;
				         opStatus.STATUS_WAITCONTROL = 1;
				         opStatus.STATUS_RESET = 1;
	                     changeSideStatus();        //side = ~side;
	                     cassetteStatus.PREVIOUS_FOR_REW = cassetteStatus.CURRENT_FOR_REW;
	                     key_press_time = 0;
	                     goto finished_r;
	                   }  
	                     if (play_type == SEQUENTIAL)			//if normal play
	                      { 
	                        monCmdSend(CMD_VRR);	//random play
	                        play_type = RANDOM;
	                      }
	                        else if (play_type = RANDOM)	//if random play		
	                         {
	                         monCmdSend(CMD_VRA);	//normal play
	                         play_type = SEQUENTIAL;
	                         }  
			          opStatus.STATUS_WAITPROMPT = 1;
				      opStatus.STATUS_WAITCONTROL = 1;
				      opStatus.STATUS_RESET = 1;
	                  changeSideStatus();      //side = ~side;
	                  cassetteStatus.PREVIOUS_FOR_REW = cassetteStatus.CURRENT_FOR_REW;
	                  key_press_time = 0;
	                  goto finished_r;
	                  
	               }
	            goto finished_f;
	           }          
	        delay_ms(30);
                //********************************Second pulse forward****************************************
                //    Used to return to side2 from FF and return to side1 from FR 
	        CASSETTE_MODE = LOW;
	        delay_ms(100);
	        CASSETTE_MODE = HIGH;
	        delay_ms(50);                   // wait until centre of R.IN pulse
	            if (CASSETTE_R_IN == HIGH)   // rin just went high, brake
	             {
	            while (CASSETTE_R_IN);    //wait for rin to go low, motor stop, now at position 2 
	               {
	               }
	    //        side = SIDE1;    removed 25/11/09 is wrong
	            goto finished_f;
	             }
	        delay_ms(30);
                //*********************************Third pulse forward*****************************************
	        CASSETTE_MODE = LOW;
	        delay_ms(100);
	        CASSETTE_MODE = HIGH;
	        delay_ms(50);     //02/10/09 was 10ms
	            if (CASSETTE_R_IN == HIGH)   // rin just went high, brake
	             {
	            while (CASSETTE_R_IN);    //wait for rin to go low, motor stop, now at position 1 
	               {
	               }
	            while (!CASSETTE_MOTOR_O)	//wait for motor.on to go high
	                 {
	                 }
	             startReelPulses();
	              CASSETTE_PAUSE = PLAYING;
	              monCmdSend(CMD_VP);           //restart paused tune
				  opStatus.STATUS_PLAY = PLAYING;  //01/10/09
				  opStatus.STATUS_WAITPROMPT = 1; //wait for responce before more checking
				  opStatus.STATUS_WAITCONTROL = 1;
	              goto finished_f;
	             }
	        delay_ms(30);
               //*********************************Fourth pulse forward*****************************************
               //    Used for resume from pause side1
	        CASSETTE_MODE = LOW;
	        delay_ms(100);
	        CASSETTE_MODE = HIGH;
	        delay_ms(50);         //middle of rin pulse 02/10/09 was 10ms
	          if (CASSETTE_R_IN == HIGH)   // rin just went high, brake
	             //if paused, then tape button pressed
	             {
	               while (CASSETTE_R_IN);    //wait for rin to go low, motor stop, now at position 0, pause 
	                 {
	                 }
	             
	               while (!CASSETTE_MOTOR_O)	//wait for motor.on to go high
	                 {
	                 }
	              startReelPulses();
	              CASSETTE_PAUSE = PLAYING;
	              monCmdSend(CMD_VP);           //restart paused tune
				  opStatus.STATUS_PLAY = PLAYING;  //01/10/09
				  opStatus.STATUS_WAITPROMPT = 1; //wait for responce before more checking
				  opStatus.STATUS_WAITCONTROL = 1;
	             }         
	   
	       finished_f:
	       delay_s(1);
	     }  //fin has gone high
	    }  //rin stayed low
	
			
              previous = current;
			// check if we have been told to wait for both control lines
			// to be released before processing more requests
			if ((!data.CONTROL_FIN) && (!data.CONTROL_RIN))
			{
				opStatus.STATUS_WAITCONTROL = 0; //both control lines released 
			}
		
		}	//else check switches
	}	//if !waitprompt
}	//jagControl
#endif

//**************************************************************************
//
// Name: Interrupt handler for timer0 , INT EXT B0.
//
// Description: A 208ms timer to create the run det f and run det r pulses
//
// Parameters: None.
//
// Returns: None.
//
// Comments:
//
//************************************************************************** 
void interrupt(void)
{
     // which int fired
    if(intcon.TMR0IF)                             //timer0 overflow
     {
       clear_bit(intcon,TMR0IF);                  // clear timer 0 overflow flag
       CASSETTE_RUN_DET_F = ~CASSETTE_RUN_DET_F;  //toggle the run det lines 
       CASSETTE_RUN_DET_R = ~CASSETTE_RUN_DET_R;  //to indicate cassette spools are turning
       key_press_time++;
     }  

    if(intcon.INT0IF)                             //Interrupt on IGN on (rising edge)
      {                                           //and wake pic, turn Vinculum power on
       clear_bit(intcon,INT0IF);
      }
}



//***************************************************************************
// Name: main
//
// Description: Main control loop for VMusic for Jaguar XJ8 cassette emulation.
//
// Parameters: None.
//
// Returns: None.
//
// Comments: Initialises cassette interface board.
//           Synchronises with the Vinculum Firmware.
//           Puts the firmware into SCS mode.
//           Detects the presence of a disk.
//           Waits for control info on F.In and R.In from radio 
//            to play, skip, pause and stop.
//           Displays information on LCD, with a bit of luck.
//
//***************************************************************************
void main()
{
    char data;
	char i;
	enum vResponse resp;
    lcdInit();
    spiInit();
    intfaceInit(); //function to init interface board 
       
	lcdInsWrite(LCD_LINE1);
	for (i = 0; i < 16; i++)
	{
		lcdDataWrite(msgBanner1[i]);
	}
	lcdInsWrite(LCD_LINE2);
	for (i = 0; i < 16; i++)
	{
		lcdDataWrite(msgBanner2[i]);
	}

	// wait 2 seconds for banner
	delay_s(2);

	// ensure Vinculum is synchronised
	// ignore all messages and prompts until sync operation completes
	while (1)
	{
		clear_wdt();
		monCmdSend('E');
		while (monPrompt() != Resp_Prompt_UE);
		
		monCmdSend('e');
		if (monPrompt() == Resp_Prompt_LE)
			break;
	};
   
	// change to Short Command Set Mode
	monCmdSend(CMD_SCS);
	resp = monPrompt();
	if (resp != Resp_Prompt_OK)
	{
		opError(resp);           //displays error message on lcd
	}
     monCmdSend(CMD_SUD);        // put in suspend disk mode
	// loop to recognise if a disk is connected
	while (1)
	{
		lcdInsWrite(LCD_CLR);
		// wait for clear operation to complete
		delay_ms(2);
		do
		{
			clear_wdt();
			// send carriage return
			monCmdSend(CMD_CR);
			resp = monPrompt();
			
			if (resp == Resp_Prompt_ND)
			{
				rspNoDisk();     //scrolls no disk message on lcd
			}
		    if ((resp == Resp_Prompt_ND) && (!CASSETTE_IGN_DET))  // added 28/10/09
		      {
		        powerDown();
		      }
		} while (resp != Resp_Prompt_OK);     //loop for any monitor responce but OK

		rspStopped();           //displays stopped msg on LCD and zero's out buffer
        delay_s(1);	// have disk, stopped, wait 1 secs 
         
        // look on USB drive for firmware file 
        //  void monCmdSendParam(char monCmd, unsigned char monCount, unsigned char *pmonParam)
        //     monCmdSend(CMD_DIR);
         checkForUpdate();
         monReadWait();
         resp = monPrompt();
         if (resp == Resp_Prompt_OK)
           {
              //then we have update file, do update
           //  lcdInsWrite(LCD_LINE2);
	       //   for (i = 0; i < 16; i++)
	       //     {
		   //       lcdDataWrite(msgFirmware[i]);
	       //     }  
	       //  delay_s(2);
           }
        // if exists start firmware loader
        // if not exists continue to cassetteloademu.
      	if (resp != Resp_Prompt_OK)
      	 {
      	  lcdInsWrite(LCD_LINE2);
	       for (i = 0; i < 16; i++)
	        {
		     lcdDataWrite(msgNoFirmware[i]);
	        }  
	      delay_s(2);
	     }     
	       // Emulate loading a tape
        cassetteLoadEmu();     //16/9/09
        monCmdSend(CMD_VRA);// send play  command to play when disk inserted 
           //  monCmdSend(CMD_VRR);// send play random command to play when disk inserted 
        opStatus = 0;  
        opStatus.STATUS_WAITPROMPT = 1;   //added 01/10/09
		opStatus.STATUS_WAITCONTROL = 1;  //added 01/10/09
        opStatus.STATUS_PLAY = PLAYING; //update status  = 1
        opStatus.STATUS_SIDE = SIDE1;
     	bufInfo[0] = '\0';
	  
	   do
		{
			clear_wdt();
			resp = monResponse();

			if (resp == Resp_Message_P)
			{
				rspPlaying();                    //reads file info from spi and stores in buffer 
				opStatus.STATUS_PLAY = 1;        //we are playing  
				opStatus.STATUS_WAITPROMPT = 0;  //can scan for input changes
				opStatus.STATUS_RESET = 1;       //
			}
			else if (resp == Resp_Message_T)
			{
				rspTime();                      //reads playing time etc from spi and displays on lcd   
				opStatus.STATUS_PLAY = 1;
			}
			else if (resp == Resp_Message_S)
			{
				rspStopped();                   //displays stopped msg on LCD and zero's out buffer
				opStatus.STATUS_PLAY = 0;       //can poll for input changes
			}
			else if (resp == Resp_Prompt_ND)
			{
				// device removed - no action
			}
			else if (resp == Resp_Prompt_OK)
			{
				// no idle processing until prompt received
				opStatus.STATUS_WAITPROMPT = 0;
			}
			else if (resp == Resp_None)
			{
	           #ifdef JagHeadUnit
	            jagControl();
	  		   #endif	 
			}
     
			opStatus();            //get status info and display on lcd

			// if disk is removed detect this and loop back
			// to No Disk message
		} while (resp != Resp_Prompt_ND);   //loop for any monitor responce but NO DISK
	}
}    

