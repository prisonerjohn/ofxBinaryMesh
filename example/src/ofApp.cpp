#include "ofApp.h"
#include "ofxBinaryMesh.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofBackground(0);
    ofSetFrameRate(30);

    float startTime = ofGetElapsedTimef();
	ofxBinaryMesh::load("sphere.obm", mesh);
    float endTime = ofGetElapsedTimef();
    cout << "Loaded mesh in " << (endTime - startTime) << " seconds" << endl;
    cout << mesh.getNumVertices() << " vertices" << endl;
    cout << mesh.getNumNormals() << " normals" << endl;
    cout << mesh.getNumTexCoords() << " tex coords" << endl;
    cout << mesh.getNumColors() << " colors" << endl;
    cout << mesh.getNumIndices() << " indices" << endl;
}

//--------------------------------------------------------------
void ofApp::update()
{
    cam.setPosition(mesh.getCentroid() + ofVec3f(0,0,mouseY/10));
    cam.lookAt(mesh.getCentroid(), ofVec3f(0,1,0));
}

//--------------------------------------------------------------
void ofApp::draw()
{	
    cam.begin();
    {
	    ofSetColor(255);
    	mesh.drawWireframe();
	}
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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