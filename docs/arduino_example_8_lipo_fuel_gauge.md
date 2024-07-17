


In this example, we will measure the LiPo battery's capacity using the built-in MAX17048 LiPo Fuel Gauge.



### Hardware Hookup

We recommend connecting a single cell LiPo battery to the 2-pin JST style connector. If you have not already, connect a compatible single cell, LiPo battery to the board.

<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/WRL-21637_Thing_Plus_NORA-W306_LiPo_Battery.jpg"><img src="../assets/img/WRL-21637_Thing_Plus_NORA-W306_LiPo_Battery.jpg" width="600px" height="600px" alt="Battery Connected"></a></td>
    </tr>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>Battery Connected</i></td>
    </tr>
  </table>
</div>

When ready, connect the board to your computer with the USB C cable.



### Installing the Arduino Library

First, you&apos;ll need to download and install the **SparkFun MAX1704x Fuel Gauge Arduino Library**. You can install this library automatically in the Arduino IDE&apos;s Library Manager by searching for "**SparkFun MAX1704x Fuel Gauge**". Or you can manually download it from the [GitHub repository](https://github.com/sparkfun/SparkFun_MAX1704x_Fuel_Gauge_Arduino_Library).

<div style="text-align: center"><a href="https://github.com/sparkfun/SparkFun_MAX1704x_Fuel_Gauge_Arduino_Library/archive/refs/heads/main.zip" class="md-button">Download the SparkFun MAX1704x Fuel Gauge Arduino Library (ZIP)</a></div>



### Arduino Code

In this example, we will be checking a single cell LiPo battery&apos;s voltage and the state of charge using the MAX17048. The output will be sent to the Serial Monitor.

From the menu, select the following: **File** > **Examples** > **SparkFun_MAX1704x_Fuel_Gauge_Arduino_Library** > **Example1_Simple**. Comment out the default instance for the MAX17043 and uncomment the line for the MAX17048.

``` C++
//SFE_MAX1704X lipo; // Defaults to the MAX17043

//SFE_MAX1704X lipo(MAX1704X_MAX17043); // Create a MAX17043
//SFE_MAX1704X lipo(MAX1704X_MAX17044); // Create a MAX17044
SFE_MAX1704X lipo(MAX1704X_MAX17048); // Create a MAX17048
//SFE_MAX1704X lipo(MAX1704X_MAX17049); // Create a MAX17049
```

Or you can copy and paste the following code in the Arduino IDE. Select your Board (in this case the **SparkFun Thing Plus NORA-W306 (RTL8720DF)**), and associated COM port (in this case **COM13**). Then hit the upload button.

``` C++
/******************************************************************************
Example1_Simple
By: Paul Clark
Date: October 23rd 2020

Based extensively on:
MAX17043_Simple_Serial.cpp
SparkFun MAX17043 Example Code
Jim Lindblom @ SparkFun Electronics
Original Creation Date: June 22, 2015

This file demonstrates the simple API of the SparkFun MAX17043 Arduino library.

This example will print the gauge's voltage and state-of-charge (SOC) readings
to Serial (115200 baud)

This code is released under the MIT license.

Distributed as-is; no warranty is given.
******************************************************************************/

#include <Wire.h> // Needed for I2C

#include <SparkFun_MAX1704x_Fuel_Gauge_Arduino_Library.h> // Click here to get the library: http://librarymanager/All#SparkFun_MAX1704x_Fuel_Gauge_Arduino_Library

//SFE_MAX1704X lipo; // Defaults to the MAX17043

//SFE_MAX1704X lipo(MAX1704X_MAX17043); // Create a MAX17043
//SFE_MAX1704X lipo(MAX1704X_MAX17044); // Create a MAX17044
SFE_MAX1704X lipo(MAX1704X_MAX17048); // Create a MAX17048
//SFE_MAX1704X lipo(MAX1704X_MAX17049); // Create a MAX17049

double voltage = 0; // Variable to keep track of LiPo voltage
double soc = 0; // Variable to keep track of LiPo state-of-charge (SOC)
bool alert; // Variable to keep track of whether alert has been triggered

void setup()
{
	Serial.begin(115200); // Start serial, to output debug data
  while (!Serial)
    ; //Wait for user to open terminal
  Serial.println(F("MAX17043 Example"));

  Wire.begin();

  lipo.enableDebugging(); // Uncomment this line to enable helpful debug messages on Serial

  // Set up the MAX17043 LiPo fuel gauge:
  if (lipo.begin() == false) // Connect to the MAX17043 using the default wire port
  {
    Serial.println(F("MAX17043 not detected. Please check wiring. Freezing."));
    while (1)
      ;
  }

	// Quick start restarts the MAX17043 in hopes of getting a more accurate
	// guess for the SOC.
	lipo.quickStart();

	// We can set an interrupt to alert when the battery SoC gets too low.
	// We can alert at anywhere between 1% - 32%:
	lipo.setThreshold(20); // Set alert threshold to 20%.
}

void loop()
{
  // lipo.getVoltage() returns a voltage value (e.g. 3.93)
  voltage = lipo.getVoltage();
  // lipo.getSOC() returns the estimated state of charge (e.g. 79%)
  soc = lipo.getSOC();
  // lipo.getAlert() returns a 0 or 1 (0=alert not triggered)
  alert = lipo.getAlert();

  // Print the variables:
  Serial.print("Voltage: ");
  Serial.print(voltage);  // Print the battery voltage
  Serial.println(" V");

  Serial.print("Percentage: ");
  Serial.print(soc); // Print the battery state of charge
  Serial.println(" %");

  Serial.print("Alert: ");
  Serial.println(alert);
  Serial.println();

  delay(500);
}
```

Open the Arduino Serial Monitor and set it to 115200 baud to view the serial output. You should see the voltage, battery percent, alert flag, and several more readings. In this case, the single cell LiPo battery that was connected to the IC was fully charged and at about 4.10V.

<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/Arduino_Output_MAX17048_LiPo_Fuel_Gauge_NORA-W306.JPG"><img src="../assets/img/Arduino_Output_MAX17048_LiPo_Fuel_Gauge_NORA-W306.JPG" width="600px" height="600px" alt="Arduino Output Showing the LiPo Battery's Capacity"></a></td>
    </tr>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>Arduino Output Showing the LiPo Battery's Capacity</i></td>
    </tr>
  </table>
</div>    

But wait! If you looked closely at the circuit of the SparkFun Thing Plus NORA-W306, there is also a charge circuit built in. Try closing out the Arduino Serial Monitor, disconnecting the USB, and disconnecting the LiPo battery. Then reinsert the LiPo battery, connect the USB cable, and reopen the Arduino Serial Monitor. The IC will recalculate everything. In the image below, the voltage is a bit misleading since the charge IC is charging the LiPo battery and may not be the true representation of the LiPo battery's voltage. The remaining charge was closer to what was expected.

<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
      <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/Arduino_Output_MAX17048_LiPo_Fuel_Gauge_NORA-W306-2.JPG"><img src="../assets/img/Arduino_Output_MAX17048_LiPo_Fuel_Gauge_NORA-W306-2.JPG" width="600px" height="600px" alt="Arduino Output Showing the LiPo Battery's Capacity"></a></td>
    </tr>
    <tr style="vertical-align:middle;">
      <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>Arduino Output Showing the LiPo Battery's Capacity</i></td>
    </tr>
  </table>
</div>    

!!! note
    For development boards that have a built in charge circuit and fuel gauge, you may want to consider using a display to view the LiPo battery's true voltage and remaining charge. Otherwise, you could use a multimeter to measure the LiPo battery's voltage when a USB cable is not plugged in. Below is an example that uses the Qwiic Micro OLED to display the LiPo battery's voltage and remaining charge since the SparkFun Thing Plus NORA-W306 includes a built in charge circuit and fuel gauge (MAX17048). Just make sure to adjust the code for your fuel gauge and display.

    <div style="text-align: center;">
      <table>
        <tr style="vertical-align:middle;">
         <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/WRL-21637_Thing_Plus_NORA-W306_LiPo_Fuel_Gauge_OLED.jpg"><img src="../assets/img/WRL-21637_Thing_Plus_NORA-W306_LiPo_Fuel_Gauge_OLED.jpg" width="600px" height="600px" alt="LiPo Fuel Gauge Monitoring LiPo Battery and Displaying Battery Capacity on Qwiic Micro OLED"></a></td>
        </tr>
        <tr style="vertical-align:middle;">
         <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>LiPo Fuel Gauge Monitoring LiPo Battery and Displaying Battery Capacity on Qwiic Micro OLED</i></td>
       </tr>
      </table>
    </div>
