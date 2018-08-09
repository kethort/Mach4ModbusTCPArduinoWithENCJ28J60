# mach4_arduino_inputs_over_modbus
Inputs from Arduino to Mach4 using Modbus over Ethernet

## Hardware

Using Arduino UNO and a NANO ENC28J60 ethernet shield. Pins 13, 12, 11, and 10 are reserved for the ethernet shield and are connected to the Arduino UNO at the same pins. 

<p align="center">
  <img src="/img/nano_ethernet.jpg" width="500"/>
</p>

## Software
### Arduino
TCP_KEEP_ALIVE is uncommented in the ModbusIP_ENC28J60.h header file in this fork of the Arduino Modbus library: 

https://github.com/kenneth-orton/modbus-arduino 

Download the forked repo as zip and import as library in arduino.

The Mach4Modbus.ino file in <b>this</b> repository should be edited for the inputs you want to use and the IP address you want for your device. Pins 13, 12, 11, and 10 are reserved for the ethernet shield and cannot be used as inputs.

### Mach4
The latest version of Mach4 comes with the Modbus plugin by default. The following images show the setup for reading 10 input states. The registers at every (n + 8) register do not "register" for inputs in Mach4 Modbus Read Coils function.

Mach4 file menu goto Configure->Plugins..->Modbus

Configure IP address and TCP port:

<p align="center">
  <img src="/img/Read_Coils_3.PNG" width="500"/>
</p>

<p align="center">
  <img src="/img/Read_Coils_1.PNG" width="500"/>
</p>

<p align="center">
  <img src="/img/Read_Coils_2.PNG" width="500"/>
</p>

Mach4 file menu goto Diagnostic->Modbus to test inputs:

<p align="center">
  <img src="/img/Read_Coils_4.PNG" width="500"/>
</p>

