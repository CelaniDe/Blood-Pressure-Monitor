bool startKsefouskoma;

void setup() {
  Serial.begin(19200);  // Initialize serial communication
  digitalWrite(13,HIGH);
  startKsefouskoma = false;
}

float getPressure(String wave)
{
  float sensorValue;
  if(wave == "two")
    sensorValue = analogRead(A1); // Replace A0 with your analog input pin
  else
    sensorValue = analogRead(A0); // Replace A0 with your analog input pin

  float voltage = sensorValue * (5.0 / 1023.0); // Convert ADC value to voltage

  // float pressure = m * voltage + b; // Convert voltage to pressure
  float pressure_mmHg = ((voltage - 0.3) / 0.135) * 7.5;

  return pressure_mmHg;
}

void ksefouskoma()
{
  delay(100);
  digitalWrite(13,LOW);
  delay(100);
  digitalWrite(13,HIGH);
}
void loop() {

  float pressure_mmHg1 = getPressure("one"); 
  float pressure_mmHg2 = getPressure("two"); 

  int maxValue = -10000;
  int minValue = 10000;

  unsigned long startTime = millis();
  while (millis() - startTime < 5000) { // Run for 1 second
    // Read analog input and convert to voltage
    float voltage = getPressure("two");

    // Update min and max values
    if (voltage < minValue) {
      minValue = voltage;
    }
    if (voltage > maxValue) {
      maxValue = voltage;
    }
  }

  // Calculate peak-to-peak voltage
  float peakToPeak = maxValue - minValue;

  if(pressure_mmHg1 > 150)
    startKsefouskoma = true;

  if(startKsefouskoma)
    ksefouskoma();

  Serial.print("ena:");
  Serial.print(pressure_mmHg1);
  Serial.print(",");
  Serial.print("dio:");
  Serial.println(pressure_mmHg2);
  Serial.print(",");
  Serial.print("peak:");
  Serial.println(peakToPeak);

  //delay(1000); // Adjust as needed
}
