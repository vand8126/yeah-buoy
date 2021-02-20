/*
  The circuit:
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 8
 * LCD D4 pin to digital pin 9
 * LCD D5 pin to digital pin 10
 * LCD D6 pin to digital pin 11
 * LCD D7 pin to digital pin 12
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/
// Libraries
#include <LiquidCrystal.h>


// Initializations
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int Resistance = 10;
int Voltage = 0;
int Power;
int VoltRead; 
int i; 

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // LCD Setups
  // Voltage
  lcd.setCursor(0,0);
  lcd.print("Voltage:");
  lcd.setCursor(11,0);
  lcd.print("V");
  // Power
  lcd.setCursor(0,1);
  lcd.print("Power:");
  
  //Plotter
  Serial.begin(9600);
}

void loop() {
  // (note: line 1 is the second row, since counting begins with 0):
  // Voltage, uses a for loop to constantly update itself
  for(i=0;i<1000;i++) {
    VoltRead = analogRead(Voltage); // Reads the Analog Input
    lcd.setCursor(8,0); // Prints VoltRead
    lcd.print(VoltRead);
    Serial.println(VoltRead);
    // Resets the For Loop
    if (i == 999) {
      i = 0;
    }
  } 
  // Power
  Power = (VoltRead * VoltRead / Resistance); 
  lcd.setCursor(6,1);
  lcd.print(Power);
  //Serial.println(Power);
 
}
