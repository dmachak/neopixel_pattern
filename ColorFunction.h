/*
  ColorFunction.h - Base class for a basic cycle algorithm that defines pixel color as a function of position and time.
*/

// ensure this library description is only included once
#ifndef ColorFunction_h
#define ColorFunction_h

// include types & constants of Wiring core API
#include <Adafruit_NeoPixel.h>
#include <ColorPalette.h>

class ColorFunction {
    
  public:
    ColorFunction();
    ColorFunction(uint32_t duration);
    ColorFunction(uint32_t duration, ColorPalette* colorPalette);
    ColorFunction(uint32_t duration, ColorPalette* colorPalette, uint8_t* params);

    virtual uint32_t getColor(float position, uint32_t time) = 0;
    inline uint32_t getDuration() {return duration;}
    inline uint8_t getParam(uint8_t p) {return params[p];}
    inline void setParam(uint8_t p, uint8_t value) {params[p] = value;}

  protected:
    uint32_t duration;
    uint8_t* params;
    ColorPalette* colorPalette;
    inline uint8_t r(uint8_t i) {return colorPalette->red(i);}
    inline uint8_t g(uint8_t i) {return colorPalette->green(i);}
    inline uint8_t b(uint8_t i) {return colorPalette->blue(i);}
};

#endif