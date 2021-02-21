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
float Ohm = 39;// Resistance of the electric motor is 39 Ohms
float Value = 0;
float Power;
float Power2;
float Volts; 
int i; 

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // LCD Setups
  // Voltage
  lcd.setCursor(0,0);
  lcd.print("Voltage:");
  lcd.setCursor(15,0);
  lcd.print("V");
  // Power
  lcd.setCursor(0,1);
  lcd.print("Power:");
  lcd.setCursor(15,1);
  lcd.print("W");
   //Plotter
  Serial.begin(9600);
}

void loop() {
  // (note: line 1 is the second row, since counting begins with 0):
  // Voltage, uses a for loop to constantly update itself
  for(i=0;i<1000;i++) {
    Volts = analogRead(Value) * 5.0/1023 ; // Reads the Analog Input, 5/1023 = 4.9 mV which is the Arduino resolution
    Power = (Volts*Volts)/Ohm; //Uses the P = V^2/R equation to find power
    lcd.setCursor(8,0); // Prints Volts
    lcd.print(Volts);
    lcd.setCursor(6,1);
    lcd.print(Power);
    Serial.println(Volts);
    delay(500);
    // Resets the For Loop
    if (i == 999) {
      i = 0;
    }
  } 
}
