/*
  Strain Gage-Based Scale

  Reads repeatedly from an analog input, printing it to the Adafruit SSD1306
  OLED graphic display and the computer.
  
  The circuit:
    * Analog sensor attached to analog input 0
    
  Created 1 August 2015
  By Gustavo H. Barrionuevo  <gustavo@barrionuevo.me>

  This code is in the public domain.

*/
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_RESET 12
#define OLED_CS    13
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);


#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

float gain_const = 1;
int adc_zero_const = 0;
int windowSize = 2;
int newReading = 0;
int average = 0;                // the current average
int inputPin = A0;
int diff;
int thres1 = 4;
int thres2 = 8;
float weight = 0;
float standard_deviation = 0;
void setup() {
  analogReference(EXTERNAL);
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC);
  display.clearDisplay();        //Clear display
  display.setTextSize(1);
  display.display();
  display.setTextColor(WHITE);   //Set text color to
  Serial.begin(115200);     // opens serial port, sets data rate to 115200 bps
  average =  analogRead(inputPin);
}
void loop() {
  newReading = analogRead(inputPin);
  diff = abs(newReading - average);
  switch (windowSize) {
    case 2:
      if (diff < thres1) {
        windowSize = 4;
      }
      break;
    case 4:
      if (diff < thres2) {
        windowSize = 8;
      } else if (diff >= thres1) {
        windowSize = 2;
        average = newReading;
      }
      break;
    case 8:
      if (diff >= thres2) {
        windowSize = 4;
        average = newReading;
      }
      break;
  }

  average = (newReading + (average * windowSize) - average) / windowSize;
  weight = (average - adc_zero_const) * gain_const;




  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("\nWeight: ");
  //Set text size to 1(small)
  //display.setCursor(10, 25);     // set cursor position x,y
  display.print(weight, 0);
  display.print("g\n");
  // display.display();
  // display.setTextSize(1.5);
  //display.setCursor(0, 30);
  display.print("\nADC Code: ");
  display.print(average);
  display.print("\nGain Const: ");
  display.print(gain_const, 3);
  display.print("\nRaw ADC Code: ");
  display.print(newReading);
  display.display();

  Serial.println(average);
  delay(100);        // delay in between reads for stability


  if (Serial.available() > 0) {
    // read the incoming byte:
    int inByte = Serial.read();
    switch (inByte) {
      case 'm':
        while (Serial.available() <= 0) {
          delay(200);
        }
        adc_zero_const = Serial.parseInt();
        break;
      case 'g':
        while (Serial.available() <= 0) {
          delay(200);
        }
        gain_const = Serial.parseFloat() / average;
        break;
    }
  }
}
