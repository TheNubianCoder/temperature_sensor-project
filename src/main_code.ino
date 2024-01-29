// C++ code
//
#include <LiquidCrystal.h>

//Define the pins for the LCD
LiquidCrystal lcd(12,11,5,4,3,2);

//Define the pin for the TMP36 temperature sensor
const int tmp36pin = A0;

void setup()
{
// Set up the LCD columns and rows
  lcd.begin(16, 2);

  // Print initial message on the LCD
  lcd.print("Temperature:");

  // Initialize serial communication for debugging (optional)
  Serial.begin(9600);
}

void loop()
{
   // Read the analog value from the TMP36
  int sensorValue = analogRead(tmp36pin);

  // Convert analog value to voltage
  float voltage = sensorValue * (5.0 / 1023.0);

  // Convert voltage to temperature in Celsius
  float temperatureC = (voltage - 0.5) * 100.0;

  // Convert Celsius to Fahrenheit
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;

  // Print temperature on the LCD
  lcd.setCursor(0, 1); // Set cursor to the second line
  lcd.print(temperatureC, 1); // Display temperature in Celsius with 1 decimal place
  lcd.print(" C   ");

  // Print temperature to Serial Monitor (optional)
  Serial.print("Temperature: ");
  Serial.print(temperatureC, 1);
  Serial.println(" °C");

  // Delay for a moment before taking the next reading
  delay(1000);
}