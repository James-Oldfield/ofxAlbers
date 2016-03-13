/**
 * @class ComplimentaryPalette
 * @brief Represents a Complimentaryic colour scheme.
 * @author James Oldfield.
 */

#ifndef ____ComplimentaryPalette__
#define ____ComplimentaryPalette__

#include "ofMain.h"
#include "TheoryPalette.h"

class ComplimentaryPalette: public TheoryPalette {
  private:
  public:

    /**
     * @brief Main method for creating Complimentary colour schemes from a seed colour.
     * @param _seedColour The ofColor seed/base colour with which to construct the palette from.
     * @return A shared_ptr<vector<ofColor>> (typedef'd - SharedPtrColVec) to the vector of of colours.
     */
    SharedPtrColVec createPalette(const ofColor & _seedColour);

    /**
     * @brief Construct an Complimentary Palette object and set relevant vars.
     */
    ComplimentaryPalette();
    ~ComplimentaryPalette();

    ComplimentaryPalette(const ComplimentaryPalette & old);
};

#endif /* defined(____ComplimentaryPalette__) */
