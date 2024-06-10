#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Pomehi
{
	Texture pomehi[8];

	Sprite poomehi;
	int anim = 0;
	

public:
	Pomehi();
	
	void load();
	
	void draw(RenderWindow& window);
	
};