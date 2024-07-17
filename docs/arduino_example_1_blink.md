Now that we have our board add-on installed, we can get started playing around with the development board. For the scope of this tutorial, we will highlight a few of the features on the board. From there we will be able to build our own custom code to integrate the development board into a project.

In this example, we will blink the LED that is built into the SparkFun Thing Plus NORA-W306.



### Hardware Hookup

The connection is the same as explained earlier in the tutorial. Connect the USB cable to the SparkFun Thing Plus NORA-W306. Of course, make sure to connect the other end to your computer.

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

Let's upload a sketch to the board. This example is the basic Arduino blink example. Note that we specify pin `18` instead of using the macro called `LED_BUILTIN`.

Copy and paste the following code in the Arduino IDE. Select the correct board definition from the menu (in this case, **Tools** > **Board** > **Realtek Ameba Boards (32-bits ARM Cortex-M33 @200MHz)** > **SparkFun Thing Plus NORA-W306 (RTL8720DF)**. Then select the correct COM port that the board enumerated to (in this case, it was **COM13**). Hit upload button.

``` C++
/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  This example code is in the public domain.
 */

// Pin 18 has an LED connected on most Arduino boards.
// give it a name:
int led = 18; //LED is connected to pin 18 on the SparkFun Thing Plus NORA-W306

//NOTE: You can also use LED_BUILTIN.

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}
```

!!! note
    <b>Note:</b> You can also use the macro for the LED by using <code>LED_BUILTIN</code>. The code in the built-in Arduino examples will function the same as well!

Once uploaded, check the LED labeled as **18** on the board. It should be blinking on and off every second! Sweet!

<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/WRL-21637_Thing_Plus_NORA-W306_Blink_User_LED.jpg"><img src="../assets/img/WRL-21637_Thing_Plus_NORA-W306_Blink_User_LED.jpg" width="600px" height="600px" alt="SparkFun Thing Plus NORA-W306 User LED On"></a></td>
    </tr>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>SparkFun Thing Plus NORA-W306 User LED On</i></td>
   </tr>
  </table>
</div>
