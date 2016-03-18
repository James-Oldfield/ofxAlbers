/**
 * @class TheoryPalette
 * @brief A high-level abstract base class representing a colour palette based on colour theory.
 * @author James Oldfield.
 */

#ifndef ____TheoryPalette__
#define ____TheoryPalette__

#include "ofMain.h"
#include "ColourPalette.h"

class TheoryPalette : public ColourPalette {
  protected:
  public:
    virtual ~TheoryPalette() {};

    /**
     * @brief Abstract virtual class which provides the interface to creating a colour scheme from a seed colour.
     * @param _seedColour The ofColor seed/base colour with which to construct the palette from.
     * @return a shared_ptr to the colour scheme vector.
     */
    virtual SharedPtrColVec createPalette(const ofColor & _seedColour) = 0;

    /**
     * @brief Constructor used to instantiate member objects, viz. 'colours'.
     */
    TheoryPalette();

    /**
     * @brief Populates the colours vector.
     * @param oldVec The vector of ofColors that is to be copied.
     */
    void populatePalette(const ColVec & oldVec);

    /**
     * @brief Generate a random colour scheme. Useful for quickly generating pleasing colours to use.
     * @param channel The channel to sort by.
     */
    SharedPtrColVec generateRandom();
};

#endif /* defined(____TheoryPalette__) */