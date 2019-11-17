#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <windows.h>
#include <iostream> //нужен для вывода строк "cout<<"
#include <iterator> 
#include <cstdio>
#include <cstdint>
#include <random>

#define CountPlot_Main 10
#define CountPlot_Breaking 2
#define Count_SuperJump 1
#define Count_OneJump 1
#define CountPlot_Move 1
#define HandsUp_Time 45
#define Acceleration_Y 0.2//0.2
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
	int n = WindowH / CountPlot_Main;
	int height = n;
	int count = 0;
	for (int i = 0; i < CountPlot_Main; i++) {
		plat[i].x = 0 + rand() / (float)RAND_MAX * ((WindowW - 68) - 0);
		
		plat[i].y = 0;
		plat[i].y = rand() % (height - count) + count;
		count = count + n;
		height = height + n;
		
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
	text.setPosition(280, 4);//280
	app.draw(text);
}

int Touch_Platform(point* plat, int x, int y, float &dy, int touch, Sound &jump_sound) {
	for (int i = 0; i < CountPlot_Main; i++) {
		if ((x + 50 > plat[i].x) && (x + 20 < plat[i].x + 68)
			&& (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0) && (plat[i].type == 1)) {
			dy = -10;
			touch = HandsUp_Time;
			jump_sound.play();
		}
		if ((x + 50 > plat[i].x) && (x + 20 < plat[i].x + 68)
			&& (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0) && (plat[i].type == 2)) {
			plat[i].type = 22;
		}
		if ((x + 50 > plat[i].x) && (x + 20 < plat[i].x + 68)
			&& (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0) && (plat[i].type == 3)) {
			dy = -20;
			touch = HandsUp_Time;
			jump_sound.play();
		}
		if ((x + 50 > plat[i].x) && (x + 20 < plat[i].x + 68)
			&& (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0) && (plat[i].type == 4)) {
			dy = -10;
			touch = HandsUp_Time;
			jump_sound.play();
			plat[i].type = 0;
		}
		if ((x + 50 > plat[i].x) && (x + 20 < plat[i].x + 68)
			&& (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0) && (plat[i].type == 5)) {
			dy = -10;
			touch = HandsUp_Time;
			jump_sound.play();
		}
	}
	return touch;
}

