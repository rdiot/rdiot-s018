/* HC Serial Bluetooth Module (HC-06) [S018] : http://rdiot.tistory.com/183 [RDIoT Demo] */

#include "U8glib.h"
#include <SoftwareSerial.h>
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);
SoftwareSerial BTSerial(2, 3);
 
char data=NULL;
String str="";
int ledPin = 9;
 
void setup() {
 pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
  BTSerial.begin(9600);
}
 
void loop(void) {
 
  if (BTSerial.available()) 
  {
   //Serial.write(BTSerial.read()); 
    data = (char)BTSerial.read();
   
    if(data == '1') {
      digitalWrite(ledPin,HIGH);
      str = "ON";
    } else if(data == '0') {
      digitalWrite(ledPin,LOW);
      str = "OFF";
    }
   }
 
  // picture loop
  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
  
  // rebuild the picture after some delay
  delay(100);
 
}
 
void draw(void) {
  u8g.setFont(u8g_font_9x15B);
  u8g.setPrintPos(0, 12); 
  u8g.println("HC-06");
 
  u8g.setFont(u8g_font_helvB14);
  u8g.setPrintPos(0,40);
 
  u8g.print("data="+(String)data);
 
  u8g.setFont(u8g_font_helvB14);
  u8g.setPrintPos(0,60);
 
  u8g.print("cmd="+(String)str);
}
