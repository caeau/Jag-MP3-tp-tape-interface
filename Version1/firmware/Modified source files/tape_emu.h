#ifndef TAPE_EMU_H
#define TAPE_EMU_H

#ifdef _PIC18F2550 

#define VINCULUM_POWER portc.7
//#define VINCULUM_RI porte.2
#define CASSETTE_PAUSE porta.5
#define CASSETTE_RUN_DET_F porta.2
#define CASSETTE_MODE porta.3
#define CASSETTE_RUN_DET_R porta.4
#define CASSETTE_PACK_IN porta.1
#define CASSETTE_MOTOR_O portb.3
#define CASSETTE_F_IN portb.1       //portb.4
#define CASSETTE_R_IN portb.2       //portb.5
#define CASSETTE_FOR_REW portb.4    //portb.1
//#define CASSETTE_CUE_PLAY porta.1
#define CASSETTE_MUSIC_DET portb.5  //portb.2
#define CASSETTE_IGN_DET  portb.0		//+5V from headunit IGN on
#define TRIS_VINCULUM_POWER trisc.7
//#define TRIS_VINCULUM_RI trise.2
#define TRIS_CASSETTE_PAUSE trisa.5
#define TRIS_CASSETTE_RUN_DET_F trisa.2
#define TRIS_CASSETTE_MODE trisa.3
#define TRIS_CASSETTE_RUN_DET_R trisa.4
#define TRIS_CASSETTE_PACK_IN trisa.1
#define TRIS_CASSETTE_MOTOR_O trisb.3
#define TRIS_CASSETTE_F_IN trisb.1    //trisb.4
#define TRIS_CASSETTE_R_IN trisb.2    //trisb.5
#define TRIS_CASSETTE_FOR_REW trisb.4  //trisb.1
//#define TRIS_CASSETTE_CUE_PLAY trisa.1
#define TRIS_CASSETTE_MUSIC_DET trisb.5 //trisb.2
#define TRIS_CASSETTE_IGN_DET trisb.0
#endif

#ifdef _PIC18F4550

#define VINCULUM_POWER porte.0
//#define VINCULUM_RI porte.2
#define CASSETTE_PAUSE porta.5
#define CASSETTE_RUN_DET_F porta.2
#define CASSETTE_MODE porta.3
#define CASSETTE_RUN_DET_R porta.4
#define CASSETTE_PACK_IN porte.1
#define CASSETTE_MOTOR_O portb.3
#define CASSETTE_F_IN portb.1       //portb.4
#define CASSETTE_R_IN portb.2       //portb.5
#define CASSETTE_FOR_REW portb.4    //portb.1
//#define CASSETTE_CUE_PLAY porta.1
#define CASSETTE_MUSIC_DET portb.5  //portb.2
#define CASSETTE_IGN_DET  portb.0		//+5V from headunit IGN on
#define TRIS_VINCULUM_POWER trise.0
//#define TRIS_VINCULUM_RI trise.2
#define TRIS_CASSETTE_PAUSE trisa.5
#define TRIS_CASSETTE_RUN_DET_F trisa.2
#define TRIS_CASSETTE_MODE trisa.3
#define TRIS_CASSETTE_RUN_DET_R trisa.4
#define TRIS_CASSETTE_PACK_IN trise.1
#define TRIS_CASSETTE_MOTOR_O trisb.3
#define TRIS_CASSETTE_F_IN trisb.1    //trisb.4
#define TRIS_CASSETTE_R_IN trisb.2    //trisb.5
#define TRIS_CASSETTE_FOR_REW trisb.4  //trisb.1
//#define TRIS_CASSETTE_CUE_PLAY trisa.1
#define TRIS_CASSETTE_MUSIC_DET trisb.5 //trisb.2
#define TRIS_CASSETTE_IGN_DET trisb.0
#endif


// F.in control line high
#define CONTROL_FIN 0
// R.in control line high
#define CONTROL_RIN 1

#define PAUSED 0
#define PLAYING 1
#define IDLE 1
#define ACTIVE 0
#define CUE 1
#define PLAY 0
#define FORWARD 1
#define REWIND 0
#define OUT 0
#define IN 1
#define PACK_LOAD 1
#define PACK_UNLOAD 0
#define VINCULUM_ON 0
#define VINCULUM_OFF 1
#define SIDE1 0
#define SIDE2 1
#define MUSIC 0
#define NO_MUSIC 1
#define LOW 0
#define HIGH 1
#define CURRENT_FOR_REW 0
#define PREVIOUS_FOR_REW 1
#define IGN 2
#define ON 1
#define OFF 0
#define SEQUENTIAL 0
#define RANDOM 1

//****FUNCTION PROTYPES**********************************
void startReelPulses(void);
void stopReelPulses(void);
void cassetteloadEmu(void);
void cassetteEjectEmu(void);
void intfaceInit(void);
void jagControl(void);
void amfmButtonEmu(void);
void sideOnefastForwardEmu(void);
void sideTwofastForwardEmu(void);
void fastRewindEmu(void);
void startFastReelPulses(void);
void stopFastReelPulses(void);
void powerDown(void);
void reset(void);
void changeSideStatus(void);
void checkForUpdate(void);

#endif