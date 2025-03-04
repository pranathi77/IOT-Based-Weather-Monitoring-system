#include <DHT.h>

#define DHTPIN D2       // Define the pin where the DHT11 data pin is connected
#define DHTTYPE DHT11   // Define the sensor type as DHT11

DHT dht(DHTPIN, DHTTYPE);  // Create an instance of the DHT sensor

void setup() {
  Serial.begin(115200);      // Start serial communication at 115200 baud rate
  dht.begin();               // Initialize the DHT11 sensor
  delay(2000);               // Wait for the sensor to initialize
}

void loop() {
  // Reading humidity and temperature values from the DHT11 sensor
  float humidity = dht.readHumidity();      // Read humidity
  float temperature = dht.readTemperature(); // Read temperature in Celsius

  // Check if the readings are valid
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    // Print the values to the Serial Monitor
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" *C");
  }

  delay(2000); // Wait for 2 seconds before taking another reading
}
