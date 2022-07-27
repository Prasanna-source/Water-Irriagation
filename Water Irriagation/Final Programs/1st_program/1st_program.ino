
/* First set your Date amd Time. then upload this code 
*/
#include<DS3231.h>
DS3231 rtc(SDA, SCL);

void setup() {
  rtc.begin();
  rtc.setTime(0, 0, 0);  // (12, 00, 00) 
  rtc.setDate(0, 0, 0);  // (07, 09, 2014)

}

void loop() {
  
}
