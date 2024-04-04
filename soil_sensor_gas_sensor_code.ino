int moisture = 0;
int LED=1;
int pin=A2;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A2, INPUT);
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop()
{
  moisture = analogRead(A0);
  Serial.print("Moisture: ");
  Serial.println(moisture);
  if (moisture < 70) // moisture level less than 70
  { 
    digitalWrite(8, HIGH); // Buzzer will buzz 
    digitalWrite(4, LOW);  // Green light will stop
    digitalWrite(3, HIGH); // Red light will glow
  } else {
    digitalWrite(8, LOW);  // Buzzer will stop 
    digitalWrite(4, HIGH); // Green light will glow
    digitalWrite(3, LOW);  // Red light will stop
  }
  delay(10); 
  
  float sensor;
  digitalWrite(LED,LOW);
  sensor=analogRead(pin);
  if (sensor!=0)
  {
    digitalWrite(LED, HIGH);
    Serial.print(sensor);
    Serial.println(" -> GAS DETECTED\n");
  }
  else
  {
    digitalWrite(LED,LOW);
    Serial.print("Sensor Value: ");
    Serial.println(sensor);
  }
  delay(500);
}