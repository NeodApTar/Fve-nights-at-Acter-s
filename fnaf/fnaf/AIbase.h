#pragma once
#include <iostream>
#include "Game.h"
using namespace std;

class AIbase
{
	friend class Usya;
	friend class Aktep;
	int onCamera = 0;
	int AIdifficult = -1;
	bool scary = 0;
	bool CanWeAttack();
	bool chance();
	bool chanceToPrev();
	virtual void Move() = 0;
	virtual void Napugali() = 0;
	virtual bool CanWeReadyToAttack() = 0;
public:
	int getOnCamera();
	void chanceOfScary();
	
	bool GetScary();
	
	void reset();

	void setDifficult(int diff);
};