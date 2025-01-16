#include "ILED4.h"

ILED4 seg(0x70);

uint32_t start, stop, d1, d2;


void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);
  //Wire.begin(4,5); // I2C For Kidbright32ix 
  Wire.begin();
  Wire.setClock(100000);
  seg.begin();

  seg.displayOn();
  seg.setBrightness(2);
  seg.displayClear();
  seg.setBlink(0);

  seg.cacheOff();
  start = millis();
  seg.displayTest(0);
  Serial.println(millis() - start);

  seg.cacheOn();
  start = millis();
  seg.displayTest(0);
  Serial.println(millis() - start);
}


void loop()
{
  uint8_t x[4] = { 255, 255, 255, 255 };
  seg.displayClear();
  delay(1000);
  seg.displayRaw(x);
  delay(1000);
  seg.displayRaw(x, true);
  delay(1000);
  seg.displayRaw(x, false);
  delay(1000);

  test_elsa();  // limited text possible
  delay(1000);
  test_random();
  delay(1000);
}


void test_elsa()
{
  uint8_t ar[4];
  ar[0] = 0x79;
  ar[1] = 0x38;
  ar[2] = 0x6D;
  ar[3] = 0x77;
  seg.displayRaw(ar);
}


void test_random()
{
  uint8_t ar[4];
  for (uint8_t run = 0; run < 50; run++)
  {
    for (uint8_t i = 0; i < 4; i++)
    {
      ar[i] = random(256);
    }
    seg.displayRaw(ar, random(2));
    delay(100);
  }
}


// -- END OF FILE --

