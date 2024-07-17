


In this example, we will show how to set your board in deep sleep, wake up to turn on the microSD card's transistor, blink the user LED as an indicator, and then go back into power saving mode.



### Hardware Hookup

For the SD power control (SDPC), make sure to cut the trace on the back of the board and add a solder blob between the center pad and pad labelled as `17`.


<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/WRL-21637_Thing_Plus_NORA-W306_SDPC_Jumper_Modification.jpg"><img src="../assets/img/WRL-21637_Thing_Plus_NORA-W306_SDPC_Jumper_Modification.jpg" width="600px" height="600px" alt="MicroSD Card Power Control Jumper Modified"></a></td>
    </tr>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>MicroSD Card Power Control Jumper Modified</i></td>
    </tr>
  </table>
</div>

Make sure to insert a microSD card into the socket on the back of the board before power the board up. When ready, connect the board to your computer with the USB C cable.



### Arduino Code

This example adds onto Realtek's deep sleep example and toggles the microSD card's control power. The user LED also blinks three times before going back to deep sleep for 5 seconds.

Copy and paste the following code in the Arduino IDE. Select your Board (in this case the **SparkFun Thing Plus NORA-W306 (RTL8720DF)**), and associated COM port (in this case **COM13**). Then hit the upload button.

``` C++

```
