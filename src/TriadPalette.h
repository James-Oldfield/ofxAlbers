/**
 * @class TriadPalette
 * @brief Represents a Triadic colour scheme.
 * @author James Oldfield.
 */

#ifndef ____TriadPalette__
#define ____TriadPalette__

#include "ofMain.h"
#include "ColourPalette.h"

class TriadPalette: public ColourPalette {
  private:
  public:

    /**
     * @brief Main method for creating Triad colour schemes from a seed colour.
     * @return A pointer to the colour scheme.
     */
    SharedPtrColVec createPalette(const ofColor & _seedColour);

    /**
     * @brief Construct an Triad Palette object and set relevant vars.
     */
    TriadPalette();
    ~TriadPalette();

    TriadPalette(const TriadPalette & old);
};

#endif /* defined(____TriadPalette__) */
