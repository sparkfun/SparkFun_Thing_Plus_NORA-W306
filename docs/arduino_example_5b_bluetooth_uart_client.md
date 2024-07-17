


We will upload code for the Bluetooth UART client in this example. Then we will send characters between two serial terminals.



### Hardware Hookup

Connect the USB C cables to the boards and two different COM ports on your computer.

!!! tip
    To keep track of which board that you are connecting to, use a sticky note and label the boards that you are using as the Service and Client.

<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/WRL-21637_Thing_Plus_NORA-W306_USB_Cable.jpg"><img src="../assets/img/WRL-21637_Thing_Plus_NORA-W306_USB_Cable.jpg" width="600px" height="600px" alt="USB Cable inserted into Thing Plus NORA-W306"></a></td>
    </tr>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>USB Cable inserted into Thing Plus NORA-W306</i></td>
    </tr>
  </table>
</div>



### Arduino Code

Let&apos;s upload the corresponding sketch to send serial data between two SparkFun Thing Plus NORA-W306 boards wirelessly using the Bluetooth&reg; Low Energy (BLE) feature. From the menu, select the following: **File** > **Examples** > **File** > **Examples** > <font style="color:gray"><b>Examples for SparkFun Thing Plus NORA-W306 (RTL8720DF)</b></font> | **AmebaBLE** > **BLEUartClient**.

Or you can copy and paste the following code in the Arduino IDE. Select the correct board definition from the menu (in this case, **Tools** > **Boards** > **SparkFun Thing Plus NORA-W306 (RTL8720DF)**). Then select the correct COM port that the board enumerated to (in this case, it was COM22). Hit upload button.

``` C++
/*

 Example guide:
 https://www.amebaiot.com/en/amebad-arduino-ble-uart/
 */

#include "BLEDevice.h"

#define UART_SERVICE_UUID      "6E400001-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_TX "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"

#define STRING_BUF_SIZE 100

BLEAdvertData foundDevice;
BLEAdvertData targetDevice;
BLEClient* client;
BLERemoteService* UartService;
BLERemoteCharacteristic* Rx;
BLERemoteCharacteristic* Tx;

void scanCB(T_LE_CB_DATA* p_data) {
    foundDevice.parseScanInfo(p_data);
    if (foundDevice.hasName()) {
        if (foundDevice.getName() == String("AMEBA_BLE_DEV")) {
            Serial.print("Found Ameba BLE Device at address ");
            Serial.println(foundDevice.getAddr().str());
            targetDevice = foundDevice;
        }
    }
}

void notificationCB (BLERemoteCharacteristic* chr, uint8_t* data, uint16_t len) {
    char msg[len+1] = {0};
    memcpy(msg, data, len);
    Serial.print("Notification received for chr UUID: ");
    Serial.println(chr->getUUID().str());
    Serial.print("Received string: ");
    Serial.println(String(msg));
}

void setup() {
    Serial.begin(115200);

    BLE.init();
    BLE.setScanCallback(scanCB);
    BLE.beginCentral(1);

    BLE.configScan()->startScan(2000);
    BLE.configConnection()->connect(targetDevice, 2000);
    delay(2000);
    int8_t connID = BLE.configConnection()->getConnId(targetDevice);
    if (!BLE.connected(connID)) {
        Serial.println("BLE not connected");
    } else {
        BLE.configClient();
        client = BLE.addClient(connID);
        client->discoverServices();
        Serial.print("Discovering services of connected device");
        do {
            Serial.print(".");
            delay(1000);
        } while (!(client->discoveryDone()));
        Serial.println();

        UartService = client->getService(UART_SERVICE_UUID);
        if (UartService != nullptr) {
            Tx = UartService->getCharacteristic(CHARACTERISTIC_UUID_TX);
            if (Tx != nullptr) {
                Serial.println("TX characteristic found");
                Tx->setBufferLen(STRING_BUF_SIZE);
                Tx->setNotifyCallback(notificationCB);
                Tx->enableNotifyIndicate();
            }
            Rx = UartService->getCharacteristic(CHARACTERISTIC_UUID_RX);
            if (Rx != nullptr) {
                Serial.println("RX characteristic found");
                Rx->setBufferLen(STRING_BUF_SIZE);
            }
        }
    }
}

void loop() {
    if (Serial.available()) {
        Rx->writeString(Serial.readString());
    }
    delay(100);
}
```

To test, open the Arduino Serial Monitor for the client device on its respective COM port at **115200**. Then open a second serial terminal (in this case we used TeraTerm) for the previous service device on its respective COM port at **115200**. Type some characters and hit **Send** button from the client device. You should see the same characters received on the service device! Then try typing messages from the service to the client. Again, you should see the same characters on the other end. You may need to turn on the local echo depending on the terminal window that you are using.

<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/Arduino_NORA_W306_BLE_UART_Service_Output.JPG"><img src="../assets/img/Arduino_NORA_W306_BLE_UART_Service_Output.JPG" width="600px" height="600px" alt="BLE UART Service via Tera Term"></a></td>
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/Arduino_NORA_W306_BLE_UART_Client_Output.JPG"><img src="../assets/img/Arduino_NORA_W306_BLE_UART_Client_Output.JPG" width="600px" height="600px" alt="BLE UART Client via Arduino Serial Monitor"></a></td>
    </tr>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>BLE UART Service via Tera Term</i></td>
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>BLE UART Client via Arduino Serial Monitor</i></td>
    </tr>
  </table>
</div>
