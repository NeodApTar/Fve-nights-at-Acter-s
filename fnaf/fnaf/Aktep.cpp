#include "Aktep.h"
int Aktep::cameraon = 1;

Aktep::Aktep()
{
	onCamera = 1;
}
Aktep::Aktep(int diff)
{
	onCamera = 1;
	AIdifficult = diff;
}
void Aktep::Move()
{
	if (chance())
	{
		scary = 0;
		if (onCamera == 1)
			onCamera = 10;
		else if (onCamera == 10)
			onCamera = 2;
		else if (onCamera == 2)
			onCamera = 4;
		else if (onCamera == 4)
			onCamera = 6;
		else if (onCamera == 6)
			onCamera = 5;
		else if (onCamera == 5)
			onCamera = 8;
		else if (onCamera == 8)
			onCamera = 7;
		else if (onCamera == 7)
			onCamera = 3;
		else if (onCamera == 3)
			onCamera = 12;
	

	}
	if (chanceToPrev())
	{
		scary = 0;
		if (onCamera == 12)
			onCamera = 3;
		else if (onCamera == 3)
			onCamera = 7;
		else if (onCamera == 7)
			onCamera = 8;
		else if (onCamera == 8)
			onCamera = 5;
		else if (onCamera == 5)
			onCamera = 6;
		else if (onCamera == 6)
			onCamera = 4;
		else if (onCamera == 5)
			onCamera = 2;
		else if (onCamera == 2)
			onCamera = 10;
		else if (onCamera == 10)
			onCamera = 1;
	}
	cameraon = onCamera;
}
void Aktep::Napugali()
{
	int camera = rand() % 10;
	onCamera = KameriAktepMojet[camera];
}
bool Aktep::CanWeReadyToAttack()
{
	cameraon = onCamera;
	int ch = rand() % 10;
	if (onCamera == 12 && ch == 5 && CanWeReadyToAttacker == 0)
		CanWeReadyToAttacker = 1;
	if (onCamera != 12)
		CanWeReadyToAttacker = 0;
	return 0;
}