#include <AR_SoundSensor.h>
#include <AR_PinAssign.h>

AR_SoundSensor ss(DS1_PIN, AS1_PIN);

uint8_t dsound = 0;
int  asound = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  dsound = ss.ifSound();
  Serial.println(ifsound);
  asound = ss.getSound();
  Serial.println(sound);
}