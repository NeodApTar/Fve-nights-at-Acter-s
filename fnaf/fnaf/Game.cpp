#include "Game.h"
#include "Usya.h"
#include "Aktep.h"
#include "Screamer.h"
#include "Win.h"
bool game::InCamera = false;
void game::load()
{
	for (int i = 1; i < 15; i++)
	{
		doorl[i - 1].Load("resources\\doorl (" + to_string(i) + ").png", false, 1.1, 1.5, 120, 100);
		doorr[i - 1].Load("resources\\rorr (" + to_string(i) + ").png", false, 1.1, 1.5, 1510,100);
	}
}
void game::game_run(RenderWindow& window)
{
	Camera camera;
	Music music;
	SoundBuffer scar;


	SoundBuffer power;
	power.loadFromFile("resources\\powerdown.ogg");
	Sound Power{ power };

	SoundBuffer door;
	door.loadFromFile("resources\\door.ogg");
	Sound Door{door };


	SoundBuffer box;
	box.loadFromFile("resources\\music-box.ogg");
	Sound Box{ box };

	scar.loadFromFile("resources\\windowscare.ogg");
	Sound scary{ scar };
	music.openFromFile("resources\\music1.ogg");
	music.play();
	Win win;
	Screamer1 scream;
	Screamer2 scream2;
	camera.load();
	Aktep aktep(5);
	Usya usya(-1);
	load();
	Vector2f mousef;
	Vector2i mouse;
	int lookl = 0;
	int lookr = 0;
	View viev(Vector2f(1920 / 2, 1080 / 2), Vector2f(1500, 1080));
	View vievnormal(Vector2f(1920 / 2, 1080 / 2), Vector2f(1920, 1080));
	FloatRect ld(Vector2f(40, 530), Vector2f(50, 50));
	FloatRect ll(Vector2f(40, 620), Vector2f(50, 50));
	FloatRect rd(Vector2f(1790, 520), Vector2f(50, 50));
	FloatRect rl(Vector2f(1790, 610), Vector2f(50, 50));
	Clock clockToMove;
	Clock clockToWait;
	Clock clockwin;
	
	Font font;
	font.loadFromFile("resources\\1.ttf");
	Text time;
	Text bat;
	bat.setFont(font);
	bat.setString("100%");
	int procents = 10;
	bat.setPosition(30, 920);
	int batkill = 20;
	Clock batclock;
	time.setFont(font);
	time.setString("12 A.M");
	time.setPosition(1750, 100);
	Clock clocktoloose;
	int flag = 0;
	Clock clockl1;
	Clock clockl2;
	while (window.isOpen())
	{
		if (procents <= 0)
		{
			clocktoloose.restart();
			Power.play();
			while (clocktoloose.getElapsedTime().asSeconds() < 5)
			{
				mouse = sf::Mouse::getPosition(window);
				mousef.x = mouse.x;
				mousef.y = mouse.y;
				Vector2f worldPos = window.mapPixelToCoords(mouse);
				FloatRect mouses(mousef, Vector2f(10, 10));

				if (mouses.intersects(FloatRect(0, 0, 50, 1080)) && viev.getCenter().x > 760)
				{
					/*buttomdown.SetMove(-10, 0);*/
					viev.move(-10, 0);
				}
				if (mouses.intersects(FloatRect(1870, 0, 50, 1080)) && viev.getCenter().x < 1170)
				{

					/*buttomdown.SetMove(10, 0);*/
					viev.move(10, 0);
				}
				window.setView(viev);
				officepower.draw(window);
				window.display();
			}
			Box.play();
			music.stop();
			clockl2.restart();
			while (clocktoloose.getElapsedTime().asSeconds() < 20&& clocktoloose.getElapsedTime().asSeconds()>5)
			{
				mouse = sf::Mouse::getPosition(window);
				mousef.x = mouse.x;
				mousef.y = mouse.y;
				Vector2f worldPos = window.mapPixelToCoords(mouse);
				FloatRect mouses(mousef, Vector2f(10, 10));

				if (mouses.intersects(FloatRect(0, 0, 50, 1080)) && viev.getCenter().x > 760)
				{
					/*buttomdown.SetMove(-10, 0);*/
					viev.move(-10, 0);
				}
				if (mouses.intersects(FloatRect(1870, 0, 50, 1080)) && viev.getCenter().x < 1170)
				{

					/*buttomdown.SetMove(10, 0);*/
					viev.move(10, 0);
				}
				window.setView(viev);
				window.clear();
					officepower.draw(window);
					
					
				
				if (clockl2.getElapsedTime().asMilliseconds()>56)
				{
					officepoweraktep.draw(window);
					clockl2.restart();
				}
				window.display();
			}
			Box.pause();
			scream.play(window);
			aktep.reset();
			usya.reset();
			boolld = 0;
			boolll = 0;
			boollld = 0;
			boollrdl = 0;
			boolrd = 0;
			boolrl = 0;
			rightdoor = 0;
			leftdoor = 0;
			batkill = 20;
			bat.setString("100%");
			procents = 100;
			time.setString("12 A.M");
			clockwin.restart();
			music.play();
		}

		if (clockwin.getElapsedTime().asSeconds() > 360)
		{
			win.play(window);
			clockwin.restart();
			usya.reset();
			aktep.reset();
			boolld = 0;
			boolll = 0;
			boollld = 0;
			boollrdl = 0;
			boolrd = 0;
			boolrl = 0;
			music.stop();
			music.play();
			rightdoor = 0;
			leftdoor = 0;
			level++;
			batkill = 20;
			bat.setString("100%");
			procents = 100;
			time.setString("12 A.M");
			if (level == 2)
			{
				aktep.setDifficult(5);
				usya.setDifficult(5);
			}
			if (level == 3)
			{
				aktep.setDifficult(11);
				usya.setDifficult(7);
			}
			if (level == 4)
			{
				aktep.setDifficult(12);
				usya.setDifficult(12);
			}
			if (level == 5)
			{
				aktep.setDifficult(15);
				usya.setDifficult(15);
			}
			if (level == 6)
				return;
		}
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
		
		
		if (clockToMove.getElapsedTime().asSeconds() > 10)
		{
			usya.Move();
			aktep.Move();
			clockToMove.restart();
		}
		
		
		sf::Event event;
		window.pollEvent(event);
		if (event.type == sf::Event::Closed)
			window.close();
		

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

		if (mouses.intersects(FloatRect(0, 0, 50, 1080)) && viev.getCenter().x > 760)
		{
			/*buttomdown.SetMove(-10, 0);*/
			viev.move(-10, 0);
		}
		if (mouses.intersects(FloatRect(1870, 0, 50, 1080)) && viev.getCenter().x < 1170)
		{

			/*buttomdown.SetMove(10, 0);*/
			viev.move(10, 0);
		}
		if (buttomdown.checkint(mouses) && clockcamera.getElapsedTime().asSeconds() > 0.2)
		{
			InCamera = true;
			if (!leftdoor && InCamera && aktep.CanWeReadyToAttacker)
			{
				scream.play(window);
				aktep.reset();
				usya.reset();
				boolld = 0;
				boolll = 0;
				boollld = 0;
				boollrdl = 0;
				boolrd = 0; music.stop();
				music.play(); rightdoor = 0;
				leftdoor = 0;
				boolrl = 0;
				batkill = 20;
				bat.setString("100%");
				procents = 100;
				time.setString("12 A.M");
				clockwin.restart();
			}
			else if (!rightdoor && InCamera && usya.CanWeReadyToAttacker)
			{
				scream2.play(window);
				usya.reset();
				aktep.reset();
				boolld = 0;
				boolll = 0;
				boollld = 0; rightdoor = 0; music.stop();
				music.play();
				leftdoor = 0;
				boollrdl = 0;
				batkill = 20;
				bat.setString("100%");
				procents = 100;
				boolrd = 0;
				boolrl = 0;
				time.setString("12 A.M");
				
				clockwin.restart();
			}
			camera.run(window,batkill,bat,time,procents,batclock,clockwin);
			InCamera = false;
			clockcamera.restart();
			//camera
		}
		if (ld.intersects(mouses) && Mouse::isButtonPressed(Mouse::Left) && clockb1.getElapsedTime().asSeconds() > 1)
		{
			clockb1.restart();
			boolld = !boolld;
			if (boolld)
				batkill -= 5;
			else
				batkill += 5;
			if (leftdoor == 0)
			{
				int i = 0;
				Door.play();
					while (i < 14)
					{
						if (clockdl.getElapsedTime().asMilliseconds() > 10)
						{
							window.setView(viev);
							office.draw(window);


							doorl[i].draw(window);

							if (boolld || boolll || boolrd || boolrl || boollld || boollrdl)
							{
								if (boolld && boolll)
									boollld = 1;
								else
									boollld = 0;

								if (boolrd && boolrl)
									boollrdl = 1;
								else
									boollrdl = 0;
								if (boollld)
									buttonlld.draw(window);
								if (boollrdl)
									buttonrld.draw(window);
								if (!boollrdl)
								{
									if (boolld)
										buttonld.draw(window);
									if (boolll)
										buttonll.draw(window);
								}
								if (!boollld)
								{
									if (boolrl)
										buttonrl.draw(window);
									if (boolrd)
										buttonrd.draw(window);
								}
							}

							if (!boolld && !boolll && !boollld)
								buttonl.draw(window);
							if (!boolrd && !boolrl && !boollrdl)
								buttonr.draw(window);



							window.setView(vievnormal);
							buttomdown.draw(window);
							window.draw(bat);
							window.draw(time);
							window.display();
							clockdl.restart();
							i++;
						}
					}
				
			}
			else
			{
				int i = 13;
				Door.play();
				while (i >= 0)
				{ 
					if (clockdl.getElapsedTime().asMilliseconds() > 10)
					{
						window.setView(viev);
						office.draw(window);


						doorl[i].draw(window);

						if (boolld || boolll || boolrd || boolrl || boollld || boollrdl)
						{
							if (boolld && boolll)
								boollld = 1;
							else
								boollld = 0;

							if (boolrd && boolrl)
								boollrdl = 1;
							else
								boollrdl = 0;
							if (boollld)
								buttonlld.draw(window);
							if (boollrdl)
								buttonrld.draw(window);
							if (!boollrdl)
							{
								if (boolld)
									buttonld.draw(window);
								if (boolll)
									buttonll.draw(window);
							}
							if (!boollld)
							{
								if (boolrl)
									buttonrl.draw(window);
								if (boolrd)
									buttonrd.draw(window);
							}
						}

						if (!boolld && !boolll && !boollld)
							buttonl.draw(window);
						if (!boolrd && !boolrl && !boollrdl)
							buttonr.draw(window);



						window.setView(vievnormal);
						buttomdown.draw(window);
						window.draw(bat);
						window.draw(time);
						window.display();
						clockdl.restart();
						i--;
					}
				}
					
				
			}
			leftdoor = !leftdoor;
		}
		if (ll.intersects(mouses) && Mouse::isButtonPressed(Mouse::Left) && clockb2.getElapsedTime().asSeconds() > 1&&!boolrl)
		{
			boolll = !boolll;
			clockb2.restart();
			if (boolll)
				batkill -= 5;
			else
				batkill += 5;
		}
		if (rd.intersects(mouses) && Mouse::isButtonPressed(Mouse::Left) && clockb3.getElapsedTime().asSeconds() > 1)
		{
			boolrd = !boolrd;
			clockb3.restart();
			if (boolrd)
				batkill -= 5;
			else
				batkill += 5;
			if (rightdoor == 0)
			{
				Door.play();
				int i = 0;
					while (i<14)
					{
						if (clockdr.getElapsedTime().asMilliseconds() > 10)
						{
							window.setView(viev);
							office.draw(window);


							doorr[i].draw(window);

							if (boolld || boolll || boolrd || boolrl || boollld || boollrdl)
							{
								if (boolld && boolll)
									boollld = 1;
								else
									boollld = 0;

								if (boolrd && boolrl)
									boollrdl = 1;
								else
									boollrdl = 0;
								if (boollld)
									buttonlld.draw(window);
								if (boollrdl)
									buttonrld.draw(window);
								if (!boollrdl)
								{
									if (boolld)
										buttonld.draw(window);
									if (boolll)
										buttonll.draw(window);
								}
								if (!boollld)
								{
									if (boolrl)
										buttonrl.draw(window);
									if (boolrd)
										buttonrd.draw(window);
								}
							}

							if (!boolld && !boolll && !boollld)
								buttonl.draw(window);
							if (!boolrd && !boolrl && !boollrdl)
								buttonr.draw(window);



							window.setView(vievnormal);
							buttomdown.draw(window);
							window.draw(bat);
							window.draw(time);
							window.display();
							clockdr.restart();
							i++;
						}
					}

				
			}
			else
			{
				int i = 13;
				Door.play();
				while (i >= 0)
				{
					if (clockdr.getElapsedTime().asMilliseconds() > 10)
					{
						window.setView(viev);
						office.draw(window);


						doorr[i].draw(window);
						
						if (boolld || boolll || boolrd || boolrl || boollld || boollrdl)
						{
							if (boolld && boolll)
								boollld = 1;
							else
								boollld = 0;

							if (boolrd && boolrl)
								boollrdl = 1;
							else
								boollrdl = 0;
							if (boollld)
								buttonlld.draw(window);
							if (boollrdl)
								buttonrld.draw(window);
							if (!boollrdl)
							{
								if (boolld)
									buttonld.draw(window);
								if (boolll)
									buttonll.draw(window);
							}
							if (!boollld)
							{
								if (boolrl)
									buttonrl.draw(window);
								if (boolrd)
									buttonrd.draw(window);
							}
						}

						if (!boolld && !boolll && !boollld)
							buttonl.draw(window);
						if (!boolrd && !boolrl && !boollrdl)
							buttonr.draw(window);



						window.setView(vievnormal);
						buttomdown.draw(window);
						window.draw(bat);
						window.draw(time);
						window.display();
						clockdr.restart();
						i--;
					}

				}
				
			}

			rightdoor = !rightdoor;
		}
		if (rl.intersects(mouses) && Mouse::isButtonPressed(Mouse::Left) && clockb4.getElapsedTime().asSeconds() > 1&& !boolll)
		{
			
			boolrl = !boolrl;
			clockb4.restart(); 
			if (boolrl)
				batkill -= 5;
			else
				batkill += 5;
		}
		aktep.CanWeReadyToAttack();
		usya.CanWeReadyToAttack();
		window.setView(viev);
		if (leftdoor && aktep.CanWeReadyToAttacker)
			aktep.Napugali();
		if (rightdoor && usya.CanWeReadyToAttacker)
			usya.Napugali();



		



		if (!boolll&&!boolrl&&!boollld&& !boollrdl)
		office.draw(window);
		if (boolll && !boolrl)
			if (!aktep.CanWeReadyToAttacker)
			{	
				flag = 0;
				officell.draw(window);
			}
			else
			{
				if (flag == 0)
				{
					scary.play();
					flag = 1;
				}
				officeAktep.draw(window);
			}
		if (!boolll && boolrl)
			if (!usya.CanWeReadyToAttacker)
			{
				flag = 0;
				officerl.draw(window);
			}
			else
			{
				if (flag == 0)
				{
					scary.play();
					flag = 1;
				}
				officeUsya.draw(window);
			}
		if (boolrl || boollrdl)
			if (!usya.CanWeReadyToAttacker)
			{
				flag = 0;
				officerl.draw(window);
			}
			else
			{
				if (flag == 0)
				{
					scary.play();
					flag = 1;
				}
				officeUsya.draw(window);
			}
		if (leftdoor)
			doorl[13].draw(window);
		else
			doorl[0].draw(window);
		if (rightdoor)
			doorr[13].draw(window);
		else
			doorr[0].draw(window);
		if (boolld || boolll || boolrd || boolrl || boollld || boollrdl)
		{
			if (boolld && boolll)
				boollld = 1;
			else
				boollld = 0;

			if (boolrd && boolrl)
				boollrdl = 1;
			else
				boollrdl = 0;
			if (boollld)
			{
				buttonlld.draw(window);
				if (!rightdoor)
					buttonr.draw(window);
				else
					buttonrd.draw(window);
			}
			if (boollrdl)
			{
				buttonrld.draw(window);
				if (!leftdoor)
					buttonl.draw(window);
				else
					buttonld.draw(window);
			}
			if (!boollrdl)
			{
				if (boolld)
					buttonld.draw(window);
				if (boolll)
					buttonll.draw(window);
			}
			if (!boollld)
			{
				if (boolrl)
					buttonrl.draw(window);
				if (boolrd)
					buttonrd.draw(window);
			}
		}
		
		if (!boolld&&!boolll&&!boollld)
			buttonl.draw(window);
		if (!boolrd&&!boolrl&&!boollrdl)
			buttonr.draw(window);
		
		
		
		window.setView(vievnormal);
		buttomdown.draw(window);
		window.draw(bat);
		window.draw(time);
		window.display();
	}
}