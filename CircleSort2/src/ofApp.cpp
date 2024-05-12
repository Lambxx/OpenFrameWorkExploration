#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(100);
    
    DefineLines(numPoints);
  
    gui.setup();
    gui.add(rValue.setup("R value", 100, 0, 255));
   
}


//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

   
   // Draw lines from center to points on circle
 

 
    
  
      for(int i = 0; i < groupOfLines.size(); i++){
         LineObj tempLine = groupOfLines[i];
         ofSetColor(tempLine.rVal, tempLine.gVal, tempLine.bVal, tempLine.alphaVal);
         ofSetLineWidth(tempLine.thickness);
         ofDrawLine(tempLine.start.x, tempLine.start.y, tempLine.end.x, tempLine.end.y);
    }
    gui.draw();

}

//--------------------------------------------------------------
void ofApp::exit(){
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 's'){
        BubbleSort();
    }
     if(key == 'r'){
        groupOfPoints.clear();
        groupOfLines.clear();
        DefineLines(numPoints);
    }
   
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
groupOfLines.clear();
     DefineLines(numPoints);
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
void ofApp::DefineLines(int numPoints){
    float x = ofGetWidth()/2;
   float y = ofGetHeight()/2;
   // Need coirdinates to calculate lines coming out 
   float radius = ofGetWidth()/100;

   DefinePointsOnCircle(x, y, radius, numPoints);
   for(int i = 0; i < groupOfPoints.size(); i++){
        ofSetColor(255, 0, 0);
        ofVec2f temp;
        temp.x = groupOfPoints[i].x - x;
        temp.y = groupOfPoints[i].y - y;
        temp = temp * 1000;
        LineObj tempLine;
        MPoint tempM1;
        tempM1.setup(groupOfPoints[i].x, groupOfPoints[i].y);
        MPoint tempM2;
        tempM2.setup(temp.x, temp.y);
        tempLine.setup(tempM1, tempM2, rValue);
        groupOfLines.push_back(tempLine);
    }

}

// Bubble sort, to add varying sort attributes
// Sorts groupOflines based on R value
void ofApp::BubbleSort(){
// Issue no inherit order, order of lines does not reflect order of points
    for(int i = 0; i < groupOfLines.size(); i++){
        for(int j = 0; j < groupOfLines.size() -1 ; j++){
            if(groupOfLines[j].rVal > groupOfLines[j+1].rVal){
                // Swap corodinates not lined 
               int tempR = groupOfLines[j].rVal;
                int tempG = groupOfLines[j].gVal;
                int tempB = groupOfLines[j].bVal;
                int tempAlpha = groupOfLines[j].alphaVal;
                int tempThickness = groupOfLines[j].thickness;
                groupOfLines[j].rVal = groupOfLines[j+1].rVal;
                groupOfLines[j].gVal = groupOfLines[j+1].gVal;
                groupOfLines[j].bVal = groupOfLines[j+1].bVal;
                groupOfLines[j].alphaVal = groupOfLines[j+1].alphaVal;
                groupOfLines[j].thickness = groupOfLines[j+1].thickness;
                groupOfLines[j+1].rVal = tempR;
                groupOfLines[j+1].gVal = tempG;
                groupOfLines[j+1].bVal = tempB;
                groupOfLines[j+1].alphaVal = tempAlpha;
                groupOfLines[j+1].thickness = tempThickness;


            }
        }
    }
}

