// Variable declaration
const int button = 2;
int buttonState = 0; // Can be 0 or LOW
int red = 12;
int blue =11;
int green = 10;

void setup() {
  // Input
  pinMode(button, INPUT);
  // Outputs
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  buttonState = digitalRead(button);
  if(buttonState == HIGH) {
    digitalWrite(red, HIGH);
    digitalWrite(blue, LOW);
  } else {
    digitalWrite(red, LOW); 
    digitalWrite(blue, HIGH); 
  }
  
}
