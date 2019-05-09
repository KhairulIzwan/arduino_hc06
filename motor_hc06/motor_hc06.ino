// Basic use of Bluetooth Serial Transceiver HC06

// Require SoftwareSerial library to convert ordinary digital pins as serial pins (TX, RX)
#include <SoftwareSerial.h>

// Namespace -- give a specific name for our new serial port
SoftwareSerial mySerial(3, 4); // RX, TX

// #define constantName value
#define LED 13

#define CW 7
#define CCW 8
#define PWM 6

#define SW 9

// Create a variables
int data = 0;

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);

  pinMode(LED, OUTPUT);
  
  pinMode(CW, OUTPUT);
  pinMode(CCW, OUTPUT);
  pinMode(PWM, OUTPUT);

  pinMode(SW, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (mySerial.available()){
    data = mySerial.read();
  }
  // Importtant: the '' and "" are different meaning
  if (data == 'A')  // Open
  {
    if (digitalRead(SW) == LOW)
    {
    // Any action put here!
    digitalWrite(LED, LOW);
    
    digitalWrite(CW, HIGH);
    digitalWrite(CCW, HIGH);
    analogWrite(PWM, 0);
    }
    else
    {
    // Any action put here!
    digitalWrite(LED, HIGH);
    
    digitalWrite(CW, LOW);
    digitalWrite(CCW, HIGH);
    analogWrite(PWM, 255);
    }
  }
  else if (data == 'B') //  Close
  {
    if (digitalRead(SW) == LOW)
    {
    // Any action put here!
    digitalWrite(LED, LOW);
    
    digitalWrite(CW, HIGH);
    digitalWrite(CCW, HIGH);
    analogWrite(PWM, 0);
    }
    else
    {
    // Any action put here!
    digitalWrite(LED, HIGH);
    
    digitalWrite(CW, HIGH);
    digitalWrite(CCW, LOW);
    analogWrite(PWM, 255);
    }
  }
  else
  {
  // Any action put here!
  digitalWrite(LED, LOW);
  
  digitalWrite(CW, HIGH);
  digitalWrite(CCW, HIGH);
  analogWrite(PWM, 0);
  }
}
