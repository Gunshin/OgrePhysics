#pragma once
#include "stdafx.h"
//#include "Ogre.h"
//#include "Ois.h"
#include <memory>

using namespace std;

class Camera
{
private:

	shared_ptr<Ogre::SceneNode> sceneNode;
	shared_ptr<Ogre::MovableObject> camera;

	Ogre::Vector3 rotation;

public:
	Camera(shared_ptr<Ogre::SceneNode> sceneNode, shared_ptr<Ogre::MovableObject> camera);
	~Camera() {};

	void Update(OIS::Keyboard* keyboard, OIS::Mouse* mouse);
};