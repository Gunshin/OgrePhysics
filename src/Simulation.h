#ifndef _OGRE_WORLD_H_
#define _OGRE_WORLD_H_

#include "stdafx.h"
#include <iostream>
#include "OgreApplication.h"

class Simulation
{
private:
										
	void UpdateSimulation(float dt);
	void UpdateOgre(Ogre::Vector3 &pos, Ogre::Quaternion &q);
	
	std::shared_ptr<Ogre::SceneNode> missileNode;
	Ogre::Vector3 initial_position;
	Ogre::Vector3 initial_velocity;
	float initial_angle;
	float total_time;

public:

	Simulation();
	~Simulation();
										
	void InitilaiseScene(OgreApplication* application_);								
	void Update(float dt);
	void Reset();

};

#endif
