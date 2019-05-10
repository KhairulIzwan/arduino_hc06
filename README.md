# arduino_hc06
Basic use of Arduino UNO with HC-06 Bluetooth module.

## Arduino UNO PinOut
![Alt text](https://github.com/KhairulIzwan/arduino_hc06/blob/master/img/Introduction-to-Arduino-UNO.png)

# Reading Serial on the Arduino
## How should us read from serial?
- serial data arrives one character at a time, and we have little or no control over just when that data arrives.
- Arduino has a handy function: Serial.available(), which tells us how many characters are in the serial device’s receive buffer.

- normally:
  if (Serial.available() > 0) {
      for (int i=0; i<8; i++) {
          buffer[i] = Serial.read();
        }
      }


<!-- -
```c++
if (Serial.available() >= 8) {
  for (int i=0; i<8; i++) {
    buffer[i] = Serial.read();
  }
}
``` -->
