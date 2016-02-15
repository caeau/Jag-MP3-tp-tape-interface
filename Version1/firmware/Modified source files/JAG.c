
#include <system.h>
#include "jag.h"
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
	running = 1;
	CASSETTE_PACK_IN = PACK_LOAD;		//pack in line high, pack in switched open, cassette inserted.
	 while (!CASSETTE_F_IN);			//wait for F.IN to go high, load motor forward.
	    {
	    }
	   delay_ms(900);
	   CASSETTE_PAUSE = PLAYING;		//take pause line high, cassette loaded
	   delay_ms(20);
	   CASSETTE_MODE = 0;			//mode line low
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
	                                      delay_ms(20);				//short delay (to emulate mechanics moving)
	                                      CASSETTE_PAUSE = PLAYING; //pause line high, tape playing 
	                                      delay_ms(120);			//delay to emulate mechanism
	                                      CASSETTE_MODE = 0;        // next 15 lines simulate the 4 mode switch positions
	                                      delay_ms(80);
	                                      CASSETTE_MODE = 1;
	                                      delay_ms(80);
	                                      CASSETTE_MODE = 0;
	                                      delay_ms(170);
	                                      CASSETTE_MODE = 1;
	                                      delay_ms(80);
	                                      CASSETTE_MODE = 0;
	                                      delay_ms(110);
	                                      CASSETTE_MODE = 1;
	                                      delay_ms(80);
	                                      CASSETTE_MODE =0;
	                                      delay_ms(90);
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
// Comments:  
//            
//            
//            
//            
//            
//            
//               
//  
//***************************************************************************
void cassetteEjectEmu()
{
	running = 0;
	while(!CASSETTE_R_IN)		//wait for R.IN to be high, reverse load motor
	{
	}
	    delay_ms(90);				//short delay (to emulate mechanics moving)
	    CASSETTE_MODE = 0;        // next 15 lines simulate the 4 mode switch positions
	    delay_ms(160);
	    CASSETTE_MODE = 1;
	    delay_ms(80);
	    CASSETTE_MODE = 0;
	    delay_ms(110);
	    CASSETTE_MODE = 1;
	    delay_ms(80);
	    CASSETTE_MODE = 0;
	    delay_ms(170);
	    CASSETTE_MODE = 1;
	    delay_ms(80);
	    CASSETTE_MODE =0;
	    delay_ms(90);
	    CASSETTE_MODE = 1;
	    
	    delay_ms(20);
	    CASSETTE_PAUSE = PAUSED;
	    stopReelPulses();
	    delay_ms(120);
	    CASSETTE_PACK_IN = PACK_UNLOAD;
}

//***************************************************************************
//
// Name: startReelPulses
//
// Description: Starts timer 0
//
// Parameters: None.
//
// Returns: None
//
// Comments:
//
//***************************************************************************
void startReelPulses()
{
  set_bit(t0con,TMR0ON);		// enable timer 0 to start reel pulses cgk
 // delay_us(500);				// alow time for pulses to start before playing file
}


//***************************************************************************
//
// Name: stopReelPulses
//
// Description: Stops timer 0
//
// Parameters: None.
//
// Returns: None
//
// Comments:
//
//***************************************************************************
void stopReelPulses()
{
  clear_bit(t0con,TMR0ON);		// de_enable timer 0 to stop reel pulses cgk
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
	  // following 2 lines disable USB and allow C4 and C5 to be input  cgk.
    ucfg.UTRDIS = 1;
    ucon.3 = 0;
    adcon1 = 0x0F;   // make all port a digital i/o
      // set port direction
   // TRIS_CASSETTE_CUE_PLAY = IN;      //cue/play H = cue L= play
    TRIS_CASSETTE_PAUSE = OUT;      // pause
    TRIS_CASSETTE_RUN_DET_F = OUT;	  // run det f	
    TRIS_CASSETTE_MODE = OUT;      // mode
    TRIS_CASSETTE_RUN_DET_R = OUT;      // run det r
    TRIS_CASSETTE_F_IN = IN;      // F.In
    TRIS_CASSETTE_R_IN = IN;      // R.In
    TRIS_VINCULUM_POWER = OUT;	  // Make C6 output vinculum power
    TRIS_CASSETTE_FOR_REW = IN;      // For/Rew H = for L = rew
    TRIS_CASSETTE_PACK_IN = OUT;
    // TRIS_MOTOR_O no tris statement for porte.3
   
      //Init output ports
    VINCULUM_POWER = VINCULUM_ON;
    CASSETTE_PAUSE = PAUSED;		//cassette paused
  	CASSETTE_MODE = IDLE;				// mode idle = H
    CASSETTE_PACK_IN = PACK_UNLOAD;
    CASSETTE_RUN_DET_F = 1;			//start H make f and r out of phase
    CASSETTE_RUN_DET_R = 0;         //start L
   
    // Set up timer 0 approx 130ms
    clear_bit(t0con,TMR0ON);		// stop timer 0
    clear_bit(t0con,T08BIT);	// 16 bit timer
    clear_bit(t0con,T0CS);		// int clock
    clear_bit(t0con,PSA);		// prescaler on
    clear_bit(t0con,T0PS0);		//set prescale 1:2 130ms approx
    clear_bit(t0con,T0PS1);		//     "
    clear_bit(t0con,T0PS2);		//     "
       
    
    tmr0l = 0x00;		    // set low byte
    tmr0h = 0x00;           // set high byte
    
    // enable interrupts
	set_bit(intcon,TMR0IE); //enable TMR0 overflow bit    
	set_bit(intcon,GIE);
}
