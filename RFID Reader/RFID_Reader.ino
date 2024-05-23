#include <Adafruit_GFX.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_ILI9341.h>
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSans12pt7b.h>
#include <Fonts/FreeSans18pt7b.h>
#include <Fonts/FreeSansBold9pt7b.h>
#include <Fonts/FreeSansBold12pt7b.h>
#include <Fonts/FreeSansBold18pt7b.h>
#include <Fonts/FreeSansBold24pt7b.h>

// The display also uses hardware SPI, plus #9 & #10
#define TFT_CS 10
#define TFT_DC 9
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

#include "SparkFun_Qwiic_Rfid.h"
#define RFID_ADDR1 0x7D  // Default I2C address
#define RFID_ADDR2 0x7C  // Default I2C address
Qwiic_Rfid myRfid1(RFID_ADDR1);
Qwiic_Rfid myRfid2(RFID_ADDR2);

const int intPin = 18;

String tag1;
String temp1;
String tag2;
String temp2;

void setup() {
  // Begin I-squared-C
  Wire.begin();
  Serial.begin(115200);
  pinMode(intPin, INPUT_PULLUP);
  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(ILI9341_BLACK);
  tft.setFont(&FreeSansBold24pt7b);
  tft.setTextColor(ILI9341_WHITE);
  NickText_center("Ready to read RFID tags!", 160, 120, 1);


  if (myRfid1.begin())
    Serial.println("Ready to scan some tags!");
  else
    Serial.println("Could not communicate with Qwiic RFID!");
  // Want to clear tags sitting on the Qwiic RFID card?
  myRfid1.clearTags();

  if (myRfid2.begin())
    Serial.println("Ready to scan some tags!");
  else
    Serial.println("Could not communicate with Qwiic RFID!");
  // Want to clear tags sitting on the Qwiic RFID card?
  myRfid2.clearTags();
}

void loop() {

  // If the pin goes low, then a card has been scanned.
  int m = micros();
  if (digitalRead(intPin) == LOW) {
    tag1 = myRfid1.getTag();
    //Serial.println(tag1);
    int m2 = micros() - m;
    tft.fillScreen(ILI9341_BLACK);
    tft.setFont(&FreeSansBold24pt7b);
    NickText_center(tag1, 160, 80, 1);
    tft.setFont(&FreeSansBold12pt7b);
    NickText_center("Microseconds to scan:", 160, 150, 1);
    NickText_center(m2, 160, 180, 1);
    myRfid1.clearTags();
  }

return;

  tag1 = myRfid1.getTag();
  if (tag1 != "000000" && temp1 != "-1-1-1-1-1-1") {
    Serial.print("Tag1 ID: ");
    Serial.println(tag1);
    tft.fillScreen(ILI9341_BLACK);
    NickText_center(tag1, 160, 80, 1);
    myRfid1.clearTags();
  }

  tag2 = myRfid2.getTag();
  //delay(50);
  if (tag2 != "000000" && temp2 != "-1-1-1-1-1-1") {
    Serial.print("Tag2 ID: ");
    Serial.println(tag2);
    tft.fillScreen(ILI9341_BLACK);
    NickText_center(tag2, 160, 180, 1);
    myRfid2.clearTags();
  }


}

//======================================================================================



void NickText_center(String text, int center_x, int center_y, int size) {
  tft.setTextSize(size);
  int16_t x1;
  int16_t y1;
  uint16_t w;
  uint16_t h;
  tft.getTextBounds(text, 0, 320, &x1, &y1, &w, &h);
  int xx = (center_x - 1) - (w / 2);
  int yy = (center_y - 1) + (h / 2);
  tft.setCursor(xx, yy);
  tft.print(text);
}

void NickText_center(int text, int center_x, int center_y, int size) {
  tft.setTextSize(size);
  int16_t x1;
  int16_t y1;
  uint16_t w;
  uint16_t h;
  String text2 = String(text);
  tft.getTextBounds(text2, 0, 320, &x1, &y1, &w, &h);
  int xx = (center_x - 1) - (w / 2);
  int yy = (center_y - 1) + (h / 2);
  tft.setCursor(xx, yy);
  tft.print(text2);
}
