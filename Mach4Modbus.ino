#include <ModbusIP_ENC28J60.h>

ModbusIP mb;
long ts;

int regs[] = {1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 17}; // values 0, 8 and 16 don't work for registers
int pins[] = {2, 3, 4, 5, 6, 7, 8, 9, 14, 15, 16, 17, 18, 19};

void setup() {
  int i = 0;
  for(i = 0; i < sizeof(pins)/sizeof(pins[0]); i++)
    pinMode(pins[i], INPUT);
    
  byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };  
  byte ip[] = { 192, 168, 1, 210 };  
  mb.config(mac, ip);

  for(i = 0; i < sizeof(regs)/sizeof(regs[0]); i++)
    mb.addCoil(regs[i]);  //create reg
    
  ts = millis();
}

void loop() {
  mb.task(); // MB comms
  int i = 0;
  if (millis() > ts + 200) {  
    ts = millis();
    
    for(i = 0; i < sizeof(regs)/sizeof(regs[0]); i++)
      mb.Coil(regs[i], digitalRead(pins[i]));  //update reg val
  }
}
