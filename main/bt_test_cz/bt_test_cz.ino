// Arduino Bluetooth modul HC-05

#define RX 2;
#define TX 3;

// nastavení propojovacích pinů Bluetooth a LED diody
#define pinLED 13
// připojení knihovny SoftwareSerial
#include <SoftwareSerial.h>
// inicializace Bluetooth modulu z knihovny SoftwareSerial
SoftwareSerial bluetooth(TX, RX);

void setup()
{
  // zahájení komunikace s Bluetooth modulem
  // skrze Softwarovou sériovou linku rychlostí 9600 baud
  bluetooth.begin(9600);
  bluetooth.println("Arduino zapnuto, test Bluetooth..");
  // nastavení pinu s LED diodou jako výstup
  pinMode(pinLED, OUTPUT);
}
//    /
//  /
void loop()
{
  // proměnná pro ukládání dat z Bluetooth modulu
  byte BluetoothData;
  // kontrola Bluetooth komunikace, pokud je dostupná nová
  // zpráva, tak nám tato funkce vrátí počet jejích znaků
  if (bluetooth.available() > 0)
  {
    // načtení prvního znaku ve frontě do proměnné
    BluetoothData = bluetooth.read();
    // dekódování přijatého znaku
    switch (BluetoothData)
    {
    // každý case obsahuje dekódování jednoho znaku
    case '0':
      // v případě přijetí znaku nuly vypneme LED diodu
      // a vypíšeme hlášku zpět do Bluetooth zařízení
      digitalWrite(pinLED, LOW);
      bluetooth.println("Vypni LED diodu.");
      break;
    case '1':
      // v případě přijetí jedničky zapneme LED diodu
      // a vypíšeme hlášku zpět do Bluetooth zařízení
      digitalWrite(pinLED, HIGH);
      bluetooth.println("Zapni LED diodu.");
      break;
    case 'a':
      // v případě přejetí znaku 'a' vypíšeme
      // čas od spuštění Arduina
      bluetooth.print("Cas od spusteni Arduina: ");
      bluetooth.print(millis() / 1000);
      bluetooth.println(" vterin.");
      break;
    case 'b':
      // zde je ukázka načtení většího počtu informací,
      // po přijetí znaku 'b' tedy postupně tiskneme
      // další znaky poslané ve zprávě
      bluetooth.print("Nacitam zpravu: ");
      BluetoothData = bluetooth.read();
      // v této smyčce zůstáváme do té doby,
      // dokud jsou nějaké znaky ve frontě
      while (bluetooth.available() > 0)
      {
        bluetooth.write(BluetoothData);
        // krátká pauza mezi načítáním znaků
        delay(10);
        BluetoothData = bluetooth.read();
      }
      bluetooth.println();
      break;

    case 'x':

    case '\r':
      // přesun na začátek řádku - znak CR
      break;
    case '\n':
      // odřádkování - znak LF
      break;
    default:
      // v případě přijetí ostatních znaků
      // vytiskneme informaci o neznámé zprávě
      bluetooth.println("Neznamy prikaz.");
    }
  }
  // krátká pauza mezi kontrolami komunikace Bluetooth modulu
  delay(100);
}
