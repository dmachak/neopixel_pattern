//
//  PulsePattern.h
//  
//
//  Created by Danny Machak on 10/28/16.
//
//

#ifndef PulsePattern_h
#define PulsePattern_h

#include <Adafruit_NeoPixel.h>
#include <ColorFunction.h>

// An array of flags for each pixel is defined. One Byte is allocated per pixel, which allows for up to 8 boolean
// flags to be tracked per pixel. Each bit in the byte determines the boolean state. (either 0:false, or 1:true)
#define FLAG1 1
#define FLAG2 2
#define FLAG3 4
#define FLAG4 8
#define FLAG5 16
#define FLAG6 32
#define FLAG7 64
#define FLAG8 128

#define FLAG1_MASK 255^FLAG1
#define FLAG2_MASK 255^FLAG2
#define FLAG3_MASK 255^FLAG3
#define FLAG4_MASK 255^FLAG4
#define FLAG5_MASK 255^FLAG5
#define FLAG6_MASK 255^FLAG6
#define FLAG7_MASK 255^FLAG7
#define FLAG8_MASK 255^FLAG8

/**
 * Controls the given strip to display a random number of pulses for individual pixels on the strip. The pulses are 
 * staggered so that each pulse starts at a different time than the other pulses. The pulse on each pixel will last
 * for a number of steps determined by the duration of the ColorFunction passed in.
 * @param strip The strip that will be controlled
 * @param function The ColorFunction that controls the color of a target pixel for the duration of the function. 
 * @param nPulses The number of pixels that will be in the pulsing state at any given time. A good number is around
 *         1/4 to 1/3 of the size of the strip. The refresh rate will slow down as you increase the number of pulsing
 *         pixels.
 */
class PulsePattern {
public:
    PulsePattern(Adafruit_NeoPixel* strip, ColorFunction* function, int nPulses);
    void increment(void);

protected:
    inline boolean getFlag(uint16_t n, uint8_t flag) {return flags[n] & flag;}
    inline void setFlag(uint16_t n, uint8_t flag, boolean value) {flags[n] = value ?  (flags[n] | flag) : (flags[n] & (255^flag));}
    void updateLength(uint16_t n);
    void initializePulses();
    inline boolean isComplete(uint16_t index) {return !isPixelOn(pulseIndex[index]) || pulseStep[index] >= function->getDuration();}
    int nPulses;

private:
    uint8_t* flags;
    uint8_t* step;
    uint8_t* pulseStep;
    uint8_t* pulseDelay;
    uint16_t* pulseIndex;
    ColorFunction* function;
    Adafruit_NeoPixel* strip;
    void resetPulse(uint16_t pIndex, uint8_t delay);
    void startPixel(uint16_t index, uint16_t pIndex, uint8_t delay);
    inline void turnPixelOn(uint16_t n) {setFlag(n, FLAG1, true);}
    inline void turnPixelOff(uint16_t n) {setFlag(n, FLAG1, false);}
    inline boolean isPixelOn(uint16_t n) {return getFlag(n, FLAG1);}
    
    inline void setStep(uint16_t n, uint8_t s) {step[n] = s;}
    inline void incrementStep(uint16_t n) {step[n]++;}
    inline uint8_t getStep(uint16_t n) {return step[n];}
};

#endif /* PulsePattern_h */
