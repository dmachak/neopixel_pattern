//
//  SinColorFunction.cpp
//  
//
//  Created by Danny Machak on 10/24/16.
//
//

#include <SinColorFunction.h>
#include <Adafruit_NeoPixel.h>
#include <math.h>
#include <Arduino.h>

SinColorFunction::SinColorFunction() : ColorFunction() {}
SinColorFunction::SinColorFunction(uint32_t duration) : ColorFunction(duration) {}
SinColorFunction::SinColorFunction(uint32_t duration, ColorPalette* colorPalette)
    : ColorFunction(duration, colorPalette) {}
SinColorFunction::SinColorFunction(uint32_t duration, ColorPalette* colorPalette, uint8_t* params)
    : ColorFunction(duration, colorPalette, params) {}


uint32_t SinColorFunction::getColor(float position, uint32_t time) {
    float f = sin(2*M_PI*(time + 3*duration/4)/duration) + 1;
    return Adafruit_NeoPixel::Color(r(0) + (r(1)-r(0))*f/2, g(0) + (g(1)-g(0))*f/2, b(0) + (b(1)-b(0))*f/2);
}