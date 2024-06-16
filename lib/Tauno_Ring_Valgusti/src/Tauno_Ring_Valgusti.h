/*
 * Tauno_Ring_Valgusti.h
 *
 * Started 08.06.2024
 * Edited  15.06.2024
 * 
 * Copyright 2024 Tauno Erik
 */

#ifndef LIB_TAUNO_RING_VALGUSTI_SRC_TAUNO_RING_VALGUSTI_H_
#define LIB_TAUNO_RING_VALGUSTI_SRC_TAUNO_RING_VALGUSTI_H_

#include <Arduino.h>
#include "Adafruit_GFX.h"
#include "Adafruit_NeoPixel.h"

class Tauno_Ring_Valgusti {
 private:
    uint8_t _LED_PIN;
    int _PCB_COUNT;
    int _LED_COUNT;

    Adafruit_NeoPixel pixels;

    uint32_t colours_transition(uint8_t value);

 public:
    Tauno_Ring_Valgusti(uint8_t LED_PIN, int PCB_count);

    ~Tauno_Ring_Valgusti();

    bool begin();
    void show();
    bool set_brightness(uint8_t level);
    bool led_on(int index, uint8_t level);
    bool led_off(int index);
    bool all_off();
    bool all_on(uint32_t level);

    void rainbow(int wait);

};

#endif  // LIB_TAUNO_RING_VALGUSTI_SRC_TAUNO_RING_VALGUSTI_H_
