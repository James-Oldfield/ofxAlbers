/**
 * @class ColourPalette
 * @brief A high-level abstract base class representing a colour palette.
 * @tparam Subclass The Derived class
 * @author James Oldfield.
 */

#ifndef ____ColourPalette__
#define ____ColourPalette__

#include "ofMain.h"


template<class SubClass>

class ColourPalette {
  protected:
    vector<ofColor> colours; //!< stores the of representation of the generated colours.

    /**
     * @brief Abstract virtual class which provides the interface to creating a colour scheme from a seed colour.
     * @return a unique_ptr to the object itself.
     */
    virtual vector<ofColor> & createPalette(const ofColor & seedColour) = 0;
    virtual SubClass test() = 0;

    /**
     * @brief Generic colour scheme getter. Returns a shared pointer to the colour scheme itself.
     * @return a shared pointer to the vector of ofColours.
     */
    shared_ptr<vector<ofColor>> getPalette() const { return shared_ptr<vector<ofColor>>(&colours); };

  public:
    virtual ~ColourPalette() {};
};

#endif /* defined(____ColourPalette__) */