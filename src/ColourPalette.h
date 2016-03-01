/**
 * @class ColourPalette
 * @brief A high-level abstract base class representing a colour palette.
 * @tparam Subclass The Derived class
 * @author James Oldfield.
 */

#ifndef ____ColourPalette__
#define ____ColourPalette__

#include "ofMain.h"

class ColourPalette {
  protected:
    shared_ptr<vector<ofColor>> colours{new vector<ofColor>()}; //!< stores the of representation of the generated colours.

    /**
     * @brief Abstract virtual class which provides the interface to creating a colour scheme from a seed colour.
     * @return a unique_ptr to the object itself.
     */
    virtual shared_ptr<vector<ofColor>> createPalette(const ofColor & seedColour) = 0;

  public:
    virtual ~ColourPalette() {};

    /**
     * @brief Generic colour scheme getter. Returns a shared pointer to the colour scheme itself.
     * @return a shared pointer to the vector of ofColours.
     */
    shared_ptr<vector<ofColor>> getPalette() const { return colours; };

    /**
     * @brief Used to sort the palette of colours based on chosen channel.
     * @param channel The channel to sort by.
     */
    void sortPalette(string channel = "hue") {
      sort(colours->begin(), colours->end(), [&] (ofColor i, ofColor j) {
        if(channel == "hue") return i.getHue() < j.getHue();
        if(channel == "saturation") return i.getSaturation() < j.getSaturation();
        if(channel == "brightness") return i.getBrightness() < j.getBrightness();

        return false;
      });
    }

};

#endif /* defined(____ColourPalette__) */