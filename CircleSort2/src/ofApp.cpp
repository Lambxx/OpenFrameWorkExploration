#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(100);
    float x = ofGetWidth()/2;
   float y = ofGetHeight()/2;
   // Need coirdinates to calculate lines coming out 
   float radius = ofGetWidth()/10;
    DefineLines(x, y, radius, 100);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

   
   // Draw lines from center to points on circle
 
float x = ofGetWidth()/2;
   float y = ofGetHeight()/2;
   // Need coirdinates to calculate lines coming out 
   float radius = ofGetWidth()/10;
 
    
  
      for(int i = 0; i < groupOfLines.size(); i++){
         LineObj tempLine = groupOfLines[i];
         ofSetColor(tempLine.rVal, tempLine.gVal, tempLine.bVal, tempLine.alphaVal);
         ofDrawLine(tempLine.start.x, tempLine.start.y, tempLine.end.x, tempLine.end.y);
    }

}

//--------------------------------------------------------------
void ofApp::exit(){
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
groupOfPoints.clear();
float x = ofGetWidth()/2;
   float y = ofGetHeight()/2;
   // Need coirdinates to calculate lines coming out 
   float radius = ofGetWidth()/10;
     DefineLines(x, y, radius, 100);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//----------Functions--------
// Define points on circle
void ofApp::DefinePointsOnCircle(float x, float y, float radius, int numPoints){
    for(int i = 0; i < numPoints; i++){
        float angle = ofMap(i, 0, numPoints, 0, TWO_PI);
        float x1 = x + radius * cos(angle);
        float y1 = y + radius * sin(angle);
        MPoint tempP;
        tempP.setup(x1, y1);
        groupOfPoints.push_back(tempP);
    }

}

// Define lines 
void ofApp::DefineLines(float x, float y, float radius, int numPoints){

   DefinePointsOnCircle(x, y, radius, numPoints);
   for(int i = 0; i < groupOfPoints.size(); i++){
        ofSetColor(255, 0, 0);
        ofVec2f temp;
        temp.x = groupOfPoints[i].x - x;
        temp.y = groupOfPoints[i].y - y;
        temp = temp * 100;
        LineObj tempLine;
        MPoint tempM1;
        tempM1.setup(groupOfPoints[i].x, groupOfPoints[i].y);
        MPoint tempM2;
        tempM2.setup(temp.x, temp.y);
        tempLine.setup(tempM1, tempM2);
        groupOfLines.push_back(tempLine);
    }

}

