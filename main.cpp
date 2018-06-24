#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream> 
#include "map.h"
#include "fstream"
#include "Functions.h"
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
	int pass=0;
	int value;
	float step = 50, w=50, h=50;
	float x, y;
	String Valuestr;
	String file_name;
	Image image;
	Texture texture;
	Sprite sprite;
	Text text;
	bool isSelect;
	figure() 
	{
		bool isSelect = false;
	};
	void initial(String Value, float X, float Y)
	{
		value = Value[0];
		Valuestr = Value;
		pass = 1;
		image.loadFromFile("Animations/"+Value+"_0.png");
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X; y = Y-5;
	    sprite.setTextureRect(IntRect(0, 0, 50, 50));
		sprite.setPosition(x, y);
		text.setCharacterSize(16);
		text.setFillColor(Color::Black);
		text.setString("");
		text.setPosition(x+25, y-25);
	}
	void settext(String str)
	{
		text.setString(str);
	}
	void setemoj(String Value)
	{
		image.loadFromFile("Animations/" + Valuestr+ "_" + Value + ".png");
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(0, 0, 50, 50));
		sprite.setPosition(x, y);
	}
	void reload()
	{
		sprite.setPosition(x, y);
	}
};

//==========================================================================================
//Functions
//==========================================================================================
void FileToMass(std::string *a, int n, std::string file1, int &k)
{
	std::ifstream file;
	file.open(file1 + ".txt");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			file >> a[i][j];
	//file >> k;
}
void MassToFile(std::string *a, int n, std::string file1, int k)
{
	std::ofstream file;
	file.open(file1 + ".txt");
	for (int i = 0; i < n; i++)
		for (int j = 0; j <n; j++)
			file << a[i][j] << " ";
	//file << k;
}
void FileToFile(std::string a, std::string b, int n)
{
	std::string k;
	std::ifstream file;
	std::ofstream file1;
	file.open(a + ".txt");
	file1.open(b + ".txt");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			file >> k;
			file1 << k << " ";
		}
	//file >> k;
	//file1 << k << "";
}

