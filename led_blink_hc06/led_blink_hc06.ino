// Basic use of Bluetooth Serial Transceiver HC06

// Require SoftwareSerial library to convert ordinary digital pins as serial pins (TX, RX)
#include <SoftwareSerial.h>

// Namespace -- give a specific name for our new serial port
SoftwareSerial mySerial(3, 4); // RX, TX

// #define constantName value
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
  if (mySerial.available()){
    data = mySerial.read();
  }
  // Importtant: the '' and "" are different meaning
  if (data == '1'){
    // Any action put here!
    digitalWrite(LED, HIGH);
  }
  else if (data == '2')
  {
    // Any action put here!
    digitalWrite(LED, LOW);
  }

}
