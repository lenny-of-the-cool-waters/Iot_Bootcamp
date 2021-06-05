#include <SoftwareSerial.h>
SoftwareSerial esp(2,3);  //Instantiating the class

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  esp.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:

   Serial.println("");
  while (esp.available() > 0) {
    char inByte = esp.read();
    Serial.write(inByte);
  }
  
    Serial.println("");
  while (Serial.available() > 0) {
    char outByte = Serial.read();
    Serial.write(outByte);
  }
}
