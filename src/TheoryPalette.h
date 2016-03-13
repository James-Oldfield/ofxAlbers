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
    ofColor seedColour = ofColor(255, 255, 255); //!< the base colour with which to generate a scheme from.

    /**
     * @brief Abstract virtual class which provides the interface to creating a colour scheme from a seed colour.
     * @param _seedColour The ofColor seed/base colour with which to construct the palette from.
     * @return a shared_ptr to the colour scheme vector.
     */
    virtual SharedPtrColVec createPalette(const ofColor & _seedColour) = 0;

  public:
    virtual ~TheoryPalette() {};

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
     * @brief Generic colour scheme getter. Returns a shared pointer to the colour scheme itself.
     * @return a shared pointer to the vector of ofColours.
     */
    SharedPtrColVec getPalette() const;

    /**
     * @brief Used to sort the palette of colours based on chosen channel.
     * @param channel The channel to sort by.
     */
    void sortPalette(string channel = "hue");

    /**
     * @brief Generate a random colour scheme. Useful for quickly generating pleasing colours to use.
     * @param channel The channel to sort by.
     */
    SharedPtrColVec generateRandom();

    /**
    * @brief Used to darken a colour scheme by a given percentage.
    * @param percent The percentage with which to change the colour by.
    */
    void darken(unsigned int percent);

    /**
    * @brief Used to lighten a colour scheme by a given percentage.
    * @param percent The percentage with which to change the colour by.
    */
    void lighten(unsigned int percent);

    /**
    * @brief Used to saturate a colour scheme by a given percentage.
    * @param percent The percentage with which to change the colour by.
    */
    void saturate(unsigned int percent);

    /**
    * @brief Used to desaturate a colour scheme by a given percentage.
    * @param percent The percentage with which to change the colour by.
    */
    void desaturate(unsigned int percent);

    /**
    * @brief Used to adjust the hue by a given percentage - n.b. can be a negative value.
    * @param percent The percentage with which to change the colour by.
    */
    void adjustHue(int percent);

    /**
     * STATIC COLOUR OPERATION FUNCTIONS
     */

    /**
     * @brief Used to darken a colour by a given percentage.
     * @param col A reference to the colour to be altered.
     * @param percent The percentage with which to change the colour by.
     * @return The new colour, post-operation.
     */
    static ofColor darken(ofColor & col, unsigned int percent);

    /**
     * @brief Used to lighten a colour by a given percentage.
     * @param col A reference to the colour to be altered.
     * @param percent The percentage with which to change the colour by.
     * @return The new colour, post-operation.
     */
    static ofColor lighten(ofColor & col, unsigned int percent);

    /**
     * @brief Used to saturate a colour by a given percentage.
     * @param col A reference to the colour to be altered.
     * @param percent The percentage with which to change the colour by.
     * @return The new colour, post-operation.
     */
    static ofColor saturate(ofColor & col, unsigned int percent);

    /**
     * @brief Used to desaturate a colour by a given percentage.
     * @param col A reference to the colour to be altered.
     * @param percent The percentage with which to change the colour by.
     * @return The new colour, post-operation.
     */
    static ofColor desaturate(ofColor & col, unsigned int percent);

    /**
     * @brief Used to adjust the hue by a given percentage - n.b. can be a negative value.
     * @param col A reference to the colour to be altered.
     * @param percent The percentage with which to change the colour by.
     * @return The new colour, post-operation.
     */
    static ofColor adjustHue(ofColor & col, int percent);
};

#endif /* defined(____TheoryPalette__) */