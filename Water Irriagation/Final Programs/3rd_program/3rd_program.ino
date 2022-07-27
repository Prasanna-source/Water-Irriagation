#include <Wire.h>
#include <DS3231.h>

DS3231 clock;
RTCDateTime dt;
int motor = 4;     // change your relay i/p as per connection

void setup()
{
    Serial.begin(9600);

//Initialize DS3231
    Serial.println("Initialize DS3231");;
    clock.begin();
    pinMode(motor, OUTPUT);
//Set sketch compiling time
//clock.setDateTime(DATE, TIME);
}

void loop()
{
  dt = clock.getDateTime();

//For leading zero look to DS3231_dateformat example

  Serial.print("Raw data: ");
  Serial.print(dt.year);   Serial.print("-");
  Serial.print(dt.month);  Serial.print("-");
  Serial.print(dt.day);    Serial.print(" ");
  Serial.print(dt.hour);   Serial.print(":");
  Serial.print(dt.minute); Serial.print(":");
  Serial.print(dt.second); Serial.println("");

  delay(1000);

// Here I'm using (Active LOW Relay Logic) for Relay. 
// Morning Watering.
 
  if (dt.hour == 9 && dt.minute == 15 && dt.second == 0)
  {
    digitalWrite(motor, LOW);
    Serial.print("Morning watering");
    delay(300000);  // 5 min 
  }
 
// Evening Watering
  if (dt.hour == 18 && dt.minute == 1 && dt.second == 0)
  {
    digitalWrite(motor, LOW);
    Serial.print("Evening watering");
    delay(300000);     // 5 min
  }
  else
  {
    digitalWrite(motor, HIGH);
  }
}
