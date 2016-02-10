/**
 * @class AnalogousPalette
 * @brief A high-level abstract base class representing a colour palette.
 * @author James Oldfield.
 */

#ifndef ____AnalogousPalette__
#define ____AnalogousPalette__

#include "ofMain.h"
#include "ColourPalette.h"

class AnalogousPalette: public ColourPalette<AnalogousPalette> {
  public:

    /**
     * @brief Main method for creating analogous colour schemes from a seed colour.
     * @return A pointer to the colour scheme.
     */
    vector<ofColor> & createPalette(const ofColor & seedColour);
    AnalogousPalette test();

    AnalogousPalette();
    ~AnalogousPalette();
};

#endif /* defined(____AnalogousPalette__) */
