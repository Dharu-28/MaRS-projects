int value = 0;
int temp=A0;
float temp_celsius;
float Voltage;
float analog_reading;
float temp_far;


long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode (A0, INPUT);
  Serial.begin(9600);
  pinMode(11, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);
  
}

void loop()
{
  value = 0.01723 * readUltrasonicDistance(6, 5);
  Serial.print("Distance : ");
  Serial.println(String(value)+(" cm"));
  if (value <= 100) {
    digitalWrite(11, HIGH);
  } else {
    digitalWrite(11, LOW);
  }
  if (value > 100) {
    if (value < 200) {
      digitalWrite(9, HIGH);
    } else {
      digitalWrite(9, LOW);
    }
  } else {
    digitalWrite(9, LOW);
  }
  if (value > 200) {
    digitalWrite(10, HIGH);
  } else {
    digitalWrite(10, LOW);
  }
  delay(10);
  
  int sens;
  sens=analogRead(A0);
  Serial.println("Light Intensity: "+String(sens));
  
  delay (500);
  
  analog_reading=analogRead(A0);
  Serial.print("Analog reading: ");
  Serial.println(analog_reading);
  
  Voltage=analog_reading*5/1024;
  
  Serial.print("Voltage Reading: ");
  Serial.print(Voltage);
  
  temp_celsius=100*(Voltage-0.5);
  Serial.println("\nCelsius reading: "+String(temp_celsius)+(" C"));
  temp_far=(temp_celsius * 9/5)+32;
  Serial.println("Fahrenheit reading:" +String(temp_far) + (" F\n"));
  delay (500);
  
}