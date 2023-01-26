#include "ofApp.h"
#include <cmath>
#include <random>
#include "Collection.h"

//--------------------------------------------------------------
void ofApp::setup() {
	m_image.load("D:/OpenFrameworks/apps/myApps/particleSystem/src/plane.png");

	plane.set(1000, 1000); 
	plane.rotateDeg(270, 1, 0, 0);
	plane.move(0, 0, 0);
	plane.mapTexCoords(0, 0, m_image.getWidth(), m_image.getHeight());
	this->collection.push_back(new Collection());

	ofEnableLighting();
	ofEnableDepthTest();
	
	light.setup();
	light.enable();
	light.setPosition(-200, 200, 200);

}

//--------------------------------------------------------------
void ofApp::update() {

	for (auto* collect : this->collection)
	{
		collect->collectionUpdate();
		collect->particleUpdate();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	cam.begin();
	ofEnableLighting();
	m_image.getTexture().bind();
		plane.draw();
	m_image.getTexture().unbind();


	for (auto* collect : this->collection)
	{
		collect->draw();
	}
	ofDisableLighting();
	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}