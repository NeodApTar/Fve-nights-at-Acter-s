#pragma once
#include "AIbase.h"
class Usya : public AIbase
{
	friend class Camera;
	int KameriUsyaMojet[6]{ 1,10,3,4,9,11 };
public:
	Usya();
	
	Usya(int diff);
	virtual void Move();
	
	virtual void Napugali();
	virtual bool CanWeReadyToAttack();
	static int cameraon;
	bool CanWeReadyToAttacker = 0;
};