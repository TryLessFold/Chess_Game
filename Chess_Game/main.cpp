#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream> 
#include "map.h"

using namespace sf;

std::stringstream toString(int val)
{
	std::stringstream ss;
	ss << val;
	return ss;
}

//===========================================================================================
//CLASS_FIGURE
//===========================================================================================
class figure
{
public:
	int value, pass=0;
	String status='0';
	float step = 50, w=50, h=50;
	float x, y;
	String file_name;
	Image image;
	Texture texture;
	Sprite sprite;
	figure() {};
	void initial(String Value, int v, float X, float Y)
	//figure(float X, float Y)
	{
		value = v;
		pass = 1;
		image.loadFromFile("Animations/"+Value+"_"+status+".png");
		//image.createMaskFromColor(Color(0, 0, 0));
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X; y = Y;
	    sprite.setTextureRect(IntRect(0, 0, 50, 50));
		sprite.setPosition(x, y);
	}
	void MoveUp()
	{
		x + 50;
		y + 50;
		sprite.setPosition(x, y);
	}
	//void update() //функция "оживления" объекта класса. update - обновление. принимает в себя время SFML , вследствие чего работает бесконечно, давая персонажу движение.
	//{
	//	//switch (dir)//реализуем поведение в зависимости от направления. (каждая цифра соответствует направлению)
	//	//{
	//	//case 0: dx = speed; dy = 0;   break;//по иксу задаем положительную скорость, по игреку зануляем. получаем, что персонаж идет только вправо
	//	//case 1: dx = -speed; dy = 0;   break;//по иксу задаем отрицательную скорость, по игреку зануляем. получается, что персонаж идет только влево
	//	//case 2: dx = 0; dy = speed;   break;//по иксу задаем нулевое значение, по игреку положительное. получается, что персонаж идет только вниз
	//	//case 3: dx = 0; dy = -speed;   break;//по иксу задаем нулевое значение, по игреку отрицательное. получается, что персонаж идет только вверх
	//	//}

	//	//x += dx*time;//то движение из прошлого урока. наше ускорение на время получаем смещение координат и как следствие движение
	//	//y += dy*time;//аналогично по игреку

	//	//speed = 0;//зануляем скорость, чтобы персонаж остановился.
	//	sprite.setPosition(x, y); //выводим спрайт в позицию x y , посередине. бесконечно выводим в этой функции, иначе бы наш спрайт стоял на месте.
	//}
};
//==========================================================================================
//MAIN
//==========================================================================================
int main()
{
	Image map_image;//объект изображения для карты
	Texture map;//текстура карты
	Sprite s_map;//создаём спрайт для карты
	map_image.loadFromFile("Animations/map.png");//загружаем файл для карты
	map.loadFromImage(map_image);//заряжаем текстуру картинкой
	s_map.setTexture(map);//заливаем текстуру спрайтом
	//figure figure[32];
	figure figure[32];
	int trigger_map = 0;
	int ch_figure = 0, i_mch, j_mch;
	int xbase = 1280, ybase = 720;
	int *xwin, *ywin;
	xwin = &xbase;
	ywin = &ybase;
	sf::RenderWindow window(VideoMode( *xwin, *ywin ), "Chess", sf::Style::Fullscreen);
	while (window.isOpen())
	{
		ch_figure = 0;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W))))
		{
			figure[0].MoveUp();
		}
		window.clear();
		i_mch = 0;
		j_mch = 0;
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == '0')
				{
					s_map.setTextureRect(IntRect(0, 0, 50, 50)); //если встретили символ пробел, то рисуем 1й квадратик
					trigger_map = 0;
				}
				if (TileMap[i][j] == 'w')
				{
					s_map.setTextureRect(IntRect(50, 0, 50, 50));//если встретили символ s, то рисуем 2й квадратик
					trigger_map = 1;
				}
				if ((TileMap[i][j] == 'b'))
				{
					s_map.setTextureRect(IntRect(100, 0, 50, 50));//если встретили символ 0, то рисуем 3й квадратик
					trigger_map = 1;
				}
				s_map.setPosition(j * 50, i * 50);
				if ((trigger_map == 1)&&(i_mch<8))
				{
					if (FigureMap[i_mch][j_mch] != '0')
					{
						figure[ch_figure].initial((FigureMap[i_mch][j_mch]), 7, 50 * j, 50 * i);
						ch_figure++;
					}
					j_mch++;
					if (j_mch > 7)
					{
						i_mch++;
						j_mch = 0;
					}
				}
				window.draw(s_map);
			}
		for (int i = 0; i <= 32; i++)
		if (figure[i].pass==1)
		window.draw(figure[i].sprite);
		window.display();
	}
	return 0;
}