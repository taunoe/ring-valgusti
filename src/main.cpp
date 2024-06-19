/*
 * main.cpp
 *
 * Started 08.06.2024
 * Edited  19.06.2024
 * 
 * Copyright 2024 Tauno Erik
 */
#include <Arduino.h>
#include "Tauno_Ring_Valgusti.h"

#define LED_PIN    2  // ESP32-WROOM D2
#define PCB_COUNT  5

#define IC_COUNT 5  // kiipi

#define DELAY_VAL 50

Tauno_Ring_Valgusti RING(LED_PIN, PCB_COUNT);
/*
// Declare our NeoPixel ring object:
Adafruit_NeoPixel ring(IC_COUNT, LED_PIN, NEO_RGB + NEO_KHZ400);
// Argument 1 = Number of pixels in NeoPixel ring
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
*/

/*
// put function declarations here:
void colorWipe(uint32_t color, int wait);
void theaterChase(uint32_t color, int wait);
void rainbow(int wait);
void theaterChaseRainbow(int wait);
*/

void setup() {
  Serial.begin(115200);
  /*
  ring.begin();           // INITIALIZE NeoPixel ring object (REQUIRED)
  ring.show();            // Turn OFF all pixels ASAP
  ring.setBrightness(50);  // Set BRIGHTNESS to about 1/5 (max = 255)
  */
  RING.begin();
}

void loop() {
  uint8_t val = 100;

  RING.all_off();

    delay(100);

  for (size_t i = 0; i < 75; i++) {
    // RING.all_off();
    RING.led_on(i, 50);  // alusta 1
    RING.show();
    delay(DELAY_VAL);
  }

  delay(100);

  for (size_t i = 0; i < 75; i++) {
    // RING.all_off();
    RING.led_on(i, 150);  // alusta 1
    RING.show();
    delay(DELAY_VAL);
  }

  delay(100);

  for (size_t i = 0; i < 75; i++) {
    // RING.all_off();
    RING.led_on(i, 0x01);  // alusta 1
    RING.show();
    delay(DELAY_VAL);
  }

/*
    RING.all_off();
    RING.led_on(0, val);
    RING.led_on(14, val);
    RING.led_on(15, val);
    RING.led_on(29, val);
    RING.led_on(30, val);
    RING.led_on(44, val);
    RING.led_on(45, val);
    RING.led_on(59, val);
    RING.led_on(60, val);
    RING.led_on(74, val);
    RING.show();
    delay(DELAY_VAL);
*/

  // put your main code here, to run repeatedly:
  // Fill along the length of the ring in various colors...
  // colorWipe(ring.Color(255, 0, 0), 50);  // Red
  // colorWipe(ring.Color(0, 255, 0), 50);  // Green
  // colorWipe(ring.Color(0, 0, 255), 50);  // Blue

  // Do a theater marquee effect in various colors...
  // theaterChase(ring.Color(127, 127, 127), 50);  // White, half brightness
  // theaterChase(ring.Color(127,   0,   0), 50);  // Red, half brightness
  // theaterChase(ring.Color(  0,   0, 127), 50);  // Blue, half brightness

  // rainbow(10);              // Flowing rainbow cycle along the whole ring
  // theaterChaseRainbow(50);  // Rainbow-enhanced theaterChase variant
/*
  // 15
  ring.clear();
  ring.setPixelColor(4, ring.Color(0, 0, 255));  // mälus
  ring.show();  // näita
  delay(PAUS);
  // 14
  ring.clear();
  ring.setPixelColor(4, ring.Color(0, 255, 0));  // mälus
  ring.show();  // näita
  delay(PAUS);
  // 13
  ring.clear();
  ring.setPixelColor(4, ring.Color(255, 0, 0));  // mälus
  ring.show();  // näita
  delay(PAUS);
  // 12
  ring.clear();
  ring.setPixelColor(3, ring.Color(0, 0, 255));  // mälus
  ring.show();  // näita
  delay(PAUS);
  // 11
  ring.clear();
  ring.setPixelColor(3, ring.Color(0, 255, 0));  // mälus
  ring.show();  // näita
  delay(PAUS);
  // 10
  ring.clear();
  ring.setPixelColor(3, ring.Color(255, 0, 0));  // mälus
  ring.show();  // näita
  delay(PAUS);
  // 9
  ring.clear();
  ring.setPixelColor(2, ring.Color(0, 0, 255));  // mälus
  ring.show();  // näita
  delay(PAUS);
  // 8
  ring.clear();
  ring.setPixelColor(2, ring.Color(0, 255, 0));  // mälus
  ring.show();  // näita
  delay(PAUS);
  // 7
  ring.clear();
  ring.setPixelColor(2, ring.Color(255, 0, 0));  // mälus
  ring.show();  // näita
  delay(PAUS);
  // 6
  ring.clear();
  ring.setPixelColor(1, ring.Color(255, 0, 0));  // mälus
  ring.show();  // näita
  delay(PAUS);
  // 5
  ring.clear();
  ring.setPixelColor(1, ring.Color(0, 255, 0));  // mälus
  ring.show();  // näita
  delay(PAUS);
  // 4
  ring.clear();
  ring.setPixelColor(1, ring.Color(0, 0, 255));  // mälus
  ring.show();  // näita
  delay(PAUS);
  // 3
  ring.clear();
  ring.setPixelColor(0, ring.Color(0, 0, 255));  // mälus
  ring.show();  // näita
  delay(PAUS);
  // 2
  ring.clear();
  ring.setPixelColor(0, ring.Color(0, 255, 0));  // mälus
  ring.show();  // näita
  delay(PAUS);
  // 1
  ring.clear();
  ring.setPixelColor(0, ring.Color(255, 0, 0));  // mälus
  ring.show();  // näita
  delay(PAUS);

  rainbow(10);
  */
}


