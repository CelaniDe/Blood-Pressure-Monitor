// C++ code
//

float simulateSensorValue(float time, float frequency, float amplitude, float meanPressure) {
  return meanPressure + amplitude + 0.36 * (sin(2 * PI * frequency * time) + 0.5 * sin(2 * PI * 2 * frequency * time) + 0.25 * sin(3 * PI * 2 * frequency * time));
}

double sinh(double x) {
  return (exp(x) - exp(-x)) / 2.0;
}

float pressureOfGaugeCuff = 0;


bool onFouskoma;
float peekToPeeks[10] = {0};
int index = 0;
void fouskoma()
{
 	 pressureOfGaugeCuff++;
}


void setup()
{
  Serial.begin(9600);
  onFouskoma = true;
}

float indexFactor()
{
  if(index == 0)
    return 0.1;
  else if(index == 1)
    return 0.2;
  else if(index == 2)
    return 0.5;
  else if(index == 3)
    return 0.7;
  else if(index == 4)
    return 0.9;
  else if(index == 5)
    return 1;
  else if(index == 6)
    return 0.9;
  else if(index == 7)
    return 0.7;
  else if(index == 8)
    return 0.5;
  else if(index == 9)
    return 0.3;
  else
    return 0;
}

void loop()
{
  if(pressureOfGaugeCuff <= 180 && onFouskoma)
  {
    	fouskoma();
  }
  if(pressureOfGaugeCuff > 180)
  {
   	 onFouskoma = false;
  }

  
  
  
  float maxValue = -10000;
  float minValue = 10000;
  unsigned long startTime = millis();
  while (millis() - startTime < 5000) { 
    
    float time = millis() / 100.0; // Convert milliseconds to seconds
    float frequency = 0.1; // Adjust the frequency as needed
    float meanPressure = 80.0; // Adjust the mean pressure as needed
    float amplitude = 10; 

    float pressureOfArthritis = simulateSensorValue(time, frequency,  amplitude, meanPressure) * indexFactor();
    
    
    //Serial.println(pressureOfArthritis);

    // Update min and max values
    if (pressureOfArthritis < minValue) {
      minValue = pressureOfArthritis;
    }
    if (pressureOfArthritis > maxValue) {
      maxValue = pressureOfArthritis;
    }
  }
  
  float peakToPeak = maxValue - minValue;
  peekToPeeks[index] = peakToPeak;
  Serial.println(peekToPeeks[index]);
  index++;
  
  for(int i = 0; i++; i < 10)
  {
    Serial.println(peekToPeeks[i]);
  }
    

  
  

  //Serial.println(peakToPeak);
  //Serial.println(maxValue);
  //Serial.println(minValue);
  //Serial.print(", ");
  //Serial.println(pressureOfGaugeCuff);
  //Serial.print(", ");
  //Serial.println(1 / pressureOfGaugeCuff);
}
