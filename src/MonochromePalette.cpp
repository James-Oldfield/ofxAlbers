#include "MonochromePalette.h"

SharedPtrColVec MonochromePalette::createPalette(const ofColor & _seedColour) {
  seedColour = _seedColour;

  vector<ofVec2f> satBri; //!< stores the saturation and brightness.
  float hue = seedColour.getHue(); //!< stores the hue value of the seed colour.
  float sat = seedColour.getSaturation(); //!< stores the sat of seed colour.
  float bri = seedColour.getBrightness(); //!< ^ Ditto brightness.

  // Push back the angles based on satDif.
  satBri.push_back(ofVec2f(ofWrap(sat-satDif*2, 0, 255), ofWrap(bri-briDif, 0, 255)));
  satBri.push_back(ofVec2f(ofWrap(sat-satDif, 0, 255), ofWrap(bri-briDif, 0, 255)));
  satBri.push_back(ofVec2f(ofWrap(sat, 0, 255), ofWrap(bri-briDif, 0, 255)));
  satBri.push_back(ofVec2f(ofWrap(sat+satDif, 0, 255), ofWrap(bri-briDif, 0, 255)));
  satBri.push_back(ofVec2f(ofWrap(sat+satDif*2, 0, 255), ofWrap(bri-briDif, 0, 255)));

  for(const auto sb : satBri) {
    ofColor c = ofColor::fromHsb(hue, sb.x, sb.y);
    colours->push_back(c);
  }

  return colours;
}

MonochromePalette::MonochromePalette(int _satDif, int _briDif): ColourPalette(), satDif(_satDif), briDif(_briDif) {};
MonochromePalette::~MonochromePalette() { cout << "destructor" << endl; };

  /**
   * @brief MonochromePalette's copy constructor. Creates a 'unique' shared pointer from the old one
   * as we don't want it to point to the previous instantiation's 'colours'.
   */
MonochromePalette::MonochromePalette(const MonochromePalette & old) {
  colours = make_shared<ColVec>(*old.colours);
}

