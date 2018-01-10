/*

Interfacing Arduino with Raspberry Pi/Computer 

Receives one ASCII character via serial communication. Interprets the character as a command under the 'Switch' control strtucture. 
Analog values are read by sending the letter 'A', followed by the analog pin number. Any letter can be added to the structure. 

Examples:
  -command 'B' activates pin 3 = HIGH
  -command 'A3' reads the analog input on pin A3, returns the digital value

*/

int del = 1000; //blinking delay
byte val;
int a = 0; //analog value
int pin;

void setup() {

  Serial.begin(9600);                   // set baud rate to 9600
   
  pinMode(13, OUTPUT);  // initialize digital pin as an output.
  pinMode(3, OUTPUT);  // initialize digital pin as an output.
  pinMode(4, OUTPUT);  // initialize digital pin as an output.
 
}

void loop()
{
 
  if (Serial.available()) {     // check if data has been sent from Computer/Pi

    val = Serial.read();        // read the most recent byte (which will be from 0 to 255)
 
      switch(val) {             // decide what to to, extended set of commands
      
        case '0':               // reset led delay 
            del=1000;
        break;
        
        case 'B':               // 
            del=350;
            digitalWrite(3, HIGH); 
        break;

        case 'C':               // 
            del=500;
            digitalWrite(4, HIGH); 
        break;

        case 'D':               // 
            del=500;
            digitalWrite(3, LOW); 
        break;

        case 'E':               // 
            del=400;
            digitalWrite(4, LOW); 
        break;

        case 'F':               // 
            del=2000;
        break;
        
        case 'p':               // 
            del=30;
        break;

        case 'A':               //  read analog pin. Returns integer value (0-1024).
            del=50;

            pin = Serial.read();        // reads pin number. 
            switch(pin) {             
      
            case '0':               // 
                a = analogRead(A0);
            break;
            case '1':               // 
                a = analogRead(A1);
            break;
            case '2':               //
                a = analogRead(A2);
            break;
            case '3':               // 
                a = analogRead(A3);
            break;
            case '4':               // 
                a = analogRead(A4);
            break;
            case '5':               // 
                a = analogRead(A5);
            break;
            }
        
            Serial.println(a); //returns pin number
        break;
        
      }
  }

    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(del);              // wait for a second
    digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    delay(del);  
  

} // end of main loop