//==========================================================================================
//MAIN
//==========================================================================================
int main()
{
	Font font;
	font.loadFromFile("Fonts/Windsor.ttf");
	Image map_image;
	Texture map;
	Sprite s_map;
	map_image.loadFromFile("Animations/map.png");
	map.loadFromImage(map_image);
	s_map.setTexture(map);
	figure figure[32];
	char castling[2] = { 3,3 }, parry[2] = { 0,0 }, x_parrying, y_parrying;
	char i_blackk = 1, j_blackk = 5, i_whitek = 8, j_whitek = 4;
	int **a;
	int trigger_map = 0, trigger_figure = -1, trigger_figure_to = -1;
	int ch_figure = 0, i_mch = 0, j_mch = 0;
	int x_desk = 0, y_desk = 0, iy = 0, jx = 0, i1 = 0, j1 = 0, k = 0, pass = 0;
	int xbase = 1280, ybase = 720;
	int *xwin, *ywin;
	xwin = &xbase;
	ywin = &ybase;
	bool mousec = false;
	sf::RenderWindow window(VideoMode(*xwin, *ywin), "Chess", sf::Style::Fullscreen);
	a = new int*[10];
	for (int i = 0; i < 10; i++)
		a[i] = new int[10];
	FileToMass(FigureMap, 8, "0", k);
	for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			if (TileMap[i][j] == '0')
			{
				s_map.setTextureRect(IntRect(0, 0, 50, 50));
				trigger_map = 0;
			}
			if (TileMap[i][j] == 'w')
			{
				s_map.setTextureRect(IntRect(50, 0, 50, 50));
				trigger_map = 1;
				if ((x_desk == 0) && (y_desk == 0))
				{
					x_desk = j * 50;
					y_desk = i * 50;
				}
			}
			if ((TileMap[i][j] == 'b'))
			{
				s_map.setTextureRect(IntRect(100, 0, 50, 50));
				trigger_map = 1;
				if ((x_desk == 0) && (y_desk == 0))
				{
					x_desk = j * 50;
					y_desk = i * 50;
				}
			}
			s_map.setPosition(j * 50, i * 50);
			if ((trigger_map == 1) && (i_mch < 8))
			{
				if(FigureMap[i_mch][j_mch]>=65) a[i_mch + 1][j_mch + 1] = FigureMap[i_mch][j_mch] - 55;
				else a[i_mch + 1][j_mch + 1] = FigureMap[i_mch][j_mch]-48;
				if (FigureMap[i_mch][j_mch] != '0')
				{
					figure[ch_figure].initial((FigureMap[i_mch][j_mch]), 50 * j, 50 * i);
					figure[ch_figure].text.setFont(font);
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
	std::cout << y_desk << " " << x_desk << std::endl;
	for (int i = 1; i < 9; i++)
	{
		for (int j = 1; j < 9; j++)
		{
			std::cout << a[i][j] << " ";
		}
		std::cout << std::endl;
	}
	while (window.isOpen())
	{
		ch_figure = 0;
		Vector2i wPos = Mouse::getPosition(window);
		sf::Event event;
		while (window.pollEvent(event))
		{
			if ((event.key.code == Mouse::Left) && (mousec == false))
			{
				if (trigger_figure == -1)
				{
					for (int i = 0; i < 32; i++)
						if (figure[i].sprite.getGlobalBounds().contains(wPos.x, wPos.y))
						{
							iy = ((wPos.y - y_desk) / 50) + 1;
							jx = ((wPos.x - x_desk) / 50) + 1;
							//if ((a[iy][jx] / 7) == k)
							//{
								mousec = true;
								figure[i].setemoj("1");
								trigger_figure = i;
							//}
							break;
						}
				}
				else
				{
					for (int i = 0; i < 32; i++)
						if (figure[i].sprite.getGlobalBounds().contains(wPos.x, wPos.y))
						{
							if (trigger_figure == i)
							{
								mousec = true;
								figure[i].setemoj("0");
								trigger_figure = -1;
								break;
							}
						}

				}
				if ((trigger_figure != -1)&&(mousec==false))
				{
					mousec = true;
					for (int i = 0; i < 32; i++)
						if (figure[i].sprite.getGlobalBounds().contains(wPos.x, wPos.y))
						{
							trigger_figure_to = i;
							break;
						}
					i1 = ((wPos.y - y_desk) / 50) + 1;
					j1 = ((wPos.x - x_desk) / 50) + 1;
					if ((iy > 0) && (iy < 9) && (jx > 0) && (jx < 9) && (j1 > 0) && (j1 < 9) && (i1 > 0) && (i1 < 9))
					{
						pass = CheckMove(a, iy, jx, i1, j1);
						if (((a[iy][jx] == 12) || (a[iy][jx] == 6)) && (castling[k] > 0) && (pass == 0))
							pass = Castling(a, iy, jx, i1, j1, castling[k]);
						if ((parry[k] == 1) && (j1 == x_parrying)&&(i1 == y_parrying))
						{
							if (((a[iy][jx] == 1) || (a[iy][jx] == 7)) && (pass == 0))
							{
								pass = Attack(a, iy, jx, i1, j1);
								parry[k] = 0;
							}
							else
								parry[k] = 0;
						}
						if (((a[iy][jx] == 1) || (a[iy][jx] == 7)) && (pass != 0))
						{
							parry[1 - k] = Charge(a, iy, jx, i1, j1);
							if (parry[1 - k] != 0) 
							{
								y_parrying = i1;
								x_parrying = j1; 
							}
						}
					}
					else pass = 4;
					if (pass == 0) printf("Wrong Move\n");
					if (pass == 3) printf("FRIEND!\n");
					if (pass == 1)
					{
						if ((a[iy][jx] == 2) && (castling[k] != 0))
						{
							if (jx == 1) castling[k] = 2;
							else if (jx == 8) castling[k] = 1;
						}
						if (((a[iy][jx] == 12) || (a[iy][jx] == 6)) && (castling[k] != 0)) castling[k] = 0;
						k = 1 - k;
						SwapMove(&a[iy][jx], &a[i1][j1]);
						figure[trigger_figure].x += ((j1 - jx) * 50);
						figure[trigger_figure].y += ((i1 - iy) * 50);
						figure[trigger_figure].reload();
						figure[trigger_figure].setemoj("0");
						Change(a, i1, j1);
						trigger_figure = -1;
					}
					if (pass == 2)
					{
						if ((a[iy][jx] == 2) && (castling[k] != 0))
						{
							if (jx == 1) castling[k] = 2;
							else if (jx == 8) castling[k] = 1;
						}
						if (((a[iy][jx] == 12) || (a[iy][jx] == 6)) && (castling[k] != 0)) castling[k] = 0;
						k = 1 - k;
						SwapMove(&a[iy][jx], &a[i1][j1]);
						figure[trigger_figure].x += ((j1 - jx) * 50);
						figure[trigger_figure].y += ((i1 - iy) * 50);
						figure[trigger_figure].reload();
						figure[trigger_figure_to].x = 0;
						figure[trigger_figure_to].y = 0;
						figure[trigger_figure_to].reload();
						figure[trigger_figure].setemoj("0");
						Change(a, iy, jx);
						trigger_figure = -1;
					}
					if (pass == 4) printf("Choose Figure\n");
					if (pass == 5)
					{
						SwapMove(&a[iy][jx], &a[i1][j1]);
						if (j1 > jx)
						{
							SwapMove(&a[i1][8], &a[i1][j1 - 1]);
							figure[trigger_figure].x += ((j1 - jx) * 50);
							figure[trigger_figure].y += ((i1 - iy) * 50);
						}
						else
						{
							figure[trigger_figure].x += ((j1 - jx) * 50);
							figure[trigger_figure].y += ((i1 - iy) * 50);
							figure[trigger_figure].reload();
							figure[trigger_figure].setemoj("0");
							SwapMove(&a[i1][1], &a[i1][j1 + 1]);
						}
						castling[k] = 0;
						k = 1 - k;
						trigger_figure = -1;
					}
					if (pass == 6)
					{
						if (k == 0) i1--;
						else i1++;
						SwapMove(&a[iy][jx], &a[i1][j1]);
						figure[trigger_figure].setemoj("0");
						figure[trigger_figure].x += ((j1 - jx) * 50);
						figure[trigger_figure].y += ((i1 - iy) * 50);
						figure[trigger_figure].reload();
						figure[trigger_figure_to].x = 0;
						figure[trigger_figure_to].y = 0;
						figure[trigger_figure_to].reload();
						k = 1 - k;
						trigger_figure = -1;
					}
				}
			}
			if (event.type == Event::MouseButtonReleased)
				if (event.key.code == Mouse::Left)
				{
					std::cout << iy << " " << jx << "    " << i1 << " " << j1 << std::endl;
					std::cout << pass << std::endl;
					mousec = false;
				}
			if (event.type == sf::Event::Closed)
				window.close();
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
					//trigger_map = 0;
				}
				if (TileMap[i][j] == 'w')
				{
					s_map.setTextureRect(IntRect(50, 0, 50, 50));//если встретили символ s, то рисуем 2й квадратик
					//trigger_map = 1;
				}
				if ((TileMap[i][j] == 'b'))
				{
					s_map.setTextureRect(IntRect(100, 0, 50, 50));//если встретили символ 0, то рисуем 3й квадратик
					//trigger_map = 1;
				}
				s_map.setPosition(j * 50, i * 50);
				window.draw(s_map);
			}
		for (int i = 0; i <= 32; i++)
			if (figure[i].pass == 1)
			{
				window.draw(figure[i].sprite);
				window.draw(figure[i].text);
			}
		window.display();
	}
	return 0;
}