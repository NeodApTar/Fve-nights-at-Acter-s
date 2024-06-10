#include "Usya.h"
int Usya::cameraon = 1;
Usya::Usya()
{
	onCamera = 1;

}
Usya::Usya(int diff)
{
	onCamera = 1;
	AIdifficult = diff;
}
bool Usya::CanWeReadyToAttack()
{
	cameraon = onCamera;
	int ch = rand() % 10;
	if (onCamera == 11 && ch == 5 && CanWeReadyToAttacker == 0)
		CanWeReadyToAttacker = 1;
	if (onCamera != 11)
		CanWeReadyToAttacker = 0;
	return 0;
}
 void Usya::Move()
{
	if (chance())
	{
		scary = 0;
		if (onCamera == 1)
			onCamera = 10;
		else if (onCamera == 10)
			onCamera = 3;
		else if (onCamera == 3)
			onCamera = 4;
		else if (onCamera == 4)
			onCamera = 9;
		else if (onCamera == 9)
			onCamera = 11;
		


	}
	if (chanceToPrev())
	{
		scary = 0;
		if (onCamera == 11)
			onCamera = 9;
		else if (onCamera == 9)
			onCamera = 4;
		else if (onCamera == 4)
			onCamera = 3;
		else if (onCamera == 3)
			onCamera = 10;
		else if (onCamera == 9)
			onCamera = 1;
	}
	
}
 void Usya::Napugali()
{
	int camera = rand() % 6;
	onCamera = KameriUsyaMojet[camera];
}