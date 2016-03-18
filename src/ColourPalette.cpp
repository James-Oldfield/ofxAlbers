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

void ColourPalette::darken(unsigned int percent) {
  for(auto & c : *colours)
    darken(c, percent);
}

void ColourPalette::lighten(unsigned int percent) {
  for(auto & c : *colours)
    lighten(c, percent);
}

void ColourPalette::saturate(unsigned int percent) {
  for(auto & c : *colours)
    saturate(c, percent);
}

void ColourPalette::desaturate(unsigned int percent) {
  for(auto & c : *colours)
    desaturate(c, percent);
}

void ColourPalette::adjustHue(int percent) {
  for(auto & c : *colours)
    adjustHue(c, percent);
}

/**
 * STATIC COLOUR OPERATION FUNCTIONS
 */

ofColor ColourPalette::darken(ofColor & col, unsigned int percent) {
  float oldBri = col.getBrightness();
  col.setBrightness( ofClamp( oldBri - ( 255 * ( percent * .01 ) ), 0, 255 ) );

  return col;
}

ofColor ColourPalette::lighten(ofColor & col, unsigned int percent) {
  cout << "lighten\n";
  float oldBri = col.getBrightness();
  col.setBrightness( ofClamp( oldBri + ( 255 * ( percent * .01  ) ), 0, 255 ) );

  return col;
}

ofColor ColourPalette::saturate(ofColor & col, unsigned int percent) {
  float oldSat = col.getSaturation();
  col.setSaturation( ofClamp( oldSat + ( 255 * ( percent * .01 ) ), 0, 255 ) );

  return col;
}

ofColor ColourPalette::desaturate(ofColor & col, unsigned int percent) {
  float oldSat = col.getSaturation();
  col.setSaturation( ofClamp( oldSat - ( 255 * ( percent * .01 ) ), 0, 255 ) );

  return col;
}

ofColor ColourPalette::adjustHue(ofColor & col, int percent) {
  float oldHue = col.getHue();
  col.setHue( ofWrap( oldHue + ( 255 * ( percent * .01 ) ), 0, 255 ) );

  return col;
}
