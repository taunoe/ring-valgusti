/*
 * Tauno_Ring_Valgusti.cpp
 *
 * Started 08.06.2024
 * Edited  19.06.2024
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

// Turn LED ON, on the desired brightness level.
// level 1-254
bool Tauno_Ring_Valgusti::led_on(int index, uint8_t level) {
    if (index > (_PCB_COUNT * (LEDS_ON_PCB+1))) {
        return false;
    }

    int pcb_nr = index / LEDS_ON_PCB;

    // Find LED index on PCB
    while (index >= LEDS_ON_PCB) {
        index -= LEDS_ON_PCB;
    }

    uint32_t add_value = 0;
    uint32_t mask = 0xff;

    switch (index) {
    case 0:
        index = 0;
        add_value = level << 16;
        mask = mask << 16;
        break;
    case 1:
        index = 0;
        add_value = level << 8;
        mask = mask << 8;
        break;
    case 2:
        index = 0;
        add_value =  level;
        break;
    case 3:
        index = 1;
        add_value =  level;
        break;
    case 4:
        index = 1;
        add_value = level << 8;
        mask = mask << 8;
        break;
    case 5:
        index = 1;
        add_value = level << 16;
        mask = mask << 16;
        break;
    case 6:
        index = 2;
        add_value = level << 16;
        mask = mask << 16;
        break;
    case 7:
        index = 2;
        add_value =  level << 8;
        mask = mask << 8;
        break;
    case 8:
        index = 2;
        add_value =  level;
        break;
    case 9:
        index = 3;
        add_value =  level << 16;
        mask = mask << 16;
        break;
    case 10:
        index = 3;
        add_value = level << 8;
        mask = mask << 8;
        break;
    case 11:
        index = 3;
        add_value =  level;
        break;
    case 12:
        index = 4;
        add_value = level;
        break;
    case 13:
        index = 4;
        add_value = level << 8;
        mask = mask << 8;
        break;
    case 14:
        index = 4;
        add_value = level << 16;
        mask = mask << 16;
        break;
    default:
        break;
    }

    int true_index = index + (ICS_ON_PCB * pcb_nr);
    uint32_t old_value = pixels.getPixelColor(true_index);
    uint32_t masked_value = old_value & ~(mask);
    uint32_t out_value = masked_value ^ add_value;

    pixels.setPixelColor(true_index, out_value);

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
