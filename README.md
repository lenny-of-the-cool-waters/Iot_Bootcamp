# IoT Tutorials

This is an IoT course designed to teach the basics of handling the internet of things. It focuses on using the Ardunio uno, esp32, esp8266 and raspberry pi, in addition to assorted sensors. Concepts covered include basic prototyping, API consumption, Web development for IoT, thingspeak and many more.

## LESSON 1

- Circuit: 
    - red LED to pin 13
    - green LED to pin 12
    - blue LED to pin 11

-Concepts covered:
    Breadboards, LEDs, resistors

## LESSON 2

- Circuit: 
    - Lesson1 circuit
    - 5V to button to pin 2, resistor + gnd 

- Concepts covered: 
    Buttons 

## LESSON 3

- Circuit: 
    - Lesson 3 circuit
    - GND to photoresistor to (resistor + A0), (resistor + 5V) 

- Concepts covered:
    LCD, Serial monitor, Importing libraries, I2C

## LESSON 4

- Circuit: 
    - GY521 with SDA to A4, SCL to A5

- Concepts covered:
    Communication protocols (Intraboard/Interboard)

## Projects

* **esp32_dht11:** This project makes use of the eps32 dev board to get temperature and humidity from a DHT11. Once data is captured, it is sent to a website hosted on the local server where it is displayed dynamically
* **Serial_ESP:** In this project, the serial monitor is used to send AT commands to an esp8266 module. This form of serial communication is fundamental for learning to use the module as a beginner
* **Weather_tutorial:** This project uses the esp32 board to fetch weather data from openweather using its free api. The weather information is then parsed, formatted and displayed on the serial monitor 