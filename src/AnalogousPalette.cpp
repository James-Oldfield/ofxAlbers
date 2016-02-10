#include "AnalogousPalette.h"

vector<ofColor> & AnalogousPalette::createPalette(const ofColor & seedColour) {
  cout << "hi non-void" << endl;

  colours.push_back(seedColour);

  return colours;
}


AnalogousPalette AnalogousPalette::test() { cout << "test func" << endl; 
  return *this;
}

AnalogousPalette::AnalogousPalette() {};
AnalogousPalette::~AnalogousPalette() { cout << "destructor" << endl; };
