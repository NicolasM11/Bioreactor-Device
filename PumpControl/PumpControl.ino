
#include <Wire.h>
#include <Adafruit_MCP4725.h>

Adafruit_MCP4725 dac;


/* 
  This code utilizes the Adafruit DAC module to send analog voltages to the MasterFlex Pump to control flow rate. 
  This code also turns the MasterFlex Pump on and off.

*/


void setup(void) {
  // enable pin connected to MasterFlex on/off port, 40 in this case
  pinMode(40, OUTPUT);
  
  // For Adafruit MCP4725A1 the address is 0x62 (default) or 0x63 (ADDR pin tied to VCC)
  // For MCP4725A0 the address is 0x60 or 0x61
  // For MCP4725A2 the address is 0x64 or 0x65
  dac.begin(0x62);
  // sets a voltage of 1.33 V
  // 5V is represented by 4096, so (1096/4096)*5 is 1.33 V...
  dac.setVoltage(1096, false); 
}

void loop(void) {
  // Turn on MasterFlex
  digitalWrite(40, HIGH);
  // Wait 5 seconds
  delay(5000);
  // Turn off MasterFlex
  digitalWrite(40, LOW);
  // Wait 5 seconds
  delay(5000);
}
