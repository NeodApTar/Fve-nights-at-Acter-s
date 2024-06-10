#pragma once
#include "GUI.h"
#include "Camera.h"
#include "AIbase.h"
class game
{
	friend class AIbase;
	GUI office{ "resources\\room.jpg",false,1920 / 1600.0,1080 / 720.0,0,0 };
	GUI officell{ "resources\\roomrl.jpg",false,1920 / 1600.0,1080 / 720.0,0,0 };
	GUI officerl{ "resources\\roomll.jpg",false,1920 / 1600.0,1080 / 720.0,0,0 };
	GUI officeUsya{ "resources\\roomusya.jpg",false,1920 / 1600.0,1080 / 720.0,0,0 };
	GUI officeAktep{ "resources\\roomakter.jpg",false,1920 / 1600.0,1080 / 720.0,0,0 };
	
	 GUI officepower{ "resources\\roompower.png",false,1920 / 1600.0,1080 / 720.0,0,0 };

	 GUI officepoweraktep{ "resources\\roompoweraktep.jpg",false,1920 / 1600.0,1080 / 720.0,0,0 };
	
	 
	 GUI buttomdown{ "resources\\buttondown.png",false,1,1,400,980 };

	GUI doorl[14];
	GUI doorr[14];

	GUI buttonl{ "resources\\buttonl.png",false,1,1,20,480 };
	GUI buttonr{ "resources\\buttonr.png",false,1,1,1790,480 };

	GUI buttonld{ "resources\\buttond.png",false,1,1,20,480 };
	GUI buttonrd{ "resources\\buttonrd.png",false,1,1,1790,480 };

	GUI buttonll{ "resources\\buttonll.png",false,1,1,20,480 };
	GUI buttonrl{ "resources\\buttonrl.png",false,1,1,1790,480 };

	GUI buttonlld{ "resources\\buttonld.png",false,1,1,20,480 };
	GUI buttonrld{ "resources\\buttonrld.png",false,1,1,1790,480 };

	static bool InCamera;
	Clock clockcamera;

	bool boolld = 0, boolll = 0, boolrd = 0, boolrl = 0, boollld = 0, boollrdl = 0;
	
	bool rightdoor = 0, leftdoor = 0;
	Clock clockdl;
	Clock clockdr;
	Clock clockb1;
	Clock clockb2;
	Clock clockb3;
	Clock clockb4;

	int level = 1;

public:

	void load();
	void game_run(RenderWindow& window);
	
};
