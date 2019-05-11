# arduino_hc06
Control dc motor using Arduino UNO with HC-06 Bluetooth module.

## Wiring Diagram
![Alt text](https://github.com/KhairulIzwan/arduino_hc06/blob/master/img/HC06_LED_Motor.png)

## Code
```c++
#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 4); // RX, TX
```
- used **SoftwareSerial** library instead of hardware serial (RX-0, TX-1) on the arduino board.

```c++
#define LED 13
```
- define pin #13 as LED

```c++
mySerial.begin(9600);
Serial.begin(9600);

pinMode(LED, OUTPUT);
```
- start the SoftwareSerial, Serial, and define pinMode (LED --> OUTPUT)

```c++
if (mySerial.available() >= 2)
```
- checking by limiting the number of data receive, in this case **2**.

```c++
for (int i=0; i<2; i++)
{
  buffer[i] = mySerial.read();
}
```
- once received, only then the data can be displayed or process for the next step.

```c++
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
```
- compare the string received; if **true --> 0**, else **false --> 1**.
- compare double data recieved.
