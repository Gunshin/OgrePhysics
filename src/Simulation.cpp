#include "Simulation.h"
#include "MyUtils.h"

#include <string>
#include <iostream>
#include <sstream>

using namespace util;

const float PI = 3.1415967;

Simulation::Simulation() 
{
	initial_position = Ogre::Vector3(0.0f, 0.0f, 0.0f); 
	initial_velocity = Ogre::Vector3(0.0f, 0.0f, 0.0f); 
	initial_angle = 0.0f;
	total_time = 0.0f;
}

Simulation::~Simulation()
{
}

void Simulation::InitilaiseScene(OgreApplication* application_)
{
	application_->CreateScene();
	application_->SetEntityColour("RED", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, Ogre::ColourValue(1.0f, 0.1f, 0.1f), Ogre::ColourValue(0.6f, 0.0f, 0.0f), 100.0f);
	application_->SetEntityColour("GREEN", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, Ogre::ColourValue(0.1f, 0.8f, 0.1f), Ogre::ColourValue(0.0f, 0.6f, 0.0f), 50.0f);
	
	// Load missile
	auto missile = application_->GetSceneManager()->createEntity("sphere.mesh");
	missile->setCastShadows(false);
	missile->setMaterialName("RED");

	initial_angle = 80.0f*PI / 180.0f;
	initial_position = Ogre::Vector3(0.0f, 5.0f, 0.0f);
	initial_velocity = Ogre::Vector3(-24.5f*cos(initial_angle), 24.5f*sin(initial_angle), 0.0f);
	
	missileNode.reset( application_->GetSceneManager()->getRootSceneNode()->createChildSceneNode("missile "));
	missileNode->setScale(Ogre::Vector3(0.01f, 0.01f, 0.01f));
	missileNode->setPosition(initial_position);
	missileNode->attachObject(missile);

}

void Simulation::Reset()
{
}

void Simulation::UpdateSimulation(float dt)
{
	// Implement projectile motion here ..... 
	printf("running\n");

	total_time += dt;
	//float t = (2.0f * sin(initial_angle) * initial_velocity.length()) / 9.81f;

	Ogre::Vector3 newPosition = Ogre::Vector3();
	newPosition.x = initial_position.x + initial_velocity.x * total_time;
	newPosition.y = initial_position.y + initial_velocity.y - 0.5 * 9.81f * pow(total_time, 2);
	newPosition.z = initial_position.z + initial_velocity.z * total_time;

	if (newPosition.y<5.0f) newPosition.y = 5.0f;

	missileNode->setPosition(newPosition);

}

void Simulation::UpdateOgre(Ogre::Vector3 &pos, Ogre::Quaternion &q)
{
	// show updated position in Ogre
}

void Simulation::Update(float dt)
{
	UpdateSimulation(dt);

}