#include <SFML/Graphics.hpp>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <windows.h>
#include <iostream> 
#include <iterator> 
#include <cstdio>
#include <cstdint>
#include <random>


#define CountPlot_Main 13
#define CountPlot_Breaking 3
#define Count_SuperJump 1
#define HandsUp_Time 45
#define Acceleration_Y 0.2
#define WindowW 400
#define Acceleration_X 3
#define WindowH 533
#define HeithJump 200
#define SpeedFPS 60

using namespace sf;
using namespace std;

struct point
{
	int x, y;
	int type;
};

void Starting_preparartions(point* plat){
	
	for (int i = 0; i < CountPlot_Main; i++)
	{
		plat[i].x = rand() % (WindowW - 68) + 0;
		plat[i].y = rand() % WindowH;
		plat[i].type = 1;
	}
}

void Score(sf::RenderWindow& app, int x, int  y, int score) {
	Font font;
	font.loadFromFile("images//CyrilicOld.ttf");
	Text text("", font, 20);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
	text.setFillColor(Color::Red);
	//text.setStyle(Text::Bold | Text::Underlined);
	
	std::string s = std::to_string(y);// y into str
	s = "Y = " + s;
	text.setString(s);
	text.setPosition(10, 20);
	app.draw(text);

	s = std::to_string(x);// x into str
	s = "X = " + s;
	text.setString(s);
	text.setPosition(10, 4);
	app.draw(text);

	s = std::to_string(score);// score into str
	s = "Scope = " + s;
	text.setString(s);
	text.setPosition(280, 4);
	app.draw(text);
}

int Touch_Platform(point* plat, int x, int y, float &dy, int touch) {
	for (int i = 0; i < CountPlot_Main; i++) {
		if ((x + 50 > plat[i].x) && (x + 20 < plat[i].x + 68)
			&& (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0) && (plat[i].type == 1)) {
			dy = -10;
			touch = HandsUp_Time;
		}
		if ((x + 50 > plat[i].x) && (x + 20 < plat[i].x + 68)
			&& (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0) && (plat[i].type ==2)) {
			plat[i].type = 22;
		}
		if ((x + 50 > plat[i].x) && (x + 20 < plat[i].x + 68)
			&& (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0) && (plat[i].type == 3)) {
			dy = -20;
			touch = HandsUp_Time;
		}
	}
	return touch;
}

int MoveScreen(point* plat, int x, int &y, float &dy, int score, int &CountPlot_Br, int &CountPlot_SupJmp) {
	if (y < HeithJump) {
		score = score + HeithJump - y;
		for (int i = 0; i < CountPlot_Main; i++)
		{
			y = HeithJump;
			plat[i].y = plat[i].y - dy;
			if (plat[i].y > WindowH) {
				if (plat[i].type == 22)  //regen
					plat[i].type = 2;

				plat[i].y = rand() % (-50) + 0;// немного рандомит появление новых платформ
				plat[i].x = rand() % (WindowW - 68) + 0;
				
				if ((CountPlot_SupJmp < Count_SuperJump) || (CountPlot_Br < CountPlot_Breaking)) {
					plat[i].type = rand() % 3 + 2;
					if (plat[i].type == 3 && CountPlot_SupJmp < Count_SuperJump) {
						CountPlot_SupJmp++;
					} else
					if (plat[i].type == 2 && CountPlot_Br < CountPlot_Breaking) {
						CountPlot_Br++;
					}
					else {
						plat[i].type = 1;
					}				
				}
			}
		}
	}
	return score;
}

void GameEnd_YareDead(sf::RenderWindow& app, const int y) {
	if (y > WindowH) {
		MessageBoxA(NULL, "YOU ARE DEAD !!!", "Game End!", MB_OK | MB_ICONINFORMATION);
		app.close();
	}
}


void If_Touch_plat_What_Moves_sPers(sf::RenderWindow& app, Sprite sPers, Sprite sPers2, int x, int y, int &touch) {
	if (touch > 0) {    //draw spers
		touch--;
		sPers2.setPosition(x, y);
		app.draw(sPers2);
	}
	else {
		sPers.setPosition(x, y);
		app.draw(sPers);
	}
}

int main()
{
	srand(time(NULL)); //for random
	RenderWindow app(VideoMode(WindowW, WindowH), "Doodle Game!");
	app.setFramerateLimit(SpeedFPS);

	Texture t1, t2, t2_2, t2_2_Br, t2_3, t3, t4;
	t1.loadFromFile("images/background1.png");
	t2.loadFromFile("images//platform_main.png");
	t2_2.loadFromFile("images//platform_2.png");
	t2_2_Br.loadFromFile("images//platform_2_Br.png");
	t2_3.loadFromFile("images//platform_3.png");
	t3.loadFromFile("images/doodle3.png");
	t4.loadFromFile("images/doodle.png");
	
	Sprite sBackground(t1), sPlat(t2), sPlat2(t2_2), sPlat2_2(t2_2_Br), sPlat3(t2_3), sPers(t3), sPers2(t4);

	point plat[CountPlot_Main];
	Starting_preparartions(plat);

	int x = 100, y = 100, score = 0, touch = 0, CountPlot_Br = 0, CountPlot_SupJmp = 0;
	float dy = 0;

	while (app.isOpen())
	{
		Event e;
		while (app.pollEvent(e))
		{
			if (e.type == Event::Closed)
				app.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Right)) x += Acceleration_X;
		if (Keyboard::isKeyPressed(Keyboard::Left)) x -= Acceleration_X;

		dy += Acceleration_Y;
		y += dy;

		score = MoveScreen(plat, x, y, dy, score, CountPlot_Br, CountPlot_SupJmp);
		touch = Touch_Platform(plat, x, y, dy, touch);

		if (x > WindowW) x = 0;
		if (x < 0) x = WindowW;
		
		GameEnd_YareDead(app, y); //if y fall down(y>533)
		///////////////////////////////////////////////////////////////start drawing
		sBackground.setPosition(0,0); //draw background
		app.draw(sBackground);
		
		If_Touch_plat_What_Moves_sPers(app, sPers, sPers2, x, y, touch);
	
		
		for (int i = 0; i < CountPlot_Main; i++) //draw splat
		{
			if (plat[i].type == 2)
			{
				sPlat2.setPosition(plat[i].x, plat[i].y);
				app.draw(sPlat2);
			}
			if (plat[i].type == 1)
			{
				sPlat.setPosition(plat[i].x, plat[i].y);
				app.draw(sPlat);
			}
			if (plat[i].type == 22)
			{
				sPlat2_2.setPosition(plat[i].x, plat[i].y);
				app.draw(sPlat2_2);
			}
			if (plat[i].type == 3)
			{
				sPlat3.setPosition(plat[i].x, plat[i].y);
				app.draw(sPlat3);
			}
		}
		Score(app, x, y, score); // draw score
		app.display();
	}

	return 0;
}
