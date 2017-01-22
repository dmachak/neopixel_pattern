//
//  ColorPalette.cpp
//  
//
//  Created by Danny Machak on 1/10/17.
//
//

#include <ColorPalette.h>
#include <Adafruit_NeoPixel.h>

ColorPalette::ColorPalette(uint8_t size) {
    this->size = size;
    initialize();
}

ColorPalette::ColorPalette(uint8_t size, uint32_t* colors) {
    this->size = size;
    this->colors = colors;
}

uint32_t ColorPalette::getColor(uint8_t index) {
    return checkIndex(index) ? colors[index] : 0;
}

uint8_t ColorPalette::red(uint8_t index) {
    return checkIndex(index) ? (uint8_t)(colors[index] >> 16) : 0;
}

uint8_t ColorPalette::green(uint8_t index) {
    return checkIndex(index) ? (uint8_t)(colors[index] >> 8) : 0;
}

uint8_t ColorPalette::blue(uint8_t index) {
    return checkIndex(index) ? (uint8_t)colors[index] : 0;
}

void ColorPalette::setColor(uint8_t index, uint32_t color) {
    if (checkIndex(index)) {
        colors[index] = color;
    }
}

void ColorPalette::setColor(uint8_t index, uint8_t red, uint8_t green, uint8_t blue) {
    if (checkIndex(index)) {
        colors[index] = Adafruit_NeoPixel::Color(red, green, blue);
    }
}

boolean ColorPalette::checkIndex(uint8_t index) {
    return (index < size);
}

void ColorPalette::initialize() {
    colors = (uint32_t *)malloc(4*size);
    memset(colors, 0, 4*size);
}