


In the following two examples, we will connect two NORA-W306 development boards  via Bluetooth and send serial characters.



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

When connecting and disconnecting the boards from your computer, you will noticed that the COM port enumerates to a certain number from the menu **Tools** > **Port**. Feel free to write down the COM port on the sticky note as well after uploading code.



### Arduino Code

Let&apos;s upload the sketch to send serial data between two SparkFun Thing Plus NORA-W306 boards wirelessly using the Bluetooth&reg; Low Energy (BLE) feature. From the menu, select the following: **File** > **Examples** > **File** > **Examples** > <font style="color:gray"><b>Examples for SparkFun Thing Plus NORA-W306 (RTL8720DF)</b></font> | **AmebaBLE** > **BLEUartService**.

Or you can copy and paste the following code in the Arduino IDE. Select the correct board definition from the menu (in this case, **Tools** > **Boards** > **SparkFun Thing Plus NORA-W306 (RTL8720DF)**). Then select the correct COM port that the board enumerated to (in this case, it was COM13). Hit upload button.

``` C++
/*

 Example guide:
 https://www.amebaiot.com/en/amebad-arduino-ble-uart-service/
 */

#include "BLEDevice.h"

#define UART_SERVICE_UUID      "6E400001-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_TX "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"

#define STRING_BUF_SIZE 100

BLEService UartService(UART_SERVICE_UUID);
BLECharacteristic Rx(CHARACTERISTIC_UUID_RX);
BLECharacteristic Tx(CHARACTERISTIC_UUID_TX);
BLEAdvertData advdata;
BLEAdvertData scndata;
bool notify = false;

void readCB (BLECharacteristic* chr, uint8_t connID) {
    Serial.print("Characteristic ");
    Serial.print(chr->getUUID().str());
    Serial.print(" read by connection ");
    Serial.println(connID);
}

void writeCB (BLECharacteristic* chr, uint8_t connID) {
    Serial.print("Characteristic ");
    Serial.print(chr->getUUID().str());
    Serial.print(" write by connection ");
    Serial.println(connID);
    if (chr->getDataLen() > 0) {
        Serial.print("Received string: ");
        Serial.print(chr->readString());
        Serial.println();
    }
}

void notifCB(BLECharacteristic* chr, uint8_t connID, uint16_t cccd) {
    if (cccd & GATT_CLIENT_CHAR_CONFIG_NOTIFY) {
        //printf("Notifications enabled on Characteristic %s for connection %d \n", chr->getUUID().str(), connID);
        Serial.print("Notifications enabled on Characteristic");
        notify = true;
    } else {
        //printf("Notifications disabled on Characteristic %s for connection %d \n", chr->getUUID().str(), connID);
        Serial.print("Notifications disabled on Characteristic");
        notify = false;
    }
    Serial.print(chr->getUUID().str());
    Serial.print(" for connection");
    Serial.println(connID);
}

void setup() {
    Serial.begin(115200);

    advdata.addFlags(GAP_ADTYPE_FLAGS_LIMITED | GAP_ADTYPE_FLAGS_BREDR_NOT_SUPPORTED);
    advdata.addCompleteName("AMEBA_BLE_DEV");
    scndata.addCompleteServices(BLEUUID(UART_SERVICE_UUID));

    Rx.setWriteProperty(true);
    Rx.setWritePermissions(GATT_PERM_WRITE);
    Rx.setWriteCallback(writeCB);
    Rx.setBufferLen(STRING_BUF_SIZE);
    Tx.setReadProperty(true);
    Tx.setReadPermissions(GATT_PERM_READ);
    Tx.setReadCallback(readCB);
    Tx.setNotifyProperty(true);
    Tx.setCCCDCallback(notifCB);
    Tx.setBufferLen(STRING_BUF_SIZE);

    UartService.addCharacteristic(Rx);
    UartService.addCharacteristic(Tx);

    BLE.init();
    BLE.configAdvert()->setAdvData(advdata);
    BLE.configAdvert()->setScanRspData(scndata);
    BLE.configServer(1);
    BLE.addService(UartService);

    BLE.beginPeripheral();
}

void loop() {
    if (Serial.available()) {
        Tx.writeString(Serial.readString());
        if (BLE.connected(0) && notify) {
            Tx.notify(0);
        }
    }
    delay(100);
}
```

When finished uploading, head to the next section to upload code to a second SparkFun Thing Plus NORA-W306 board.
