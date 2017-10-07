#include <LiquidCrystal.h>
int pos=0; // variable to hold cursor position

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
 lcd.begin(16, 2);                              //initializes 16x2 LCD
 lcd.print("16x2 LCD MODULE & ARDUINO-UNO");   //text to display
}

void loop()
{
  for(pos=0; pos<2; pos++)  
  {
lcd.scrollDisplayLeft();    //scrolls display left by two positions
  }  
  delay(800);              //sets the speed at which display moves
}
