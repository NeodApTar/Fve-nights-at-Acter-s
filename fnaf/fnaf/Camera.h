#pragma once
#include "GUI.h"
#include "Pomehi.h"

class Camera
{
	int cameraactive = 1;
	Sprite camera;
	Image imga;

	Clock clock1;
	Texture camerasanim[8];
	GUI buttomdown{ "resources\\buttondown.png",false,1,1,400,980 };
	GUI ca01{"resources\\cabutton (1).png",true,2,2,1400,800}, 
		ca02{ "resources\\cabutton (2).png",true,2,2,1500,800 }, 
		ca03{ "resources\\cabutton (3).png",true,2,2,1600,800 },
		ca04{ "resources\\cabutton (4).png",true,2,2,1700,800 }, 
		ca05{ "resources\\cabutton (5).png",true,2,2,1800,800 },
		ca06{ "resources\\cabutton (6).png",true,2,2,1400,900 },
		ca07{ "resources\\cabutton (7).png",true,2,2,1500,900 },
		ca08{ "resources\\cabutton (8).png",true,2,2,1600,900 },
		ca09{ "resources\\cabutton (9).png",true,2,2,1700,900 },
		ca10{ "resources\\cabutton (10).png",true,2,2,1400,1000 },
		ca11{ "resources\\cabutton (11).png",true,2,2,1500,1000 },
		ca12{ "resources\\cabutton (12).png",true,2,2,1600,1000 };
	
	
	

	GUI caroom01{ "resources\\camera13_1.jpg",false,1920/1559.0,1080/992.0,0,0 },
		caroom02{ "resources\\camera1.png",false,1920 / 1024.0,1080 / 768.0,0,0 }, 
		caroom03{ "resources\\camera2.png",false,1920 / 1600.0,1080 / 720.0,0,0 }, 
		caroom04{ "resources\\camera3.png",false,1920 / 1024.0,1080 / 768.0,0,0 },
		caroom05{ "resources\\camera4.png",false,1920 / 1600.0,1080 / 720.0,0,0 },
		caroom06{ "resources\\camera5.png",false,1920 / 1600.0,1080 / 720.0,0,0 },
		caroom07{ "resources\\camera6.jpg",false,1920 / 1000.0,1080 / 450.0,0,0 },
		caroom08{ "resources\\camera7.png",false,1920 / 1600.0,1080 / 720.0,0,0 },
		caroom09{ "resources\\camera8.png",false,1920 / 1600.0,1080 / 720.0,0,0 },
		caroom10{ "resources\\camera9.png",false,1920 / 1600.0,1080 / 720.0,0,0 },
		caroom11{ "resources\\camera10.png",false,1920 / 1600.0,1080 / 720.0,0,0 },
		caroom12{ "resources\\camera11.png",false,1920 / 1600.0,1080 / 720.0,0,0 };


	GUI caroom101{ "resources\\camera13_2.jpg",false,1920 / 1559.0,1080 / 992.0,0,0 }, 
		caroom102{ "resources\\camera1_1.jpg",false,1920 / 1559.0,1080 / 992.0,0,0 }, 
		caroom103{ "resources\\camera2_1.jpg",false,1920 / 1396.0,1080 / 637.0,0,0 }, 
		caroom104{ "resources\\camera3_1.jpg",false,1920 / 1559.0,1080 / 992.0,0,0 }, 
		caroom105{ "resources\\camera4_1.jpg",false,1920 / 1559.0,1080 / 992.0,0,0 }, 
		caroom106{ "resources\\camera5_1.jpg",false,1920 / 1559.0,1080 / 992.0,0,0 }, 
		caroom107{ "resources\\camera6_2.jpg",false,1920 / 1276.0,1080 / 581.0,0,0 }, 
		caroom108{ "resources\\camera7_1.jpg",false,1920 / 1000.0,1080 / 450.0,0,0 }, 
		caroom109{ "resources\\camera8_1.jpg",false,1920 / 1559.0,1080 / 992.0,0,0 },
		caroom110{ "resources\\camera9_1.jpg",false,1920 / 1559.0,1080 / 992.0,0,0 }, 
		caroom111{ "resources\\camera10_1.jpg",false,1920 / 1559.0,1080 / 992.0,0,0 }, 
		caroom112{ "resources\\camera11_1.jpg",false,1920 / 1559.0,1080 / 992.0,0,0 };
	
	
	GUI caroom201{ "resources\\camera13_3.jpg",false,1920 / 1559.0,1080 / 992.0,0,0 }, 
		caroom203{ "resources\\camera2_2.jpg",false,1920 / 1551.0,1080 / 850.0,0,0 }, 
		caroom205{ "resources\\camera4_2.jpg",false,1920 / 1559.0,1080 / 992.0,0,0 }, 
		caroom212{ "resources\\camera11_2.jpg",false,1920 / 1559.0,1080 / 992.0,0,0 };


	GUI caroom301{ "resources\\camera13_4.jpg",false,1920 / 1559.0,1080 / 992.0,0,0 },
		caroom401{ "resources\\camera13_5.jpg",false,1920 / 1559.0,1080 / 992.0,0,0 },
		caroom501{ "resources\\camera13_6.jpg",false,1920 / 1559.0,1080 / 992.0,0,0 },
		caroom601{ "resources\\camera13_7.jpg",false,1920 / 1559.0,1080 / 992.0,0,0 },
		caroom701{ "resources\\camera13.png",false,1920 / 1600.0,1080 / 720.0,0,0 },
		caroom303{ "resources\\camera2_3.jpg",false,1920 / 1559.0,1080 / 992.0,0,0 },
		caroom403{ "resources\\camera2_4.jpg",false,1920 / 1559.0,1080 / 992.0,0,0 };

public:
	void load();
	
	void run(RenderWindow& window, int batkill, Text& bat, Text& time, int& procents, Clock& batclock, Clock& clockwin);
	
};