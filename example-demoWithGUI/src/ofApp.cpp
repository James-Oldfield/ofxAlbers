#include "ofApp.h"

template<class BaseClass>
void ofApp::createPalette() {

  /**
   * This function demonstrates how to create different types of colour palettes, viz. Those that inherit from the ABS 'TheoryPalette', and treat them with Polymorphism.
   */

  auto palette = new BaseClass();
  palette->createPalette(gui->getColorPicker("Seed colour")->getColor());
  palettes.push_back(UniColPal(palette));
}

void ofApp::adjustPalette(ofColor (*funcPointer)(ofColor &, unsigned int), unsigned int percent) {

  /**
   * This function calls the static colour operation method on each ofColor:
   * ofxAlbers::lighten(ofColor & col, unsigned int percent);
   *
   * You can also call methods on whole palettes, which performs the equivalent on all colours in the palette:
   * palette.lighten(unsigned int percent);
   */

  for_each(palettes.begin(), palettes.end(), [funcPointer, percent](UniColPal & p) {
      for(auto & c : *p->getPalette()) {
        // Call the desired function as passed in via function pointer
        c = funcPointer(c, percent);
      }
  });

}

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(255);

  /**
   * Setup demo GUI
   */
  vector<string> options = { "Analogous", "Triad", "Monochrome", "Complimentary", "Dribbble" };

  gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
  ofxDatGuiLog::quiet();

  gui->addLabel("Choose the seed colour");
  gui->addColorPicker("Seed colour")->setColor(ofColor(255, 98, 63));
  gui->addBreak()->setHeight(10.0f);

  gui->addLabel("Or load in a palette from a Dribbble project");
  gui->addTextInput("URL", "https://dribbble.com/shots/2585138-Sunset-Badge");
  gui->addBreak()->setHeight(10.0f);
  gui->setWidth(500);

  gui->addLabel("Choose the type of colour scheme");
  gui->addDropdown("Palette type", options);
  gui->addBreak()->setHeight(10.0f);

  gui->addButton("Generate Palette");
  gui->onButtonEvent(this, &ofApp::onButtonEvent);
  gui->addBreak()->setHeight(30.0f);

  /**
   * Static colour function demo
   */

  gui->addLabel("Static Colour functions demo");

  gui->addLabel("Enter percent change:");
  gui->addTextInput("percent", "10");
  gui->addBreak()->setHeight(10.0f);

  vector<string> funcOptions = { "lighten", "darken", "saturate", "desaturate", "adjustHue" };
  gui->addLabel("Choose the colour operation");
  gui->addDropdown("Function Type", funcOptions);
  gui->addBreak()->setHeight(10.0f);

  gui->addButton("Modify palettes");
  gui->onButtonEvent(this, &ofApp::onButtonEvent);
  gui->addBreak()->setHeight(10.0f);
}

void ofApp::onButtonEvent(ofxDatGuiButtonEvent e) {
  if(e.target->getLabel() == "GENERATE PALETTE")
    addPalettes();
  else
    modifyPalettes();
}

void ofApp::addPalettes() {
  string type = gui->getDropdown("Palette type")->getSelected()->getName();

  /**
   * Create new palettes from Child classes of TheoryPalette by calling:
   * palette.createPalette(ofColor myRGBCol);
   *
   * This returns a shared pointer to the colour vector.
   */

  if(type == "Analogous") createPalette<AnalogousPalette>();
  if(type == "Monochrome") createPalette<MonochromePalette>();
  if(type == "Complimentary") createPalette<ComplimentaryPalette>();
  if(type == "Triad") createPalette<TriadPalette>();

  if(type == "Dribbble") {
    string url = gui->getTextInput("URL")->getText();

    for_each(url.begin(), url.end(), [] (char & c) {
      c = tolower(c);
    });

    auto palette = new DribbblePalette();
    palette->createPalette(url);
    palettes.push_back(UniColPal(palette));
  } 
}

void ofApp::modifyPalettes() {
  string func = gui->getDropdown("Function Type")->getSelected()->getName();
  int perc = stoi(gui->getTextInput("percent")->getText());

  /**
   * You can either perform methods on individual colours or on whole palettes.
   * palette.lighten(int percent);
   * ofxAlbers::lighten(ofColor col, int percent);
   *
   * These static functions return the new colour, so you re-assign if need be.
   */

  if(func == "lighten") adjustPalette(ColourPalette::lighten, perc);
  if(func == "darken") adjustPalette(ColourPalette::darken, perc);
  if(func == "saturate") adjustPalette(ColourPalette::saturate, perc);
  if(func == "desaturate") adjustPalette(ColourPalette::desaturate, perc);

  /**
   * Below is an example of calling the colour methods for each Palette.
   * adjustHue is agnostic as to whether or not the int is unsigned.
   */

  if(func == "adjustHue")
    for(auto & p: palettes)
      p->adjustHue(perc);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw() {
  for(int i=0; i<palettes.size(); i++) {
    for(int j=0; j<palettes.at(i)->getPalette()->size(); j++) {
      ofSetColor(palettes.at(i)->getPalette()->at(j));
      ofDrawEllipse(550 + (i+1)*50, (j+1)*50, 30, 30);
    }
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
