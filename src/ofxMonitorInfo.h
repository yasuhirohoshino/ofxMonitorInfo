#pragma once

#include "ofMain.h"
#include <GLFW/glfw3.h>

class ofxMonitorInfo{
    
private:
    struct monitor{
        ofRectangle frame;
        bool isPrimary;
        string name;
    };

    vector<monitor> monitorsInfo;
    
public:
    ofxMonitorInfo();
    ~ofxMonitorInfo();
    
    void getMonitorsInfo();
    int getCount();
    ofRectangle getFrame(int index);
    ofPoint getPosition(int index);
    int getX(int index);
    int getY(int index);
    int getWidth(int index);
    int getHeight(int index);
    string getName(int index);
    bool getIsPrimary(int index);
    
};
