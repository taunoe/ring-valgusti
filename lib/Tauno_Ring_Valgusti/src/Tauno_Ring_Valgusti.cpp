/*
 * Tauno_Ring_Valgusti.cpp
 *
 * Started 08.06.2024
 * Edited  15.06.2024
 * 
 * Copyright 2024 Tauno Erik
 */

#include <Arduino.h>
#include "Adafruit_GFX.h"  // ???
#include "Adafruit_NeoPixel.h"
#include "Tauno_Ring_Valgusti.h"

Tauno_Ring_Valgusti::Tauno_Ring_Valgusti(
    uint8_t LED_PIN,
    int PCB_COUNT)
    : _LED_PIN(LED_PIN),
    _PCB_COUNT(PCB_COUNT),
    pixels(_PCB_COUNT*15, _LED_PIN, NEO_RGB + NEO_KHZ400)
    {}

Tauno_Ring_Valgusti::~Tauno_Ring_Valgusti() {
    // Cleanup
}

bool Tauno_Ring_Valgusti::begin() {
    pixels.begin();
    pixels.show();
    pixels.setBrightness(50);  // 1-255
    return true;
}

void Tauno_Ring_Valgusti::show() {
    pixels.show();
}

bool Tauno_Ring_Valgusti::set_brightness(uint8_t level) {
    pixels.setBrightness(level);
    return true;
}

// color: 0x7aff18
bool Tauno_Ring_Valgusti::led_on(int index, uint8_t level) {
    if (index > _PCB_COUNT*15) {
        return false;
    }

    uint32_t color = 0xff0000;

    // int old = pixels.getPixelColor(index);

    pixels.setPixelColor(index, color);

    return true;
}

bool Tauno_Ring_Valgusti::led_off(int index) {
    uint32_t color = 0x000000;
    if (index > _PCB_COUNT*15) {
        return false;
    }

    int old = pixels.getPixelColor(index);

    if (old != color) {
        pixels.setPixelColor(index, color);
    }
    return true;
}

bool Tauno_Ring_Valgusti::all_off() {
    pixels.clear();
    pixels.show();
    return true;
}

bool Tauno_Ring_Valgusti::all_on(uint32_t color) {
    for (int i = 0; i < _PCB_COUNT*15; i++) {
        pixels.setPixelColor(i, color);
    }
    pixels.show();
    return true;
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
// Is Adafruit Wheel()
uint32_t Tauno_Ring_Valgusti::colours_transition(uint8_t value) {
    value = 255 - value;

    if (value < 85) {
        return pixels.Color(255 - value * 3, 0, value * 3);
    }
    if (value < 170) {
        value -= 85;
        return pixels.Color(0, value * 3, 255 - value * 3);
    }
    value -= 170;
    return pixels.Color(value * 3, 255 - value * 3, 0);
}


void Tauno_Ring_Valgusti::rainbow(int wait) {
    static int pixel_interval = 0;
    static int pixel_cycle = 0;
    static uint32_t pixel_previous = 0;   // Previous Pixel Millis
    static uint32_t patternPrevious = 0;  // Previous Pattern Millis

    if (pixel_interval != wait) {
        pixel_interval = wait;
    }

    uint32_t currentMillis = millis();  //  Update current time

    if (currentMillis - pixel_previous >= pixel_interval) {
      pixel_previous = currentMillis;

      for (uint16_t led = 0; led < _PCB_COUNT*15; led++) {
        //  Update delay time
        pixels.setPixelColor(led, colours_transition((led + pixel_cycle) & 255));
      }

      pixels.show();
      pixel_cycle++;
      if (pixel_cycle >= 256) {
        pixel_cycle = 0;
      }
    }
}
