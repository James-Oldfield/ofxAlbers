/**
 * @class AnalogousPalette
 * @brief Functionality for constructing and manipulating Analogous colour schemes.
 * @author James Oldfield.
 */

#ifndef ____AnalogousPalette__
#define ____AnalogousPalette__

#include "ofMain.h"
#include "TheoryPalette.h"

class AnalogousPalette: public TheoryPalette {
  private:
    int angDif; //!< difference between the hue values, angle-wise, in the colour scheme.
    int b;      //!< brightness of the colour
    int s;      //!< saturation of the colour
  public:

    /**
     * @brief Main method for creating analogous colour schemes from a seed colour.
     * @param _seedColour The ofColor seed/base colour with which to construct the palette from.
     * @return A shared_ptr<vector<ofColor>> (typedef'd - SharedPtrColVec) to the vector of of colours.
     */
    SharedPtrColVec createPalette(const ofColor & _seedColour);

    /**
     * @brief Adjusts the angDif (the difference between the hue angles), and updates the colour vec.
     * @param _angDif The value to offset the hue values by in the colour scheme by.
     */
    void setAngleDif(const int & _angDif);

    /**
     * @brief Construct an Analogous Palette object and set relevant vars.
     * @param _angDif The amount to space out the colours by.
     * @param _b The brightness of the colour.
     * @param _s The saturation of the colour.
     */
    AnalogousPalette(int _angDif = 15, int _b = 255, int _s = 255);
    ~AnalogousPalette();

    AnalogousPalette(const AnalogousPalette & old);

};

#endif /* defined(____AnalogousPalette__) */
