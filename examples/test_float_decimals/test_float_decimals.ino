

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

  seg.displayFloat(1.945, 3);
  delay(1000);
  seg.displayFloat(1.945, 2);
  delay(1000);
  seg.displayFloat(1.945, 1);
  delay(1000);
  seg.displayFloat(1.945, 0);
  delay(1000);
}


void loop()
{
  test_printfloat();
  Serial.println("---------------");
  delay(1000);
}


void test_printfloat()
{
  uint8_t decimals = 3;
  for (int i = -2000; i < 2000; i++)
  {
    float f = i * 0.001;
    seg.displayFloat(f, decimals);
    delay(2);
  }

  decimals = 2;
  for (int i = -2000; i < 2000; i++)
  {
    float f = i * 0.001;
    seg.displayFloat(f, decimals);
    delay(2);
  }

  decimals = 1;
  for (int i = -2000; i < 2000; i++)
  {
    float f = i * 0.001;
    seg.displayFloat(f, decimals);
    delay(2);
  }

  decimals = 0;
  for (int i = -2000; i < 2000; i++)
  {
    float f = i * 0.001;
    seg.displayFloat(f, decimals);
    delay(2);
  }

}


// -- END OF FILE --

