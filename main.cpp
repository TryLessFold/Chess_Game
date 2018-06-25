#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream> 
#include "map.h"
#include "view.h"
#include "fstream"
#include "Functions.h"
using namespace sf;

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
	bool isAttack;
	bool isMove;
	figure() 
	{
		isAttack = false;
		isMove = false;
	};
	void initial(char Value, float X, float Y)
	{
		if (Value >= 'A') value = Value - 55;
		else value = Value-48;
		Valuestr = Value;
		pass = 1;
		image.loadFromFile("Animations/"+Valuestr+"_0.png");
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X; y = Y-5;
	    sprite.setTextureRect(IntRect(0, 0, 50, 50));
		sprite.setPosition(x, y);
		text.setCharacterSize(16);
		text.setFillColor(Color::Black);
		text.setString(Value);
		text.setPosition(x+25, y-25);
		//sprite.setOrigin(25, 25);
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
	void setemojanot(String Value)
	{
		image.loadFromFile("Animations/" + Value + ".png");
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(0, 0, 50, 50));
		sprite.setPosition(x, y);
	}
	void reload()
	{
		//sprite.setOrigin(25, 25);
		sprite.setPosition(x, y);
		text.setPosition(x + 25, y - 25);
	}
	void mirror(String Value)
	{
		image.loadFromFile("Animations/" + Valuestr + "_" + Value + ".png");
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(50, 0, -50, 50));
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
void ChangeView(figure* a, int n, int k, int x, int y, int i)
{
	if (i==90)
		for (int i = 0; i < n; i++)
		{
			if (k != 1)
			{
				a[i].sprite.setOrigin(0, 0);
				a[i].text.setOrigin(0, 0);
				a[i].sprite.setRotation(0);
				a[i].text.setRotation(0);
			}
			else
			{
				a[i].sprite.setOrigin(50, 60);
				a[i].text.setOrigin(0, 110);
				a[i].sprite.rotate(180);
				a[i].text.setRotation(180);
			}
		}
	ChangeRotate_0(k, x, y, i);
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
	Clock clock;
	double dis;
	char castling[2] = { 3,3 }, parry[2] = { 0,0 }, x_parrying, y_parrying;
	char i_blackk = 1, j_blackk = 4, i_whitek = 8, j_whitek = 4;
	int **a;
	int trigger_map = 0, trigger_figure = -1, trigger_figure_to = -1, trigger_view=180;
	int ch_figure = 0, i_mch = 0, j_mch = 0, mp=0;
	int x_desk = 0, y_desk = 0, iy = 0, jx = 0, i1 = 0, j1 = 0, k = 0, b, w, pass = 0, tempX=0, tempY=0;
	int xbase = 1280, ybase = 720, aat=0;
	int *xwin, *ywin;
	xwin = &xbase;
	ywin = &ybase;
	bool mousec = false;
	char ch;
	//sf::RenderWindow window(VideoMode(*xwin, *ywin), "Chess", sf::Style::Fullscreen);
	RenderWindow window(VideoMode(*xwin, *ywin), "Chess");
	view.reset(sf::FloatRect(0, 0, *xwin, *ywin));
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
	//std::cout << y_desk << " " << x_desk << std::endl;
	for (int i = 1; i < 9; i++)
	{
		for (int j = 1; j < 9; j++)
		{
			std::cout << a[i][j] << " ";
		}
		std::cout << std::endl;
	}
	view.setCenter(Vector2f(x_desk+200, y_desk+200));
	while (window.isOpen())
	{
		if (mp == -1) mp = 0;
		float time = clock.getElapsedTime().asMicroseconds(); //���� ��������� ����� � �������������
		clock.restart(); //������������� �����
		time = time / 600; //�������� ����
		ch_figure = 0;
		Vector2i pixelPos = Mouse::getPosition(window);//�������� ����� �������
		Vector2f wPos = window.mapPixelToCoords(pixelPos);//��������� �� � ������� (������ �� ����� ����)
		std::cout << wPos.x << " " << wPos.y << std::endl;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if ((event.key.code == Mouse::Left) && (mousec == false)&&(figure[trigger_figure].isMove!=true) && (figure[trigger_figure].isAttack != true))
			{
				if (trigger_figure == -1)
				{
					for (int i = 0; i < 32; i++)
						if (figure[i].sprite.getGlobalBounds().contains(wPos.x, wPos.y))
						{
							iy = ((wPos.y - y_desk) / 50) + 1;
							jx = ((wPos.x - x_desk) / 50) + 1;
							if ((a[iy][jx] / 7) == k)
							{
								mousec = true;
								figure[i].setemoj("1");
								trigger_figure = i;
							}
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
				if ((trigger_figure != -1) && (mousec == false))
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
					tempX = wPos.x - x_desk;
					tempY = wPos.y - y_desk;
					if ((iy > 0) && (iy < 9) && (jx > 0) && (jx < 9) && (j1 > 0) && (j1 < 9) && (i1 > 0) && (i1 < 9))
					{
						pass = CheckMove(a, iy, jx, i1, j1);
						if (((a[iy][jx] == 12) || (a[iy][jx] == 6)) && (castling[k] > 0) && (pass == 0))
							pass = Castling(a, iy, jx, i1, j1, castling[k]);
						if ((parry[k] == 1) && (j1 == x_parrying) && (i1 == y_parrying))
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
						if (figure[trigger_figure].value == 12)
						{
							i_blackk = i1; j_blackk = j1;
						}
						else if (figure[trigger_figure].value == 6)
						{
							i_whitek = i1; j_whitek = j1;
						}
						figure[trigger_figure].isMove = true;
						figure[trigger_figure].setemoj("0");
						Change(a, i1, j1);
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
						if (figure[trigger_figure].value == 12)
						{
							i_blackk = i1; j_blackk = j1;
						}
						else if (figure[trigger_figure].value == 6)
						{
							i_whitek = i1; j_whitek = j1;
						}
						figure[trigger_figure].isAttack = true;
						Change(a, iy, jx);
					}
					if (pass == 4) printf("Choose Figure\n");
					if (pass == 5)
					{
						SwapMove(&a[iy][jx], &a[i1][j1]);
						if (figure[trigger_figure].value == 12)
						{
							i_blackk = i1; j_blackk = j1;
						}
						else if (figure[trigger_figure].value == 6)
						{
							i_whitek = i1; j_whitek = j1;
						}
						figure[trigger_figure].isMove = true;
						if (j1 > jx)
						{
							std::cout << ((i1 - 1) * 50) + y_desk + 25 << " " << (7 * 50) + x_desk + 25 << std::endl;
							for (int i = 0; i < 32; i++)
								if (figure[i].sprite.getGlobalBounds().contains(((7 * 50) + x_desk + 25), ((i1 - 1) * 50) + y_desk + 25))
								{
									trigger_figure_to = i;
									break;
								}
							figure[trigger_figure_to].x -= ((j1 + 1 - jx) * 50);
							SwapMove(&a[i1][8], &a[i1][j1 - 1]);
						}
						else
						{
							std::cout << ((i1 - 1) * 50) + y_desk + 25 << " " << (7 * 50) + x_desk + 25 << std::endl;
							for (int i = 0; i < 32; i++)
								if (figure[i].sprite.getGlobalBounds().contains(((0 * 50) + x_desk + 25),((i1-1) * 50) + y_desk+25))
								{
									trigger_figure_to= i;
									break;
								}
							figure[trigger_figure_to].x -= ((j1 - jx) * 50);
							SwapMove(&a[i1][1], &a[i1][j1 + 1]);
						}
						std::cout <<"||||||||"<< trigger_figure_to << std::endl;
						figure[trigger_figure_to].reload();
						castling[k] = 0;
						k = 1 - k;
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
						//trigger_figure = -1;
						//ChangeView(figure, 32, k, x_desk + 200, y_desk + 200);
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
		if ((figure[trigger_figure].isMove)&&(trigger_figure!=-1)){
			//std::cout << iy << " " << jx << "    " << i1 << " " << j1 << std::endl;
			dis = sqrt((((j1 - 1) * 50 - (int)((figure[trigger_figure].x - x_desk))))*(((j1 - 1) * 50 - (int)((figure[trigger_figure].x - x_desk))))
				+ (((i1 - 1) * 50 - (int)((figure[trigger_figure].y - y_desk))))*(((i1 - 1) * 50 - (int)((figure[trigger_figure].y - y_desk)))));
		
			if (dis > 0) {
				figure[trigger_figure].x += 0.1*time*(((j1-1)*50 - (int)((figure[trigger_figure].x - x_desk)))) / dis;
				figure[trigger_figure].y += 0.1*time*(((i1-1)*50 - (int)((figure[trigger_figure].y - y_desk)))) / dis;
			}
			else
			{
				figure[trigger_figure].setemoj("0");
				figure[trigger_figure].x = (int)((j1-1) * 50 + x_desk);
				figure[trigger_figure].y = (int)((i1-1) * 50 + y_desk-5);
				figure[trigger_figure].isMove = false;
				if (!figure[trigger_figure].isAttack)
				{
					if (w == 1) w = 2;
					else if (CheckSafetyKing(a, i_whitek, j_whitek))
						w = 1;
					else w = 0;
					if (b == 1) b = 2;
					else if (CheckSafetyKing(a, i_blackk, j_blackk))
						b = 1;
					else b = 0;
					std::cout << "|||" << b << "|||" << w << std::endl;
					trigger_figure = -1;
					trigger_view = 0;
				}
			}
			std::cout << trigger_figure << std::endl;
			std::cout << figure[trigger_figure].x<<" ";
			std::cout << figure[trigger_figure].y << std::endl;
		}
		if ((figure[trigger_figure_to].isMove) && (trigger_figure_to != -1)) {
			//std::cout << iy << " " << jx << "    " << i1 << " " << j1 << std::endl;
			dis = sqrt((((j1 - 1) * 50 - (int)((figure[trigger_figure_to].x - x_desk))))*(((j1 - 1) * 50 - (int)((figure[trigger_figure_to].x - x_desk))))
				+ (((i1 - 1) * 50 - (int)((figure[trigger_figure_to].y - y_desk))))*(((i1 - 1) * 50 - (int)((figure[trigger_figure_to].y - y_desk)))));

			if (dis > 0) {
				figure[trigger_figure_to].x += 0.1*time*(((j1 - 1) * 50 - (int)((figure[trigger_figure_to].x - x_desk)))) / dis;
				figure[trigger_figure_to].y += 0.1*time*(((i1 - 1) * 50 - (int)((figure[trigger_figure_to].y - y_desk)))) / dis;
			}
			else
			{
				figure[trigger_figure_to].setemoj("0");
				figure[trigger_figure_to].x = (int)((j1 - 1) * 50 + x_desk);
				figure[trigger_figure_to].y = (int)((i1 - 1) * 50 + y_desk - 5);
				figure[trigger_figure_to].isMove = false;
			}
		}
		if ((figure[trigger_figure].isAttack) && (trigger_figure != -1))
		{
			if (w == 1) w = 2;
			else if (CheckSafetyKing(a, i_whitek, j_whitek))
				w = 1;
			else w = 0;
			if (b == 1) b = 2;
			else if (CheckSafetyKing(a, i_blackk, j_blackk))
				b = 1;
			else b = 0;
			std::cout << "|||" << b << "|||" << w << std::endl;
			ch = figure[trigger_figure].value;
			if (ch >= 7) ch = (ch % 7) + 1;
			switch (ch)
			{
			case 1:
				std::cout << "tut" << std::endl;
				std::cout << mp << std::endl;
				sf::sleep(sf::seconds(0.3));
				if (mp == 4)
				{
					figure[trigger_figure].setemoj("0");
					figure[trigger_figure_to].x = -50;
					figure[trigger_figure_to].y = -50;
					figure[trigger_figure].isAttack = false;
					figure[trigger_figure].isMove = true;
					figure[trigger_figure].sprite.setOrigin(0, 0);
					figure[trigger_figure].sprite.setScale(1, 1);
					aat = 0;
					mp = -1;
				}
				if (mp == 3)
				{
					figure[trigger_figure].setemoj("0");
					figure[trigger_figure_to].sprite.setColor(Color(255, 255, 255, 128));
					figure[trigger_figure_to].sprite.setRotation(aat);
					mp++;
				}
				if (mp == 2)
				{
					figure[trigger_figure].setemoj("2");
					figure[trigger_figure_to].sprite.setRotation(aat+5);
					mp++;
				}
				if (mp == 1)
				{
					figure[trigger_figure].setemoj("1");
					figure[trigger_figure_to].sprite.setRotation(aat);
					mp++;
				}
				if (mp == 0)
				{
					if ((j1 < jx) && (figure[trigger_figure].value == 1))
					{
						figure[trigger_figure].sprite.setOrigin(50, 0);
						figure[trigger_figure].sprite.setScale(-1, 1);
						aat = 0;
					}
					else if ((j1 > jx) && (figure[trigger_figure].value == 7))
					{
						figure[trigger_figure].sprite.setOrigin(0, 50);
						figure[trigger_figure].sprite.setScale(-1, 1);
						aat = 180;
					}
					else if (figure[trigger_figure].value == 7)
						aat = 180;
					else aat = 0;
					figure[trigger_figure].setemoj("2");
					figure[trigger_figure_to].sprite.setRotation(aat+10);
					mp++;
				}
				break;
			case 2:
				if ((mp == 2) && (!figure[trigger_figure_to].isMove))
				{
					figure[trigger_figure].isAttack = false;
					figure[trigger_figure_to].x = -50;
					figure[trigger_figure_to].y = -50;
					trigger_figure = -1;
					trigger_view = 0;
					mp = -1;
				}
				if ((mp == 1)&&(!figure[trigger_figure].isMove))
				{
					sf::sleep(sf::seconds(0.3));
					if (aat == 4)
					{
						j1 = j1-2; //i1 = 4;
					}
					else if (aat == 5)
					{
						j1 = j1+2; //i1 = 4;
					}
					else if (aat == 2)
					{
						i1 = i1+2; //j1 = 4;
					}
					else if (aat == 3)
					{
						i1 = i1-2; //j1 = 4;
					}
					figure[trigger_figure].setemoj("0");
					figure[trigger_figure].isMove = false;
					std::cout << trigger_figure << std::endl;
					figure[trigger_figure_to].isMove = true;
					mp++;
				}
				if (mp == 0)
				{
					if (j1 < jx)
					{
						if(figure[trigger_figure].value / 7 == 0)
						figure[trigger_figure].setemoj("4");
						else
						figure[trigger_figure].setemoj("5");
						aat = 4;
					}
					else if (j1 > jx)
					{
						if (figure[trigger_figure].value / 7 == 0)
						figure[trigger_figure].setemoj("5");
						else
						figure[trigger_figure].setemoj("4");
						aat = 5;
					}
					else if (i1 > iy)
					{
						if (figure[trigger_figure].value / 7 == 0)
							figure[trigger_figure].setemoj("2");
						else
							figure[trigger_figure].setemoj("3");
						aat = 2;
					}
					else
					{
						if (figure[trigger_figure].value / 7 == 0)
							figure[trigger_figure].setemoj("3");
						else
							figure[trigger_figure].setemoj("2");
						aat = 3;
					}
					figure[trigger_figure].isMove = true;
					mp++;
				}
				break;
			case 3:
				if ((mp == 1) && (!figure[trigger_figure].isMove))
				{
					figure[trigger_figure].isAttack = false;
					figure[trigger_figure_to].x = -50;
					figure[trigger_figure_to].y = -50;
					trigger_figure = -1;
					trigger_view = 0;
					mp=-1;
				}
				if (mp == 0)
				{
					figure[trigger_figure].setemoj("2");
					figure[trigger_figure].isMove = true;
					mp++;
				}
				break;
			case 4:
				sf::sleep(sf::seconds(0.3));
				if (mp == 6)
				{
					figure[trigger_figure].sprite.setColor(Color(255, 255, 255, 255));
					figure[trigger_figure].setemoj("0");
					figure[trigger_figure].isAttack = false;
					trigger_figure = -1;
					trigger_view = 0;
					mp = -1;
				}
				if (mp == 5)
				{
					figure[trigger_figure].setemojanot("4_1");
					figure[trigger_figure].sprite.setColor(Color(255, 255, 255, 128));
					//sf::sleep(sf::seconds(1));
					mp++;
				}
				if (mp == 4)
				{
					figure[trigger_figure].sprite.setColor(Color(255, 255, 255, 128));
					figure[trigger_figure_to].x = -50;
					figure[trigger_figure_to].y = -50;
					mp++;
				}
				if (mp == 3)
				{
					figure[trigger_figure_to].sprite.setColor(Color(255, 255, 255, 128));
					mp++;
				}
				if (mp == 2)
				{
					int xx, yy;
					xx = figure[trigger_figure_to].x;
					figure[trigger_figure_to].x = figure[trigger_figure].x;
					figure[trigger_figure].x = xx;
					yy = figure[trigger_figure_to].y;
					figure[trigger_figure_to].y = figure[trigger_figure].y;
					figure[trigger_figure].y = yy;
					mp++;
				}
				if (mp == 1)
				{
					figure[trigger_figure_to].setemojanot("4_2");
					mp++;
				}
				if (mp == 0)
				{
					figure[trigger_figure].setemoj("2");
					mp++;
				}
				break;
			case 5:
				sf::sleep(sf::seconds(0.5));
				if (mp == 10)
				{
					figure[trigger_figure].isAttack = false;
					figure[trigger_figure].setemoj("0");
					trigger_figure = -1;
					trigger_view = 0;
					mp=-1;
				}
				if (mp == 9)
				{
					figure[trigger_figure_to].x = -50;
					figure[trigger_figure_to].x = -50;
					figure[trigger_figure].setemoj("1");
					mp++;
				}
				if (mp == 8)
				{
					figure[trigger_figure].setemoj("2");
					mp++;
				}
				if (mp == 7)
				{
					if (figure[trigger_figure_to].value / 7 == 0)
						figure[trigger_figure_to].setemojanot("B_1");
					else figure[trigger_figure_to].setemojanot("5_1");
					mp ++;
				}
				if (mp == 6)
				{
					figure[trigger_figure].setemoj("3");
					mp++;
				}
				if (mp == 5)
				{
					figure[trigger_figure].sprite.setColor(Color(255, 255, 255, 255));
					mp++;
				}
				if (mp == 4)
				{
					figure[trigger_figure].x = figure[trigger_figure_to].x;
					figure[trigger_figure].y = figure[trigger_figure_to].y;
					mp++;
				}
				if (mp == 3)
				{
					figure[trigger_figure].sprite.setColor(Color(255, 255, 255, 0));
					mp++;
				}
				if (mp == 2)
				{
					figure[trigger_figure].setemoj("2");
					mp++;
				}
				if (mp == 1)
				{
					figure[trigger_figure].setemoj("3");
					mp++;
				}
				if (mp == 0)
				{
					figure[trigger_figure].setemoj("3");
					mp++;
				}
				break;
			case 6:
				if ((mp == 1)&& (!figure[trigger_figure].isMove))
				{
					figure[trigger_figure].isAttack = false;
					figure[trigger_figure_to].x = -50;
					figure[trigger_figure_to].x = -50;
					trigger_figure = -1;
					trigger_view = 0;
					mp = -1;
				}
				if (mp == 0)
				{
					figure[trigger_figure].isMove = true;
					mp++;
				}
				break;
			}
		}
		if (trigger_view < 180 )
		{
			sf::sleep(sf::seconds(0.01));
			trigger_view += 5;
			ChangeView(figure, 32, k, x_desk + 200, y_desk + 200, trigger_view);
		}
		window.setView(view);
		window.clear();
		i_mch = 0;
		j_mch = 0;
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == '0')
				{
					s_map.setTextureRect(IntRect(0, 0, 50, 50)); //���� ��������� ������ ������, �� ������ 1� ���������
					//trigger_map = 0;
				}
				if (TileMap[i][j] == 'w')
				{
					s_map.setTextureRect(IntRect(50, 0, 50, 50));//���� ��������� ������ s, �� ������ 2� ���������
					//trigger_map = 1;
				}
				if ((TileMap[i][j] == 'b'))
				{
					s_map.setTextureRect(IntRect(100, 0, 50, 50));//���� ��������� ������ 0, �� ������ 3� ���������
					//trigger_map = 1;
				}
				s_map.setPosition(j * 50, i * 50);
				window.draw(s_map);
			}
		for (int i = 0; i <= 32; i++)
			if (figure[i].pass == 1)
			{
				figure[i].reload();
				window.draw(figure[i].sprite);
				window.draw(figure[i].text);
			}
		if (trigger_figure_to != -1)
		window.draw(figure[trigger_figure_to].sprite);
		if (trigger_figure != -1)
		window.draw(figure[trigger_figure].sprite);
		window.display();
	}
	return 0;
}