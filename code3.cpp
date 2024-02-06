#define TROMBA 12
#define VALVIDA 13

unsigned long startMillis;  //some global variables available anywhere in the program
unsigned long currentMillis;
const unsigned long period = 1000;



float getPressure(String wave)
{
  float sensorValue;
  if(wave == "artiria")
    sensorValue = analogRead(A3); // artiria
  else
    sensorValue = analogRead(A2); // perixirida

  float voltage = sensorValue * (5.0 / 1023.0); // Convert ADC value to voltage

  float pressure_mmHg = ((voltage - 0.3) / 0.135) * 7.5;

  return pressure_mmHg;
}


void fouskoma()
{
  digitalWrite(TROMBA,HIGH);
  digitalWrite(VALVIDA,HIGH);
}

void neutral()
{
  digitalWrite(TROMBA,LOW);
  digitalWrite(VALVIDA,HIGH);
}

void ksefouskoma()
{
  digitalWrite(TROMBA,LOW);
  digitalWrite(VALVIDA,LOW);
}

void setup() {
  Serial.begin(19200);
  pinMode(TROMBA,OUTPUT);
  pinMode(VALVIDA,OUTPUT);
  startMillis = millis();  //initial start time
  fouskoma();
}

void loop() {

  float pressure_mmHg1 = getPressure("perixirida"); 
  float pressure_mmHg2 = getPressure("artiria"); 

  // if((pressure_mmHg1 >= 80) && !onKsefouskoma)
  // {
  //   upper_counter++;
  // }
  // else
  // {
  //   upper_counter = 0;
  // }

  // if(upper_counter >= 5)
  // {
  //   onNeutral = true;
  // }

  // if(onNeutral)
  // {
  //   neutral();
  //   delay(5000);
  //   ksefouskoma();
  //   onKsefouskoma = true;
  // }

  currentMillis = millis();  //get the current "time" (actually the number of milliseconds since the program started)
  if (currentMillis - startMillis >= 7000)  //test whether the period has elapsed
  {
    neutral();
    startMillis = currentMillis;  //IMPORTANT to save the start time of the current LED state.
  }


  Serial.print("dio:");
  Serial.println(pressure_mmHg2);

  delay(250);

  // ksefouskoma();
}
