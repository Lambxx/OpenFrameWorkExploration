#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

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
   float radius = ofGetWidth()/100;
   ofSetColor(0, 0, 255);
   ofDrawCircle(x,y,radius);
    
   DefinePointsOnCircle(x, y, radius, 10);
      for(int i = 0; i < groupOfPoints.size(); i++){
        ofSetColor(255, 0, 0);
        ofVec2f temp;
        temp.x = groupOfPoints[i].x - x;
        temp.y = groupOfPoints[i].y - y;
        temp = temp * 100;
         ofDrawLine(groupOfPoints[i].x, groupOfPoints[i].y,temp.x, temp.y);
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
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//----------Functions--------
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
