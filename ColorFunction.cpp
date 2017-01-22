#include <ColorFunction.h>

ColorFunction::ColorFunction() {}

ColorFunction::ColorFunction(uint32_t duration) {
    this->duration = duration;
}

ColorFunction::ColorFunction(uint32_t duration, ColorPalette* colorPalette) {
    this->duration = duration;
    this->colorPalette = colorPalette;
}

ColorFunction::ColorFunction(uint32_t duration, ColorPalette* colorPalette, uint8_t* params) {
    this->duration = duration;
    this->colorPalette = colorPalette;
    this->params = params;
}
