#include "Pomehi.h"
const char* localee[] = {
	"resources\\2.png",
	"resources\\3.png",
	"resources\\4.png",
	"resources\\5.png",
	"resources\\6.png",
	"resources\\7.png",
	"resources\\8.png",
	"resources\\9.png"
};
Pomehi::Pomehi()
{

}
void Pomehi::load()
{
	for (int i = 0; i < 8; i++)
	{
		pomehi[i].loadFromFile(localee[i]);
	}
}
void Pomehi::draw(RenderWindow& window)
{
	Color color(255, 255, 255, 55);
	poomehi.setTexture(pomehi[anim]);
	poomehi.setColor(color);
	poomehi.setScale(2, 2);
	window.draw(poomehi);
	if (anim + 1 >= 8)
		anim = 0;
	else
		anim++;
}