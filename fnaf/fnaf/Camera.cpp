#include "Camera.h"
#include "Usya.h"
#include "Aktep.h"
#include "SFML/Audio.hpp"
const char* localee1[] = {
	"resources\\camera (1).png",
	"resources\\camera (2).png",
	"resources\\camera (3).png",
	"resources\\camera (4).png",
	"resources\\camera (5).png",
	"resources\\camera (6).png",
	"resources\\camera (7).png"
};
void Camera::load()
{
	for (int i = 0; i < 7; i++)
	{
		camerasanim[i].loadFromFile(localee1[i]);
	}
	imga.loadFromFile(localee1[6]);
	imga.createMaskFromColor(imga.getPixel(50, 50));
	camerasanim[7].loadFromImage(imga);
}
void Camera::run(RenderWindow& window,int batkill,Text& bat,Text& time,int& procents,Clock& batclock,Clock& clockwin)
{
	Pomehi pomehi;
	pomehi.load();
	int ii = 0;
	Vector2f mousef;
	Vector2i mouse;
	SoundBuffer click;
	SoundBuffer rec;
	SoundBuffer cameraoff;
	cameraoff.loadFromFile("resources\\put down.ogg");
	click.loadFromFile("resources\\blip.ogg");
	rec.loadFromFile("resources\\camera.ogg");

	Sound clickcamera{ click };
	Sound record{ rec };
	Sound offcamera{ cameraoff };
	int flag = 0;
	batkill -= 5;
	record.play();
	while (ii < 7)
	{
		if (clock1.getElapsedTime().asMilliseconds() > 26)
		{
			camera.setTexture(camerasanim[ii]);
			camera.setScale(1920 / 1024.0, 1080 / 768.0);
			window.draw(camera);
			window.display();
			ii++;
			clock1.restart();
		}
	}
	camera.setTexture(camerasanim[7]);
	while (window.isOpen())
	{

		if (clockwin.getElapsedTime().asSeconds() > 360)
			return;
		if (clockwin.getElapsedTime().asSeconds() >= 60 && clockwin.getElapsedTime().asSeconds() < 120)
			time.setString("1 A.M");
		else if (clockwin.getElapsedTime().asSeconds() >= 120 && clockwin.getElapsedTime().asSeconds() < 180)
			time.setString("2 A.M");
		else if (clockwin.getElapsedTime().asSeconds() >= 180 && clockwin.getElapsedTime().asSeconds() < 240)
			time.setString("3 A.M");
		else if (clockwin.getElapsedTime().asSeconds() >= 240 && clockwin.getElapsedTime().asSeconds() < 300)
			time.setString("4 A.M");
		else if (clockwin.getElapsedTime().asSeconds() >= 300 && clockwin.getElapsedTime().asSeconds() < 360)
			time.setString("5 A.M");
		if (batclock.getElapsedTime().asSeconds() > batkill)
		{
			procents--;
			bat.setString(to_string(procents) + "%");
			batclock.restart();
		}

		mouse = sf::Mouse::getPosition(window);
		mousef.x = mouse.x;
		mousef.y = mouse.y;
		Vector2f worldPos = window.mapPixelToCoords(mouse);
		FloatRect mouses(mousef, Vector2f(10, 10));
		if (buttomdown.checkint(mouses))
		{

			break;
			//camera
		}

		sf::Event event;
		window.pollEvent(event);
		if (event.type == sf::Event::Closed)
			window.close();
		if (ca01.checkint(mouses) && Mouse::isButtonPressed(Mouse::Left))
		{
			cameraactive = 1;
			clickcamera.play();
		}
		if (ca02.checkint(mouses) && Mouse::isButtonPressed(Mouse::Left))
		{
			cameraactive = 2;
			clickcamera.play();
		}
		if (ca03.checkint(mouses) && Mouse::isButtonPressed(Mouse::Left))
		{
			cameraactive = 3;
			clickcamera.play();
		}
		if (ca04.checkint(mouses) && Mouse::isButtonPressed(Mouse::Left))
		{
			cameraactive = 4;
			clickcamera.play();
		}
		if (ca05.checkint(mouses) && Mouse::isButtonPressed(Mouse::Left))
		{
			cameraactive = 5;
			clickcamera.play();
		}
		if (ca06.checkint(mouses) && Mouse::isButtonPressed(Mouse::Left))
			{
			cameraactive = 6;
			clickcamera.play();
		}
		if (ca07.checkint(mouses) && Mouse::isButtonPressed(Mouse::Left))
		{
			cameraactive = 7;
			clickcamera.play();
		}
		if (ca08.checkint(mouses) && Mouse::isButtonPressed(Mouse::Left))
		{
			cameraactive = 8;
			clickcamera.play();
		}
		if (ca09.checkint(mouses) && Mouse::isButtonPressed(Mouse::Left))
		{
			cameraactive = 9;
			clickcamera.play();
		}
		if (ca10.checkint(mouses) && Mouse::isButtonPressed(Mouse::Left))
		{
			cameraactive = 10;
			clickcamera.play();
		}
		if (ca11.checkint(mouses) && Mouse::isButtonPressed(Mouse::Left))
		{
			cameraactive = 11;
			clickcamera.play();
		}
		if (ca12.checkint(mouses) && Mouse::isButtonPressed(Mouse::Left))
		{
			cameraactive = 12;
			clickcamera.play();
		}

		window.clear(Color::Black);
		if (cameraactive == 1) {
			if (Usya::cameraon == 1 && Aktep::cameraon == 1)
				caroom01.draw(window);
			if (Usya::cameraon != 1 && Aktep::cameraon != 1)
				caroom401.draw(window);
			if (Usya::cameraon == 1 && Aktep::cameraon != 1)
				caroom101.draw(window);
			if (Usya::cameraon != 1 && Aktep::cameraon == 1)
				caroom201.draw(window);
		}
		if (cameraactive == 2) {
		if (Usya::cameraon != 2 && Aktep::cameraon != 2)
			caroom02.draw(window);
		if (Usya::cameraon == 2 || Aktep::cameraon == 2)
			caroom102.draw(window);
		}
		if (cameraactive == 3)
		{
			if (Usya::cameraon != 3 && Aktep::cameraon != 3)
			caroom03.draw(window);
			if (Usya::cameraon != 3 && Aktep::cameraon == 3)
				caroom203.draw(window);
			
			if (Usya::cameraon == 3 && Aktep::cameraon != 3 )
				caroom303.draw(window);
			if (Usya::cameraon == 3 || Aktep::cameraon == 3)
				caroom403.draw(window);
		}
		if (cameraactive == 4)
		{
			if(Usya::cameraon != 4 && Aktep::cameraon != 4)
			caroom04.draw(window);
			if (Usya::cameraon == 4 || Aktep::cameraon == 4)
				caroom104.draw(window);
		}
		if (cameraactive == 5)
		{
			if (Usya::cameraon != 5 && Aktep::cameraon != 5)
				caroom05.draw(window);
			if (Usya::cameraon != 5 && Aktep::cameraon == 5)
				caroom105.draw(window);
		}
		if (cameraactive == 6)
		{
			if (Usya::cameraon != 6 && Aktep::cameraon != 6)
				caroom06.draw(window);
			if (Usya::cameraon != 6 && Aktep::cameraon == 6)
				caroom106.draw(window);
		}
		if (cameraactive == 7)
		{
			if (Usya::cameraon != 7 && Aktep::cameraon != 7)
				caroom07.draw(window);
			if (Usya::cameraon != 7 && Aktep::cameraon == 7)
				caroom107.draw(window);
		}
		if (cameraactive == 8)
		{
			if (Usya::cameraon != 8 && Aktep::cameraon !=8)
				caroom08.draw(window);
			if (Usya::cameraon != 8 && Aktep::cameraon == 8)
				caroom108.draw(window);
		}
		if (cameraactive == 9)
		{
			if (Usya::cameraon != 9 && Aktep::cameraon != 9)
				caroom09.draw(window);
			if (Usya::cameraon == 9 && Aktep::cameraon != 9)
				caroom109.draw(window);
		}
		if (cameraactive == 10)
		{
			if (Usya::cameraon != 10 && Aktep::cameraon != 10)
				caroom10.draw(window);
			if (Usya::cameraon == 10 || Aktep::cameraon == 10)
				caroom110.draw(window);
		}
		if (cameraactive == 11)
		{
			if (Usya::cameraon != 11 && Aktep::cameraon != 11)
				caroom11.draw(window);
			if (Usya::cameraon == 11 && Aktep::cameraon != 11)
				caroom111.draw(window);
		}
		if (cameraactive == 12)
		{
			if (Usya::cameraon !=12 && Aktep::cameraon !=12)
				caroom12.draw(window);
			if (Usya::cameraon != 12 && Aktep::cameraon == 12)
				caroom212.draw(window);
		}
		pomehi.draw(window);

		ca01.draw(window);
		ca02.draw(window);
		ca03.draw(window);
		ca04.draw(window);
		ca05.draw(window);
		ca06.draw(window);
		ca07.draw(window);
		ca08.draw(window);
		ca09.draw(window);
		ca10.draw(window);
		ca11.draw(window);
		ca12.draw(window);
		window.draw(time);
		window.draw(bat);
		window.display();
		if (procents <= 0)
			return;
	}
	offcamera.play();
	while (ii >= 0)
	{
		if (clock1.getElapsedTime().asMilliseconds() > 26)
		{
			camera.setTexture(camerasanim[ii]);
			camera.setScale(1920 / 1024.0, 1080 / 768.0);
			window.draw(camera);
			window.display();
			ii--;
			clock1.restart();
		}
	}

}