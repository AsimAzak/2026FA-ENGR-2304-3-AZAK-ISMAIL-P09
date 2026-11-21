
// 2026FA-ENGR-2304-3-AZAK-ISMAIL-P09
// Pressure Regulation + Countdown System
// Number convention: Binary unless prefixed with 0x

#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

// LCD configuration
Adafruit_LiquidCrystal lcd(0);

// Hardware pin assignments
const int leds[] = {
  0b1101,  // Pin 13 - Binary bit 0
  0b1100,  // Pin 12 - Binary bit 1
  0b1000,  // Pin 8  - Binary bit 2
  0b0100   // Pin 4  - Binary bit 3
};

const int compressor = 0b0111;  // Pin 7

// Pressure settings
const int targetInput = A0;
const int pressureInput = A2;

const int maxPressure = 0b1100100;  // 100 PSI

// System variables
int targetPressure = 0;
int currentPressure = 0;

bool launched = false;


// ======================================
// SETUP
// ======================================

void setup()
{
  // Initialize LCD
  lcd.begin(0b10000, 0b10);
  lcd.setBacklight(0b1);

  // Initialize compressor output
  pinMode(compressor, OUTPUT);
  digitalWrite(compressor, LOW);

  // Initialize countdown LEDs
  for (int i = 0; i < 0b100; i++)
  {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }

  lcd.print("System Starting");
  delay(0b10111011100);  // 1500 ms
  lcd.clear();
}


// ======================================
// READ PRESSURE
// ======================================

void readPressure()
{
  // Read target pressure potentiometer
  int targetReading = analogRead(targetInput);

  // Read current pressure potentiometer
  int pressureReading = analogRead(pressureInput);

  // Convert analog readings into PSI (0-100)
  targetPressure = map(
    targetReading, 0, 0b1111111111, 0, maxPressure
  );

  currentPressure = map(
    pressureReading, 0, 0b1111111111, 0, maxPressure
  );
}


// ======================================
// DISPLAY PRESSURE
// ======================================

void displayPressure()
{
  lcd.setCursor(0, 0);
  lcd.print("Target: ");
  lcd.print(targetPressure);
  lcd.print(" psi   ");

  lcd.setCursor(0, 1);
  lcd.print("Now: ");
  lcd.print(currentPressure);
  lcd.print(" psi     ");
}


// ======================================
// CONTROL COMPRESSOR
// ======================================

void controlCompressor()
{
  if (currentPressure < targetPressure)
  {
    // Pressure is below target
    digitalWrite(compressor, HIGH);
  }
  else
  {
    // Target pressure achieved
    digitalWrite(compressor, LOW);
  }
}


// ======================================
// DISPLAY BINARY COUNTDOWN
// ======================================

void displayBinary(int number)
{
  for (int i = 0; i < 0b100; i++)
  {
    digitalWrite(leds[i], bitRead(number, i));
  }
}


// ======================================
// ROCKET COUNTDOWN
// ======================================

void runCountdown()
{
  digitalWrite(compressor, LOW);

  lcd.clear();
  lcd.print("Pressure Ready");

  delay(0b1111101000);  // 1000 ms

  // Countdown from 10 to 0
  for (int count = 0b1010; count >= 0; count--)
  {
    displayBinary(count);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Launch in: ");
    lcd.print(count);

    delay(0b1111101000);  // 1000 ms
  }

  // Countdown completed
  lcd.clear();
  lcd.print("LIFTOFF!");

  // Turn off all LEDs
  for (int i = 0; i < 0b100; i++)
  {
    digitalWrite(leds[i], LOW);
  }

  digitalWrite(compressor, LOW);

  launched = true;
}


// ======================================
// MAIN PROGRAM LOOP
// ======================================

void loop()
{
  // Prevent repeated countdown
  if (launched)
  {
    return;
  }

  // Read pressure measurements
  readPressure();

  // Display current system status
  displayPressure();

  // Regulate compressor output
  controlCompressor();

  // Start countdown when target pressure is reached
  if (currentPressure >= targetPressure)
  {
    runCountdown();
  }

  delay(0b1100100);  // 100 ms
}
