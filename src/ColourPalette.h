/**
 * @class ColourPalette
 * @brief Top of the inheritance chain, describes a colour palette.
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

#endif /* defined(____ColourPalette__) */
