/**
 * @class ColourPalette
 * @brief Top of the inheritence chain, describes a colour palette.
 * @author James Oldfield.
 */

#ifndef ____ColourPalette__
#define ____ColourPalette__

#include "ofMain.h"

using ColVec = vector<ofColor>;
using SharedPtrColVec = shared_ptr<ColVec>;

class ColourPalette {
  protected:
    SharedPtrColVec colours; //!< stores the of representation of the generated colours.
    ofColor seedColour = ofColor(255, 255, 255); //!< the base colour with which to generate a scheme from.

  public:
    virtual ~ColourPalette() {};

    /**
     * @brief Constructor used to instantiate member objects, viz. 'colours'.
     */
    ColourPalette();

    /**
     * @brief ABS's copy constructor. Creates a 'unique' shared pointer from the old one
     * as we don't want it to point to the previous instantiation's 'colours'.
     */
    ColourPalette(const ColourPalette & old): colours(make_shared<ColVec>(*old.colours)) {}

    /**
     * @brief ABS's assignment operator. Creates a 'unique' shared pointer from the old one
     * as we don't want it to point to the previous instantiation's 'colours'.
     */
    void operator = (const ColourPalette & old) {
      colours = make_shared<ColVec>(*old.colours);
    }

    /**
     * @brief Generic colour scheme getter. Returns a shared pointer to the colour scheme itself.
     * @return a shared pointer to the vector of ofColours.
     */
    SharedPtrColVec getPalette() const;

    /**
     * @brief Used to sort the palette of colours based on chosen channel.
     * @param channel The channel to sort by.
     */
    void sortPalette(string channel = "hue");
};

#endif /* defined(____ColourPalette__) */
