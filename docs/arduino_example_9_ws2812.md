


In this example, we will blink the WS2812.



### Hardware Hookup

The connection is the same as explained earlier in the tutorial. Connect the USB cable to the SparkFun Thing Plus NORA-W306 and the other end to your computer. For the scope of this tutorial, we will be using the built-in WS2812B on the development board.

For those that are interested in connecting additional WS2812, you can follow the table below to daisy chain additional LEDs. This configuration is when users are using USB for power and daisy chaining a small number of WS2812's.

<div style="text-align: center;">
    <table>
        <tr>
            <th style="text-align: center; border: solid 1px #cccccc;">NORA-W306<br />Pinout
            </th>
            <th style="text-align: center; border: solid 1px #cccccc;">WS2812 LED<br />Pinout
            </th>
        </tr>
        <tr>
            <td style="text-align: center; border: solid 1px #cccccc;" bgcolor="#f2dede"><font color="#000000">VUSB (if powering off USB<br />and low number of WS2812 LEDs)</font>
            <td style="text-align: center; border: solid 1px #cccccc;" bgcolor="#f2dede"><font color="#000000">VIN</font>
            </td>
        </tr>
        <tr>
            <td style="text-align: center; border: solid 1px #cccccc;" bgcolor="#d4edda"><font color="#000000">LD/LED_D0</font>
            </td>
            <td style="text-align: center; border: solid 1px #cccccc;" bgcolor="#d4edda"><font color="#000000">DI</font>
            </td>
        </tr>
        <tr>
            <td style="text-align: center; border: solid 1px #cccccc;" bgcolor="#fff3cd"><font color="#000000">GND</font>
            </td>
            <td style="text-align: center; border: solid 1px #cccccc;" bgcolor="#fff3cd"><font color="#000000">GND</font>
            </td>
        </tr>
    </table>
</div>

