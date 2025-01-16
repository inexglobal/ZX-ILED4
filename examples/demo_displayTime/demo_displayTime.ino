
// sketch will work correctly up to 99:99

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
  seg.setDigits(4);
}


void loop()
{
  static uint32_t last = 0;
  uint32_t now = millis();
  if (now != last)
  {
    last = now;
    uint32_t s = now / 1000;
    uint32_t t = (now - s * 1000) / 10;
    s = s % 100;
    // seg.displayTime(s, t);
    seg.displayTime(s, t, true, false);  // do not display leading zero.
    seg.displayColon(1);
  }
}


// -- END OF FILE --

