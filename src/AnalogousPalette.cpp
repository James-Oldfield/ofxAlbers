#include "AnalogousPalette.h"

SharedPtrColVec AnalogousPalette::createPalette(const ofColor & _seedColour) {
  seedColour = _seedColour;

  vector<float> hues; // stores the hue values
  float ang = seedColour.getHueAngle(); // hue angle of the seed colour

  ang = ofMap(ang, 0, 360, 0, 255); // map from angle to HSB colour space min and max.

  // Push back the angles based on angDif
  hues.push_back(ofWrap(ang-angDif*2, 0, 255));
  hues.push_back(ofWrap(ang-angDif, 0, 255));
  hues.push_back(ofWrap(ang, 0, 255));
  hues.push_back(ofWrap(ang+angDif, 0, 255));
  hues.push_back(ofWrap(ang+angDif*2, 0, 255));

  // If colour vector is already populated, simply edit existing colours.
  // Else simply push new colours back.
  if(colours->size() > 4)
    for(int i=0; i<hues.size(); i++)
      colours->at(i) = ofColor::fromHsb(hues.at(i), s, b);
  else
    for(const auto h : hues)
      colours->push_back(ofColor::fromHsb(h, s, b));

  return colours;
}

void AnalogousPalette::setAngleDif(const int & _angDif) {
  angDif = _angDif;
  this->createPalette(seedColour);
}

AnalogousPalette::AnalogousPalette(int _angDif, int _b, int _s): ColourPalette(), angDif(_angDif), b(_b), s(_s) {};
AnalogousPalette::~AnalogousPalette() {};

  /**
   * @brief AnalogousPalette's copy constructor. Creates a 'unique' shared pointer from the old one
   * as we don't want it to point to the previous instantiation's 'colours'.
   */
AnalogousPalette::AnalogousPalette(const AnalogousPalette & old) {
  colours = make_shared<ColVec>(*old.colours);
}
