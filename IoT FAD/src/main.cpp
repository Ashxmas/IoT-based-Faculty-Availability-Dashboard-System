#include <Arduino.h>

#include <BLEDevice.h>
#include <WiFi.h>
#include <HTTPClient.h>

// Replace with your Wi-Fi SSID and password
const char *ssid = "ZEPHY";
const char *password = "Ashams@0302";

// Replace with your Azure Function endpoint and API key
const char *endpoint = "faculty-availability-dashboard.azurewebsites.net";
const char *apiKey = "ckSXQRSTooU3aftJ3OgXjq7JaZ50asGMhgcWiluljmwDAzFuqQyMKw==";

BLEUUID uuid("0000XXXX-0000-1000-8000-00805f9b34fb"); // Replace with your beacon UUID

void sendAddress(String address)
{
  HTTPClient http;
  String url = "https://" + String(endpoint) + "/api/UpdateDatabase?code=" + String(apiKey) + "&address=" + address;
  Serial.println("Sending device address to Azure Function: " + url);
  http.begin(url);
  int httpCode = http.GET();
  if (httpCode > 0)
  {
    Serial.println("Device address sent successfully");
  }
  else
  {
    Serial.println("Failed to send device address");
  }
  http.end();
}

void setup()
{
  BLEDevice::init("");
  BLEServer *pServer = BLEDevice::createServer();
  BLEAdvertising *pAdvertising = pServer->getAdvertising();
  pAdvertising->addServiceUUID(uuid);
  pAdvertising->start();
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Connecting to Wi-Fi...");
  }
  Serial.println("Connected to Wi-Fi");
}

void loop()
{
  BLEScan *pBLEScan = BLEDevice::getScan();
  pBLEScan->setActiveScan(true);
  BLEScanResults scanResults = pBLEScan->start(5);
  int count = scanResults.getCount();
  if (count > 0)
  {
    Serial.println("Device found");
    BLEAdvertisedDevice device = scanResults.getDevice(0);
    Serial.print("Address: ");
    Serial.println(device.getAddress().toString().c_str());
    sendAddress(device.getAddress().toString().c_str());
  }
  delay(2500);
}
