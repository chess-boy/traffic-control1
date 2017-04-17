int red = 10;
int yellow = 9;
int green = 8;
int duration, distance;
#define trigPin 12
#define echoPin 13
void setup(){
    Serial.begin (9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(red, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(green, OUTPUT);
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
}
    delay(3000);
}


