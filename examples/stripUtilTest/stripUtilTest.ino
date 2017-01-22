#include <Adafruit_NeoPixel.h>
#include <StripUtil.h>

#define PIN 6
#define PIXELS_TOTAL 721
#define RED 40
#define GREEN 15
#define BLUE 3

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXELS_TOTAL, PIN, NEO_GRB + NEO_KHZ800);
StripUtil stripUtil = StripUtil(&strip);

void setup() {
    Serial.begin(9200);
    Serial.println("Starting up.");
    stripUtil.resetStrip();

    delay(1000);
    stripUtil.setStripToColor(strip.Color(RED, GREEN, BLUE));
    strip.show();

    delay(1000);
    stripUtil.setStripToColor(strip.Color(RED, 0, 0));
    strip.show();

    stripUtil.fade(strip.Color(RED, 0, 0), strip.Color(RED, GREEN, BLUE), 1000);
    stripUtil.fade(strip.Color(RED, GREEN, BLUE), strip.Color(RED, 0, 0), 1000);
    stripUtil.fade(strip.Color(RED, 0, 0), strip.Color(10, 10, 40), 1000);
    stripUtil.fade(strip.Color(10, 10, 40), strip.Color(RED, 0, 0), 1000);

    stripUtil.swipeUp(strip.Color(RED, GREEN, BLUE), 1);
    stripUtil.swipeUp(strip.Color(RED, 0, 0), 2);
    stripUtil.swipeUp(strip.Color(0, 40, 0), 3);
    stripUtil.swipeUp(strip.Color(0, 0, 40), 4);
    stripUtil.swipeUp(strip.Color(RED, 0, 0), 5);
    stripUtil.swipeUp(strip.Color(0, 40, 0), 6);
    stripUtil.swipeUp(strip.Color(0, 0, 40), 7);
    stripUtil.fade(strip.Color(0, 0, 40), strip.Color(RED,GREEN,BLUE), 2000);

}



void loop() {

}
