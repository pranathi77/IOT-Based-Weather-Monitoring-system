#include <ESP8266WiFi.h>
#include <DHT.h>

// Define sensor pins
#define DHTPIN D2  // DHT11 data pin connected to D2
#define DHTTYPE DHT11
#define MQ135_PIN A0  // MQ135 analog output connected to A0
#define MQ5_PIN D1     // MQ5 analog output connected to D1

// Initialize the DHT11 sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(115200);
    dht.begin();  
    pinMode(MQ5_PIN, INPUT);
    Serial.println("DHT11, MQ135 & MQ5 Sensor Monitoring");
}

void loop() {
    // Read DHT11 temperature and humidity
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();
    
    // Read MQ135 and MQ5 sensor values
    int mq135_value = analogRead(MQ135_PIN);
    int mq5_value = digitalRead(MQ5_PIN);  

    // Print values to Serial Monitor
    Serial.println("=================================");
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    Serial.print("MQ135 Air Quality: ");
    Serial.println(mq135_value);

    Serial.print("MQ5 Gas Detection (0 = Gas detected): ");
    Serial.println(mq5_value == 0 ? "Gas Detected!" : "No Gas");

    Serial.println("=================================\n");

    delay(2000);  // Delay for stability
}
