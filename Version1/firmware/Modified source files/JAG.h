

#define VINCULUM_POWER portc.6
#define VINCULUM_ON 0
#define VINCULUM_OFF 1
#define CASSETTE_PAUSE porta.0
#define CASSETTE_RUN_DET_F portb.4
#define CASSETTE_MODE portb.5
#define CASSETTE_RUN_DET_R portb.6
#define CASSETTE_PACK_IN portb.3
#define CASSETTE_MOTOR_O porte.3
#define CASSETTE_F_IN portc.5
#define CASSETTE_R_IN portc.4
#define CASSETTE_FOR_REW portc.7
//#define CASSETTE_CUE_PLAY porta.0
#define TRIS_VINCULUM_POWER trisc.6
#define TRIS_CASSETTE_PAUSE trisa.0
#define TRIS_CASSETTE_RUN_DET_F trisb.4
#define TRIS_CASSETTE_MODE trisb.5
#define TRIS_CASSETTE_RUN_DET_R trisb.6
#define TRIS_CASSETTE_PACK_IN trisb.3
#define TRIS_CASSETTE_MOTOR_O trise.3
#define TRIS_CASSETTE_F_IN trisc.5
#define TRIS_CASSETTE_R_IN trisc.4
#define TRIS_CASSETTE_FOR_REW trisc.7
//#define TRIS_CASSETTE_CUE_PLAY trisa.0
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



bool running ;
//****FUNCTION PROTYPES**********************************
void startReelPulses();
void stopReelPulses();
void cassetteloadEmu();
void cassetteEjectEmu();
void intfaceInit();

