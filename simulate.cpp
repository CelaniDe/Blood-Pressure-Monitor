const int pressurePin = 9; // choose an appropriate PWM pin
const float meanPressure = 128.0; // mean pressure value
const float amplitude = 50.0; // amplitude of the pressure waveform
const float frequency = 1.0; // frequency of the waveform in Hz

void setup() {
  pinMode(pressurePin, OUTPUT);
}

void loop() {
  float time = millis() / 1000.0; // convert milliseconds to seconds
  float pressure = meanPressure + amplitude + 0.36 * (
      sin(2 * PI * frequency * time) +
      0.5 * sin(2 * PI * 2 * frequency * time) +
      0.25 * sin(3 * PI * 2 * frequency * time)
  );

  // Map the pressure value to the range 0-255 for analogWrite
  int pressureMapped = map(pressure, 0, 255, 0, 255);
  
  analogWrite(pressurePin, pressureMapped);

  delay(10); // adjust delay based on your application requirements
}
