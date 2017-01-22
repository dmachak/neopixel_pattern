#ifndef SinColorFunction_h
#define SinColorFunction_h
#include <ColorFunction.h>
#include <ColorPalette.h>

class SinColorFunction : public ColorFunction {
    
public:
    SinColorFunction();
    SinColorFunction(uint32_t duration);
    SinColorFunction(uint32_t duration, ColorPalette* colorPalette);
    SinColorFunction(uint32_t duration, ColorPalette* colorPalette, uint8_t* params);
    
    virtual uint32_t getColor(float position, uint32_t time);
    
private:
    boolean continuous = false;
};

#endif /* SinColorFunction_h */
