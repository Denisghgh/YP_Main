#include <SFML/Graphics.hpp>
#include <time.h>
#include <cstdlib>
#include <windows.h>
#include <iostream> 
using namespace sf;
using namespace std;

int Score = 0;
bool dead = false, Mouse_Clicked = false;

void Scores(sf::RenderWindow& app, int& score) {
	Font font;
	font.loadFromFile("images//CyrilicOld.ttf");
	Text text("", font, 20);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
	text.setFillColor(Color::Black);

	std::string s = "";
	s = std::to_string(score);// score into str
	s = "Score = " + s;
	text.setString(s);
	text.setPosition(200, 7);//280
	app.draw(text);
}

void GameEnd_YareDead(sf::RenderWindow& app) {
	if (dead && Mouse_Clicked)
	{
		cout << Score;
		MessageBoxA(NULL, "YOU ARE DEAD !!!", "Game End!", MB_OK | MB_ICONINFORMATION);
		app.close();
	}
		
}

int main()
{
	srand(time(0));

	RenderWindow app(VideoMode(400, 400), "Miner!");

	int w = 32;
	int grid[12][12];
	int sgrid[12][12]; //for showing

	Texture t;
	t.loadFromFile("images/tiles.jpg");
	Sprite s(t);

	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
		{
			sgrid[i][j] = 10;
			if (rand() % 5 == 0)  grid[i][j] = 9;
			else grid[i][j] = 0;
		}

	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
		{
			int n = 0;

			if (grid[i][j] == 9) continue;
			if (grid[i + 1][j] == 9) n++;
			if (grid[i][j + 1] == 9) n++;
			if (grid[i - 1][j] == 9) n++;
			if (grid[i][j - 1] == 9) n++;
			if (grid[i + 1][j + 1] == 9) n++;
			if (grid[i - 1][j - 1] == 9) n++;
			if (grid[i - 1][j + 1] == 9) n++;
			if (grid[i + 1][j - 1] == 9) n++;
			grid[i][j] = n;
		}

	while (app.isOpen())
	{
		Vector2i pos = Mouse::getPosition(app);
		int x = pos.x / w;
		int y = pos.y / w;

		Event e;
		while (app.pollEvent(e))
		{
			if (e.type == Event::Closed)
				app.close();

			if (e.type == Event::MouseButtonPressed)
				if (e.key.code == Mouse::Left)
				{
					sgrid[x][y] = grid[x][y];
					Score++;
					Mouse_Clicked = true;
				}
				else if (e.key.code == Mouse::Right) sgrid[x][y] = 11;
		}

		app.clear(Color::White);

		for (int i = 1; i <= 10; i++)
			for (int j = 1; j <= 10; j++)
			{
				if (sgrid[x][y] == 9)
				{
					sgrid[i][j] = grid[i][j];
					dead = true;
				}
				s.setTextureRect(IntRect(sgrid[i][j] * w, 0, w, w));
				s.setPosition(i*w, j*w);
				app.draw(s);
			}
		Scores(app, Score);
		app.display();
		GameEnd_YareDead(app);
	}
	return 0;
}