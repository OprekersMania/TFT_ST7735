/*
 Display all the fonts.

 This sketch uses the GLCD (font 1) and fonts 2, 4, 6, 7, 8
 
 Make sure all the required fonts are loaded by editting the
 User_Setup.h file in the TFT_ST7735 library folder.

 If using an UNO or Mega (ATmega328 or ATmega2560 processor) then for best
 performance use the F_AS_T option found in the User_Setup.h file in the
 TFT_ST7735 library folder.

 The library uses the hardware SPI pins only:
   For UNO, Nano, Micro Pro ATmega328 based processors
      MOSI = pin 11, SCK = pin 13
   For Mega:
      MOSI = pin 51, SCK = pin 52

 The pins used for the TFT chip select (CS) and Data/command (DC) and Reset (RST)
 signal lines to the TFT must also be defined in the library User_Setup.h file.

 Sugested TFT connections for UNO and Atmega328 based boards
   sclk 13  // Don't change, this is the hardware SPI SCLK line
   mosi 11  // Don't change, this is the hardware SPI MOSI line
   cs   10  // Chip select for TFT display
   dc   9   // Data/command line
   rst  7   // Reset, you could connect this to the Arduino reset pin

 Suggested TFT connections for the MEGA and ATmega2560 based boards
   sclk 52  // Don't change, this is the hardware SPI SCLK line
   mosi 51  // Don't change, this is the hardware SPI MOSI line
   cs   47  // TFT chip select line
   dc   48  // TFT data/command line
   rst  44  // you could alternatively connect this to the Arduino reset

  #########################################################################
  ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
  ######       TO SELECT THE FONTS AND PINS YOU USE, SEE ABOVE       ######
  #########################################################################
 */

// New background colour
#define TFT_BROWN 0x38E0

// Pause in milliseconds between screens, change to 0 to time font rendering
#define WAIT 500

#include <TFT_ST7735.h> // Graphics and font library for ST7735 driver chip
#include <SPI.h>
#include <Fonts/campus_29p_full.h>

TFT_ST7735 tft = TFT_ST7735();  // Invoke library, pins defined in User_Setup.h

unsigned long targetTime = 0; // Used for testing draw times

void setup(void) {
  tft.init();
  tft.setRotation(1);
}

