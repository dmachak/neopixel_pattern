//
//  StripUtil.cpp
//  
//
//  Created by Danny Machak on 12/30/16.
//
//

#include "StripUtil.h"
#include "Arduino.h"

StripUtil::StripUtil(Adafruit_NeoPixel* strip) {
    this->strip = strip;
}

void StripUtil::resetStrip() {
    this->strip->begin();
    this->strip->show();
}

void StripUtil::setStripToColor(uint32_t color) {
    uint16_t n = this->strip->numPixels();
    for (uint16_t i = 0; i < n; i++) {
        this->strip->setPixelColor(i, color);
    }
}

void StripUtil::fade(uint32_t c1, uint32_t c2, int32_t t) {
    uint8_t r1 = (uint8_t)(c1 >> 16);
    uint8_t g1 = (uint8_t)(c1 >>  8);
    uint8_t b1 = (uint8_t)c1;
    
    uint8_t r2 = (uint8_t)(c2 >> 16);
    uint8_t g2 = (uint8_t)(c2 >>  8);
    uint8_t b2 = (uint8_t)c2;
    
    int32_t nSteps = t/stepSize;
    
    int8_t rdiff = r2 - r1;
    int8_t gdiff = g2 - g1;
    int8_t bdiff = b2 - b1;
    
    for (int32_t i = 0; i < nSteps; i++) {
        uint8_t r = r1 + i * rdiff/nSteps;
        uint8_t g = g1 + i * gdiff/nSteps;
        uint8_t b = b1 + i * bdiff/nSteps;
        
        setStripToColor(strip->Color(r,g,b));
        strip->show();
    }
}

void StripUtil::fadeIn(uint32_t color, int32_t timeInMilliseconds) {
    fade(strip->Color(0,0,0), color, timeInMilliseconds);
}

void StripUtil::swipeUp(uint32_t color, int32_t pixelsPerStep) {
//    int32_t stepSize = timeInMilliseconds/strip->numPixels();
    for (int32_t i = 0; i < strip->numPixels(); i+=pixelsPerStep) {
        for (int32_t j = 0; j < pixelsPerStep; j++) {
            strip->setPixelColor(i+j, color);
        }
        strip->show();
//        delay(stepSize);
    }
}
