#include <LiquidCrystal_PCF8574.h>
#include <Wire.h>
LiquidCrystal_PCF8574 lcd(0x27);

#define analogPin  A1 //the thermistor attach to 
#define beta 4090 //the beta of the thermistor

const int buttonLight = 10;
const int buttonTemp = 9; 
const int buttonMess = 8;
int lightState = 0;
int tempState = 0;
int messState = 0;

const int light_pin = A0;
float light_intensity =  0.0;

void setup()
{
  pinMode(buttonLight, INPUT);
  pinMode(buttonTemp, INPUT);
  pinMode(buttonMess, INPUT);
  
  // Initialise LCD
  Wire.begin(); //  Initialise i2c
  Wire.beginTransmission(0x27);
  lcd.begin(16, 2); // initialize the lcd
  Serial.print("Start");  
}

void loop()
{
   // Read button states
  lightState = digitalRead(buttonLight);
  tempState = digitalRead(buttonTemp);
  messState = digitalRead(buttonMess);
  
  if(lightState == HIGH) {
    // Read light sensor value
    light_intensity = analogRead(light_pin); // This is a 10bit sensor (its resolution)
    float val = map(light_intensity,0,1023, 0,255);
  
    lcd.clear();
    lcd.setBacklight(255);
    lcd.setCursor(0,0);
    lcd.print("Light intensity: ");
    lcd.setCursor(0,1);
    lcd.print(val);
  } else if(tempState == HIGH) {
    //read thermistor value 
    long a =analogRead(analogPin);
    //the calculating formula of temperature
    float tempC = beta /(log((1025.0 * 10 / a - 10) / 10) + beta / 298.0) - 273.0;
    float tempF = 1.8*tempC + 32.0;
  
    lcd.clear();
    lcd.setBacklight(255);
    lcd.setCursor(0, 0); // set the cursor to column 0, line 0
    lcd.print("Temp: ");// Print a message of "Temp: "to the LCD.
    // Print a centigrade temperature to the LCD.
    lcd.print(tempC);
    // Print the unit of the centigrade temperature to the LCD.
    lcd.print("  C");
    // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(0, 1); // set the cursor to column 0, line 1
    lcd.print("Fahr: ");
    lcd.print(tempF);// Print a Fahrenheit temperature to the LCD.
    lcd.print(" F"); // Print the unit of the Fahrenheit temperature to the LCD.  
  } else if(messState == HIGH) {
    lcd.clear();
    lcd.setBacklight(255);
    lcd.setCursor(0,0);
    lcd.print("Booster");
    lcd.setCursor(7,1);
    lcd.print("By Couch");
  } else {
    lcd.clear();
    lcd.setBacklight(255);
    lcd.setCursor(0,0);
    lcd.print("Zzzz");
  }

  delay(400);
}
