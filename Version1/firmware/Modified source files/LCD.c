#include <system.h>

#include "LCD.h"

//***************************************************************************
//  
//  Pin definitions for LCD
//  
//***************************************************************************
/*
// LCD data bits on PORTD
#define TRIS_LCD_D4  trisd.0
#define TRIS_LCD_D5  trisd.1
#define TRIS_LCD_D6  trisd.2
#define TRIS_LCD_D7  trisd.3
#define PORT_LCD_D4  portd.0
#define PORT_LCD_D5  portd.1
#define PORT_LCD_D6  portd.2
#define PORT_LCD_D7  portd.3

// LCD control bits on PORTD
// LCD Enable bit
#define PORT_LCD_EN  portd.7
#define TRIS_LCD_EN  trisd.7
// LCD E clock on PORTD6
#define PORT_LCD_E   portd.6
#define TRIS_LCD_E   trisd.6
// LCD read/write line on PORTD5
#define PORT_LCD_RW  portd.5
#define TRIS_LCD_RW  trisd.5
// LCD register select line on PORTD4
#define PORT_LCD_RS  portd.4
#define TRIS_LCD_RS  trisd.4
*/

// LCD data bits on PORTD      for viper lcd connections cgk
#define TRIS_LCD_D4  trisd.4
#define TRIS_LCD_D5  trisd.5
#define TRIS_LCD_D6  trisd.6
#define TRIS_LCD_D7  trisd.7
#define PORT_LCD_D4  portd.4
#define PORT_LCD_D5  portd.5
#define PORT_LCD_D6  portd.6
#define PORT_LCD_D7  portd.7

/*
// LCD data bits on PORTB      for 18F2550 emu lcd connections cgk
#define TRIS_LCD_D4  trisb.3
#define TRIS_LCD_D5  trisb.2
#define TRIS_LCD_D6  trisb.1
#define TRIS_LCD_D7  trisb.0
#define PORT_LCD_D4  portb.3
#define PORT_LCD_D5  portb.2
#define PORT_LCD_D6  portb.1
#define PORT_LCD_D7  portb.0
*/

// LCD control bits on PORTD
// LCD Enable bit
//#define PORT_LCD_EN  portd.3
//#define TRIS_LCD_EN  trisd.3
// LCD E clock on PORTD6
#define PORT_LCD_E   portd.0
#define TRIS_LCD_E   trisd.0
// LCD read/write line on PORTD5
#define PORT_LCD_RW  portd.2
#define TRIS_LCD_RW  trisd.2
// LCD register select line on PORTD4
#define PORT_LCD_RS  portd.1
#define TRIS_LCD_RS  trisd.1

/*
// LCD control bits on PORTC        for 18F2550 emu lcd connections cgk
// LCD Enable bit
//#define PORT_LCD_EN  portd.3
//#define TRIS_LCD_EN  trisd.3
// LCD E clock on PORTC2
#define PORT_LCD_E   portc.2
#define TRIS_LCD_E   trisc.2
// LCD read/write line on PORTC1
#define PORT_LCD_RW  portc.1
#define TRIS_LCD_RW  trisc.1
// LCD register select line on PORTC0
#define PORT_LCD_RS  portc.0
#define TRIS_LCD_RS  trisc.0
*/

//***************************************************************************
//  
//  Constants and variables for LCD
//  
//***************************************************************************

#define	LCD_INS		0
#define	LCD_DATA	1

#define LCD_WRITE	0
#define LCD_READ	1

#define LCD_ENABLE_ON	1
#define LCD_ENABLE_OFF	0

#define LCD_RESET       0x30 // reset LCD code
#define LCD_4BIT        0x20 // set 4 bit data mode
#define LCD_FN_SET      0x28 // function set
#define LCD_ON          0x0C // display on in 2 line mode
#define LCD_ENTRY_MODE  0x06 // entry mode l to r no scroll

//***************************************************************************
//
// Internal Routines
//
//***************************************************************************

void lcdWriteNibble(char lcdData);
void lcdWrite(char lcdData);

