
const int RED_PIN = C2;
const int GREEN_PIN = C1;
const int BLUE_PIN = D6;


int DISPLAY_TIME = 50;  // Miliseconds

void AnalogWrite(int pin, int value) {
 int delayTime = map(value, 0, 255, 50000, 0); // Simulated analogwrite using pwm

  int brightness = map(value, 0, 255, 0, 255);
  digitalWrite(pin, HIGH);
  delayMicroseconds(brightness);
  digitalWrite(pin, LOW);
  delayMicroseconds(255 - brightness);
  
  digitalWrite(pin, LOW);
}
void setup()
{
  pinMode(C4, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}


void loop()
{
 

  showSpectrum();
}


void showSpectrum()
{
  int x;  
 
  for (x = 0; x < 768; x++)

  {
    showRGB(x);   
    delay(10);   
  }
}

void showRGB(int color)
{
  int redIntensity;
  int greenIntensity;
  int blueIntensity;

  if (color <= 255)
  {
    redIntensity = 255 - color;
    greenIntensity = color;
    blueIntensity = 0;
  }
  else if (color <= 511)
  {
    redIntensity = 0;
    greenIntensity = 255 - (color - 256);
    blueIntensity = (color - 256);
  }
  else // color >= 512
  {
    redIntensity = (color - 512);
    greenIntensity = 0;
    blueIntensity = 255 - (color - 512);
  }


  redIntensity = redIntensity * 16;
  greenIntensity = greenIntensity * 16;
  blueIntensity = blueIntensity * 16;
  AnalogWrite(C4, greenIntensity);

  AnalogWrite(RED_PIN, redIntensity);
  AnalogWrite(BLUE_PIN, blueIntensity);
  AnalogWrite(GREEN_PIN, greenIntensity);
}
