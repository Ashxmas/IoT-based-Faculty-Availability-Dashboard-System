#ifndef BLUETOOTH_CONNECTIVITY_H
#define BLUETOOTH_CONNECTIVITY_H

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>

class BluetoothScanner : public BLEAdvertisedDeviceCallbacks
{
public:
    void startScan(int scanTime, bool isContinuous);
    void onResult(BLEAdvertisedDevice advertisedDevice);
};

#endif /* BLUETOOTH_CONNECTIVITY_H */
