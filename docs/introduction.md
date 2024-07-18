


The [SparkFun Thing Plus - NORA-W306](https://www.sparkfun.com/products/21637) is a Feather form-factor development board equipped with the u-blox NORA-W306 module. The module contains a Realtek RTL8720DF, which has an integrated single-chip low-power dual-band (2.4GHz and 5GHz) Wireless LAN (WLAN) and Bluetooth&reg; Low Energy (BLE 5.3) communication microcontroller. It also consists of a dual processor core: Arm Cortex-M33 and Cortex-M23. To complement the module's low-power options, we've optimized components and added the ability to depower all subsystems to conserve as much power as possible for remote battery-powered applications.


<div class="grid cards" style="width:500px; margin: 0 auto;" markdown>

-   <a href="https://www.sparkfun.com/products/21637">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/2/1/4/7/0/WRL-21637-Thing-Plus-NORA-W306-feature.jpg" style="width:140px; height:140px; object-fit:contain;" alt="SparkFun Thing Plus NORA-W306">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/21637">
      <b>SparkFun Thing Plus NORA-W306</b>
      <br />
      WRL-21637
      <br />
      <center>[Purchase from SparkFun :fontawesome-solid-cart-plus:](https://www.sparkfun.com/products/21637){ .md-button .md-button--primary }</center>
    </a>

</div>


In this tutorial, we'll go over the hardware and how to hookup the development board to an Arduino. We will also go over a few Arduino examples to get started!



### Required Materials

To follow along with this tutorial, you will need the following materials. You may not need everything though depending on what you have. Add it to your cart, read through the guide, and adjust the cart as necessary.

<!--


* 1x [USB micro-B Cable - 6 Foot [CAB-15425]](https://www.sparkfun.com/products/15425)
* 1x [SparkFun Thing Plus NORA-W306 [WRL-21637]](https://www.sparkfun.com/products/21637)
* 1x microSD Card
    * [microSD Card - 1GB (Class 4) [COM-15107]](https://www.sparkfun.com/products/15107) for those that are interested in logging data
* 1x microSD Card Adapter
* 1x Qwiic Cable
    * [Flexible Qwiic Cable - 50mm [PRT-17260]](https://www.sparkfun.com/products/17260), for short distances
    * [Flexible Qwiic Cable - 500mm [PRT-17257]](https://www.sparkfun.com/products/17257), for those that need to wire the board farther away from your microcontroller
* 1x [SparkFun Micro OLED Breakout (Qwiic) [SEN-22495]](https://www.sparkfun.com/products/22495) to Qwiic-ly connect and display readings

-->



<div class="grid cards col-4" markdown>

<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/15425">
      <figure markdown>
        <img src="https://cdn.sparkfun.com//assets/parts/1/3/9/8/4/15425-Reversible_USB_A_to_C_Cable_-_0.8m-02.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Reversible USB A to C Cable - 0.8m">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/15425">
      <b>Reversible USB A to C Cable - 0.8m</b>
      <br />
      CAB-15425
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/21637">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/2/1/4/7/0/WRL-21637-Thing-Plus-NORA-W306-feature.jpg" style="width:140px; height:140px; object-fit:contain;" alt="SparkFun Thing Plus NORA-W306">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/21637">
      <b>SparkFun Thing Plus NORA-W306</b>
      <br />
      WRL-21637
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/15107">
      <figure markdown>
        <img src="https://cdn.sparkfun.com//assets/parts/1/3/4/7/0/15107-microSD_Card_-_1GB__Class_4_-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="microSD Card - 1GB (Class 4)">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/15107">
      <b>microSD Card - 1GB (Class 4)</b>
      <br />
      COM-15107
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/22495">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/2/2/5/5/8/22495-OLED-front.jpg" style="width:140px; height:140px; object-fit:contain;" alt="SparkFun Micro OLED Breakout (Qwiic)">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/22858">
      <b>SparkFun Micro OLED Breakout (Qwiic)</b>
      <br />
      SEN-22495
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/17260">
      <figure markdown>
        <img src="https://cdn.sparkfun.com//assets/parts/1/6/2/4/7/17260-Flexible_Qwiic_Cable_-_50mm-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Flexible Qwiic Cable - 50mm">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/17260">
      <b>Flexible Qwiic Cable - 50mm</b>
      <br>
      PRT-17260
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->

</div>


!!! note
    Make sure that you have a microSD card reader or adapter as well to read the contents saved on the memory card.

    <div style="text-align: center;">
      <table>
        <tr style="vertical-align:middle;">
         <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="https://cdn.sparkfun.com/assets/parts/7/6/3/6/11609-Action.jpg"><img src="https://cdn.sparkfun.com/assets/parts/7/6/3/6/11609-Action.jpg" width="140px" height="140px" alt="MicroSD Card Adapters"></a></td>
        </tr>
        <tr style="vertical-align:middle;">
         <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>MicroSD Card Adapters</i></td>
      </table>
    </div>




### Tools (Optional)

You will need a soldering iron, solder, and [general soldering accessories](https://www.sparkfun.com/categories/49) for a secure connection when using the plated through holes. For users that are measuring the current draw, you may want to consider grabbing a digital multimeter or a USB C cable that is able to display the current draw.

<!--

* [Soldering Iron [TOL-14456]](https://www.sparkfun.com/products/14456)
* [Solder Lead Free - 15-gram Tube [TOL-9163]](https://www.sparkfun.com/products/9163)
* [Flush Cutters - Hakko [TOL-11952]](https://www.sparkfun.com/products/11952)
* [Hook-Up Wire - Assortment (Stranded, 22 AWG) [PRT-11375]](https://www.sparkfun.com/products/11375)
* [Wire Strippers - 30AWG (Hakko) [TOL-12630]](https://www.sparkfun.com/products/12630)

-->

<div class="grid cards col-4" markdown>

-   <a href="https://www.sparkfun.com/products/14456">
      <figure markdown>
        <img src="https://cdn.sparkfun.com//assets/parts/1/2/4/9/0/14456-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Soldering Iron - 60W (Adjustable Temperature)">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/14456">
      <b>Soldering Iron - 60W (Adjustable Temperature)</b>
      <br />
      TOL-14456
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/9163">
      <figure markdown>
        <img src="https://cdn.sparkfun.com//assets/parts/2/5/8/7/09162-02-L.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Solder Lead Free - 15-gram Tube">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/9163">
      <b>Solder Lead Free - 15-gram Tube</b>
      <br>
      TOL-09163
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/11375">
      <figure markdown>
        <img src="https://cdn.sparkfun.com//assets/parts/7/1/2/0/11375-Hook-Up_Wire_-_Assortment__Solid_Core__22_AWG_-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Hook-Up Wire - Assortment (Stranded, 22 AWG)">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/11375">
      <b>Hook-Up Wire - Assortment (Stranded, 22 AWG)</b>
      <br />
      PRT-11375
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/12630">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/9/3/1/2/12630-Hakko-Wire-Strippers-30AWG-Feature.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Wire Strippers - 30AWG (Hakko)">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/12630">
      <b>Wire Strippers - 30AWG (Hakko)</b>
      <br />
      TOL-12630
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/11952">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/8/4/2/2/11952-Hakko-Flush-Cutters-feature.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Flush Cutters - Hakko">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/11952">
      <b>Flush Cutters - Hakko</b>
      <br />
      TOL-11952
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/12966">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/9/9/0/7/12966-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Digital Multimeter - Basic">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/12966">
      <b>Digital Multimeter - Basic</b>
      <br />
      TOL-12966
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/19718">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/1/9/4/1/5/19718-USAMS_USB_Type_A_to_Type_C_6A_Fast_Charging_and_Data_Cable_with_LED_Display-02.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Fast Charging USB A to C Cable with LCD - 4ft (6A)">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/19718">
      <b>Fast Charging USB A to C Cable with LCD - 4ft (6A)</b>
      <br />
      CAB-19718
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
</div>



### Prototyping Accessories

Depending on your setup, you may want to use IC hooks for a temporary connection. However, you will want to solder header pins to connect devices to the plated through holes for a secure connection.

<!--

* [Breadboard - Self-Adhesive (White) [PRT-12002]](https://www.sparkfun.com/products/12002)
* [IC Hook with Pigtail [CAB-09741]](https://www.sparkfun.com/products/9741)
* [Break Away Headers - Straight [PRT-00116]](https://www.sparkfun.com/products/116)
* [Feather Stackable Header Kit [PRT-15187]](https://www.sparkfun.com/products/15187)
* [Jumper Wires Premium 6" M/M Pack of 10 [PRT-08431]](https://www.sparkfun.com/products/8431)

-->

<div class="grid cards col-4" markdown>

-   <a href="https://www.sparkfun.com/products/12002">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/8/5/0/3/12002-Breadboard_-_Self-Adhesive__White_-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Breadboard - Self-Adhesive (White)">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/12002">
      <b>Breadboard - Self-Adhesive (White)</b>
      <br />
      PRT-12002
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/9741">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/3/6/9/6/09741-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="IC Hook with Pigtail">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/9741">
      <b>IC Hook with Pigtail</b>
      <br>
      CAB-09741
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/116">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/1/0/6/00116-02-L.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Break Away Headers - Straight">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/116">
      <b>Break Away Headers - Straight</b>
      <br />
      PRT-00116
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/15187">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/1/3/6/0/4/15187-Feather_Stackable_Header_Kit-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Feather Stackable Header Kit">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/15187">
      <b>Feather Stackable Header Kit</b>
      <br />
      PRT-15187
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/9044">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/2/4/0/7/09044-04-L.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Jumper - 2 Pin">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/9044">
      <b>Jumper - 2 Pin</b>
      <br />
      PRT-09044
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/8431">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/1/1/8/1/JumperWire-Male-01-L.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Jumper Wires Premium 6" M/M Pack of 10">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/8431">
      <b>Jumper Wires Premium 6" M/M Pack of 10</b>
      <br />
      PRT-08431
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
</div>




### Qwiic Cables

For those that want to take advantage of the Qwiic enabled devices, you'll want to grab a Qwiic cable.

<div class="grid cards col-4" markdown>

-   <a href="https://www.sparkfun.com/products/15081">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/1/3/4/3/1/15081-_01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="SparkFun Qwiic Cable Kit">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/15081">
      <b>SparkFun Qwiic Cable Kit</b>
      <br />
      KIT-15081
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/14427">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/1/2/4/5/3/14427-Qwiic_Cable_-_100mm-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Qwiic Cable - 100mm">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/14427">
      <b>Qwiic Cable - 100mm</b>
      <br>
      PRT-14427
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/14429">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/1/2/4/5/5/14429-Qwiic_Cable_-_500mm-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Qwiic Cable - 500mm">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/14429">
      <b>Qwiic Cable - 500mm</b>
      <br />
      PRT-14429
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/14425">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/parts/1/2/4/5/1/14425-Qwiic_Cable_-_Breadboard_Jumper__4-pin_-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Qwiic Cable - Breadboard Jumper (4-pin)">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/14425">
      <b>Qwiic Cable - Breadboard Jumper (4-pin)</b>
      <br />
      PRT-14425
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
</div>


### LiPo Battery

A [single-cell Lithium-ion battery](https://www.sparkfun.com/categories/tags/lithium-polymer) can be connected to the SparkFun Thing Plus NORA-W306 for portability.

<div class="grid cards col-4" markdown>

-   <a href="https://www.sparkfun.com/products/18286">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/r/140-140/assets/parts/1/7/6/0/6/17748-Lithium_Ion_Battery_-_1250_mAh__IEC62133_certified_-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Lithium Ion Battery - 1250mAh (IEC62133 Certified)">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/18286">
      <b>Lithium Ion Battery - 1250mAh (IEC62133 Certified)</b>
      <br />
      PRT-18286
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/13854">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/r/140-140/assets/parts/1/1/4/6/1/13854-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Lithium Ion Battery - 850mAh">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/13854">
      <b>Lithium Ion Battery - 850mAh</b>
      <br>
      PRT-13854
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/13856">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/r/140-140/assets/parts/1/1/4/6/3/13856-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Lithium Ion Battery - 6Ah">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/13856">
      <b>Lithium Ion Battery - 6Ah</b>
      <br />
      PRT-13856
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
</div>



### Suggested Reading

If you aren't familiar with the Qwiic Connection System, we recommend reading [here for an overview](https://www.sparkfun.com/qwiic).

<div style="text-align: center">
  <table style="border-style:none">
    <tr>
     <td style="text-align: center; vertical-align: middle;">
     <div style="text-align: center"><a href="https://www.sparkfun.com/qwiic"><img src="../assets/Qwiic-registered-updated.png" alt="Qwiic Connection System" title="Click to learn more about the Qwiic Connection System!"></a>
     </div>
    </td>
    </tr>
    <tr>
      <td style="text-align: center; vertical-align: middle;"><div style="text-align: center"><i><a href="https://www.sparkfun.com/qwiic">Qwiic Connection System</a></i></div></td>
    </tr>
  </table>
</div>

If you aren’t familiar with the following concepts, we also recommend checking out a few of these tutorials before continuing.

<div class="grid cards col-4" markdown>

-   <a href="https://learn.sparkfun.com/tutorials/how-to-solder-through-hole-soldering">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/learn_tutorials/5/Soldering_Action-01.jpg"style="width:264px; height:148px; object-fit:contain;" alt="How to Solder: Through-Hole Soldering">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/how-to-solder-through-hole-soldering">
      <b>How to Solder: Through-Hole Soldering</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/installing-arduino-ide">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/learn_tutorials/6/1/arduinoThumb.jpg" style="width:264px; height:148px; object-fit:contain;" alt="Installing Arduino IDE">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/installing-arduino-ide">
      <b>Installing Arduino IDE</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/arduino-shields-v2">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/learn_tutorials/1/1/6/7/qwiic_shield.jpg"style="width:264px; height:148px; object-fit:contain;" alt="Arduino Shields V2">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/arduino-shields-v2">
      <b>Arduino Shields V2</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/i2c">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/learn_tutorials/8/2/I2C-Block-Diagram.jpg" style="width:264px; height:148px; object-fit:contain;" alt="I2C">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/i2c">
      <b>I2C</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/installing-board-definitions-in-the-arduino-ide">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/learn_tutorials/1/2/6/5/sparkfun_boards.PNG" style="width:264px; height:148px; object-fit:contain;" alt="Installing Board Definitions in the Arduino IDE">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/installing-board-definitions-in-the-arduino-ide">
      <b>Installing Board Definitions in the Arduino IDE</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/serial-communication">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/7/d/f/9/9/50d24be7ce395f1f6c000000.jpg" style="width:264px; height:148px; object-fit:contain;" alt="Serial Communication">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/serial-communication">
      <b>Serial Communication</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/serial-peripheral-interface-spi">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/learn_tutorials/1/6/spiThumb_Updated2.png" style="width:264px; height:148px; object-fit:contain;" alt="Serial Peripheral Interface (SPI)">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/serial-peripheral-interface-spi">
      <b>Serial Peripheral Interface (SPI)</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/pulse-width-modulation">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/f/9/c/8/a/512e869bce395fbc64000002.JPG" style="width:264px; height:148px; object-fit:contain;" alt="Pulse Width Modulation">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/pulse-width-modulation">
      <b>Pulse Width Modulation</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/logic-levels">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/learn_tutorials/6/2/Input_Output_Logic_Level_Tolerances_tutorial_tile.png" style="width:264px; height:148px; object-fit:contain;" alt="Logic Levels">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/logic-levels">
      <b>Logic Levels</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/analog-vs-digital">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/3/7/6/6/0/51c48875ce395f745a000000.png" style="width:264px; height:148px; object-fit:contain;" alt="Analog vs. Digital">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/analog-vs-digital">
      <b>Analog vs. Digital</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/ws2812-breakout-hookup-guide/">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/learn_tutorials/1/0/5/WS2812B_-_13282-03.jpg" style="width:264px; height:148px; object-fit:contain;" alt="WS2812 Breakout Hookup Guide">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/ws2812-breakout-hookup-guide/">
      <b>WS2812 Breakout Hookup Guide</b>
    </a>
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
-   <a href="https://learn.sparkfun.com/tutorials/lipo-fuel-gauge-max1704x-hookup-guide">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/learn_tutorials/2/9/4/6/20680-_TOL_SparkFun_LiPo_Fuel_Gauge-_01.jpg" style="width:264px; height:148px; object-fit:contain;" alt="LiPo Fuel Gauge (MAX1704X) Hookup Guide">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/lipo-fuel-gauge-max1704x-hookup-guide">
      <b>LiPo Fuel Gauge (MAX1704X) Hookup Guide</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
</div>
