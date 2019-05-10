/*
 * SoftwareSerail -- Create another UART/Serial communincation
 */
#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 4); // RX, TX

String inputString = "";
String command = "";
String value = "";
String password = "arduPi"; // this is the password for opening and closing your door
                            // you can set any pasword you like using digit and symbols
boolean stringComplete = false; 

int data = 0;

#define LED 13

char incoming;

void setup(){
  //start serial connection
  Serial.begin(9600);  // baud rate is 9600 must match with bluetooth
  mySerial.begin(9600);
   
//  //The String reserve() function allows you to allocate a buffer in memory for manipulating strings.
//  inputString.reserve(50);  // reserve 50 bytes in memory to save for string manipulation 
//  command.reserve(50);
//  value.reserve(50);
//  
//  boolean stringOK = false;

//  digitalWrite(LED, LOW);
  pinMode(LED, OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
//  if (mySerial.available()){
//    data = mySerial.read();
//    Serial.println(data);
//  }
  serialEvent();
}
//  if (stringComplete) {
//    //Serial.println(inputString);
//    delay(100);
//    // identified the posiion of '=' in string and set its index to pos variable
//    int pos = inputString.indexOf('=');
//    // value of pos variable > or = 0 means '=' present in received string.
//    if (pos > -1) {
//      // substring(start, stop) function cut a specific portion of string from start to stop
//      // here command will be the portion of received string till '='
//      // let received string is open=test123
//      // then command is 'open' 
//        command = inputString.substring(0, pos);
//      // value will be from after = to newline command
//      // for the above example value is test123
//      // we just ignoreing the '=' taking first parameter of substring as 'pos+1'
//      // we are using '=' as a separator between command and vale
//      // without '=' any other character can be used
//      // we are using = menas our command or password must not contains any '=', otherwise it will cause error 
//        value = inputString.substring(pos+1, inputString.length()-1);  // extract command up to \n exluded
//        //Serial.println(command);
//        //Serial.println(value);
//       
//       // password.compareTo(value) compare between password tring and value string, if match return 0 
//    if(!password.compareTo(value) && (command == "OPEN")){
//          // if password matched and command is 'OPEN' than door should open
//           openDoor(); // call openDoor() function
//           Serial.println(" OPEN"); // sent open feedback to phone
//           delay(100);
//           }
//    else if(!password.compareTo(value) && (command == "CLOSE")){
//          // if password matched and command is 'CLOSE' than door should close
//           closeDoor();
//           Serial.println(" CLOSE"); // sent " CLOSE" string to the phone 
//           delay(100);
//           }
//    else if(password.compareTo(value)){
//          // if password not matched than sent wrong feedback to phone
//           Serial.println(" WRONG");
//           delay(100);
//           } 
//        } 
//       // clear the string for next iteration
//       inputString = "";
//       stringComplete = false;
//    }
//   
//}


void serialEvent() 
{
  if(mySerial.available()>0) 
  {
    while(1) 
    {
      data=mySerial.read(); //read user input and move to data char
      if(data != '\n')
      {
        incoming = data; //if data doesn't equal newline data = incoming
      }
      if (data == '\n')
      {
        stringComplete = true;
        openDoor();
        break; // newline char detected break
      }
      if (data == -1) //continue reading all of user input
      {
        closeDoor();
        continue;
      }
      Serial.print(data);
      Serial.print(incoming);
    }
  }
}

void openDoor()
{
  digitalWrite(LED, HIGH);
}

void closeDoor()
{
  digitalWrite(LED, LOW);
}