void loop() {
  targetTime = millis();

  // First we test them with a background colour set
  tft.setTextSize(1);
  tft.fillScreen(TFT_BLACK);
	// TES ADAFRUIT SAMPLE FONT
  tft.setFont(&campus_29p_full);
  tft.setTextColor(TFT_GREEN);
  tft.drawString("Adafruit font", 0, 17, 1);
  tft.setTextColor(TFT_RED);
  tft.drawString("ABCDE klmno", 0, 40, 1);
  tft.setTextColor(TFT_BLUE);
  tft.drawString("1234567890", 0, 63, 1);
  tft.setTextSize(2);
  tft.setTextColor(TFT_YELLOW);
  tft.drawString("Size 2", 0, 100, 1);
  delay(WAIT);
  tft.setTextSize(1);
  tft.setFont(); // back to original library support
  
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.drawString(" !\"#$%&'()*+,-./0123456", 0, 0, 2);
  tft.drawString("789:;<=>?@ABCDEFGHIJKL", 0, 16, 2);
  tft.drawString("MNOPQRSTUVWXYZ[\\]^_`", 0, 32, 2);
  tft.drawString("abcdefghijklmnopqrstuvw", 0, 48, 2);
  int xpos = 0;
  xpos += tft.drawString("xyz{|}~", 0, 64, 2);
  tft.drawChar(127, xpos, 64, 2);
  delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_GREEN, TFT_BLACK);

  tft.drawString(" !\"#$%&'()*+,-.", 0, 0, 4);
  tft.drawString("/0123456789:;", 0, 26, 4);
  tft.drawString("<=>?@ABCDE", 0, 52, 4);
  tft.drawString("FGHIJKLMNO", 0, 78, 4);
  tft.drawString("PQRSTUVWX", 0, 104, 4);
  delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.drawString("YZ[\\]^_`abc", 0, 0, 4);
  tft.drawString("defghijklmno", 0, 26, 4);
  tft.drawString("pqrstuvwxyz", 0, 52, 4);
  xpos = 0;
  xpos += tft.drawString("{|}~", 0, 78, 4);
  tft.drawChar(127, xpos, 78, 4);
  delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_BLUE, TFT_BLACK);

  tft.drawString("012345", 0, 0, 6);
  tft.drawString("6789", 0, 40, 6);
  tft.drawString("apm-:.", 0, 80, 6);
  delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_RED, TFT_BLACK);

  tft.drawString("0123", 0, 0, 7);
  tft.drawString("4567", 0, 60, 7);
  delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.drawString("890:.", 0, 0, 7);
  tft.drawString("", 0, 60, 7);
  delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_YELLOW, TFT_BLACK);

  tft.drawString("01", 0, 0, 8);
  delay(WAIT);
  
  tft.drawString("23", 0, 0, 8);
  delay(WAIT);

  tft.drawString("45", 0, 0, 8);
  delay(WAIT);
  

  tft.setTextColor(TFT_MAGENTA);
  tft.drawNumber(millis() - targetTime, 0, 100, 4);
  delay(4000);

  // Now test them with transparent background
  targetTime = millis();

  tft.setTextSize(1);
  tft.fillScreen(TFT_BROWN);
  tft.setTextColor(TFT_GREEN);

  tft.drawString(" !\"#$%&'()*+,-./0123456", 0, 0, 2);
  tft.drawString("789:;<=>?@ABCDEFGHIJKL", 0, 16, 2);
  tft.drawString("MNOPQRSTUVWXYZ[\\]^_`", 0, 32, 2);
  tft.drawString("abcdefghijklmnopqrstuvw", 0, 48, 2);
  xpos = 0;
  xpos += tft.drawString("xyz{|}~", 0, 64, 2);
  tft.drawChar(127, xpos, 64, 2);
  delay(WAIT);

  tft.fillScreen(TFT_BROWN);
  tft.setTextColor(TFT_GREEN);

  tft.drawString(" !\"#$%&'()*+,-.", 0, 0, 4);
  tft.drawString("/0123456789:;", 0, 26, 4);
  tft.drawString("<=>?@ABCDE", 0, 52, 4);
  tft.drawString("FGHIJKLMNO", 0, 78, 4);
  tft.drawString("PQRSTUVWX", 0, 104, 4);

  delay(WAIT);
  tft.fillScreen(TFT_BROWN);
  tft.drawString("YZ[\\]^_`abc", 0, 0, 4);
  tft.drawString("defghijklmno", 0, 26, 4);
  tft.drawString("pqrstuvwxyz", 0, 52, 4);
  xpos = 0;
  xpos += tft.drawString("{|}~", 0, 78, 4);
  tft.drawChar(127, xpos, 78, 4);
  delay(WAIT);

  tft.fillScreen(TFT_BROWN);
  tft.setTextColor(TFT_BLUE);

  tft.drawString("012345", 0, 0, 6);
  tft.drawString("6789", 0, 40, 6);
  tft.drawString("apm-:.", 0, 80, 6);
  delay(WAIT);

  tft.fillScreen(TFT_BROWN);
  tft.setTextColor(TFT_RED);

  tft.drawString("0123", 0, 0, 7);
  tft.drawString("4567", 0, 60, 7);
  delay(WAIT);

  tft.fillScreen(TFT_BROWN);
  tft.drawString("890:.", 0, 0, 7);
  tft.drawString("", 0, 60, 7);
  delay(WAIT);

  tft.fillScreen(TFT_BROWN);
  tft.setTextColor(TFT_YELLOW);

  tft.drawString("0123", 0, 0, 8);
  delay(WAIT);

  tft.fillScreen(TFT_BROWN);
  tft.drawString("4567", 0, 0, 8);
  delay(WAIT);

  tft.fillScreen(TFT_BROWN);
  tft.drawString("890:.", 0, 0, 8);
  delay(WAIT);

  tft.setTextColor(TFT_MAGENTA);

  tft.drawNumber(millis() - targetTime, 0, 100, 4);
  delay(4000);;
}

