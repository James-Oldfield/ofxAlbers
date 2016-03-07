#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(255);

  ofColor r = ofColor(255, 100, 100);
  ofColor g = ofColor(0, 255, 0);
  ofColor b = ofColor(0, 0, 255);
  
  //triad.createPalette(r);
  // anal.createPalette(g);
  anal.generateRandom();
  mono.generateRandom();
  newMono.generateRandom();

  newMono = mono;

  cols = newMono.getPalette();
}

//--------------------------------------------------------------
void ofApp::update(){
  if(flag) {
    cols = anal.getPalette();
  }
  else {
    cols = anal.getPalette();
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  for(int i=0; i<cols->size(); i++) {
    ofSetColor(cols->at(i));
    ofDrawEllipse(10, (i+1)*20, 20, 20);
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  ColourPalette::adjustHue( cols->at(3), 10 );
}

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
