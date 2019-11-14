#include <SFML/Graphics.hpp>
#include <sstream>
#include <windows.h>
#include <string> 
#define CountPlot 10
#define Acceleration 0.2
#define WindowW 400
#define WindowH 533
#define HeithJump 200
#define SpeedFPS 60

using namespace sf;

struct point
{
	int x, y;
};

void Score(sf::RenderWindow& app, int x, int  y, int score) {
	Font font;
	font.loadFromFile("CyrilicOld.ttf");
	Text text("", font, 20);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
	//text.setColor(Color::Red);
	text.setFillColor(Color::Red);
	//text.setStyle(Text::Bold | Text::Underlined);

	std::string s = std::to_string(y);// y into str
	s = "Y = " + s;
	text.setString(s);
	text.setPosition(10, 20);
	app.draw(text);

	s = std::to_string(x);// x into str
	s = "Y = " + s;
	text.setString(s);
	text.setPosition(10, 4);
	app.draw(text);

	s = std::to_string(score);// score into str
	s = "Y = " + s;
	text.setString(s);
	text.setPosition(350, 4);
	app.draw(text);
}

int main()
{
	RenderWindow app(VideoMode(WindowW, WindowH), "Doodle Game!");
	app.setFramerateLimit(SpeedFPS);

	Texture t1, t2, t3;
	t1.loadFromFile("images/background.png");
	t2.loadFromFile("images/platform.png");
	t3.loadFromFile("images/doodle2.png");

	Sprite sBackground(t1), sPlat(t2), sPers(t3);

	point plat[CountPlot];

	for (int i = 0; i < CountPlot; i++)
	{
		plat[i].x = rand() % (WindowW - 68) + 0;
		plat[i].y = rand() % WindowH;
	}

	int x = 100, y = 100, score = 0;
	float dx = 0, dy = 0;

	while (app.isOpen())
	{
		Event e;
		while (app.pollEvent(e))
		{
			if (e.type == Event::Closed)
				app.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Right)) x += 3;
		if (Keyboard::isKeyPressed(Keyboard::Left)) x -= 3;

		dy += Acceleration;
		y += dy;

		if (y < HeithJump)
			for (int i = 0; i < CountPlot; i++)
			{
				score = score + HeithJump - y;
				y = HeithJump;
				plat[i].y = plat[i].y - dy;
				if (plat[i].y > WindowH) {
					plat[i].y = 0;   
					plat[i].x = rand() % (WindowW - 68) + 0;
				}

		
			}
		for (int i = 0; i < CountPlot; i++)
			if ((x + 50 > plat[i].x) && (x + 20 < plat[i].x + 68)
				&& (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0))
				dy = -10;

		if (x > WindowW) x = 0;
		if (x < 0) x = WindowW;
		if (y > WindowH) {
			MessageBoxA(NULL, "YOU ARE DEAD !!!", "Game End!", MB_OK | MB_ICONINFORMATION);
			app.close();
		}
		sPers.setPosition(x, y);

		app.draw(sBackground);
		app.draw(sPers);
		for (int i = 0; i < CountPlot; i++)
		{
			sPlat.setPosition(plat[i].x, plat[i].y);
			app.draw(sPlat);
		}
		Score(app, x, y, score);
		app.display();
	}

	return 0;
}
