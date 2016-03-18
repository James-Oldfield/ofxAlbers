#include "ComplimentaryPalette.h"

SharedPtrColVec ComplimentaryPalette::createPalette(const ofColor & _seedColour) {
  seedColour = _seedColour;

  vector<float> hues; // stores the hue values
  float ang = seedColour.getHueAngle(); // hue angle of the seed colour
  float s = seedColour.getSaturation();
  float b = seedColour.getBrightness();

  ang = ofMap(ang, 0, 360, 0, 255); // map from angle to HSB colour space min and max.

  float compHue = ofWrap(ang + 127.5, 0, 255); // The complimentary hue's colour.

  colours->push_back( ofColor::fromHsb( ang, s, b ) );
  colours->push_back( ofColor::fromHsb( ang, ofWrap(s + 15, 0, 255), ofWrap(b + 15, 0, 255) ) );
  colours->push_back( ofColor::fromHsb( ang, ofWrap(s - 15, 0, 255), ofWrap(b - 15, 0, 255) ) );
  colours->push_back( ofColor::fromHsb( compHue, ofWrap(s + 15, 0, 255), ofWrap(b + 15, 0, 255) ) );
  colours->push_back( ofColor::fromHsb( compHue, ofWrap(s - 15, 0, 255), ofWrap(b - 15, 0, 255) ) );

  cout << colours->at(0) << endl;
  cout << colours->at(1) << endl;
  cout << colours->at(2) << endl;
  cout << colours->at(3) << endl;
  cout << colours->at(4) << endl;

  return colours;
}

ComplimentaryPalette::ComplimentaryPalette() {};
ComplimentaryPalette::~ComplimentaryPalette() {};


  /**
   * @brief ComplimentaryPalette's copy constructor. Creates a 'unique' shared pointer from the old one
   * as we don't want it to point to the previous instantiation's 'colours'.
   */
ComplimentaryPalette::ComplimentaryPalette(const ComplimentaryPalette & old) {
  colours = make_shared<ColVec>(*old.colours);
}
