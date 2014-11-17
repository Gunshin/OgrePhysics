#include "MyUtils.h"

namespace util
{
	//*** Exerise 3: define your reusable utility functions here
	Ogre::Matrix3 RotationMatrixXYZ(Ogre::Vector3&  orientation)
	{
		Ogre::Matrix3 rotateX, rotateY, rotateZ;
		const float angleX = orientation.x;
		const float angleY = orientation.y;
		const float angleZ = orientation.z;

        
		rotateX = Ogre::Matrix3(
			1.0, 0.0, 0.0,
			0.0, std::cos(angleX), -std::sin(angleX),
			0.0, std::sin(angleX), std::cos(angleX)
			);

		rotateY = Ogre::Matrix3(
			std::cos(angleY), 0.0, std::sin(angleY),
			0.0, 1.0, 0.0,
			-std::sin(angleY), 0.0, std::cos(angleY)
			);

		rotateZ = Ogre::Matrix3(
			std::cos(angleZ), -std::sin(angleZ), 0.0,
			std::sin(angleZ),  std::cos(angleZ), 0.0,
			0.0, 0.0, 1.0
			);

		Ogre::Matrix3 rotation = rotateZ*rotateY*rotateX;
		
		return rotation;
	}


}