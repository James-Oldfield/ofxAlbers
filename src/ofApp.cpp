#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(255);

  ofColor r = ofColor(255, 100, 100);
  ofColor g = ofColor(0, 255, 0);
  ofColor b = ofColor(0, 0, 255);
  
  //triad.createPalette(r);
  // anal.createPalette(g);
  mono.createPalette(b);
  newMono.createPalette(g);

  newMono = mono;

  cols = newMono.getPalette();
}

//--------------------------------------------------------------
void ofApp::update(){
  if(flag) {
    cols = mono.getPalette();
  }
  else {
    cols = newMono.getPalette();
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
  flag =! flag;  
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
