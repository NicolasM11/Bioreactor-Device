/*
  This code is ran on the Arduino Mega
  
  Receives from the hardware serial (User input), sends to software serial (to the UNO).
  
  The message is in the form of: "s705f0.0250e"
  Where 's' is the number of steps and 'f' is the desired frequency in hertz
  
  The circuit:
   RX is digital pin 10 (connect to TX of other device)
   TX is digital pin 11 (connect to RX of other device)

  Note:
  Not all pins on the Mega and Mega 2560 support change interrupts,
  so only the following can be used for RX:
  10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69

  Not all pins on the Leonardo and Micro support change interrupts,
  so only the following can be used for RX:
  8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).


*/
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 12); // RX, TX

void setup() {
  // Open serial communications and wait for port to open:
  delay(2000);
  Serial.begin(57600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  
}

void loop() { // run over and over
  // reads data from UNO (if any)
  if (mySerial.available()) {
    Serial.println(mySerial.readString()); 
  }
  // reads user input from serial terminal and sends message to UNO
  if (Serial.available()) {
    mySerial.print(Serial.readString());

  }
}
