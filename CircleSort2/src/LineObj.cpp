#include "LineObj.h"
#include "ofMain.h"

LineObj::LineObj(){
}

void LineObj::setup(MPoint _start, MPoint _end){
    start = _start;
    end = _end;
    rVal =  ofRandom(255);
    gVal = ofRandom(255);
    bVal = ofRandom(255);
    alphaVal = ofRandom(255);
    thickness = ofRandom(10);
  
}

