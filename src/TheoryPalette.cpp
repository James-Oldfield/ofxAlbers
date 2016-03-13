#include "TheoryPalette.h"

SharedPtrColVec TheoryPalette::generateRandom() {
  seedColour = ofColor( ofRandom(255), ofRandom(255), ofRandom(255) );
  return this->createPalette(seedColour);
}

TheoryPalette::TheoryPalette():ColourPalette() {};

void TheoryPalette::populatePalette(const ColVec & oldVec) {
  colours = make_shared<ColVec>(oldVec);
}

void TheoryPalette::darken(unsigned int percent) {
  for(auto & c : *colours)
    darken(c, percent);
}

void TheoryPalette::lighten(unsigned int percent) {
  for(auto & c : *colours)
    lighten(c, percent);
}

void TheoryPalette::saturate(unsigned int percent) {
  for(auto & c : *colours)
    saturate(c, percent);
}

void TheoryPalette::desaturate(unsigned int percent) {
  for(auto & c : *colours)
    desaturate(c, percent);
}

void TheoryPalette::adjustHue(int percent) {
  for(auto & c : *colours)
    adjustHue(c, percent);
}

/**
 * STATIC COLOUR OPERATION FUNCTIONS
 */

ofColor TheoryPalette::darken(ofColor & col, unsigned int percent) {
  float oldBri = col.getBrightness();
  col.setBrightness( ofClamp( oldBri - ( oldBri * ( percent * .01 ) ), 0, 255 ) );

  return col;
}

ofColor TheoryPalette::lighten(ofColor & col, unsigned int percent) {
  float oldBri = col.getBrightness();
  col.setBrightness( ofClamp( oldBri + ( oldBri * ( percent * .01  )  ), 0, 255  ) );

  return col;
}

ofColor TheoryPalette::saturate(ofColor & col, unsigned int percent) {
  float oldSat = col.getSaturation();
  col.setSaturation( ofClamp( oldSat + ( oldSat * ( percent * .01 ) ), 0, 255 ) );

  return col;
}

ofColor TheoryPalette::desaturate(ofColor & col, unsigned int percent) {
  float oldSat = col.getSaturation();
  col.setSaturation( ofClamp( oldSat - ( oldSat * ( percent * .01 ) ), 0, 255 ) );

  return col;
}

ofColor TheoryPalette::adjustHue(ofColor & col, int percent) {
  float oldHue = col.getHue();
  col.setHue( ofWrap( oldHue + ( oldHue * ( percent * .01 ) ), 0, 255 ) );

  return col;
}
