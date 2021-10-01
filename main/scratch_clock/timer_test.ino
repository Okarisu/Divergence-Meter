// RTC Hodiny reálného času DS3231

// připojení potřebných knihoven
#include <Wire.h>
#include <DS3231.h>
// inicializace RTC z knihovny
DS3231 rtc;
// vytvoření proměnné pro práci s časem
RTCDateTime datumCas;

void setup() {
  // zahájení komunikace po sériové lince
  // rychlostí 9600 baud
  Serial.begin(9600);
  // zahájení komunikace s RTC obvodem
  rtc.begin();
  // nastavení času v RTC podle času kompilace programu,
  // stačí nahrát jednou
  rtc.setDateTime(__DATE__, __TIME__);
  // přímé nastavení času pro RTC
  //rtc.setDateTime(__DATE__, "12:34:56");
}
void loop() {
  // načtení času z RTC do proměnné
  datumCas = rtc.getDateTime();
  // postupný tisk informací po sériové lince
  Serial.print("Datum a cas DS3231: ");
  Serial.print(datumCas.year);   Serial.print("-");
  Serial.print(datumCas.month);  Serial.print("-");
  Serial.print(datumCas.day);    Serial.print(" ");
  Serial.print(datumCas.hour);   Serial.print(":");
  Serial.print(datumCas.minute); Serial.print(":");
  Serial.print(datumCas.second); Serial.println("");
  // pauza na konci smyčky loop
  delay(1000);
}