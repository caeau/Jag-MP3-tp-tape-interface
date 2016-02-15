#include <system.h>
#include "tape_emu.h"
#include "monitor.h"

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
  set_bit(t0con,TMR0ON);		// enable timer 0 to start reel pulses 
   
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
  clear_bit(t0con,TMR0ON);		// disable timer 0 to stop reel pulses 
  
}

//***************************************************************************
//
// Name: StartFastReelPulses
//
// Description: Simulates FF and FR tape speeds, by generating faster reel pulses
//
// Parameters: None
//
// Returns: None.
//
// Comments: 
//
//***************************************************************************
void startFastReelPulses()
{
    clear_bit(t0con,TMR0ON);	// stop timer 0
    clear_bit(t0con,T08BIT);	// 16 bit timer
    clear_bit(t0con,T0CS);		// int clock
    clear_bit(t0con,PSA);		// prescaler on
    clear_bit(t0con,T0PS0);		//set prescale 1:2 ms approx with 20mhz clock
    clear_bit(t0con,T0PS1);		//     "
    clear_bit(t0con,T0PS2);		//     "
    set_bit(t0con,TMR0ON);		// enable timer 0 to start fast reel pulses
}

//***************************************************************************
//
// Name: StopFastReelPulses
//
// Description: Stops generation of FF and FR reel pulses
//
// Parameters: None
//
// Returns: None.
//
// Comments: 
//
//***************************************************************************
void stopFastReelPulses()
{
    clear_bit(t0con,TMR0ON);		// disable timer 0 to stop fast reel pulses
    clear_bit(t0con,TMR0ON);		// stop timer 0
    clear_bit(t0con,T08BIT);	// 16 bit timer
    clear_bit(t0con,T0CS);		// int clock
    clear_bit(t0con,PSA);		// prescaler on
    set_bit(t0con,T0PS0);		//set prescale 1:16 208ms approx with 20mhz clock
    set_bit(t0con,T0PS1);		//     "
    clear_bit(t0con,T0PS2);		//     "
}





