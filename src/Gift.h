#ifndef Gift_H
#define Gift_H

#include "ofMain.h"
#include "v3.h"
#include "Object.h"

class Gift : public Object
{
private:
	ofMaterial material1;
	ofMaterial material2;
	ofMaterial material3;

	ofBoxPrimitive box1;
	ofBoxPrimitive box2;
	ofBoxPrimitive box3;

public:
	Gift(v3 posvec);
	virtual ~Gift();

	void draw() override;
};

#endif