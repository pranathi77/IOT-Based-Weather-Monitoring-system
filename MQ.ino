// Define pin for MQ-135 sensor analog output
const int mq135Pin = A0;  // ESP8266 has only one ADC pin, which is A0

void setup() {
  // Start the serial communication
  Serial.begin(115200); // Open serial monitor at 115200 baud rate
  
  // Give the sensor some time to warm up (typically 2 minutes)
  delay(2000);  
}

void loop() {
  // Read the analog value from MQ-135
  int sensorValue = analogRead(mq135Pin);  // Read the analog value
  
  // Print the sensor value to the serial monitor
  Serial.print("MQ-135 Sensor Value: ");
  Serial.println(sensorValue);
  
  // Add a delay before the next reading
  delay(2000);  // Wait for 2 seconds before taking another reading
}
