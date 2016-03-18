#include "TheoryPalette.h"

SharedPtrColVec TheoryPalette::generateRandom() {
  seedColour = ofColor( ofRandom(255), ofRandom(255), ofRandom(255) );
  return this->createPalette(seedColour);
}

TheoryPalette::TheoryPalette():ColourPalette() {};

void TheoryPalette::populatePalette(const ColVec & oldVec) {
  colours = make_shared<ColVec>(oldVec);
}
