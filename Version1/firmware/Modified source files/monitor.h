#ifndef MONITOR_H
#define MONITOR_H

// monitor is connected via SPI
#include "SPI.h"

#define CMD_SCS 0x10
#define CMD_IPH 0x91

#define CMD_DIR 0x01
#define CMD_CD  0x02
#define CMD_VST 0x20
#define CMD_V3A 0x21
#define CMD_VRR 0x8F
#define CMD_VRA 0x8A
#define CMD_VSF 0x25
#define CMD_VSB 0x26
#define CMD_VSD 0x8E
#define CMD_VP 0x8B
#define CMD_VF 0x8C
#define CMD_VB 0x8D
#define CMD_VSV 0x88
#define CMD_SUD 0x15        //suspend disk 
#define CMD_WKD 0x16        //wake disk
#define CMD_SUM 0x17        //suspend monitor
#define CMD_CR 0x0d

// Prompts and messages returned by VNC1L
enum vResponse {
	// Prompts returned by all VNC1L firmware
    Resp_Prompt_OK,	// >  (Success)
    Resp_Prompt_ND,	// ND (Success)
    Resp_Prompt_UE,	// E echo
    Resp_Prompt_LE,	// e echo
    Resp_Prompt_CF,	// CF (Command Failed)
    Resp_Prompt_BC,	// BC (Bad Command)
    Resp_Prompt_DF,	// DF (Disk Full)
    Resp_Prompt_FI,	// FI (File Invalid)
    Resp_Prompt_RO,	// RO (Read Only)
    Resp_Prompt_FO,	// FO (File Open)
    Resp_Prompt_NE,	// NE (Dir Not Empty)
    Resp_Prompt_FN,	// FN (Filename Invalid)
	Resp_Prompt_End,
	// Asynchronous messages returned by VMSC1 firmware
    Resp_Message_P,		// P / Playing
    Resp_Message_S,		// S / Stopped
    Resp_Message_T,		// T / Time
	// Asynchronous messages returned by all VNC1L firmware
    Resp_Message_NU,		// NU / No Upgrade
    Resp_Message_DD1,	// DD1 / Device Detected USB Port 1)
    Resp_Message_DD2,	// DD2 / Device Detected USB Port 2)
    Resp_Message_DR1,	// DR1 / Device Removed USB Port 1)
    Resp_Message_DR2,	// DR2 / Device Removed USB Port 2)
	Resp_Message_Splash, // Ver ...
    Resp_None = 0xff,
};


void monSendByte(char monData);
void monCmdSend(char monCmd);
void monCmdSendParam(char monCmd, unsigned char monCount, unsigned char *pmonParam);
void monCmdSendByteParam(char monCmd, unsigned char monParam);
enum vResponse monPrompt();
enum vResponse monResponse();

#endif