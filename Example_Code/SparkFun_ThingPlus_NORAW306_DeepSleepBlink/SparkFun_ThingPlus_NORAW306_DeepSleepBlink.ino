/*
* SparkFun Electronics 
* 7/17/2024 
*
* SparkFun_ThingPlus_NORAW306_DeepSleepBlink.ino
*
* Deep Sleep mode example for the SparkFun Thing Plus NORA-W306
*
* This example demonstrates how to put the NORA-W306 into deep sleep mode and
* wake it up using the AON timer (every 5 seconds). 
* When awake, the onboard LED will blink.
* When asleep, the current consumption can be monitored using the MEAS jumper.
*
* Hardware Hookup and Instructions:
*   Connect the NORA-W306 to your computer using a USB-C cable.
*   Upload this code to the NORA-W306.
*   To measure the low-power consumption of the NORA-W306, remove USB-C cable 
*   and utilize the MEAS jumper to measure the current consumption.
*   
* Software versions used in this example:
*   Arduino IDE 2.3.2
*   Realtek Ameba Boards (32-bits ARM Cortex-M33 @200MHz) by Realtek Version 3.1.8
*     (https://github.com/ambiot/ambd_arduino)
*     (https://raw.githubusercontent.com/ambiot/ambd_arduino/dev/Arduino_package/package_realtek_amebad_early_index.json)
*
* Original code is from the following example in the RealTek Ameba Arduino package:
*  Examples -> AmebaPowerSave -> DeepSleepMode.ino
*
* MIT License
*
* Copyright (c) 2024 SparkFun Electronics
*
* Permission is hereby granted, free of charge, to any person obtaining a copy of
* this software and associated documentation files (the "Software"), to deal in the
* Software without restriction, including without limitation the rights to use,
* copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the
* Software, and to permit persons to whom the Software is furnished to do so,
* subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
* PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
* HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
* OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <PowerSave.h>

//SET_DS_AON_TIMER_WAKEUP
//SET_DS_RTC_WAKEUP
//For AMB21/22 only the AON GPIO pins listed below should be selected
    //SET_AON_GPIO_WAKEUP_PA25          // pin 16
    //SET_AON_GPIO_WAKEUP_PA26          // pin 17
    //SET_AON_GPIO_WAKEUP_PA21          // pin 26
    //SET_AON_GPIO_WAKEUP_PA20          // pin 27
    //SET_AON_GPIO_WAKEUP_PA19          // pin 28
//For AMB23 only the AON GPIO pins listed below should be selected
    //SET_AON_GPIO_WAKEUP_PA12          // pin 9
    //SET_AON_GPIO_WAKEUP_PA13          // pin 10
    //SET_AON_GPIO_WAKEUP_PA14          // pin 11
    //SET_AON_GPIO_WAKEUP_PA15          // pin 12
    //SET_AON_GPIO_WAKEUP_PA16          // pin 13
    //SET_AON_GPIO_WAKEUP_PA18          // pin 15
    //SET_AON_GPIO_WAKEUP_PA19          // pin 16
    //SET_AON_GPIO_WAKEUP_PA21          // pin 18
//For BW16/BW16-TypeC only the AON GPIO pins listed below should be selected
    //SET_AON_GPIO_WAKEUP_PA25          // pin 7
    //SET_AON_GPIO_WAKEUP_PA26          // pin 8
    //SET_AON_GPIO_WAKEUP_PA15          // pin 9
    //SET_AON_GPIO_WAKEUP_PA14          // pin 10
    //SET_AON_GPIO_WAKEUP_PA13          // pin 11
    //SET_AON_GPIO_WAKEUP_PA12          // pin 12
//For board AW-CU488_ThingPlus
    //SET_AON_GPIO_WAKEUP_PA18          // pin 0
    //SET_AON_GPIO_WAKEUP_PA16          // pin 1
    //SET_AON_GPIO_WAKEUP_PA17          // pin 2
    //SET_AON_GPIO_WAKEUP_PA13          // pin 3
    //SET_AON_GPIO_WAKEUP_PA12          // pin 4
    //SET_AON_GPIO_WAKEUP_PA26          // pin 5
    //SET_AON_GPIO_WAKEUP_PA25          // pin 6
    //SET_AON_GPIO_WAKEUP_PA19          // pin 8
    //SET_AON_GPIO_WAKEUP_PA15          // pin 28
    //SET_AON_GPIO_WAKEUP_PA14          // pin 29
//For board AMB25/AMB26
    //SET_AON_GPIO_WAKEUP_PA12          // pin 3
    //SET_AON_GPIO_WAKEUP_PA13          // pin 2
    //SET_AON_GPIO_WAKEUP_PA14          // pin 1
    //SET_AON_GPIO_WAKEUP_PA15          // pin 0
    //SET_AON_GPIO_WAKEUP_PA25          // pin 7
    //SET_AON_GPIO_WAKEUP_PA26          // pin 6
//For board SparkFun Thing Plus NORA-W306
    //SET_AON_GPIO_WAKEUP_PA18          // pin 6
    //SET_AON_GPIO_WAKEUP_PA13          // pin 13
    //SET_AON_GPIO_WAKEUP_PA12          // pin 14
    //SET_AON_GPIO_WAKEUP_PA26          // pin 11
    //SET_AON_GPIO_WAKEUP_PA25          // pin 12
    //SET_AON_GPIO_WAKEUP_PA15          // pin 15
    //SET_AON_GPIO_WAKEUP_PA14          // pin 16

#define DS_WAKEUP_SOURCE                SET_DS_AON_TIMER_WAKEUP

#define AON_TIMER_SLEEP_DURATION        5000
#define DS_RTC_ALARM_DAY                0
#define DS_RTC_ALARM_HOUR               0
#define DS_RTC_ALARM_MIN                0
#define DS_RTC_ALARM_SEC                10

void DeepSleep_wakeup(void) {
    //printf("\r\nDeep sleep wakeuped! \r\n");
    uint32_t wakereason_number = PowerSave.AONWakeReason();

    //pinMode(17, OUTPUT); // 17 SDPC uSD power control
    //digitalWrite(17, LOW); // Turn on uSD power if you'd like to measure its current consumption   
    
    if (wakereason_number == AONWakeReason_AON_GPIO) {
        //printf("AonWakepin wakeup. Wait 5s sleep again.    \r\n");
        delay(5000);
    } else if (wakereason_number == AONWakeReason_AON_TIMER) {
        PowerSave.AONTimerCmd();
        //printf("AonTimer wakeup. Wait 5s sleep again.    \r\n");
     
        pinMode(LED_BUILTIN, OUTPUT);
        for(int i = 0 ; i < 5 ; i ++)
        {
          digitalWrite(LED_BUILTIN, HIGH);
          delay(1000);
          digitalWrite(LED_BUILTIN, LOW);
          delay(1000);
        }
        pinMode(LED_BUILTIN, INPUT);
        //delay(5000);
    } else if (wakereason_number == AONWakeReason_RTC) {
        //printf("RTC wakeup. Wait 5s sleep again.    \r\n");
        delay(5000);
    }

    //pinMode(17, INPUT_PULLUP); // 17 SDPC uSD power control (Pullup = off)

    PowerSave.AONWakeClear();
}

void setup() {
    // If you want serial debug messages, uncomment the following lines and others
    // below, as desired.
    // Open serial communications and wait for port to open:
    // Serial.begin(115200);
    // while (!Serial) {
    //     ; // wait for serial port to connect. Needed for native USB port only
    // }

    // Pin configuration - specific to the SparkFun Thing Plus NORA-W306

    pinMode(0, INPUT_PULLDOWN); // LOG RX, can backpower the CP2102
    pinMode(1, INPUT_PULLDOWN); // LOG TX, can backpower the CP2102
    pinMode(4, INPUT_PULLDOWN); // SPI0_CS, can sink current from 3V3 via R16 (100K), note, this is only possible if you leave uSD power on
    pinMode(5, INPUT_PULLDOWN); // SPI0_CLK
    pinMode(6, INPUT_PULLDOWN); // SPI0_PICO
    pinMode(7, INPUT_PULLDOWN); // SPI0_POCI

    pinMode(11, INPUT_PULLUP); // SDA
    pinMode(12, INPUT_PULLUP); // SCL
    pinMode(17, INPUT_PULLUP); // 17 SDPC uSD power control
    pinMode(20, INPUT_PULLNONE); // aka PB_24, this is tied internally to PB_23 (aka Arduino pin "17") and also defaults to internal pulldown.

    PowerSave.begin(DEEPSLEEP_MODE);

    if (TRUE == (PowerSave.DsleepWakeStatusGet())) {
        DeepSleep_wakeup();
    }

    PowerSave.AONTimerDuration(0);

    switch (DS_WAKEUP_SOURCE) {
        case SET_DS_AON_TIMER_WAKEUP:
            PowerSave.DS_AON_TIMER_WAKEUP();
            PowerSave.AONTimerDuration(AON_TIMER_SLEEP_DURATION);
            break;
        case SET_DS_RTC_WAKEUP:
            PowerSave.DS_RTC_WAKEUP();
            PowerSave.RTCWakeSetup(DS_RTC_ALARM_DAY, DS_RTC_ALARM_HOUR, DS_RTC_ALARM_MIN, DS_RTC_ALARM_SEC);
            break;
        case SET_AON_GPIO_WAKEUP_PA12:
            PowerSave.AON_WAKEPIN_WAKEUP_PA12();
            break;
        case SET_AON_GPIO_WAKEUP_PA13:
            PowerSave.AON_WAKEPIN_WAKEUP_PA13();
            break;
        case SET_AON_GPIO_WAKEUP_PA14:
            PowerSave.AON_WAKEPIN_WAKEUP_PA14();
            break;
        case SET_AON_GPIO_WAKEUP_PA15:
            PowerSave.AON_WAKEPIN_WAKEUP_PA15();
            break;
        case SET_AON_GPIO_WAKEUP_PA16:
            PowerSave.AON_WAKEPIN_WAKEUP_PA16();
            break;
        case SET_AON_GPIO_WAKEUP_PA17:
            PowerSave.AON_WAKEPIN_WAKEUP_PA17();
            break;
        case SET_AON_GPIO_WAKEUP_PA18:
            PowerSave.AON_WAKEPIN_WAKEUP_PA18();
            break;
        case SET_AON_GPIO_WAKEUP_PA19:
            PowerSave.AON_WAKEPIN_WAKEUP_PA19();
            break;
        case SET_AON_GPIO_WAKEUP_PA20:
            PowerSave.AON_WAKEPIN_WAKEUP_PA20();
            break;
        case SET_AON_GPIO_WAKEUP_PA21:
            PowerSave.AON_WAKEPIN_WAKEUP_PA21();
            break;
        case SET_AON_GPIO_WAKEUP_PA25:
            PowerSave.AON_WAKEPIN_WAKEUP_PA25();
            break;
        case SET_AON_GPIO_WAKEUP_PA26:
            PowerSave.AON_WAKEPIN_WAKEUP_PA26();
            break;
        default:
            printf("Unknown wakeup source.    \r\n");
        break;
    }

    PowerSave.enable();
}

void loop() {
    delay(1000);
}
