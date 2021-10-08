#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2, 3); // RX | TX
//int flag = 0;
byte btInput;

int LED = 8;
void setup()
{
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(LED, OUTPUT);
  Serial.println("Ready to connect\nDefualt password is 1234 or 000");
}
void loop()
{
  if (bluetooth.available())
    //flag = bluetooth.read();
    btInput = bluetooth.read();
  if (btInput == 1)
  {
    digitalWrite(LED, HIGH);
    Serial.println("LED On");
  }
  else if (btInput == 0)
  {
    digitalWrite(LED, HIGH);
    Serial.println("LED Off");
  }
}
