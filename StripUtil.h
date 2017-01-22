//
//  StripUtil.h
//  
//
//  Created by Danny Machak on 12/30/16.
//
//

#ifndef StripUtil_h
#define StripUtil_h

#include <Adafruit_NeoPixel.h>

class StripUtil {
public:
    StripUtil(Adafruit_NeoPixel* strip);
    void resetStrip();
    void setStripToColor(uint32_t color);
    // Fades from c1 to c2 over t milliseconds
    void fade(uint32_t c1, uint32_t c2, int32_t t);

    // Convenience method for fading from black to color
    void fadeIn(uint32_t color, int32_t timeInMilliseconds);
    
    void swipeUp(uint32_t color, int32_t pixelsPerStep);
    
private:
    Adafruit_NeoPixel* strip;
    int32_t stepSize=20;
};

#endif /* StripUtil_h */
