/*
 * SoftwareSerail -- Create another UART/Serial communincation
 */
#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 4); // RX, TX

// Create a variables
char buffer[8];

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
  Serial.begin(9600);
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
  Serial.println(buffer);
}
