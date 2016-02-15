#ifndef LCD_H
#define LCD_H

#define LCD_LINE1	0x80
#define LCD_LINE2	0xC0
#define LCD_CLR		0x01

void lcdInit();
void lcdInsWrite(char lcdI);
void lcdDataWrite(char lcdD);

#endif