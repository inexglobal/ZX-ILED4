//
//    FILE: demo_temperature_humidity.ino
//  AUTHOR: Rob Tillaart

//  https://github.com/RobTillaart/DHTNew


#include "ILED4.h"
#include "dhtnew.h"


ILED4 seg(0x70);
DHTNEW dht(32);// GPIO32
uint32_t lastTime = 0;
bool flag = true;


void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);

  Wire.begin();
  Wire.setClock(100000);
  seg.begin();
  
  seg.displayOn();
}


void loop()
{

  uint32_t now = millis();
  if (now - lastTime > 4000)
  {
    lastTime = now;
    dht.read();

    if (flag)
    {
      seg.displayFixedPoint1(dht.getTemperature());
    }
    else
    {
      seg.displayFixedPoint1(dht.getHumidity());
    }
    flag = !flag;
  }
}


// -- END OF FILE --

