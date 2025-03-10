#include <DHT.h>

#define DHTPIN 2       // DHT11 sensor connected to digital pin 2
#define DHTTYPE DHT11  // Define sensor type
DHT dht(DHTPIN, DHTTYPE);

#define MQ135_PIN A0   // MQ135 sensor connected to analog pin A0

void setup() {
    Serial.begin(9600);  // Start serial communication
    dht.begin();
}

void loop() {
    // Read MQ135 Sensor
    int gasValue = analogRead(MQ135_PIN);
    
    // Read DHT11 Sensor
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    // Air Quality Classification
    String airQuality;
    if (gasValue < 300) {
        airQuality = "Good";
    } else if (gasValue < 600) {
        airQuality = "Poor";
    } else if (gasValue < 900) {
        airQuality = "Very Bad";
    } else {
        airQuality = "Toxic";
    }

    // Display Data on Serial Monitor
    Serial.print("Air Quality: ");
    Serial.print(airQuality);
    Serial.print(" | Gas Level: ");
    Serial.print(gasValue);
    Serial.print(" | Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C | Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    delay(2000);  // Wait for 2 seconds before next reading
}