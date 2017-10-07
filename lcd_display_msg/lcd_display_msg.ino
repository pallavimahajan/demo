#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // sets the interfacing pins

void setup()
{
 lcd.begin(16, 2);  // initializes the 16x2 LCD
}

void loop()
{
  lcd.setCursor(0,0);           //sets the cursor at row 0 column 0
  lcd.print("16x2 LCD MODULE"); // prints 16x2 LCD MODULE
  lcd.setCursor(2,1);           //sets the cursor at row 1 column 2
  lcd.print("HELLO WORLD");  // prints HELLO WORLD  
}

//
//// include the library code:
//#include <LiquidCrystal.h>
//
//// initialize the library by associating any needed LCD interface pin
//// with the arduino pin number it is connected to
//const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//
//void setup() {
//  // set up the LCD's number of columns and rows:
//  lcd.begin(16, 2);
//  // Print a message to the LCD.
//
//  lcd.print("hello, world!");
//}
//
//void loop() {
//  // Turn off the display:
//  lcd.noDisplay();
//  delay(500);
//  // Turn on the display:
//  lcd.display();
//  delay(500);
//}
