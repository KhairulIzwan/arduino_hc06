# arduino_hc06
Arduino UNO with HC-06 Bluetooth module -- suitable for troubleshoot; check the data send/recieve.

## Wiring Diagram
![Alt text](https://github.com/KhairulIzwan/arduino_hc06/blob/master/img/HC06.png)

## Code
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
