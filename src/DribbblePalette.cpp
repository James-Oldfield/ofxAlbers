#include "DribbblePalette.h"

void DribbblePalette::searchForCols(GumboNode* node, const string & orig, const string className) {
  if (node->type != GUMBO_NODE_ELEMENT) return; // Ensure the node is a valid HTML element

  GumboAttribute* classAtt; // Stores the class attribute
  GumboAttribute* titleAtt; // Stores the title attribute

  GumboVector* children = &node->v.element.children; // Cache all the node's children

  // We're looking for the <li>'s so compare to the GUMBO_TAG_LI enum.
  // The Node's class attribute also needs to be 'colour' as required by Dribbble's HTML structure.
  if (node->v.element.tag == GUMBO_TAG_LI && (classAtt = gumbo_get_attribute(&node->v.element.attributes, "class")) && classAtt->value == className && classAtt->value != NULL) {
    GumboNode* child = static_cast<GumboNode*>(children->data[1]);

    titleAtt = gumbo_get_attribute(&child->v.element.attributes, "title");
    string col = titleAtt->value;
    col.erase(0, 1); // remove preffixing '#'

    colours->push_back(ofColor::fromHex(ofHexToInt(col))); // Parse the Hex and create an ofColor from it.
  }

  // Perform the search recursively and traverse the whole DOM.
  for (int i = 0; i < children->length; ++i)
    searchForCols(static_cast<GumboNode*>(children->data[i]), orig, className);
}

SharedPtrColVec DribbblePalette::createPalette(const string & _url) {
  // Attempt the HTTP request, scrape the project's page and traverse the HTML DOM, pulling in the data from the 'colours' li nodes.
  try {
    res = ofLoadURL(_url);
    GumboOutput* output = gumbo_parse(res.data.getText().c_str());
    searchForCols(output->root, res.data.getText(), "color");
    gumbo_destroy_output(&kGumboDefaultOptions, output);
  } catch (Poco::Net::DNSException) {
    cout << "host not found!" << endl;
  } catch (...) {
    cout << "Error loading palette from Url." << endl;
    cout << "Is your connection working / is the url to the Dribbble shot correct?" << endl;
  }

    if(colours->size() == 0) cout << "There was an error scraping Dribbble. Returning an empty palette." << endl;
    return colours;
}

DribbblePalette::DribbblePalette() {};

DribbblePalette::~DribbblePalette() {};
