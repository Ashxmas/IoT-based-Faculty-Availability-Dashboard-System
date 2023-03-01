#include <WiFi.h>

#define AZURE_SERVER_NAME "your_azure_server_name"
#define AZURE_SERVER_PORT 80
#define AZURE_POST_URL "/your_post_url"

String buildRequestBody(String deviceAddress)
{
    return "{\"deviceAddress\":\"" + deviceAddress + "\"}";
}

void sendToAzure(String deviceAddress)
{
    WiFiClient client;
    if (client.connect(AZURE_SERVER_NAME, AZURE_SERVER_PORT))
    {
        String requestBody = buildRequestBody(deviceAddress);
        client.print(String("POST ") + AZURE_POST_URL + " HTTP/1.1\r\n" +
                     "Host: " + AZURE_SERVER_NAME + "\r\n" +
                     "Content-Type: application/json\r\n" +
                     "Content-Length: " + requestBody.length() + "\r\n" +
                     "Connection: close\r\n\r\n" +
                     requestBody + "\r\n");
        Serial.println("Azure HTTP request sent!");
    }
    else
    {
        Serial.println("Failed to connect to Azure server!");
    }
}
