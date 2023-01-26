#ifndef Fireplace_H
#define Fireplace_H

#include "ofMain.h"
#include "v3.h"
#include "Object.h"


class Fireplace : public Object
{
private:
	ofMaterial material1;
	ofMaterial material2;
	std::vector<ofCylinderPrimitive*> cylinder;
	std::vector<ofIcoSpherePrimitive*> sphere;

public:
	Fireplace(v3 posvec);
	virtual ~Fireplace();

	void draw();
};

#endif