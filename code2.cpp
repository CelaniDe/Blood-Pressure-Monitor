#define TROMBA 12
#define VALVIDA 13


bool onKsefouskoma;
bool onFouskoma;

float getPressure(String wave)
{
  float sensorValue;
  if(wave == "artiria")
    sensorValue = analogRead(A1); // artiria
  else
    sensorValue = analogRead(A0); // perixirida

  float voltage = sensorValue * (5.0 / 1023.0); // Convert ADC value to voltage

  // float pressure = m * voltage + b; // Convert voltage to pressure
  float pressure_mmHg = ((voltage - 0.3) / 0.135) * 7.5;

  return pressure_mmHg;
}


void fouskoma()
{
  digitalWrite(TROMBA,LOW);
  digitalWrite(VALVIDA,LOW);
}

void neutral()
{
  digitalWrite(TROMBA,HIGH);
  digitalWrite(VALVIDA,LOW);
}

void ksefouskoma()
{
  digitalWrite(TROMBA,HIGH);
  digitalWrite(VALVIDA,HIGH);
}

void setup() {
  Serial.begin(19200);
  onFouskoma = true;
  pinMode(TROMBA,OUTPUT);
  pinMode(VALVIDA,OUTPUT);

}

void loop() {

  // float pressure_mmHg1 = getPressure("perixirida"); 
  // if(pressure_mmHg1 <= 120 && onFouskoma)
  // {
  //   fouskoma();
  // }
  // if(pressure_mmHg1 <= 120)
  // {
  //   onFouskoma = false;
  // }

  // Serial.print("ena:");
  // Serial.println(pressure_mmHg1);

  digitalWrite(TROMBA,HIGH);
}
