#include <SFML/Graphics.hpp>
#include <iostream>
#include "map.h"
using namespace sf;
class figure
{
private:
public:
	int value;
	float step = 50;
	float x, y;
	String file_name;
};
int main()
{
	Image map_image;//объект изображения для карты
	map_image.loadFromFile("Animations/map.png");//загружаем файл для карты
	Texture map;//текстура карты
	map.loadFromImage(map_image);//заряжаем текстуру картинкой
	Sprite s_map;//создаём спрайт для карты
	s_map.setTexture(map);//заливаем текстуру спрайтом
	sf::RenderWindow window(VideoMode( 1280, 720 ), "Chess", sf::Style::Fullscreen);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == '0') s_map.setTextureRect(IntRect(0, 0, 50, 50)); //если встретили символ пробел, то рисуем 1й квадратик
				if (TileMap[i][j] == 'w')  s_map.setTextureRect(IntRect(50, 0, 50, 50));//если встретили символ s, то рисуем 2й квадратик
				if ((TileMap[i][j] == 'b')) s_map.setTextureRect(IntRect(100, 0, 50, 50));//если встретили символ 0, то рисуем 3й квадратик


				s_map.setPosition(j * 50, i * 50);

				window.draw(s_map);
			}
		window.display();
	}
	return 0;
}