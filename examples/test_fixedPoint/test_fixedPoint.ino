
#include "ILED4.h"

ILED4 seg(0x70);


void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);

  Wire.begin();
  Wire.setClock(100000);

  if (! seg.begin())
  {
    Serial.println("not connected");
  }

  seg.displayOn();

  seg.displayFixedPoint0(1.945);
  delay(1000);
  seg.displayFixedPoint1(1.945);
  delay(1000);
  seg.displayFixedPoint2(1.945);
  delay(1000);
  seg.displayFixedPoint3(1.945);
  delay(1000);
}


void loop()
{
  test_printFixedPoint();
  Serial.println("---------------");
  delay(1000);
}


void test_printFixedPoint()
{
  for (int i = -2000; i < 2000; i++)
  {
    float f = i * 0.001;
    seg.displayFixedPoint3(f);
    delay(2);
  }

  for (int i = -2000; i < 2000; i++)
  {
    float f = i * 0.001;
    seg.displayFixedPoint2(f);
    delay(2);
  }

  for (int i = -2000; i < 2000; i++)
  {
    float f = i * 0.001;
    seg.displayFixedPoint1(f);
    delay(2);
  }

  for (int i = -2000; i < 2000; i++)
  {
    float f = i * 0.001;
    seg.displayFixedPoint0(f);
    delay(2);
  }
}


// -- END OF FILE --

