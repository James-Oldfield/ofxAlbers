#pragma once

#include "ofMain.h"
#include "AnalogousPalette.h"
#include "MonochromePalette.h"
#include "ComplimentaryPalette.h"
#include "TriadPalette.h"
#include "ColourPalette.h"
#include "DribbblePalette.h"
#include "ofxDatGui.h"

using UniColPal = unique_ptr<ColourPalette>;

class ofApp : public ofBaseApp{

  public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    vector<UniColPal> palettes;

    /**
     * @brief Takes a function pointer to the desired static function to demo, and performs this on all colours in all palettes.
     * @param funcPointer A pointer to the desired func.
     * @param percent The percent to modify the colours by.
     */
    void adjustPalette(ofColor (*funcPointer)(ofColor &, unsigned int), unsigned int percent);

    /**
     * @brief Generates a palette of varying derived-class type, from the GUI options.
     * @tparam BaseClass The Dervied class to instantiate.
     */
    template<class BaseClass>
    void createPalette();

    void onButtonEvent(ofxDatGuiButtonEvent e);
    void modifyPalettes();
    void addPalettes();

    // GUI
    ofxDatGui * gui;
};
