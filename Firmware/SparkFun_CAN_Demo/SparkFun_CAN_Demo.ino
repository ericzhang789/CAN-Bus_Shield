/****************************************************************************
CAN-Bus Demo

Toni Klopfenstein @ SparkFun Electronics
September 2015
https://github.com/sparkfun/CAN-Bus_Shield

This example sketch works with the CAN-Bus shield from SparkFun Electronics.

It enables the MCP2515 CAN controller and MCP2551 CAN-Bus driver, and demos
using the chips to communicate with a CAN-Bus.


Resources:

Development environment specifics:
Developed for Arduino 1.6.5


This code is beerware; if you see me (or any other SparkFun employee) 
at the local, and you've found our code helpful, please buy us a round!

Distributed as-is; no warranty is given.
*************************************************************************/

#include <Canbus.h>
char UserInput;
int data;
char buffer[512];  //Data will be temporarily stored to this buffer before being written to the file

//********************************Setup Loop*********************************//

void setup(){
Serial.begin(9600);
Serial.println("CAN-Bus Demo");

if(Canbus.init(CANSPEED_500))  /* Initialise MCP2515 CAN controller at the specified speed */
  {
    Serial.println("CAN Init ok");
  } else
  {
    Serial.println("Can't init CAN");
  } 
   
  delay(1000); 

Serial.println("Please choose a menu option.");
Serial.println("1.Speed");
Serial.println("2.RPM");
Serial.println("3.Throttle");
Serial.println("4.Coolant Temperature");
Serial.println("5.O2 Voltage");
Serial.println("6.MAF Sensor");

}



//********************************Main Loop*********************************//

void loop(){

while(Serial.available()){
   UserInput = Serial.read();

if (UserInput=='1'){
 data=Canbus.ecu_req(VEHICLE_SPEED, buffer);
 Serial.print("Vehicle Speed: ");
 Serial.print(data);
 Serial.println(" km/hr ");
 delay(1000);
}

if (UserInput=='2'){
 data= Canbus.ecu_req(ENGINE_RPM, buffer);
 Serial.print("Engine RPM: ");
 Serial.print(data);
 Serial.println(" rpm ");
 delay(1000);

}

if (UserInput=='3'){
 data= Canbus.ecu_req(THROTTLE, buffer);
 Serial.print("Throttle: ");
  Serial.print(data);
 Serial.println(" %% ");
 delay(1000);

}

if (UserInput=='4'){
 data =Canbus.ecu_req(ENGINE_COOLANT_TEMP, buffer);
 Serial.print("Engine Coolant Temp: ");
 Serial.print(data);
 Serial.println(" degC");
 delay(1000);

}

if (UserInput=='5'){
 data=Canbus.ecu_req(O2_VOLTAGE, buffer);
 Serial.print("O2 Voltage: ");
 Serial.print(data);
 Serial.println(" V");
 delay(1000);

}

if (UserInput=='6'){
 data=Canbus.ecu_req(MAF_SENSOR, buffer);
 Serial.print("MAF Sensor: ");
 Serial.print(data);
 Serial.println(" g/s");
 delay(1000);

}
else
{
  Serial.println(UserInput);
  Serial.println("Not a valid input");
}

}
}

