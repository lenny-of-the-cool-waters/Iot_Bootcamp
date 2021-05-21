#include <LiquidCrystal_PCF8574.h>
#include <Wire.h>

LiquidCrystal_PCF8574 lcd(0x27);  // set the LCD address to 0x27 for a 16 chars and 2 line display

// Read potentiometer value
float light_intensity =  0.0;
const int light_pin = A0;
const int green_led = 13;

void setup() {
  // Start serial monitor 
  // Baud rate is basically rate of data transfer
  Serial.begin(9600);
  pinMode(green_led, OUTPUT);
  
  // Initialise LCD
  Wire.begin(); //  Initialise i2c
  Wire.beginTransmission(0x27);
  lcd.begin(16, 2); // initialize the lcd
  Serial.print("Start");
}

void loop() {
  // Read sensor value
  light_intensity = analogRead(light_pin); // This is a 10bit sensor (its resolution)
  float val = map(light_intensity,0,1023, 0,255);

  if(val < 150) {
    digitalWrite(green_led, HIGH);  
  } else {
    digitalWrite(green_led, LOW); 
  }
  
  // Print sensor value
  lcd.setBacklight(255);
  lcd.setCursor(0,0);
  lcd.print("Light intensity: ");
  lcd.setCursor(0,1);
  lcd.print(val);
  Serial.print("Light intensity: ");
  Serial.print(val);
  Serial.print("\n");
  delay(500);
  lcd.clear();
}
