#include <Adafruit_NeoPixel.h>
#include <PulsePattern.h>
#include <SinColorFunction.h>
#include <StripUtil.h>
#include <ColorPalette.h>

/*
  This is an example of the Pulse class, which will make random pixels on the strand
  pulse according to the defined pattern. 
  PIN: Arduino pin that sends the NeoPixel signal.
  PIXELS_TOTAL: total number of pixels in the strip.
  PIXELS_BLINK: total number of pixels that are in the process of pulseing at any one time.
  RED, GREEN, BLUE: 0-255: value of max brightness for each pixel. (TBD colors are still hard-coded
                    in the SinColorFunction class.
*/

#define PIN 6
#define PIXELS_TOTAL 721
#define PIXELS_BLINK 220
#define DURATION 30
#define RED 40
#define GREEN 15
#define BLUE 3

uint32_t colors[] = {Adafruit_NeoPixel::Color(40, 15, 3), Adafruit_NeoPixel::Color(160, 60, 12)};
ColorPalette colorPalette = ColorPalette(2, colors);
SinColorFunction sinFunction = SinColorFunction(DURATION, &colorPalette);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXELS_TOTAL, PIN, NEO_GRB + NEO_KHZ800);
StripUtil stripUtil = StripUtil(&strip);
PulsePattern pulsePattern = PulsePattern(&strip, &sinFunction, PIXELS_BLINK);


void setup() {
    strip.begin();
    strip.show();
    stripUtil.fadeIn(strip.Color(RED, GREEN, BLUE), 2000);
    strip.show();
}

void loop() {
    pulsePattern.update();
}