/*
// Some functions of our own for creating animated effects -----------------

// Fill ring pixels one after another with a color. ring is NOT cleared
// first; anything there will be covered pixel by pixel. Pass in color
// (as a single 'packed' 32-bit value, which you can get by calling
// ring.Color(red, green, blue) as shown in the loop() function above),
// and a delay time (in milliseconds) between pixels.
void colorWipe(uint32_t color, int wait) {
  for (int i = 0; i < ring.numPixels(); i++) {
    ring.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    ring.show();                          //  Update ring to match
    delay(wait);                           //  Pause for a moment
  }
}

// Theater-marquee-style chasing lights. Pass in a color (32-bit value,
// a la ring.Color(r,g,b) as mentioned above), and a delay time (in ms)
// between frames.
void theaterChase(uint32_t color, int wait) {
  for (int a = 0; a < 10; a++) {  // Repeat 10 times...
    for (int b = 0; b < 3; b++) {  //  'b' counts from 0 to 2...
      ring.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of ring in steps of 3...
      for (int c = b; c < ring.numPixels(); c += 3) {
        ring.setPixelColor(c, color);  // Set pixel 'c' to value 'color'
      }
      ring.show();  // Update ring with new contents
      delay(wait);  // Pause for a moment
    }
  }
}

// Rainbow cycle along whole ring. Pass delay time (in ms) between frames.
void rainbow(int wait) {
  // Hue of first pixel runs 5 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
  // means we'll make 5*65536/256 = 1280 passes through this loop:
  for (uint32_t firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    // ring.rainbow() can take a single argument (first pixel hue) or
    // optionally a few extras: number of rainbow repetitions (default 1),
    // saturation and value (brightness) (both 0-255, similar to the
    // ColorHSV() function, default 255), and a true/false flag for whether
    // to apply gamma correction to provide 'truer' colors (default true).
    ring.rainbow(firstPixelHue);
    // Above line is equivalent to:
    // ring.rainbow(firstPixelHue, 1, 255, 255, true);
    ring.show();  // Update ring with new contents
    delay(wait);  // Pause for a moment
  }
}

// Rainbow-enhanced theater marquee. Pass delay time (in ms) between frames.
void theaterChaseRainbow(int wait) {
  int firstPixelHue = 0;     // First pixel starts at red (hue 0)
  for (int a = 0; a < 30; a++) {  // Repeat 30 times...
    for (int b = 0; b < 3; b++) {  //  'b' counts from 0 to 2...
      ring.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of ring in increments of 3...
      for (int c = b; c < ring.numPixels(); c += 3) {
        // hue of pixel 'c' is offset by an amount to make one full
        // revolution of the color wheel (range 65536) along the length
        // of the ring (ring.numPixels() steps):
        int      hue   = firstPixelHue + c * 65536L / ring.numPixels();
        uint32_t color = ring.gamma32(ring.ColorHSV(hue));  // hue -> RGB
        ring.setPixelColor(c, color);  // Set pixel 'c' to value 'color'
      }
      ring.show();                // Update ring with new contents
      delay(wait);                 // Pause for a moment
      firstPixelHue += 65536 / 90;  // One cycle of color wheel over 90 frames
    }
  }
}
*/
