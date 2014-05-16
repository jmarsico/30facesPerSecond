#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    vid.initGrabber(320, 280);
    index = 0;
    bTakePic = false;
    bShowCam = true;
}

//--------------------------------------------------------------
void testApp::update(){
    vid.update();
    
    if(bTakePic)
    {
        ofImage tempPic;
        tempPic.setFromPixels(vid.getPixelsRef());
        faces.push_back(tempPic);
        bTakePic = false;
        
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(255,255,255,255);

    if(faces.size())
    {
        faces[index].draw(0, 0, ofGetWidth(), ofGetHeight());
    
        index++;
        if(index > faces.size() - 1)
        {
            index = 0;
        }
        ofLog() << "index: " << index;
        ofLog() << "facesSize: " << faces.size();
    }

    
    if(bShowCam)
    {
        ofSetColor(255, 255, 255, 100);
        vid.draw(0, 0, ofGetWidth(), ofGetHeight());
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == ' ')
    {
        bTakePic = true;
    }
    if(key == 'v')
    {
        bShowCam = !bShowCam;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
