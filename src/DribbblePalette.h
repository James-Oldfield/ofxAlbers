/**
 * @class DribbblePalette
 * @brief Functionality for constructing colour schemes from dribbble shots via HTTP. Has a ofxGumbo dependency.
 * @author James Oldfield.
 */

#ifndef ____DribbblePalette__
#define ____DribbblePalette__

#include "ofMain.h"
#include "TheoryPalette.h"
// #include "ofxGumbo.h"

class DribbblePalette: public TheoryPalette {
  private:
    ofHttpResponse res; //!< Stores the response of the HTTP request to scrape dribbble.
    void urlResponse(ofHttpResponse & _res);
  public:

    /**
     * @brief Construct an Dribbble Palette object.
     */
    DribbblePalette();
    ~DribbblePalette();

    /**
     * @brief DribbblePalette's copy constructor.
     */
    DribbblePalette(const DribbblePalette & old);

};

#endif /* defined(____DribbblePalette__) */
