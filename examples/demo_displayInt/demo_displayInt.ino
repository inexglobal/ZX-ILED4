#include "ILED4.h"

ILED4 seg(0x70);

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
}
void loop()
{
  Serial.print("INT TEST 0:\t");
  for (int16_t d = 4; d >= 0; d--)
  {
    seg.setDigits(d);
    seg.displayInt(0);
    delay(1000);
    seg.setDigits(d);
    seg.displayInt(8);
    delay(1000);
    seg.setDigits(d);
    seg.displayInt(-8);
    delay(1000);
  }
  for (int16_t d = 0; d <= 4; d++)
  {
    seg.setDigits(d);
    seg.displayInt(0);
    delay(1000);
    seg.setDigits(d);
    seg.displayInt(8);
    delay(1000);
    seg.setDigits(d);
    seg.displayInt(-8);
    delay(1000);
  }
  Serial.println();
  delay(1000);

  Serial.print("INT TEST 1:\t");
  seg.setDigits(1);
  for (int16_t counter = -200; counter < 1001; counter += 7)
  {
    seg.displayInt(counter);
    delay(100);
  }
  Serial.println();
  delay(1000);

  Serial.print("INT TEST 2:\t");
  seg.setDigits(4);
  for (int16_t counter = -200; counter < 1001; counter += 7)
  {
    seg.displayInt(counter);
    delay(100);
  }
  Serial.println();
  delay(1000);

}
// -- END OF FILE --

