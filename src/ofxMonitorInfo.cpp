#include "ofxMonitorInfo.h"

ofxMonitorInfo::ofxMonitorInfo(){}
ofxMonitorInfo::~ofxMonitorInfo(){}

void ofxMonitorInfo::getMonitorsInfo(){
    monitorsInfo.clear();
    GLFWmonitor *pMonitor = glfwGetPrimaryMonitor();
    int pX, pY;
    glfwGetMonitorPos(pMonitor, &pX, &pY);
    string pName = glfwGetMonitorName(pMonitor);
    GLFWvidmode pVidmode = *glfwGetVideoMode(pMonitor);
    monitor pMonitorInfo;
    pMonitorInfo.frame = ofRectangle(pX, pY, pVidmode.width, pVidmode.height);
    pMonitorInfo.isPrimary = true;
    pMonitorInfo.name = pName;
    monitorsInfo.push_back(pMonitorInfo);
    
    int monitorsCount;
    GLFWmonitor **monitors = glfwGetMonitors(&monitorsCount);
    if(monitorsCount > 1){
        for(int i=1;i<monitorsCount;i++){
            int x, y;
            glfwGetMonitorPos(monitors[i], &x, &y);
            string name = glfwGetMonitorName(monitors[i]);
            GLFWvidmode vidmode = *glfwGetVideoMode(monitors[i]);
            monitor monitorInfo;
            monitorInfo.frame = ofRectangle(x, y, vidmode.width, vidmode.height);
            monitorInfo.isPrimary = false;
            monitorInfo.name = name;
            monitorsInfo.push_back(monitorInfo);
        }
    }
}

int ofxMonitorInfo::getCount(){
    return monitorsInfo.size();
}

ofRectangle ofxMonitorInfo::getFrame(int index){
    if(index < monitorsInfo.size()){
        return monitorsInfo[index].frame;
    }else{
        ofLog(OF_LOG_FATAL_ERROR, "ofxMonitorInfo :: The index is out of range.");
        return ofRectangle(0,0,0,0);
    }
}

ofPoint ofxMonitorInfo::getPosition(int index){
    if(index < monitorsInfo.size()){
        return ofPoint(monitorsInfo[index].frame.x, monitorsInfo[index].frame.y,0);
    }else{
        ofLog(OF_LOG_FATAL_ERROR, "ofxMonitorInfo :: The index is out of range.");
        return ofPoint(0,0,0);
    }
}

int ofxMonitorInfo::getX(int index){
    if(index < monitorsInfo.size()){
        return monitorsInfo[index].frame.x;
    }else{
        ofLog(OF_LOG_FATAL_ERROR, "ofxMonitorInfo :: The index is out of range.");
        return 0;
    }
}

int ofxMonitorInfo::getY(int index){
    if(index < monitorsInfo.size()){
        return monitorsInfo[index].frame.y;
    }else{
        ofLog(OF_LOG_FATAL_ERROR, "ofxMonitorInfo :: The index is out of range.");
        return 0;
    }
}

int ofxMonitorInfo::getWidth(int index){
    if(index < monitorsInfo.size()){
        return monitorsInfo[index].frame.width;
    }else{
        ofLog(OF_LOG_FATAL_ERROR, "ofxMonitorInfo :: The index is out of range.");
        return 0;
    }
}

int ofxMonitorInfo::getHeight(int index){
    if(index < monitorsInfo.size()){
        return monitorsInfo[index].frame.height;
    }else{
        ofLog(OF_LOG_FATAL_ERROR, "ofxMonitorInfo :: The index is out of range.");
        return 0;
    }
}

string ofxMonitorInfo::getName(int index){
    if(index < monitorsInfo.size()){
        return monitorsInfo[index].name;
    }else{
        ofLog(OF_LOG_FATAL_ERROR, "ofxMonitorInfo :: The index is out of range.");
        return "None";
    }
}

bool ofxMonitorInfo::getIsPrimary(int index){
    if(index < monitorsInfo.size()){
        return monitorsInfo[index].isPrimary;
    }else{
        ofLog(OF_LOG_FATAL_ERROR, "ofxMonitorInfo :: The index is out of range.");
        return false;
    }
}