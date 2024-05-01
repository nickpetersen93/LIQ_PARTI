# LIQ PARTI - Lick Instance Quantifier with Poly-Animal RFID Tracking Integration 

## Included in this repository:
  - Arduino code for LIQ PARTI running off an Arduino Mega
  - 3D models for all required 3D-printed components in various file formats (STL, STEP, SHAPR)
  - Step-by-step build instructions and video tutorial can be found on the [Wiki page](https://github.com/nickpetersen93/LIQ_HD/wiki/LIQ-HD---Step-by-Step-Tutorial "LIQ HD - Step-by-Step Tutorial")
  
------------------------------------------------------------------

### Required Arduino Libraries:
  - Adafruit_GFX.h
  - RTClib.h
  - Adafruit_MPR121.h
  - Adafruit_ILI9341.h
  - Adafruit_FT6206.h
  - SparkFun_Qwiic_Rfid.h
  
------------------------------------------------------------------

### Publication Link: TBD


## Abstract

LIQ PARTI, an evolution of LIQ HD, is built from commercially available electronic components combined with 3D-printed parts. Each cage is controlled by a single Arduino MEGA microcontroller connected to a real-time clock plus data logging shield (Adafruit), a capacitive touchscreen shield (Adafruit), a 12-channel MPR121 capacitive sensor breakout board (Adafruit), and two 125kHz RFID readers (SparkFun). Like LIQ HD, LIQ PARTI utilizes capacitive touch sensing to measure individual lick events. The metal sipper for each bottle is in contact with conductive copper foil tape that is wired to the MPR121 capacitance sensor breakout board. The two RFID readers lay inside the 3D-printed housing above two small tunnels that the mice must enter to reach each sipper, which allows the device to accurately determine which mouse is actively drinking from each sipper. Both sippers can be used simultaneously without affecting data collection. Date and time are kept with the Adafruit Data Logger Shield, which also writes the cage data to a CSV file on an SD card for downstream analysis. A 2.8” Adafruit Touchscreen Shield is used to display an easy-to-use graphical user interface, allowing the user to change device settings (time, light/dark schedule, sensor sensitivity, metrics to record), mount/eject the SD card, track the total licks at each sipper throughout recordings, and start/stop/pause recordings. The screen will also prompt the user if there are any errors, such as disconnected sensors or SD card.


<p align="center">
<img width="800" alt="Screen Shot 2022-12-15 at 4 54 24 PM" src="https://github.com/nickpetersen93/LIQ_PARTI/assets/86747820/ac5190c5-3204-40c8-a3d3-297990e5020e">
</p>
