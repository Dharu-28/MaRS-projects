#include <Adafruit_LiquidCrystal.h>

int FlexSensor = 0;
int LED=13;
int pin=7;

Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  lcd_1.begin(16, 2);
  pinMode(LED,OUTPUT);
  pinMode(pin,INPUT);
}

void loop()
{
  FlexSensor = analogRead(A0);
  Serial.println(FlexSensor);
  lcd_1.setCursor(0, 0);
  lcd_1.print("Flexibilty : ");
  if (FlexSensor > 10) {
    lcd_1.setCursor(13, 0);
    lcd_1.print(FlexSensor);
  } else {
    lcd_1.setCursor(13, 0);
    lcd_1.print("0");
    lcd_1.print(FlexSensor);
  }
  delay(10); // Delay a little bit to improve simulation performance
  
  int val= digitalRead(pin);
  if (val==0)
  {
    digitalWrite(LED,HIGH);
  }
  else
  {
    digitalWrite(LED,LOW);
  }
  
}