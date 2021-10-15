void setup() {


Serial.begin(9600);
}

void loop() {

  float runtimeSeconds = millis() / 1000;

    
    Serial.print("System runtime: ");
    Serial.print(runtimeSeconds);
    Serial.print(" seconds - aprox ");
    Serial.print(runtimeSeconds / 60);
    Serial.print(" minutes - aprox ");
    Serial.print(runtimeSeconds / 3600);
    Serial.print(" hours - aprox ");
    Serial.print(runtimeSeconds / 86400);
    Serial.println(" days.");


}
