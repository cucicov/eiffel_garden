// Relay control on pin 2 for 1 minute every day with soil humidity check

#include <TimeLib.h> // Library for time functions

int relayPin = 2; // Pin connected to the relay
int startHour = 12; // Hour to start the relay (24-hour format)
int startMinute = 0; // Minute to start the relay
int soilHumidityThreshold = 500; // Threshold value for soil humidity

// Function to simulate reading soil humidity
int readSoilHumidity() {
  // Simulated soil humidity reading (replace this with your actual sensor reading)
  return analogRead(A0); // Assuming the soil humidity sensor is connected to analog pin A0
}

void setup() {
  pinMode(relayPin, OUTPUT); // Set the relay pin as an output
  setTime(0, 0, 0, 1, 1, 2023); // Set the initial time (format: hour, min, sec, day, month, year)
}

void loop() {
  if (hour() == startHour && minute() == startMinute) { // Check if it's the specified start time
    int humidity = readSoilHumidity(); // Read the soil humidity value

    if (humidity < soilHumidityThreshold) { // Check if the humidity is below the threshold
      digitalWrite(relayPin, HIGH); // Turn on the relay
      delay(60000); // Wait for 1 minute
      digitalWrite(relayPin, LOW); // Turn off the relay
    }
  }

  // Update the time (needed for time-based comparison)
  if (second() == 59) {
    setTime(hour(), minute() + 1, 0, day(), month(), year());
  }

  delay(1000); // Wait for 1 second
}
