/*
 * SoftwareSerail -- Create another UART/Serial communincation
 */
#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 4); // RX, TX

// Create a variables
int data = 0;
char buf[80];

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
  Serial.begin(9600);
}

void loop() 
{
  if (readline(mySerial.read(), buf, 80) > 0)
  {
    Serial.print("You entered: >");
    Serial.print(buf);
    Serial.println("<");
  }
}

int readline(int readch, char *buffer, int len)
{
  static int pos = 0;
  int rpos;
  
  if (readch > 0)
  {
    switch (readch)
    {
      // Ignore CR
      case '\r':
        break;

      // Return on new-line
      case '  ':
        rpos = pos;
        pos = 0;  // Reset position index ready for next time
        return rpos;

      default:
        if (pos < len-1)
        {
//          Serial.println("C");
          buffer[pos++] = readch;
          buffer[pos] = 0;
          Serial.print(buffer);
          Serial.print("You entered: >");
          Serial.print(buf);
          Serial.println("<");
        }
    }
  }
  return 0;
}

