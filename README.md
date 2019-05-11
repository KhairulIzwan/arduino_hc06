# arduino_hc06
Basic use of Arduino UNO with HC-06 Bluetooth module.
- using **SoftwareSerial** library instead of hardware serial exist on arduino board.

## Arduino UNO PinOut
![Alt text](https://github.com/KhairulIzwan/arduino_hc06/blob/master/img/Introduction-to-Arduino-UNO.png)

# Reading Serial on the Arduino
## How should us read from serial?
- serial data arrives one character at a time, and we have little or no control over just when that data arrives.
- Arduino has a handy function: Serial.available(), which tells us how many characters are in the serial device’s receive buffer.

```c++
if (Serial.available() > 0) {
  for (int i=0; i<8; i++) {
    buffer[i] = Serial.read();
  }
}
```
- this code is intended to wait for the message to arrive, then read all 8 characters of it into a buffer **wrong**.
- **truth** it actually wait for the first character of the message to arrive and then try and read in 8 characters into the buffer, whether or not they have actually arrived.

- **correct** way to do it:
```c++
if (Serial.available() >= 8) {
  for (int i=0; i<8; i++) {
    buffer[i] = Serial.read();
  }
}
```

## What to do if we don’t know how many characters we will be receiving?
- need to have some marker that tells the receiver when the whole message has arrived.
- The normal marker to use is character **13**, or the carriage return character. Keyboard press for the **RETURN** or **ENTER** key.
