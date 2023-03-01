#ifndef AzureConnectivity_h
#define AzureConnectivity_h

#include <WiFi.h>

class AzureClient
{
public:
    void sendToAzure(String deviceAddress);

private:
    const char *AZURE_SERVER_NAME = "your_azure_server_name";
    const int AZURE_SERVER_PORT = 80;
    const char *AZURE_POST_URL = "/your_post_url";
    String buildRequestBody(String deviceAddress);
};

#endif
