/*
 * SoftwareSerail -- Create another UART/Serial communincation
 */
#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 4); // RX, TX

#define LED 13

// Create a variables
int data = 0;

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);

  pinMode(LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (mySerial.available())
  {
    data = mySerial.read();
  }

  // Importtant: the '' and "" are different meaning
  if (data == 'C')
  {
    // Any action put here!
    digitalWrite(LED, HIGH);
  }
  else if (data == 'D')
  {
    // Any action put here!
    digitalWrite(LED, LOW);
  }

}
