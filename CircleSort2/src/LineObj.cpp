#include "LineObj.h"
#include "ofMain.h"

LineObj::LineObj(){
}

void LineObj::setup(MPoint _start, MPoint _end, float rValue,float gValue, float bValue,float aValue){
    start = _start;
    end = _end;
    rVal =  ofRandom(rValue);
    gVal = ofRandom(gValue);
    bVal = ofRandom(bValue);
    alphaVal = ofRandom(aValue);
    thickness = ofRandom(100);
  
}

