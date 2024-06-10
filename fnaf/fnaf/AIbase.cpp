#include "AIbase.h"
bool AIbase::CanWeAttack()
{
	return game::InCamera;
}
bool AIbase::chance()
{
	int chance = rand() % 20;
	if (chance < AIdifficult)
		return 1;
	return 0;
}
int AIbase::getOnCamera()
{
	return onCamera;
}
bool AIbase::chanceToPrev()
{
	int chance = rand() % 5000;
	if (chance < 20)
		return 1;
	return 0;
}
void AIbase::chanceOfScary()
{
	int chance = rand() % 50;
	if (chance < 20)
		scary = 1;
}
bool AIbase::GetScary()
{
	return scary;
}
void AIbase::reset()
{
	AIdifficult = -1;
	onCamera = 1;
}
void AIbase::setDifficult(int diff)
{
	AIdifficult = diff;
}