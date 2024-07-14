At a minimum, you will need to plug in the USB C cable to the SparkFun Thing Plus NORA-W306 to power and program the board.

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



### Single Cell LiPo Battery

!!! warning "Battery Polarity"
    Please make sure that you use one of our recommended Lithium Ion batteries. Some batteries use the same JST connector as ours but have the opposite polarity. Connecting one of these to your SparkFun Thing Plus NORA-W306 will destroy it. If you are going to use your own battery, it is up to you to ensure it has the correct polarity.

For remote applications, you can connect a standard single cell LiPo battery. The SparkFun Thing Plus NORA-W306 has a built-in charger too which will charge your battery at **500mA** when a USB-C is connected. Please make sure your battery capacity is at least 500mAh (0.5Ah); bad things will happen if you try to charge smaller batteries using the board's default charge rate of 500mA. Of course, you can adjust the charge rate with the 3-way jumper on the back of the board. The yellow CHG charging LED will light up while the battery is charging and will turn off once charging is complete.

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


The MCP73831 charge IC on the board is used on a few SparkFun products. For more information about the CHG status LED, we recommend taking look at the Hardware Overview. We also recommend taking a look at this tutorial for [Single Cell LiPo Battery Care](https://learn.sparkfun.com/tutorials/single-cell-lipo-battery-care).

<div class="grid cards" style="width:500px; margin: 0 auto;" markdown>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/single-cell-lipo-battery-care">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/learn_tutorials/3/0/4/5/Remove_2-pin_JST-PH_Connector_LiPo_Battery_Needle_Nose_Pliers_Wiggling-3.jpg" style="width:264px; height:148px; object-fit:contain;" alt="Single Cell LiPo Battery Care">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/single-cell-lipo-battery-care">
      <b>Single Cell LiPo Battery Care</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
</div>



### Inserting a MicroSD Card

For those that need to store data, you can add a microSD card to your application. You will just need to insert a microSD card with the metal contacts facing the board and into the socket on the back. Compared to other microSD cards sockets in sparkFun's storefront, this will not have a click to lock the memory card in place. Just make sure to fully insert the memory card.

<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/WRL-21637_Thing_Plus_NORA-W306_microSD_Card.jpg"><img src="../assets/img/WRL-21637_Thing_Plus_NORA-W306_microSD_Card.jpg" width="600px" height="600px" alt="MicroSD Card in Socket"></a></td>
    </tr>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>MicroSD Card in Socket</i></td>
    </tr>
  </table>
</div>

You should only insert or remove the SD card while the power is turned off or disconnected. Removing the card while the SparkFun Thing Plus NORA-W306 is powered will almost certainly corrupt your data.



### Connecting via Qwiic

For users that want to connect a Qwiic-enabled device, you will simply need to insert a cable between the Qwiic connectors. Then insert a USB cable between the microcontroller and your computer to power and program.

<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/WRL-21637_Thing_Plus_NORA-W306_Qwiic_Enabled_Device_OLED.jpg"><img src="../assets/img/WRL-21637_Thing_Plus_NORA-W306_Qwiic_Enabled_Device_OLED.jpg" width="600px" height="600px" alt="Qwiic-enabled Device Connected to Thing Plus NORA-w306"></a></td>
    </tr>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>Qwiic-enabled Device Connected to Thing Plus NORA-W306</i></td>
    </tr>
  </table>
</div>



### Connecting via PTH

For temporary connections to the PTHs, you could use IC hooks to test out the pins. However, you'll need to solder headers or wires of your choice to the board for a secure connection. You can choose between a combination of [header pins and jumper wires](https://learn.sparkfun.com/tutorials/how-to-solder-through-hole-soldering/all), or [stripping wire and soldering the wire](https://learn.sparkfun.com/tutorials/working-with-wire/all) directly to the board.

<div class="grid cards col-2" markdown>

-   <a href="https://learn.sparkfun.com/tutorials/how-to-solder-through-hole-soldering/all">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/learn_tutorials/5/Soldering_Action-01.jpg"style="width:264px; height:148px; object-fit:contain;" alt="How to Solder: Through Hole Soldering">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/how-to-solder-through-hole-soldering/all">
      <b>How to Solder: Through Hole Soldering</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->

-   <a href="https://learn.sparkfun.com/tutorials/working-with-wire/all">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/0/5/0/0/f/5138de3cce395fbb1b000002.JPG" style="width:264px; height:148px; object-fit:contain;" alt="Working with Wire">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/working-with-wire/all">
      <b>Working with Wire</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
</div>
