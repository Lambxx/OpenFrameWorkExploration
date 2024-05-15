#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(100);
    ofSetBackgroundColor(255,255,255);
    DefineLines(numPoints);
  
  // Setup GUI
    gui.setup();
    gui.add(rValue.setup("R value", 100, 0, 255));
    gui.add(gValue.setup("G value", 100, 0, 255));
    gui.add(bValue.setup("B value", 100, 0, 255));
    gui.add(aValue.setup("A value", 100, 0, 255));
    gui.add(sortByRvalue.setup("Sort by R value"));
    gui.add(sortByGvalue.setup("Sort by G value"));
    gui.add(sortByBvalue.setup("Sort by B value"));
    gui.add(sortByAvalue.setup("Sort by A value"));
    gui.add(sortSpeed.setup("Sort Speed", 1, 0, 10));
    gui.add(drawLines.setup("Draw new lines"));

    //gui.add(rLabel.setup("R Label",));
    sortByRvalue.addListener(this,&ofApp::sortByRvalueButtonPressed);
    sortByGvalue.addListener(this,&ofApp::sortByGvalueButtonPressed);
    sortByBvalue.addListener(this,&ofApp::sortByBvalueButtonPressed);
    sortByAvalue.addListener(this,&ofApp::sortByAvalueButtonPressed);
    drawLines.addListener(this,&ofApp::drawNewLines);
}
// Button listeners----------------
void ofApp::sortByRvalueButtonPressed(){
    sorted = false;
    SortWanted = true;
    valueToSort = 'r';
}

void ofApp::sortByGvalueButtonPressed(){
    sorted = false;
    SortWanted = true;
    valueToSort = 'g';
}

void ofApp::sortByBvalueButtonPressed(){
    sorted = false;
    SortWanted = true;
    valueToSort = 'b';
}

void ofApp::sortByAvalueButtonPressed(){
    sorted = false;
    SortWanted = true;
    valueToSort = 'a';
}

void ofApp::drawNewLines(){
    groupOfPoints.clear();
    groupOfLines.clear();
    DefineLines(numPoints);
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
    if (SortWanted && !sorted){
        BubbleSort();
        int speed = ofMap(sortSpeed, 0, 10, 100, 1);
        ofSleepMillis(speed);
        
    }
    if (sorted && SortWanted){
        ofDrawBitmapString("Sorted", ofGetWidth()/2, ofGetHeight()/2);
        SortWanted = false;
        sorted = false;
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
        tempLine.setup(tempM1, tempM2, rValue, gValue, bValue, aValue);
        groupOfLines.push_back(tempLine);
    }

}

// Bubble sort, to add varying sort attributes
// Sorts groupOflines based on R value
void ofApp::BubbleSort(){

// ADD IN paramter r,g,b, alpha, thickness. Then set compare val based on this, then use comparison val in if statement to check if it should swap.

// Issue no inherit order, order of lines does not reflect order of points
sorted = true;

        for(int j = 0; j < groupOfLines.size()-1 ; j++){
            float compareVal1;
            float compareVal2;
            switch (valueToSort) {
            case 'r':
            {
                /* code */
                compareVal1 = groupOfLines[j].rVal; 
                 compareVal2 = groupOfLines[j+1].rVal;
                break;
            }

            case 'g':
            {
                /* code */
                compareVal1 = groupOfLines[j].gVal; 
                 compareVal2 = groupOfLines[j+1].gVal;
                break;
            }
            case 'b':
            {
                /* code */
                 compareVal1 = groupOfLines[j].bVal; 
                compareVal2 = groupOfLines[j+1].bVal;
                break;
            }
            case 'a':
            {
                /* code */
                 compareVal1 = groupOfLines[j].alphaVal; 
                compareVal2 = groupOfLines[j+1].alphaVal;
                break;
            }
            default:
            {
                 compareVal1 = groupOfLines[j].rVal; 
                 compareVal2 = groupOfLines[j+1].rVal;
                break;
            }
            }

            if(compareVal1 < compareVal2){
                sorted = false;
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


