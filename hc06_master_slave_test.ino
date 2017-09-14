/* HC Serial Bluetooth Module (HC-06) [S018] : http://rdiot.tistory.com/183 [RDIoT Demo] */

#include <SoftwareSerial.h>
SoftwareSerial BT_Serial(2,3); //RX, TX
 
void setup()
{
  Serial.begin(9600);
  BT_Serial.begin(9600); // connect bluetooth
}
 
void loop()
{
  if(BT_Serial.available())
    Serial.write(BT_Serial.read()); // bluetooth read
    
  if(Serial.available())
    BT_Serial.write(Serial.read()); // bluetooth write  
}
