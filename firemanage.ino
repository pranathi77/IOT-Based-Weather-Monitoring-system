#define FIRE_SENSOR_PIN 2  // Fire sensor digital output
#define MQ_SENSOR_PIN A0   // MQ sensor analog output
#define RELAY_PIN 3        // Relay connected to digital pin
#define LED_PIN 4          // LED for MQ sensor alert

int mqThreshold = 400; // Adjust this threshold based on sensor calibration

void setup() {
    pinMode(FIRE_SENSOR_PIN, INPUT);
    pinMode(RELAY_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int fireStatus = digitalRead(FIRE_SENSOR_PIN);
    int mqValue = analogRead(MQ_SENSOR_PIN);

    Serial.print("MQ Sensor Value: ");
    Serial.println(mqValue);

    // If fire detected, turn on relay
    if (fireStatus == LOW) {  // Assuming LOW means fire detected
        digitalWrite(RELAY_PIN, HIGH);
        Serial.println("Fire detected! Relay ON");
    } else {
        digitalWrite(RELAY_PIN, LOW);
    }

    // If MQ sensor value exceeds threshold, turn on LED
    if (mqValue > mqThreshold) {
        digitalWrite(LED_PIN, HIGH);
        Serial.println("Gas level high! LED ON");
    } else {
        digitalWrite(LED_PIN, LOW);
    }

    delay(500);
}
