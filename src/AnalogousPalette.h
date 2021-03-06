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
     */
    AnalogousPalette(int _angDif = 15);
    ~AnalogousPalette();

    /**
     * @brief AnalogousPalette's copy constructor.
     * @param old A reference to the old palette to copy over.
     */
    AnalogousPalette(const AnalogousPalette & old);

};

#endif /* defined(____AnalogousPalette__) */
