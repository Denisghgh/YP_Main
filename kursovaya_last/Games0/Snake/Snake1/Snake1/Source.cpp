#include <SFML/Graphics.hpp>
#include <time.h>
#include <windows.h> // for messagebox
#include <iostream> 
#define MB_OK                       0x00000000L
#define MB_ICONASTERISK             0x00000040L
#define MB_ICONINFORMATION          MB_ICONASTERISK

using namespace sf;
using namespace std;

int N = 30, M = 20;
int Sqsize = 16;
int w = Sqsize * N;
int h = Sqsize * M;

int dir = 0, num = 8, check = 0, score = 0;

struct Snake
{
	int x, y;
}  s[100];

struct Fruit
{
	int x, y;
} f;

void Scores(sf::RenderWindow& app, int& score) {
	Font font;
	font.loadFromFile("images//CyrilicOld.ttf");
	Text text("", font, 20);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
	text.setFillColor(Color::Black);

	std::string s = "";
	s = std::to_string(score);// score into str
	s = "Score = " + s;
	text.setString(s);
	text.setPosition(393, 7);//280
	app.draw(text);
}

void Tick(sf::RenderWindow& window)
{
	for (int i = num; i > 0; --i)
	{
		s[i].x = s[i - 1].x;
		s[i].y = s[i - 1].y;
	}
	
	if ((dir == 0) && (check != 3)) {
		s[0].y += 1;
		check = dir;
	}
	if ((dir == 3) && (check != 0)) {
		s[0].y -= 1;
		check = dir;
	}
	if ((dir == 1) && (check != 2)) {
		s[0].x -= 1;
		check = dir;
	}
	if ((dir == 2) && (check != 1)) {
		s[0].x += 1;
		check = dir;
	}

	if ((s[0].x == f.x) && (s[0].y == f.y))
	{
		score++;
		num++;
		f.x = rand() % N;
		f.y = rand() % M;
	}

	if (s[0].x > N-1) s[0].x = 0;
	if (s[0].x < 0) s[0].x = N;
	if (s[0].y > M-1) s[0].y = 0;
	if (s[0].y < 0) s[0].y = M;

	for (int i = 1; i < num; i++)
		if (s[0].x == s[i].x && s[0].y == s[i].y) {
			cout << score;
			MessageBoxA(NULL, "YOU ARE DEAD !!!", "Game End!", MB_OK | MB_ICONINFORMATION);
			window.close();
		}		
}

int main()
{
	srand(time(0));

	RenderWindow window(VideoMode(w, h), "Snake Game!");

	Texture t1, t2;
	t1.loadFromFile("images\\white.png");
	t2.loadFromFile("images\\red.png");

	Sprite sprite1(t1);
	Sprite sprite2(t2);

	Clock clock;
	float timer = 0, delay = 0.1;

	f.x = 10;
	f.y = 10;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
		}

		if ((Keyboard::isKeyPressed(Keyboard::Left)) && (check != 2)) dir = 1;
		if ((Keyboard::isKeyPressed(Keyboard::Right)) && (check != 1)) dir = 2;
		if ((Keyboard::isKeyPressed(Keyboard::Up)) && (check != 0)) dir = 3;
		if ((Keyboard::isKeyPressed(Keyboard::Down)) && (check != 3)) dir = 0;


		if (timer > delay) 
		{
			timer = 0;
			Tick(window);
		}

		////// draw  ///////
		window.clear();

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				sprite1.setPosition(i*Sqsize, j*Sqsize); 
				window.draw(sprite1);
			}

		for (int i = 0; i < num; i++)
		{
			sprite2.setPosition(s[i].x*Sqsize, s[i].y*Sqsize); 
			window.draw(sprite2);
		}

		sprite2.setPosition(f.x*Sqsize, f.y*Sqsize);  
		window.draw(sprite2);
		Scores(window, score);
		window.display();
	}

	return 0;
}
