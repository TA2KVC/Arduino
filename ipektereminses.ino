int buzzerPin = 7;
int LDRPin = 0;

void setup()
{
}

void loop()
{
  int deger = analogRead(LDRPin);
  int pitch = 1000 + deger / 4;
  tone(buzzerPin, pitch);
}
