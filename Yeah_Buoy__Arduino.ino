// Libraries
#include <LiquidCrystal.h>

// Initializations
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); //LCD in the Digital Ports 7, 8, 9, 10, 11, and 12
float Ohm = 39;// Resistance of the electric motor is 39 Ohms
float Value = 0; // The analog value taken from the electric motor
float Power; //Variable that stores Power Data
float Volts; // Variable that stores voltage data
float Energy; //Variable that stores energy data
float Kwh; // Stores the kWh energy data
int i; // variable that creates the recurring for loop

// Setup
void setup() {
  // LCD Setups
    lcd.begin(16, 2); // set up the LCD's number of columns and rows:
    // Voltage
      lcd.setCursor(0,0);
      lcd.print("Voltage:");
      lcd.setCursor(15,0);
      lcd.print("V"); // Volts unit
    // Energy
      lcd.setCursor(0,1);
      lcd.print("Energy:");
      lcd.setCursor(13,1);
      lcd.print("kWh"); //Energy Unit
   //Plotter
    Serial.begin(9600);
}

// Loops
void loop() {
  //In order to use an updating LCD display, a recurring for loop is needed 
    for(i=0;i<1000;i++) {
      // Calculations
        Volts = analogRead(Value) * 5.0/1023 ; // Reads the Analog Input, 5/1023 = 4.9 mV which is the Arduino resolution
        Power = (Volts*Volts)/Ohm; //Uses the P = V^2/R equation to find power
        Energy += Power; // See Appendix 1B 
        Kwh = Energy / 3.6e6; // Turns it from Joules to kilowatt-hours ( 1 Joule = 2.778e-7 kWh) 
      // Printing Results on LCD
        // Voltage
          lcd.setCursor(8,0);
          lcd.print(Volts);
        // Energy
          lcd.setCursor(7,1);
          lcd.print(Kwh);
        // Power
          Serial.println(Power); //Puts the power numbers on the serial plotter
        // Making sure the results are legible
          delay(1000); // delays results by 500 ms
      // Resets the for Loop
      if (i == 999) {
        i = 0;
      }
    }   
 }

/*
 Appendix: 
 
  1A The circuit:
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
 * 
 1B: The Energy calculation
 * The total energy generated is an estimate that uses the delay in the for loop. 
 * The power shown is the number of watts, with the energy shown being that wattage generated over a second
 * That energy, similar to a step-function, increases over time as Joules
 * It is then turned into kWh for teh function itself
*/