For large number of LEDs, you may want to considering using an [external power supply to power the strip of addressable LEDs](https://learn.sparkfun.com/tutorials/mean-well-led-switching-power-supply-hookup-guide#daisychain).

<div style="text-align: center;">
    <table>
        <tr>
            <th style="text-align: center; border: solid 1px #cccccc;">NORA-W306<br />Pinout
            </th>
            <th style="text-align: center; border: solid 1px #cccccc;">External 5V Power Supply
            </th>
            <th style="text-align: center; border: solid 1px #cccccc;">WS2812 LED<br />Pinout
            </th>
        </tr>
        <tr>
            <td style="text-align: center; border: solid 1px #cccccc;" bgcolor="#f2dede"><font color="#000000"></font>
            <td style="text-align: center; border: solid 1px #cccccc;" bgcolor="#f2dede"><font color="#000000">5V</font>
            <td style="text-align: center; border: solid 1px #cccccc;" bgcolor="#f2dede"><font color="#000000">VIN</font>
            </td>
        </tr>
        <tr>
            <td style="text-align: center; border: solid 1px #cccccc;" bgcolor="#d4edda"><font color="#000000">LD/LED_D0</font>
            </td>
            <td style="text-align: center; border: solid 1px #cccccc;" bgcolor="#d4edda"><font color="#000000"></font>
            </td>
            <td style="text-align: center; border: solid 1px #cccccc;" bgcolor="#d4edda"><font color="#000000">DI</font>
            </td>
        </tr>
        <tr>
            <td style="text-align: center; border: solid 1px #cccccc;" bgcolor="#fff3cd"><font color="#000000">GND</font>
            </td>
            <td style="text-align: center; border: solid 1px #cccccc;" bgcolor="#fff3cd"><font color="#000000">GND</font>
            </td>
            <td style="text-align: center; border: solid 1px #cccccc;" bgcolor="#fff3cd"><font color="#000000">GND</font>
            </td>
        </tr>
    </table>
</div>



### Arduino Code

Let&apos;s upload the sketch control the WS2812. We recommend using the WS2812B Arduino Library that came installed with the board add-on. Below is a modified example of the **WS2812B_Basics.ino** sketch since we the LED is on the secondary SPI port and we are using new terminology for the macro. Of course, since we are using only one WS2812, we also adjusted the code to acknowledge that we have only controlling one LED. Copy and paste the following code in the Arduino IDE.


!!! note
    This code is modified and not the same as the one in the board-add on!!! A few lines were commented out, a macro was used when making an instance of the WS2812B, one LED is used, and the red and green colors are blinking in the loop. For a comparison, you could view the original code provided in the board support package by heading to: **File** > **Examples** > **File** > **Examples** > <font style="color:gray"><b>Examples for SparkFun Thing Plus NORA-W306 (RTL8720DF)</b></font> | **AmebaWS2812B** > **WS2812B_Basics**.

Copy and paste the following code in the Arduino IDE. Select the correct board definition from the menu (in this case, **Tools** > **Board** > **Realtek Ameba Boards (32-bits ARM Cortex-M33 @200MHz)** > **SparkFun Thing Plus NORA-W306 (RTL8720DF)**). Then select the correct COM port that the board enumerated to (in this case, it was **COM13**). Hit upload button.  

``` C++
/*

 Example guide:
 https://www.amebaiot.com/en/amebad-arduino-ws2812b-basics/
 */

#include "WS2812B.h"

#define TOTAL_NUM_OF_LED 1
#define NUM_OF_LEDS 1

// There are multiple choice of SPI_MOSI pins depends on different boards. The default is SPI_MOSI/SPI1_MOSI
// AMB21/AMB22              pin 11 /  pin21
// AMB23                    pin 9  /  pin 4
// BW16/BW16 Type C         pin 12
// AW-CU488 ThingPlus       pin 1  /  pin 14
// AMB25/AMB26              pin 17 /  pin 3
// NORA-W306 Thing Plus     pin 6  /  pin 14


//WS2812B led(SPI_MOSI, TOTAL_NUM_OF_LED);  //default SPI macro
WS2812B led(SPI1_PICO, TOTAL_NUM_OF_LED); // SPI1 macro for NORA-W306 since built-in WS2812 is attached to secondary SPI pin

void setup() {
    Serial.begin(115200);
    Serial.println("WS2812B test");
    led.begin();
    //Set a specific LED with a certain color
    led.setPixelColor(0, 50, 0, 0);
    //led.setPixelColor(1, 0, 50, 0);
    //led.setPixelColor(2, 0, 0, 50);
    led.show();
    delay(1000);
    //Fill the entire LED strip with the same color
    //led.fill(60, 0, 25, 0, NUM_OF_LEDS);
    //led.show();
}

void loop() {
    led.setPixelColor(0, 50, 0, 0);
    led.show();
    delay(1000);

    led.setPixelColor(0, 0, 50, 0);
    led.show();
    delay(1000);
}

```

After uploading code, the built-in WS2812B LED will light up red momentarily. Once in the loop, the red and green LED will blink back and forth every second. Try adjusting the code to control the LED to make primary, secondary, or tertiary colors with the press of a button! Or changing the color of the LED based on how much power your LiPo battery has available. Or even modify the **WS2812B_Patterns.ino** included with the board add-on to add effects and patterns to your LED. You can even go as far as soldering additional WS2812Bs by daisy chaining them to the DO / LED_DO pin. Just make sure that you have a [sufficient power supply to power your all of your LEDs](https://learn.sparkfun.com/tutorials/how-to-power-a-project/all#voltagecurrent-considerations).

<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/WRL-21637_Thing_Plus_NORA-W306_WS2812_RGB_Addressable_LED.jpg"><img src="../assets/img/WRL-21637_Thing_Plus_NORA-W306_WS2812_RGB_Addressable_LED.jpg" width="600px" height="600px" alt="More Arduino Examples!"></a></td>
    </tr>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>WS2812 Addressable LED Green LED Turned On</i></td>
   </tr>
  </table>
</div>
