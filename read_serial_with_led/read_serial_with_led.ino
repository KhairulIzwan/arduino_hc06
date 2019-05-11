/*
 * SoftwareSerail -- Create another UART/Serial communincation
 */
#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 4); // RX, TX

#define LED 13

void setup()
{
  mySerial.begin(9600);
  Serial.begin(9600);

  pinMode(LED, OUTPUT);
}

void loop()
{
  if (mySerial.available() >= 2)
  {
    for (int i=0; i<2; i++)
    {
      char buffer[i] = mySerial.read();
    }
  }

  if (strcmp(buffer[0], 'C') == 0)
  {
    if (strcmp(buffer[1], 'C') == 0)
    {
      digitalWrite(LED, HIGH);
    }
    else
    {
      digitalWrite(LED, LOW);
    }
  }
  else if (strcmp(buffer[0], 'D') == 0)
  {
    if (strcmp(buffer[1], 'D') == 0)
    {
      digitalWrite(LED, LOW);
    }
    else
    {
      digitalWrite(LED, HIGH);
    }
  }
  Serial.println(buffer);
}
