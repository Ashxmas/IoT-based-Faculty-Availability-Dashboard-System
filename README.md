# IoT-based-Faculty-Availability-Dashboard-System
Hardware Requirements:
ESP32 Bluetooth Beacon
Smartphones with Bluetooth capabilities
Wi-Fi connection
Microsoft Azure Cloud
Software Requirements:
Arduino IDE for ESP32 development
Microsoft Azure account
Static Web App for data visualization
System Architecture:
The ESP32 acts as a Bluetooth beacon, continuously transmitting a signal.
The faculty member's smartphone will bond with the ESP32 via Bluetooth.
Once the smartphone is connected to the ESP32, the smartphone's device address is sent to Microsoft Azure via Wi-Fi.
When the message arrives in the cloud, a function will be triggered to update the real-time database of the faculty member, i.e., the status of the attribute 'active' will be changed from 'no' to 'yes.'
A static web app will fetch the data from the database and display it on the screen.
ESP32 Code:
The code for the ESP32 should include the following functionalities:
Start advertising as a Bluetooth beacon
Scan for devices with Bluetooth capabilities
When a device is connected, get the device address and send it to the Azure cloud via Wi-Fi
Stop advertising when not connected
Azure Cloud:
The Azure cloud will be used to receive the device address from the ESP32 and update the real-time database of the faculty member.
Set up an Azure Function that will receive the device address sent by the ESP32.
Update the faculty member's status in the real-time database by changing the 'active' attribute from 'no' to 'yes.'
The Azure Function should return a success message to the ESP32.
Static Web App:
The static web app will be used to display the faculty member's availability status.
Fetch the data from the real-time database in Azure.
Display the data in a table or other suitable visual representation.
Security:
Data sent over Bluetooth should be encrypted to prevent eavesdropping.
The Wi-Fi connection should also be secure to prevent unauthorized access to the Azure cloud.
The Azure Function should only accept data from authorized ESP32 devices.
