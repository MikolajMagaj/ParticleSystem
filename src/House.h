#ifndef House_H
#define House_H

#include "ofMain.h"
#include "v3.h"
#include "Object.h"

class House : public Object
{
private:
	ofMaterial material1;
	ofMaterial material2;
	ofMaterial material3;
	ofMaterial material4;

	ofBoxPrimitive box1;
	ofBoxPrimitive box11;
	ofBoxPrimitive box111;
	ofBoxPrimitive box1111;
	ofBoxPrimitive box11111;
	ofBoxPrimitive box2;
	ofBoxPrimitive box3;
	ofBoxPrimitive box33;

	ofConePrimitive cone1;

public:
	House(v3 posvec);
	virtual ~House();

	void draw() override;
};

#endif