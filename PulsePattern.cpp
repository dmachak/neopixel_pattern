//
//  PulsePattern.cpp
//  
//
//  Created by Danny Machak on 10/28/16.
//
//

#include <Adafruit_NeoPixel.h>
#include <PulsePattern.h>

PulsePattern::PulsePattern(Adafruit_NeoPixel* strip, ColorFunction* function, int nPulses) {
    this->strip = strip;
    this->function = function;
    this->nPulses = nPulses;
    updateLength(strip->numPixels());
    initializePulses();

}

void PulsePattern::updateLength(uint16_t n) {
    flags = (uint8_t *)malloc(n);
    step = (uint8_t *)malloc(n);
    memset(flags, 0, n);
    memset(step, 0, n);
}

void PulsePattern::initializePulses() {
    pulseStep = (uint8_t *)malloc(nPulses);
    pulseDelay = (uint8_t *)malloc(nPulses);
    pulseIndex = (uint16_t *)malloc(2*nPulses);
    memset(pulseStep, 0, nPulses);
    memset(pulseDelay, 0, nPulses);
    memset(pulseIndex, 0, 2*nPulses);
    for (uint16_t i = 0; i < nPulses; i++) {
        resetPulse(i, i*100/nPulses);
    }
}

void PulsePattern::increment(void) {
    for (uint16_t i = 0; i < nPulses; i++) {
        
        if (isComplete(i)) {
            resetPulse(i, 0);
        } else {
        
            if (pulseDelay[i] > 0) {
                pulseDelay[i]--;
            } else {
                strip->setPixelColor(pulseIndex[i], function->getColor(0, pulseStep[i]));
                pulseStep[i]++;
            }
        }
    }
    strip->show();
}

void PulsePattern::resetPulse(uint16_t pIndex, uint8_t delay) {
    turnPixelOff(pulseIndex[pIndex]);
    pulseIndex[pIndex] = 0;
    pulseDelay[pIndex] = 0;
    pulseStep[pIndex] = 0;
    
    uint16_t pix = 0;
    do {pix = rand() % strip->numPixels();}
    while (isPixelOn(pix));
    
    startPixel(pix, pIndex, delay);
}

void PulsePattern::startPixel(uint16_t index, uint16_t pIndex, uint8_t delay) {
    turnPixelOn(index);
    pulseIndex[pIndex] = index;
    pulseDelay[pIndex] = delay;
    pulseStep[pIndex] = 0;
}
