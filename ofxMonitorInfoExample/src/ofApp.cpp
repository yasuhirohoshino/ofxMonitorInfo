#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(17);
    monitorInfo.getMonitorsInfo();
    
    scale = 0.15;
    
    int x = 0;
    int y = 0;
    int width = 0;
    int height = 0;
    
    totalInfo = "";
    info.assign(monitorInfo.getCount(), string());
    for(int i=0; i<monitorInfo.getCount(); i++){
        info[i] = "";
        if(monitorInfo.getIsPrimary(i) == true){
            info[i] += "Primary Monitor\n";
        }else{
            info[i] += "Secondary Monitor\n";
        }
        info[i] += "Index : " + ofToString(i) + "\n";
        info[i] += "Name : " + ofToString(monitorInfo.getName(i)) + "\n";
        info[i] += "X : " + ofToString(monitorInfo.getX(i)) + "\n";
        info[i] += "Y : " + ofToString(monitorInfo.getY(i)) + "\n";
        info[i] += "Width : " + ofToString(monitorInfo.getWidth(i)) + "\n";
        info[i] += "Height : " + ofToString(monitorInfo.getHeight(i)) + "\n\n";
        x = fminf(x, monitorInfo.getX(i));
        y = fminf(y, monitorInfo.getY(i));
        width = fmaxf(width, monitorInfo.getX(i) + monitorInfo.getWidth(i));
        height = fmaxf(height, monitorInfo.getY(i) + monitorInfo.getHeight(i));
        totalInfo += info[i];
    }
    rect.set(x, y, width, height);
    if(x < 0){
        offsetX = x;
    }else{
        offsetX = 0;
    }
    if(y < 0){
        offsetY = y;
    }else{
        offsetY = 0;
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushStyle();
    ofNoFill();
    ofPushMatrix();
    ofTranslate((ofGetWidth() - rect.width * scale - offsetX * scale) / 2,
                (ofGetHeight() - rect.height * scale - offsetY * scale) / 2);
    for(int i=0; i<monitorInfo.getCount(); i++){
        if(monitorInfo.getIsPrimary(i)){
            ofSetColor(255, 0, 0);
        }else{
            ofSetColor(255);
        }
        ofRect(monitorInfo.getFrame(i).x * scale,
               monitorInfo.getFrame(i).y * scale,
               monitorInfo.getFrame(i).width * scale,
               monitorInfo.getFrame(i).height * scale);
        ofDrawBitmapString(info[i], monitorInfo.getPosition(i) * ofPoint(scale,scale,0.0) + ofPoint(8, 18, 0));
    }
    ofPopMatrix();
    ofPopStyle();
    ofDrawBitmapString(totalInfo, 4,14);
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
