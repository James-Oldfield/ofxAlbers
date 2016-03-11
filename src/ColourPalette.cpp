#include "ColourPalette.h"

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
  col.setBrightness( ofClamp( oldBri - ( oldBri * ( percent * .01 ) ), 0, 255 ) );

  return col;
}

ofColor ColourPalette::lighten(ofColor & col, unsigned int percent) {
  float oldBri = col.getBrightness();
  col.setBrightness( ofClamp( oldBri + ( oldBri * ( percent * .01  )  ), 0, 255  ) );

  return col;
}

ofColor ColourPalette::saturate(ofColor & col, unsigned int percent) {
  float oldSat = col.getSaturation();
  col.setSaturation( ofClamp( oldSat + ( oldSat * ( percent * .01 ) ), 0, 255 ) );

  return col;
}

ofColor ColourPalette::desaturate(ofColor & col, unsigned int percent) {
  float oldSat = col.getSaturation();
  col.setSaturation( ofClamp( oldSat - ( oldSat * ( percent * .01 ) ), 0, 255 ) );

  return col;
}

ofColor ColourPalette::adjustHue(ofColor & col, int percent) {
  float oldHue = col.getHue();
  col.setHue( ofWrap( oldHue + ( oldHue * ( percent * .01 ) ), 0, 255 ) );

  return col;
}

SharedPtrColVec ColourPalette::generateRandom() {
  seedColour = ofColor( ofRandom(255), ofRandom(255), ofRandom(255) );
  return this->createPalette(seedColour);
}
