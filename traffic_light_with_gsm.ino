#include <SoftwareSerial.h>
SoftwareSerial mySerial(7,6);
int red = 10;
int yellow = 9;
int green = 8;
int duration, distance;
//char object detected;
#define trigPin 12
#define echoPin 13
void setup(){
    Serial.begin (9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(red, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(green, OUTPUT);
    mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
}
void loop(){
digitalWrite(green, HIGH);
digitalWrite(yellow, LOW);
digitalWrite(red, LOW);
digitalWrite(trigPin, HIGH);
delay(3000);
    
    digitalWrite(green, LOW);
    digitalWrite(red, LOW);
    digitalWrite(yellow, HIGH);  
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
if (distance >= 80 || distance <= 0)
  {
Serial.println("no object detected");
}
else
{
  Serial.println("object detected");
  SendMessage();  
}
 delay(3000);
 
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
if (distance >= 80 || distance <= 0)
  {
Serial.println("no object detected");
  }
else
{
  Serial.println("object detected");
  SendMessage(); 
}


    delay(3000);
}
void SendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+919409401223\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println(" vehicle current location is : ");// The SMS text you want to send
  delay(100);
  mySerial.println(" longitude : ");// The SMS text you want to send
  delay(100);
  mySerial.println(" latitude: ");// The SMS text you want to send
  delay(100);
  mySerial.println(" please take some action soon ");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}


 

