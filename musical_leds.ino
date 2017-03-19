int levelLeds[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 }; // LEDs from 2 to 11 pin of Arduino
 
void setup() {
  for (int i = 0; i < 10; i++) {
    pinMode(levelLeds[i], OUTPUT);
    digitalWrite(levelLeds[i], LOW);
  }
  //Serial.begin(9600); 
}
 
int ecmPin = 0; // Analog pin 0 from microphone amplifier
 
void loop()
{
  static int lastEcmLevel = 0;
  int input = analogRead(ecmPin);
 
  //Serial.print(input);
  //Serial.print(", ");
 
  input = abs(input - 512);
 
  //Serial.println(input);
  
  // 50 - minimal value of signal,
  // 380 - maximal value of signal,
  // 0 - I don't know :D, 10 - amount of diodes
  int ecmLevel = map(input, 50, 380, 0, 10);
 
  //  if (ecmLevel > lastEcmLevel)
  //    lastEcmLevel++;
  //  else if (ecmLevel < lastEcmLevel)
  //    lastEcmLevel--;
  lastEcmLevel = ecmLevel;
 
  int pos;
  for (pos=0; pos < lastEcmLevel; pos++) {
    digitalWrite(levelLeds[pos], HIGH);
  }
 
  for (; pos < 10; pos++) { // 10 - amount of diodes
    digitalWrite(levelLeds[pos], LOW);
  }
 
  delay(5);
}
