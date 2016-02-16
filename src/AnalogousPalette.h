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
  private:
    int angDif; //!< difference between the angles in the colour scheme.
    int b;      //!< brightness of the colour
    int s;      //!< saturation of the colour
  public:

    /**
     * @brief Main method for creating analogous colour schemes from a seed colour.
     * @return A pointer to the colour scheme.
     */
    vector<ofColor> & createPalette(const ofColor & seedColour);
    AnalogousPalette test();

    /**
     * @brief Construct an Analogous Palette object and set relevant vars.
     * 
     * @param _angDif The amount to space out the colours by.
     * @param _b The brightness of the colour.
     * @param _s The saturation of the colour.
     */
    AnalogousPalette(int _angDif = 15, int _b = 255, int _s = 255);
    ~AnalogousPalette();
};

#endif /* defined(____AnalogousPalette__) */
