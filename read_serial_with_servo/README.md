# arduino_hc06
Blinking an LED using Arduino UNO with HC-06 Bluetooth module.

## Wiring Diagram
![Alt text](https://github.com/KhairulIzwan/arduino_hc06/blob/master/img/HC06_LED_Servo.png)

## Code
```c++
#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 4); // RX, TX

#include <Servo.h>
Servo myservo;
```
- import **SoftwareSerial** library instead of hardware serial (RX-0, TX-1) on the arduino board.
- import **Servo** library as my servo to control servo motor.

```c++
#define LED 13
```
- define pin #13 as LED

```c++
void setup()
{
  mySerial.begin(9600);
  Serial.begin(9600);

  pinMode(LED, OUTPUT);

  myservo.attach(9);
}
```
- start the SoftwareSerial, Serial, define pinMode (LED --> OUTPUT), and sero at pin #9.

```c++
if (mySerial.available() >= 5)
```
- checking by limiting the number of data receive, in this case **5**.

```c++
for (int i=0; i<5; i++)
{
  buffer[i] = mySerial.read();
}
```
- once received, only then the data can be displayed or process for the next step.

```c++
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
```
- compare the string received; if **true --> 0**, else **false --> 1**.
- compare **5** data recieved.
