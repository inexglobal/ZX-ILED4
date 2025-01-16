
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

    //  default followed by HT16K33_SPACE
  seg.displayUnit(1.23, 0);             //  no unit
  delay(1000);
  seg.displayUnit(1.23, 1);
  delay(1000);
  seg.displayUnit(1.23, 2);
  delay(1000);
  Serial.println();


  //  now followed by HT16K33_A
  seg.displayUnit(1.23, 0, HT16K33_A);  //   Ampere
  delay(1000);
  seg.displayUnit(1.23, 1, HT16K33_A);
  delay(1000);
  seg.displayUnit(1.23, 2, HT16K33_A);
  delay(1000);
  Serial.println();


  seg.displayUnit(-1.23, 0, HT16K33_C);  //  Celsius
  delay(1000);
  seg.displayUnit(-1.23, 1, HT16K33_C);
  delay(1000);
  seg.displayUnit(-1.23, 2, HT16K33_C);
  delay(1000);
  Serial.println();


  seg.displayUnit(12.3, 0, HT16K33_F);   //  Fahrenheit
  delay(1000);
  seg.displayUnit(12.3, 1, HT16K33_F);
  delay(1000);
  seg.displayUnit(12.3, 2, HT16K33_F);
  delay(1000);
  Serial.println();

  seg.displayUnit(12.3, 0, HT16K33_TOP_C);   //  c
  delay(1000);
  seg.displayUnit(12.3, 1, HT16K33_TOP_C);
  delay(1000);
  seg.displayUnit(12.3, 2, HT16K33_TOP_C);
  delay(1000);
  Serial.println();
  
  seg.displayUnit(12.3, 0, HT16K33_DEGREE);   //  °
  delay(1000);
  seg.displayUnit(12.3, 1, HT16K33_DEGREE);
  delay(1000);
  seg.displayUnit(12.3, 2, HT16K33_DEGREE);
  delay(1000);
  Serial.println();
  
  Serial.println("done");

}


void loop()
{
}


// -- END OF FILE --
