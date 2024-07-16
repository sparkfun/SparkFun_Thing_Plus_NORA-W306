To take advantage of a few of the built-in components on the board, you will need to install a Arduino Library. Of course, you may need additional Arduino Libraries depending on what you connect to the development board. At a minimum, you will need the following listed below to take advantage of the built-in LiPo Fuel Gauge (MAX17048).



### SparkFun MAX1704x Fuel Gauge Arduino Library

SparkFun has written a library to work with the LiPo Fuel Gauge - MAX17048 that is built into the SparkFun Thing Plus NORA-W306. You can obtain this library through the Arduino Library Manager by searching for "**SparkFun MAX1704x Fuel Gauge**". Find the one written by SparkFun Electronics and install the latest version. Users who prefer to manually install the library can get it from the  [GitHub Repository](https://github.com/sparkfun/SparkFun_MAX1704x_Fuel_Gauge_Arduino_Library) or download the .ZIP by clicking the button below:

<div style="text-align: center"><a href="https://github.com/sparkfun/SparkFun_MAX1704x_Fuel_Gauge_Arduino_Library/archive/refs/heads/main.zip" class="md-button">SparkFun MAX1704x Fuel Gauge Arduino Library (ZIP)</a></div>



### SdFat Arduino Library

Bill Greiman has written a library for memory cards formatted to FAT16/FAT32 exFAT. We used this Arduino Library instead of the ones that were listed in the libraries included with the AmebaD. You can obtain this library through the Arduino Library Manager by searching for "**sdfat**". Find the one written by Bill Greiman and install the latest version. Users who prefer to manually install the library can get it from the [GitHub Repository](https://github.com/greiman/SdFat) or download the .ZIP by clicking the button below:

<div style="text-align: center"><a href="https://github.com/greiman/SdFat/archive/refs/heads/master.zip" class="md-button">Bill Greiman&apos;s SdFat Arduino Library (ZIP)</a></div>

!!! note
    At the time of writing, **SdFat** by Bill Greiman **v2.2.3** worked with the SparkFun Thing Plus - NORA-W306. 

!!! note
    We recommend using some of the built-in libraries for the u-blox NORA-W306 as well after installing the board add-ons: **File** > **Examples** > <font style="color:gray"><b>Examples for SparkFun Thing Plus NORA-W306 (RTL8720DF)</b></font> . Certain examples like the AmebaWS2812B were written specifically for the NORA-W306 architecture.

    <div style="text-align: center;">
      <table>
        <tr style="vertical-align:middle;">
         <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/AmebaD_RealTek_Additional_Arduino_Examples.JPG"><img src="../assets/img/AmebaD_RealTek_Additional_Arduino_Examples.JPG" width="600px" height="600px" alt="More Arduino Examples!"></a></td>
        </tr>
        <tr style="vertical-align:middle;">
         <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>More Arduino Examples!</i></td>
       </tr>
      </table>
    </div>