int MoveScreen(point* plat, int x, int &y, float &dy, float &dx, int score) {
	int CountPlot_Br = 0, CountPlot_SupJmp = 0, CountPlot_OneJmp = 0, CountPlot_Mov = 0;
	if (y < HeithJump) {
		score = score + HeithJump - y;
		for (int i = 0; i < CountPlot_Main; i++)
		{
			y = HeithJump;
			plat[i].y = plat[i].y - dy;

			if (plat[i].y > WindowH) {
				if (plat[i].type == 22)  //regen brown
					plat[i].type = 2;
				if (plat[i].type == 0)  //regen white
					plat[i].type = 4;

				plat[i].y = rand() % (-50) + 0;// немного рандомит появление новых платформ
				if ((plat[i - 1].y + 10 > plat[i].y) || (plat[i - 1].y - 10 < plat[i].y)) // проверка от склеивания платформ
				plat[i].y = plat[i].y + 10;
				plat[i].x = rand() % (WindowW - 68) + 0;
			
				for (int i2 = 0; i2 < CountPlot_Main; i2++) {
					if (plat[i2].type == 2) CountPlot_Br++;
					if (plat[i2].type == 3) CountPlot_SupJmp++;
					if (plat[i2].type == 4) CountPlot_OneJmp++;
					if (plat[i2].type == 5) CountPlot_Mov++;
				}

				if ((CountPlot_SupJmp < Count_SuperJump) || (CountPlot_Br < CountPlot_Breaking) || (CountPlot_OneJmp < Count_OneJump) || (CountPlot_Mov < CountPlot_Move)) {
					plat[i].type = rand() % 4  + 2;//2.3.4.5
					if (plat[i].type == 3 && CountPlot_SupJmp < Count_SuperJump) {
						CountPlot_SupJmp++;
					}
					else
						if (plat[i].type == 2 && CountPlot_Br < CountPlot_Breaking) {
							CountPlot_Br++;
						}
						else 
							if (plat[i].type == 4 && CountPlot_OneJmp < Count_OneJump) {
								CountPlot_OneJmp++;
							}
							else 
								if (plat[i].type == 5 && CountPlot_Mov < CountPlot_Move) {
									CountPlot_Mov++;
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

void Draw_sPlat(sf::RenderWindow& app, const point* plat, Sprite sPlat, int x, int y, int type) {
	for (int i = 0; i < CountPlot_Main; i++) //draw splat
	{
		if (plat[i].type == type)
		{
			sPlat.setPosition(plat[i].x, plat[i].y);
			app.draw(sPlat);
		}
	}
}

void Sound_Playing(Sound &jump_sound){
	jump_sound.play();
}


int main()
{
	SoundBuffer jumpBuffer;
	jumpBuffer.loadFromFile("images/JumpSound.ogg");
	Sound jump_sound(jumpBuffer);

	srand(time(NULL)); //for random
	RenderWindow app(VideoMode(WindowW, WindowH), "Doodle Game!");
	app.setFramerateLimit(SpeedFPS);

	Texture t1, t2, t2_2, t2_2_Br, t2_3, t3, t4, t2_4, t2_5;
	t1.loadFromFile("images/background1.png");
	t2.loadFromFile("images//platform_main.png");
	t2_2.loadFromFile("images//platform_2.png");
	t2_2_Br.loadFromFile("images//platform_2_Br.png");
	t2_3.loadFromFile("images//platform_3.png");
	t2_4.loadFromFile("images//platform_4.png");
	t2_5.loadFromFile("images//platform_5.png");
	t3.loadFromFile("images/doodle3.png");
	t4.loadFromFile("images/doodle.png");
	
	Sprite sBackground(t1), sPlat(t2), sPlat2(t2_2), sPlat2_2(t2_2_Br), sPlat3(t2_3), sPlat4(t2_4), sPlat5(t2_5), sPers(t3), sPers2(t4);

	point plat[CountPlot_Main];
	Starting_preparartions(plat);

	int x = 100, y = 100, score = 0, touch = 0;
	float dy = 0, dx = 1;

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
    if (Keyboard::isKeyPressed(Keyboard::Up)) y = y - 20;
	if (Keyboard::isKeyPressed(Keyboard::Down)) y = y + 20;
	if (Keyboard::isKeyPressed(Keyboard::Space)) dy += 0.2;
	if (Keyboard::isKeyPressed(Keyboard::Delete)) dy = 0;
	else

		dy += Acceleration_Y;
		y += dy;
		for (int i = 0; i < CountPlot_Main; i++)
		if (plat[i].type == 5) {
			plat[i].x = plat[i].x - dx; //влево 
			if (plat[i].x < 0)
				dx = -1;
			if (plat[i].x > WindowW)
				dx = 1;
		}


		score = MoveScreen(plat, x, y, dy, dx, score);
		touch = Touch_Platform(plat, x, y, dy, touch, jump_sound);

		if (x > WindowW) x = 0;
		if (x < 0) x = WindowW;
		
		GameEnd_YareDead(app, y); //if y fall down(y>533)
		///////////////////////////////////////////////////////////////start drawing
		sBackground.setPosition(0,0); //draw background
		app.draw(sBackground);
	
		Draw_sPlat(app, plat, sPlat2, x, y, 2);
		Draw_sPlat(app, plat, sPlat2_2, x, y, 22);
		Draw_sPlat(app, plat, sPlat3, x, y, 3);
		Draw_sPlat(app, plat, sPlat4, x, y, 4);
		Draw_sPlat(app, plat, sPlat5, x, y, 5);
		Draw_sPlat(app, plat, sPlat, x, y, 1);

		If_Touch_plat_What_Moves_sPers(app, sPers, sPers2, x, y, touch);//draw spers

    	Score(app, x, y, score); // draw score
		app.display();
	}
	return 0;
}
