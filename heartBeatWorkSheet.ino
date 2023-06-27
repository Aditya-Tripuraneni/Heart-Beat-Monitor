#define USE_ARDUINO_INTERRUPTS true // used for short delays in sending pulse data to make it easier to process


#include<LiquidCrystal.h> // including the LCD library needed
#include <PulseSensorPlayground.h>  // including the pulse sensor library needed


int const PULSE_SENSOR_PIN = 0; //A0 pin
int signal;
int thresh_hold = 550; // Thresh hold for pulse sensor
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // object for LCD monitor


PulseSensorPlayground pulseSensor; // Making object for pulse sensor

void setup() {
  Serial.begin(9600); // exchanges data at rate of 9600 bits per second
  lcd.begin(16, 2); // Creating LCD and defining dimensions of 16 columns and 2 rows
  pulseSensor.analogInput(0); // connects to pin A0
  pulseSensor.setThreshold(thresh_hold); //set thresh hold for pulse sensor
  pinMode(7, OUTPUT); // connect to pin 7 of arduino (for LED)

  if (pulseSensor.begin()){ // Short check to make sure our pulse sensor libary works
		Serial.println("PulseSensor object created!");
	}

}


void loop() {
  //empty for now students will write the code here

}



void measureHeartBeat(int heartBPM)
{
  if (pulseSensor.sawStartOfBeat()) // Constantly test to see if a beat happened 
  {               
    delay(10); 
		Serial.println("♥  A HeartBeat Happened ! "); // displays in console heart beat detected
		Serial.print("BPM: " + String(heartBPM)); // displays in console heart beats per minute
    lcd.print("Measured BPM:" + String(heartBPM)); // displays on LCD what the measured BPM is
    digitalWrite(7, 1); // Turn on LED light
    delay(100);
    digitalWrite(7, 0); // Turn off LED light
  }

}
