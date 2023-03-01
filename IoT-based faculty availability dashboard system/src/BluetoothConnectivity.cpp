#include "BluetoothConnectivity.h"
#include <Arduino.h>

void BluetoothScanner::startScan(int scanTime, bool isContinuous)
{
    BLEDevice::init("");
    BLEScan *pBLEScan = BLEDevice::getScan();
    pBLEScan->setAdvertisedDeviceCallbacks(this);
    pBLEScan->setActiveScan(isContinuous);
    pBLEScan->setInterval(100);
    pBLEScan->setWindow(99);

    Serial.println("Starting BLE scan...");
    pBLEScan->start(scanTime, false);
}

void BluetoothScanner::onResult(BLEAdvertisedDevice advertisedDevice)
{
    Serial.print("BLE Advertised Device found: ");
    Serial.println(advertisedDevice.getAddress().toString().c_str());
    // send data to Azure here
}
