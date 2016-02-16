#include "AnalogousPalette.h"

vector<ofColor> & AnalogousPalette::createPalette(const ofColor & seedColour) {
  vector<float> hues; //!< stores the hue values
  float ang = seedColour.getHueAngle(); //!< hue angle of the seed colour

  // Push back the angles based on angDif
  hues.push_back(ofWrap(ang-angDif*2, 0, 255));
  hues.push_back(ofWrap(ang-angDif, 0, 255));
  hues.push_back(ofWrap(ang, 0, 255));
  hues.push_back(ofWrap(ang+angDif, 0, 255));
  hues.push_back(ofWrap(ang+angDif*2, 0, 255));

  for(const auto h : hues) {
    ofColor c = ofColor::fromHsb(h, s, b);
    colours.push_back(c);
  }

  return colours;
}


AnalogousPalette AnalogousPalette::test() { cout << "test func" << endl; 
  return *this;
}

AnalogousPalette::AnalogousPalette(int _angDif, int _b, int _s): angDif(_angDif), b(_b), s(_s) {};
AnalogousPalette::~AnalogousPalette() { cout << "destructor" << endl; };