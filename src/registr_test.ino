// pin připojen na RCLK registru (12)
int latchPin = 3;
//Pin connected to SRCLK registru (11)
int clockPin = 4;
////Pin připojen na Data pin registu (14)
int dataPin = 2;
 
 
void setup() {
 
  // nastaví naše piny pro regist na výstupní
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
 
    // když dáme latchPin na LOW mužeme
    // do registru poslat data
    digitalWrite(latchPin, LOW);
   
    // a to pomocí funkce shiftOut,
    // která po bitu odešle do registru
    // hodnotu b10101010
    shiftOut(dataPin, clockPin, LSBFIRST, B11111111);
    // MSBFIRS - znamená v jakém pořádí odesílá bity
    // v tomto případě první bit je jednička
    // a v registru se objeví až na konci,
    // protože se 8x posune
    // opak bude - LSBFIRST  
   
    // jakmile dáte latchPin na HIGH,
    // data se objeví na výstupu
    digitalWrite(latchPin, HIGH);    
}
 
void loop() {
   }
