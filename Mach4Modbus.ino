#include <ModbusIP_ENC28J60.h>

ModbusIP mb;
long ts;

int regs[] = {1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 17}; // values 0, 8 and 16 don't work for registers
int pins[] = {2, 3, 4, 5, 6, 7, 8, 9, 14, 15, 16, 17, 18, 19}; // pins 10, 11, 12 and 13 are reserved for ethernet shield

void setup() {
  int i = 0;
  // set the pins as inputs
  for(i = 0; i < sizeof(pins)/sizeof(pins[0]); i++)
    pinMode(pins[i], INPUT);
    
  // define a MAC and IP address for the hardware
  byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };  
  byte ip[] = { 192, 168, 1, 210 }; 
  mb.config(mac, ip);

  // setup the registers as coils
  for(i = 0; i < sizeof(regs)/sizeof(regs[0]); i++)
    mb.addCoil(regs[i]); 
    
  ts = millis();
}

void loop() {
  mb.task(); 
  int i = 0;
  // read the state of the input pins every 200ms
  if (millis() > ts + 200) {  
    ts = millis();
    
    for(i = 0; i < sizeof(regs)/sizeof(regs[0]); i++)
      mb.Coil(regs[i], digitalRead(pins[i])); 
  }
}
