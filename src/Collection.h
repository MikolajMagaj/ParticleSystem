#ifndef COLLECTION_H
#define COLLECTION_H

#include "Emitter.h"
#include "Particle.h"
#include "ForcePoint.h"
#include "ForceWind.h"
#include "Object.h"
#include "Gift.h"
#include "Tree.h"
#include "Fireplace.h"
#include "House.h"



class Collection
{
private:
	std::vector<Emitter*> emitter;
	std::vector<Particle*> particle;
	std::vector<ForcePoint*> forcepoint;
	std::vector<ForceWind*> wind;
	std::vector<Object*> object;

public:
	Collection();
	virtual ~Collection();

	void addEmitter(v3 posvec, string name);
	//void deleteEmitter();

	void addPoint(v3 posvec, float force);
	//void deletePoint();

	void addWind(v3 posvec, v3 fvec, float force);
	//void deleteWind();

	void addObject(v3 posvec, int value);
	//void deleteObject();

	void collectionUpdate();
	void particleUpdate();

	void draw();
};

#endif