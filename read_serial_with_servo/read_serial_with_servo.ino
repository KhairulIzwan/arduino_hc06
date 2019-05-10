/*
 * SoftwareSerail -- Create another UART/Serial communincation
 */
#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 4); // RX, TX

/*
 * 
 */
#include <Servo.h>
Servo myservo;

#define LED 13

// Create a variables
int data = 0;
char buffer[8];

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
  Serial.begin(9600);

  pinMode(LED, OUTPUT);

  myservo.attach(9);
}

void loop() 
{
  if (mySerial.available() >= 3)
  {
    for (int i=0; i<3; i++)
    {
      buffer[i] = mySerial.read();
    }
  }
  
//  //  C -- Open
//  if (strcmp(buffer[0], 'C') == 0)
//  {
//    if (atoi(buffer[1]) == 1)
//    {
//      digitalWrite(LED, LOW); 
//    }
//    else
//    {
//      digitalWrite(LED, HIGH);
//    }
//  }
//  //  D -- Close
//  else if (strcmp(buffer[0], 'D') == 0)
//  {
//    if (atoi(buffer[1]) == 1)
//    {
//      digitalWrite(LED, LOW); 
//    }
//    else
//    {
//      digitalWrite(LED, HIGH);
//    }
//  }

  if (strcmp(buffer[0], 'C') == 0)
  {
    if (strcmp(buffer[1], '1') == 0)
    {
      if (strcmp(buffer[2], '2') == 0)
      {
        digitalWrite(LED, HIGH);
        myservo.write(180);  
      }
    }
//    else
//    {
//      digitalWrite(LED, LOW);  
//    }
  }
  else if (strcmp(buffer[0], 'D') == 0)
  {
    if (strcmp(buffer[1], '1') == 0)
    {
      if (strcmp(buffer[2], '2') == 0)
      {
        digitalWrite(LED, LOW);
        myservo.write(0);
      }
    }
//    else
//    {
//      digitalWrite(LED, HIGH);
//    }
  }
  else
  {
    digitalWrite(LED, LOW);
  }
  Serial.println(buffer);
}

//if (atoi(buffer[1]) == 1)
//{
//  digitalWrite(LED, HIGH);
//}
//else if (atoi(buffer[1]) != 1)
//{
//  digitalWrite(LED, LOW);
//}
