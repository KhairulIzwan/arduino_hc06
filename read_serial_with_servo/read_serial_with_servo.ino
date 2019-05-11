/*
 * SoftwareSerial -- Create another UART/Serial communincation
 */
#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 4); // RX, TX

/*
 * Servo library
 */
#include <Servo.h>
Servo myservo;

#define LED 13

void setup()
{
  mySerial.begin(9600);
  Serial.begin(9600);

  pinMode(LED, OUTPUT);

  myservo.attach(9);
}

void loop()
{
  if (mySerial.available() >= 5)
  {
    for (int i=0; i<5; i++)
    {
      buffer[i] = mySerial.read();
    }
  }

  if (strcmp(buffer[0], '1') == 0)
  {
    if (strcmp(buffer[1], '2') == 0)
    {
      if (strcmp(buffer[2], '3') == 0)
      {
        if (strcmp(buffer[3], '4') == 0)
        {
          if (strcmp(buffer[4], 'C') == 0)
          {
            digitalWrite(LED, HIGH);
            myservo.write(180);
          }
          else if (strcmp(buffer[4], 'D') == 0)
          {
            digitalWrite(LED, HIGH);
            myservo.write(0);
          }
        }
      }
    }
  }
  Serial.println(buffer);
}