//***************************************************************************
// Name: lcdWriteNibble
//
// Description: Send 4 bits of data to the LCD controller.
//
// Parameters: lcdData - High nibble in lcdData.
//
// Returns: None.
//
// Comments: Clocks out one nibble of data on the LCD interface.
//
//***************************************************************************
void lcdWriteNibble(char lcdData)
{
	// data bus bits to outputs
	TRIS_LCD_D4 = 0;
	TRIS_LCD_D5 = 0;
	TRIS_LCD_D6 = 0;
	TRIS_LCD_D7 = 0;

	nop(); 
	nop(); 

	// set write mode
	PORT_LCD_RW = LCD_WRITE;
	nop(); 

	// send data
	PORT_LCD_D7 = (lcdData.7)?1:0;
	PORT_LCD_D6 = (lcdData.6)?1:0;
	PORT_LCD_D5 = (lcdData.5)?1:0;
	PORT_LCD_D4 = (lcdData.4)?1:0;
	delay_us(20);

	// enable write
	PORT_LCD_E = LCD_ENABLE_ON;
	delay_us(20);

	// complete write
	PORT_LCD_E = LCD_ENABLE_OFF;
}

//***************************************************************************
// Name: lcdWrite
//
// Description: Write 2 nibbles of data to the LCD controller
//
// Parameters: lcdData - Byte of data to write to LCD controller.
//
// Returns: None.
//
// Comments: Clocks out two nibbles of data to the LCD controller in two
//           transactions.
//
//***************************************************************************
void lcdWrite(char lcdData)
{
	lcdWriteNibble(lcdData);
	lcdWriteNibble(lcdData<<4);
}

//***************************************************************************
//
// External Routines
//
//***************************************************************************

//***************************************************************************
// Name: lcdInit
//
// Description: Initialise the LCD interface and controller. 
//
// Parameters: None.
//
// Returns: None.
//
// Comments: Sets up pins connecting to the LCD display. Sends setup
//           commands to the controller to initialise and clear the screen.
//
//***************************************************************************
void lcdInit()
{
/* 
	// disable then enable LCD panel   not necessary for our panel cgk
	PORT_LCD_EN = 1;
	TRIS_LCD_EN = 0;
	PORT_LCD_EN = 0;
	delay_ms(15); 
	PORT_LCD_EN = 1;
	delay_ms(15); 
*/
    // configure pin direction
	TRIS_LCD_D4 = 0;
	TRIS_LCD_D5 = 0;
	TRIS_LCD_D6 = 0;
	TRIS_LCD_D7 = 0;
	TRIS_LCD_E = 0;
	TRIS_LCD_RW = 0;
	TRIS_LCD_RS = 0;

	// configure initial pin state
    PORT_LCD_D4 = 0;
    PORT_LCD_D5 = 0;
    PORT_LCD_D6 = 0;
    PORT_LCD_D7 = 0;
	// initial control line states
    PORT_LCD_E = LCD_ENABLE_OFF;
    PORT_LCD_RW = LCD_WRITE;
	// register select low for instruction input
	PORT_LCD_RS = LCD_INS;

    // delay 15ms
	delay_ms(15); 

	lcdWriteNibble(LCD_RESET); 
	// min delay 4.1ms
	delay_ms(5); 

	lcdWriteNibble(LCD_RESET); 
	// min delay 4.1ms
	delay_ms(5); 

	lcdWriteNibble(LCD_RESET); 
	// min delay 4.1ms
	delay_ms(5); 

	lcdWriteNibble(LCD_4BIT);
	// min delay 100us
	delay_us(100); 

	lcdWriteNibble(LCD_FN_SET);
	delay_us(100); 
	lcdWriteNibble(LCD_FN_SET<<4);
	delay_us(100); 

	lcdWriteNibble(LCD_ON);
	delay_us(100); 
	lcdWriteNibble(LCD_ON<<4);
	delay_us(100); 

	lcdWriteNibble(LCD_ENTRY_MODE);
	delay_us(100); 
	lcdWriteNibble(LCD_ENTRY_MODE<<4);
	delay_us(100); 

	lcdWriteNibble(LCD_CLR);
	delay_us(100); 
	lcdWriteNibble(LCD_CLR<<4);
	// wait for clear operation to complete
	delay_ms(2);
}	

//***************************************************************************
// Name: lcdInsWrite
//
// Description: Write an instruction code to the LCD controller.
//
// Parameters: lcdI - Instruction byte to write.
//
// Returns: None.
//
// Comments: RS line is set to low.
//
//***************************************************************************
void lcdInsWrite(char lcdI)
{
	// RS low for instruction write
	PORT_LCD_RS = LCD_INS;

	lcdWrite(lcdI);
}

//***************************************************************************
// Name: lcdDataWrite
//
// Description: Write data to the LCD controller.
//
// Parameters: lcdD - Data byte to write.
//
// Returns: None.
//
// Comments: RS line is set to high.
//
//***************************************************************************
void lcdDataWrite(char lcdD)
{
	// RS high for data write
	PORT_LCD_RS = LCD_DATA;

	lcdWrite(lcdD);
}

