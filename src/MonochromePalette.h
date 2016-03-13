/**
 * @class MonochromePalette
 * @brief Functionality for constructing and manipulating Monochromatic colour schemes.
 * @author James Oldfield.
 */

#ifndef ____MonochromePalette__
#define ____MonochromePalette__

#include "ofMain.h"
#include "TheoryPalette.h"

class MonochromePalette: public TheoryPalette {
  private:
    int satDif; //!< difference between the Saturation of the colours.
    int briDif; //!< difference between the Brightness of the colours.
  public:

    /**
     * @brief Main method for creating monochrome colour schemes from a seed colour.
     * @param _seedColour The ofColor seed/base colour with which to construct the palette from.
     * @return A shared_ptr<vector<ofColor>> (typedef'd - SharedPtrColVec) to the vector of of colours.
     */
    SharedPtrColVec createPalette(const ofColor & _seedColour);

    /**
     * @brief Adjusts the satDif (the saturation) between the colours in the colour scheme, and updates the colour vec.
     * @param _satDif The value to offset the saturation values by in the colour scheme by.
     */
    void setSaturationDif(const int & _satDif);

    /**
     * @brief Adjusts the briDif (the brightness) between the colours in the colour scheme, and updates the colour vec.
     * @param _briDif The value to offset the brightness values by in the colour scheme by.
     */
    void setBrightnessDif(const int & _briDif);

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
