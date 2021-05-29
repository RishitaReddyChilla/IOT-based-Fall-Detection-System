#include <LiquidCrystal.h>
#include<Blynk.h>
#include <BlynkSimpleStream.h>

// Pin Assignment

//Your app authentication token (can be fetched from your blynk app
char auth[] = "XXXXXXXXXXXXXXXXXXXXXXXXXX";//Enter blynk auth token
BlynkTimer timer;
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
const int lm1 = 2;
const int lm2 = 3;
const int rm1 = 4;
const int rm2 = 5;
long duration, inches, cm;
const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int buzzer=A0;
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
void sendSensor()
{
  pinMode(pingPin, OUTPUT);

digitalWrite(pingPin, LOW);

delayMicroseconds(2);

digitalWrite(pingPin, HIGH);

delayMicroseconds(10);

digitalWrite(pingPin, LOW);


pinMode(echoPin, INPUT);

duration = pulseIn(echoPin, HIGH);

inches = microsecondsToInches(duration);

cm = microsecondsToCentimeters(duration);


if(cm < 390)
  {
    buzzer_func();
   
    stop();
    delay(100);
   
    go_back();
    delay(100);
    
    stop_again();
    delay(100);
   
    go_right();
    delay(100);
    
  }
  
  else
  {
    go_straight();
    delay(100);
  }
  Blynk.virtualWrite(V5, cm);
  if(cm<380)
  {
     Blynk.email("c.rishita.reddy@gmail.com", "OBSTACLE ALERT!", "FALL DETECTED");
  }
  
}
void setup() {
  // put your setup code here, to run once:
 pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
  pinMode(buzzer,OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
  Blynk.begin(auth, Serial);
  timer.setInterval(2000L, sendSensor);
  
  
}

void loop() {
  Blynk.run();
  timer.run();
  Blynk.notify("Device started");

}
long microsecondsToInches(long microseconds)
{
return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
return microseconds / 29 / 2;
}

void go_straight()
{
  lcd.setCursor(0,0);
lcd.print("NOTHING AHEAD");
lcd.setCursor(0,1);
lcd.print("SAFE TO MOVE FORWARD");

 digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
}
void go_back()
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("TAKING REVERSE");
lcd.setCursor(0,1);
lcd.print(cm);
  
  digitalWrite(lm2,HIGH);
  digitalWrite(lm1,LOW);
  digitalWrite(rm2,HIGH);
  digitalWrite(rm1,LOW);
} 
void stop()
{
   lcd.clear();
lcd.setCursor(0,0);
lcd.print("SOMETHING AHEAD");
lcd.setCursor(0,1);
lcd.print("STOP!!");

  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
  
  
}
void stop_again()
{

lcd.clear(); 
lcd.setCursor(0,0);
lcd.print("STOP FOR TURN");
  
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
}

void go_right()
{
  
lcd.clear();
lcd.setCursor(0,0);
lcd.print("TURNING RIGHT");
lcd.setCursor(0,1);
lcd.print(cm);
  
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
}
void buzzer_func()
{
  tone(buzzer,1000);
  delay(200);
  noTone(buzzer);
}
