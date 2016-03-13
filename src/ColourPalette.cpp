#include "ColourPalette.h"

ColourPalette::ColourPalette() {
  colours = make_shared<ColVec>();
};

SharedPtrColVec ColourPalette::getPalette() const {
  return colours;
}

void ColourPalette::sortPalette(string channel) {
  sort(colours->begin(), colours->end(), [&] (ofColor i, ofColor j) {
    if(channel == "hue") return i.getHue() < j.getHue();
    if(channel == "saturation") return i.getSaturation() < j.getSaturation();
    if(channel == "brightness") return i.getBrightness() < j.getBrightness();

    return false;
  });
}

