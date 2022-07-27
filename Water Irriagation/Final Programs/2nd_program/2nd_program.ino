// After uploading 1st progam upload this program without changing anyting

#include<DS3231.h>
DS3231 rtc(SDA, SCL);

void setup()
{
  Serial.begin(9600);
  rtc.begin();

  }

 void loop()
 {
  delay(1000);
  Serial.print("TIME -- ");
  Serial.print(rtc.getTimeStr());

  Serial.print("DATE  -- ");
  Serial.println(rtc.getDateStr());
    
  }
