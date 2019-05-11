/*
 * SoftwareSerail -- Create another UART/Serial communincation
 */
#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 4); // RX, TX

#define LED 13

void setup()
{
  mySerial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop()
{
  if (mySerial.available() >= 1)
  {
    for (int i=0; i<1; i++)
    {
      char buffer[i] = mySerial.read();
    }
  }

  if (strcmp(buffer[0], 'C') == 0)
  {
    digitalWrite(LED, HIGH);
  }
  else if (strcmp(buffer[0], 'D') == 0)
  {
    digitalWrite(LED, LOW);
  }

}
