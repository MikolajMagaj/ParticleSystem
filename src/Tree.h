#ifndef Tree_H
#define Tree_H

#include "ofMain.h"
#include "v3.h"
#include "Object.h"


class Tree: public Object 
{
private:
	ofMaterial material1;
	ofMaterial material2;
	ofConePrimitive cone1;
	ofConePrimitive cone2;
	ofConePrimitive cone3;
	ofCylinderPrimitive cylinder1;

public:
	Tree(v3 posvec);
	virtual ~Tree();

	void draw();
};

#endif