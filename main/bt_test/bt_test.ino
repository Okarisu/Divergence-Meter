/*   
HC05 - Bluetooth AT-Command mode  
modified on 10 Feb 2019 
by Saeed Hosseini 
https://electropeak.com/learn/ 
*/ 
#include <SoftwareSerial.h> 
SoftwareSerial MyBlue(2, 3); // RX | TX 
String flag; 
int LED = 13; 
void setup() 
{   
  Serial.begin(9600); 
  MyBlue.begin(9600); 
  pinMode(LED, OUTPUT); 
  Serial.println("Ready to connect\nDefualt password is 1234 or 000"); 
} 
void loop() 
{ 
  if (MyBlue.available()>=0) 
    flag = MyBlue.read(); 
  if (flag == 1) 
  { 
    digitalWrite(LED, HIGH); 
    Serial.println("LED On");
    
  } 
  else if (flag == 0) 
  { 
    digitalWrite(LED, HIGH); 
    Serial.println("LED Off"); 
  } 
/*switch (flag){

  case "on":
    digitalWrite(LED, HIGH); 
    Serial.println("LED On");
    break;

   case "off":
    digitalWrite(LED, LOW); 
    Serial.println("LED Off");
    break;


*/


}
 
