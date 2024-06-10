#pragma once
#include "AIbase.h"
class Aktep : public AIbase
{
	friend class Camera;
int KameriAktepMojet[10]{ 2,3,4,5,6,7,8,10,12,1 };
public:
	Aktep();

	Aktep(int diff);
	virtual void Move();

	virtual void Napugali();
	virtual bool CanWeReadyToAttack();
	static int cameraon;
	bool CanWeReadyToAttacker = 0;

};