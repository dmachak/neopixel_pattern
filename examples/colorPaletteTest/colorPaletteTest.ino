#include <Adafruit_NeoPixel.h>
#include <ColorPalette.h>

ColorPalette colorPalette = ColorPalette(4);

void setup() {
    Serial.begin(9200);
    colorPalette.setColor(0, 40, 15, 3);
    colorPalette.setColor(1, 80, 30, 6);
    colorPalette.setColor(2, 0, 0, 30);
    colorPalette.setColor(3, 30, 30, 0);

    for (int i = 0; i < 4; i++) {
        printColor(i);
    }

    colorPalette.setColor(2, Adafruit_NeoPixel::Color(15, 15, 15));
    printColor(2);
    Serial.print(Adafruit_NeoPixel::Color(15, 15, 15));
}

void printColor(int i) {
    Serial.print(i);
    Serial.print(": ");
    Serial.print(colorPalette.red(i));
    Serial.print(",");
    Serial.print(colorPalette.green(i));
    Serial.print(",");
    Serial.print(colorPalette.blue(i));
    Serial.print("  -  ");
    Serial.println(colorPalette.getColor(i));
}

void loop() {
  // put your main code here, to run repeatedly:
}
