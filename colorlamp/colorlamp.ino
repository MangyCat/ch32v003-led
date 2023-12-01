const int redPin = D6;
const int greenPin = C2;
const int bluePin = C1;
void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  for (int hue = 0; hue < 360; ++hue) {
    int rgb[3];
    calculateRGB(hue, 255, 255, rgb); // You can adjust saturation and value

    simulatedAnalogWrite(redPin, rgb[0]);
    simulatedAnalogWrite(greenPin, rgb[1]);
    simulatedAnalogWrite(bluePin, rgb[2]);
    delay(10); // Adjust the delay for the color transition speed
  }
}

// Function to calculate RGB values from HSV
void calculateRGB(int hue, int saturation, int value, int rgb[]) {
  float chroma = (float)value * ((float)saturation / 255.0);
  float h = hue / 60.0;
  float x = chroma * (1 - abs((int)h % 2 - 1));

  float r, g, b;

  if (0 <= h && h < 1) {
    r = chroma;
    g = x;
    b = 0;
  } else if (1 <= h && h < 2) {
    r = x;
    g = chroma;
    b = 0;
  } else if (2 <= h && h < 3) {
    r = 0;
    g = chroma;
    b = x;
  } else if (3 <= h && h < 4) {
    r = 0;
    g = x;
    b = chroma;
  } else if (4 <= h && h < 5) {
    r = x;
    g = 0;
    b = chroma;
  } else {
    r = chroma;
    g = 0;
    b = x;
  }

  float m = (float)value - chroma;

  rgb[0] = (int)(255.0 * (r + m));
  rgb[1] = (int)(255.0 * (g + m));
  rgb[2] = (int)(255.0 * (b + m));
}

// Simulated analogWrite function using digitalWrite
void simulatedAnalogWrite(int pin, int value) {
  int threshold = map(value, 0, 255, 0, 100);

  for (int i = 0; i <= 100; ++i) {
    int brightness = map(i, 0, 100, 0, 255);

    if (i < threshold) {
      digitalWrite(pin, LOW);  // Simulate turning on the LED
      delayMicroseconds(brightness);
    } else {
      digitalWrite(pin, LOW);  // Simulate turning on the LED
      delayMicroseconds(255 - brightness);
    }

    digitalWrite(pin, HIGH);  // Simulate turning off the LED
    delayMicroseconds(5000); // Adjust this delay for the off state
  }
}
