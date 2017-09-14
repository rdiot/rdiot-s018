/* HC Serial Bluetooth Module (HC-06) [S018] : http://rdiot.tistory.com/183 [RDIoT Demo] */

#include <SoftwareSerial.h>
 
SoftwareSerial BTSerial(2, 3);
 
void setup()  
{
  Serial.begin(9600);
  BTSerial.begin(9600);
}
void loop()
{
  if (BTSerial.available())
    Serial.write(BTSerial.read());
  if (Serial.available())
    BTSerial.write(Serial.read());
}  
