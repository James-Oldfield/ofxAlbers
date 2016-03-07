/**
 * @class MonochromePalette
 * @brief Functionality for constructing and manipulating Monochromatic colour schemes.
 * @author James Oldfield.
 */

#ifndef ____MonochromePalette__
#define ____MonochromePalette__

#include "ofMain.h"
#include "ColourPalette.h"

class MonochromePalette: public ColourPalette {
  private:
    int satDif; //!< difference between the Saturation of the colours.
    int briDif; //!< difference between the Brightness of the colours.
  public:

    /**
     * @brief Main method for creating monochrome colour schemes from a seed colour.
     * @return A pointer to the colour scheme.
     */
    SharedPtrColVec createPalette(const ofColor & _seedColour);

    /**
     * @brief Construct a Monochrome Palette object and set relevant vars.
     * 
     * @param _satDif The amount to space out the colours by.
     * @param _b The brightness of the colour.
     */
    MonochromePalette(int _satDif = 15, int _briDif = 15);
    ~MonochromePalette();

    MonochromePalette(const MonochromePalette & old);
};

#endif /* defined(____MonochromePalette__) */
