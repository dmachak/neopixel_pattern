//
//  ColorPalette.h
//  
//
//  Created by Danny Machak on 1/10/17.
//
//

#ifndef ColorPalette_h
#define ColorPalette_h
#include <Adafruit_NeoPixel.h>

class ColorPalette {
public:
    ColorPalette(uint8_t size);
    ColorPalette(uint8_t size, uint32_t* colors);
    uint32_t getColor(uint8_t index);
    
    uint8_t red(uint8_t index);
    uint8_t green(uint8_t index);
    uint8_t blue(uint8_t index);
    
    void setColor(uint8_t index, uint32_t color);
    void setColor(uint8_t index, uint8_t red, uint8_t green, uint8_t blue);

private:
    uint8_t size;
    uint32_t* colors;
    boolean checkIndex(uint8_t index);
    void initialize();
};

#endif /* ColorPalette_h */
