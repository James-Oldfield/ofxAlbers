/**
 * @class DribbblePalette
 * @brief Functionality for constructing colour schemes from dribbble shots via HTTP. Has a ofxGumbo dependency. Scrapes a dribbble project's URI and extracts the colour data based on their HTML schema.
 * @author James Oldfield.
 */

#ifndef ____DribbblePalette__
#define ____DribbblePalette__

#include "ofMain.h"
#include "ColourPalette.h"
#include "ofxGumbo.h"
#include "Poco/Net/NetException.h"

class DribbblePalette: public ColourPalette {
  private:
    ofHttpResponse res; //!< Stores the response of the HTTP request to scrape dribbble.

    /**
     * @brief A method to recursively search a DOM to search for the colour class where the dribbble shot's colours are stored. Uses Google's Gumbo HTML parser for C - included with ofxGumbo.
     * @param node A pointer to the GumboNode to traverse in this instance.
     * @param orig The HTML/DOM structure stringified.
     * @param className The classname to search for, viz. 'color'.
     */
    void searchForCols(GumboNode* node, const string & orig, const string className);
  public:
    /**
     * @brief Main entry method to create colour schemes from Dribbble project palettes. Example url = https://dribbble.com/shots/2585138-Sunset-Badge.
     * @param _url The Dribbble project's URL. An example is "https://dribbble.com/shots/2585138-Sunset-Badge".
     * @return A shared_ptr<vector<ofColor>> (typedef'd - SharedPtrColVec) to the vector of of colours.
     */
    SharedPtrColVec createPalette(const string & _url);

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
