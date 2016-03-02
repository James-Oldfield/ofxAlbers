/**
 * @class ComplimentaryPalette
 * @brief Represents a Complimentaryic colour scheme.
 * @author James Oldfield.
 */

#ifndef ____ComplimentaryPalette__
#define ____ComplimentaryPalette__

#include "ofMain.h"
#include "ColourPalette.h"

class ComplimentaryPalette: public ColourPalette {
  private:
  public:

    /**
     * @brief Main method for creating Complimentary colour schemes from a seed colour.
     * @return A pointer to the colour scheme.
     */
    shared_ptr<vector<ofColor>> createPalette(const ofColor & seedColour);

    /**
     * @brief Construct an Complimentary Palette object and set relevant vars.
     */
    ComplimentaryPalette();
    ~ComplimentaryPalette();

    ComplimentaryPalette(const ComplimentaryPalette & old);
};

#endif /* defined(____ComplimentaryPalette__) */
