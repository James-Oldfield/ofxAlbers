#include "TriadPalette.h"

shared_ptr<vector<ofColor>> TriadPalette::createPalette(const ofColor & seedColour) {
  vector<float> hues; //!< stores the hue values
  float ang = seedColour.getHueAngle(); //!< hue angle of the seed colour
  float s = seedColour.getSaturation();
  float b = seedColour.getBrightness();

  ang = ofMap(ang, 0, 360, 0, 255); // map from angle to HSB colour space min and max.

  float dif = 255 / 3; // Evenly space the 3 hues around a 255 hue circle.

  // Push back the angles based on dif
  hues.push_back(ofWrap(ang-dif, 0, 255));
  hues.push_back(ofWrap(ang, 0, 255));
  hues.push_back(ofWrap(ang+dif, 0, 255));

  for(const auto h : hues) {
    ofColor c = ofColor::fromHsb(h, s, b);
    colours->push_back(c);
  }

  // Push back the final two colours with different s and b values.
  ofColor h1 = ofColor::fromHsb(ofWrap(ang - dif, 0, 255), ofWrap(s - dif, 0, 255), b);
  ofColor h2 = ofColor::fromHsb(ofWrap(ang + dif, 0, 255), ofWrap(s - dif, 0, 255), b);

  colours->push_back(h1);
  colours->push_back(h2);

  return colours;
}

TriadPalette::TriadPalette(): ColourPalette() {};
TriadPalette::~TriadPalette() { cout << "destructor" << endl; };


  /**
   * @brief TriadPalette's copy constructor. Creates a 'unique' shared pointer from the old one
   * as we don't want it to point to the previous instantiation's 'colours'.
   */
TriadPalette::TriadPalette(const TriadPalette & old) {
  colours = make_shared<vector<ofColor>>(*old.colours);
}
