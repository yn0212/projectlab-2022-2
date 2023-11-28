#include <Wire.h>
#include <MPU9250_asukiaaa.h>
#include <HTTPClient.h>

// Replace these variables with your actual network credentials and server details
const char *ssid = "your_SSID";
const char *password = "your_PASSWORD";
const char *serverUrl = "http://your_raspberry_pi_ip:your_port/your_endpoint";

MPU9250_asukiaaa imu;

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize the MPU9250
  Wire.begin();
  imu.setWire(&Wire);
  imu.beginAccel();
  imu.beginGyro();

  delay(1000);
}

void loop() {
  // Read accelerometer and gyroscope data
  imu.readAccel();
  imu.readGyro();

  // Create JSON payload
  String payload = "{\"accel_x\":" + String(imu.accelX) +
                   ",\"accel_y\":" + String(imu.accelY) +
                   ",\"accel_z\":" + String(imu.accelZ) +
                   ",\"gyro_x\":" + String(imu.gyroX) +
                   ",\"gyro_y\":" + String(imu.gyroY) +
                   ",\"gyro_z\":" + String(imu.gyroZ) +
                   "}";

  // Send data to the server
  sendPostRequest(payload);

  delay(1000);  // Adjust the delay as needed
}

void sendPostRequest(String payload) {
  HTTPClient http;

  http.begin(serverUrl);
  http.addHeader("Content-Type", "application/json");

  int httpResponseCode = http.POST(payload);

  if (httpResponseCode > 0) {
    Serial.println("HTTP POST Request Sent Successfully");
    Serial.print("HTTP Response Code: ");
    Serial.println(httpResponseCode);
  } else {
    Serial.println("HTTP POST Request Failed");
  }

  http.end();
}
