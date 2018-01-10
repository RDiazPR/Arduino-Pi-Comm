/*

Listens for commands via I2C from Raspberry Pi

*/

#include <Wire.h> // Include the required Wire library for I2C

// set pin numbers for the five buttons:
const int ledPin = 13;

//Declarations
String inString = "";
int inChar = 0;
int power = 0;
int analogval = 0;
bool sendkeys = LOW;
byte orden;
char buffer[10];         //the ASCII of the integer will be stored in this char array (message sent)

void setup() { // initialize the buttons' inputs:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

  Wire.begin(8); // Start the I2C Bus as Slave on address 8
  Wire.onReceive(receiveEvent); // Attach a function to trigger when something is received.
  Wire.onRequest(requestEvent); // register event
}

void loop() {
  
  
  Serial.print("No command yet. Analog value = ");
  Serial.println(analogval);
  
       if (sendkeys){
        Serial.println(inString);
          orden = Wire.read();    // read command character

        switch (orden) {

        case 'P': //change set power
        
          inString = ""; //clear input string
           for (int i=1; i<=4; i++) {
             inChar = Wire.read();    // read next character from the I2C
              inString += (char)inChar;
            }
            power = inString.toInt();
            Serial.print("Power = ");
            Serial.println(power);
           
         break;

         //insert new commands here.<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

        }//end switch command interpretation
        
        sendkeys = LOW; //return to standby mode    
        }//end if command received
        
       analogval = analogRead(A0); //read analog value
       
        digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(200);           // wait for a second
        digitalWrite(ledPin, LOW);   // turn the LED on (HIGH is the voltage level)
        delay(200);
        }

void receiveEvent(int bytes) {
  sendkeys = HIGH;
}

void requestEvent() {
  Serial.println("Request received");
  int number = analogval;
  Serial.print("Number sent:");
  Serial.println(number);
  Wire.write(itoa(number,buffer,10)); //(integer, yourBuffer, base)
}

  
