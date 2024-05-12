#ifndef _LINEOBJ // if this class hasn't been defined, the program can define it
#define _LINEOBJ // by using this if statement you prevent the class to be called more than once which would confuse the compiler
#include "ofMain.h" // we need to include this to have a reference to the openFrameworks framework
#include "MPoint.h"

class LineObj {


    public: // place public functions or variables declarations here

    // methods, equivalent to specific functions of your class objects
    void setup(MPoint _start, MPoint _end,float rValue);
    // variables
    MPoint start;      // position
    MPoint end; // position
    int rVal;
    int gVal;   
    int bVal;
    int alphaVal;   
    int thickness;
 

    LineObj();  // constructor - used to initialize an object, if no properties are passed the program sets them to the default value
    private: // place private functions or variables declarations here
}; // don't forget the semicolon!
#endif