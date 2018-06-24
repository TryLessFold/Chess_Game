#include<iostream>
#include<string>
#include<stdlib.h>
#include<fstream>
#include "Functions.h"

using namespace std;

void FileToMass(int **a, int n, string file1, int &k)
{
	ifstream file;
	file.open(file1 + ".txt");
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			file >> a[i][j];
	file >> k;
}

void MassToFile(int **a, int n, string file1, int k)
{
	ofstream file;
	file.open(file1 + ".txt");
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			file << a[i][j] << " ";
	file << k;
}

void FileToFile(string a, string b, int n)
{
	int k;
	ifstream file;
	ofstream file1;
	file.open(a + ".txt");
	file1.open(b + ".txt");
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			file >> k;
			file1 << k << " ";
		}
	file >> k;
	file1 << k << "";
}

/*
int CheckMove(int **a, int y, int x, int y1, int x1)
//0 - Невозможно походить, 1 - обычный ход, 2 - ход на врага, 3 - ход на союзника, 4-нет фигуры. y-строка x-столбец
{
	int chmove, k = 0, i, j;
	if (a[y][x] != 0)
	{
		if (a[y][x] > 7) chmove = (a[y][x] % 7) + 1;
		else chmove = a[y][x];
		switch (chmove)
		{
		case 1:
			if ((a[y1][x1] == 0) && (y == 7))
			{
				if ((&a[y - 1][x] == &a[y1][x1]) || (&a[y - 2][x] == &a[y1][x1])) return 1;
			}
			else if (a[y1][x1] == 0)
			{
				if ((&a[y - 1][x] == &a[y1][x1])) return 1;
			}
			else if ((&a[y - 1][x + 1] == &a[y1][x1]) || (&a[y - 1][x - 1] == &a[y1][x1]))
			{
				if ((a[y][x] / 7) != (a[y1][x1] / 7)) return 2;
				else return 3;
			}
			return 0;
			break;
		case 2:
			if ((x1 != x) && (y1 != y)) return 0;
			if (x1 == x)
			{
				if ((y1 - y) > 0)
				{
					for (i = y + 1; i < y1; i++)
					{
						if (a[i][x] == 0) k++;
					}
				}
				if ((y1 - y) < 0)
				{
					for (i = y - 1; i > y1; i--)
					{
						if (a[i][x] == 0) k++;
					}
				}
			}
			if (y1 == y)
			{
				if ((x1 - x) > 0)
				{
					for (i = x + 1; i < x1; i++)
					{
						if (a[y][i] == 0) k++;
					}
				}
				if ((x1 - x) < 0)
				{
					for (i = x - 1; i > x1; i--)
					{
						if (a[y][i] == 0) k++;
					}
				}
			}
			k++;
			if (((x == x1) && (abs(y - y1) == k)) || ((y == y1) && (abs(x - x1) == k)))
			{
				if (a[y1][x1] != 0)
				{
					if (a[y1][x1] / 7 != a[y][x] / 7) return 2;
					else return 3;
				}
				return 1;
			}
			else return 0;
			break;
		case 3:
			if (((abs(x1 - x) == 1) && (abs(y1 - y) == 2)) || ((abs(x1 - x) == 2) && (abs(y1 - y) == 1)))
			{
				if (a[y1][x1] != 0)
				{
					if (a[y1][x1] / 7 != a[y][x] / 7) return 2;
					else return 3;
				}
				return 1;
			}
			else return 0;
			break;
		case 4:
			if ((abs((y1 - y)) != abs((x1 - x))) || (abs(y1 - y) > 7))
			{
				return 0;
				break;
			}
			if ((y1 - y) > 0)
			{
				if ((x1 - x) > 0)
				{
					for (i = y + 1, j = x + 1; i < y1; i++, j++)
					{
						if (a[i][j] == 0) k++;
					}
				}
				if ((x1 - x) < 0)
				{
					for (i = y + 1, j = x - 1; (i < y1) && (j > x1); i++, j--)
					{
						if (a[i][j] == 0) k++;
					}
				}
			}
			if ((y1 - y) < 0)
			{
				if ((x1 - x) > 0)
				{
					for (i = y - 1, j = x + 1; i > y1; i--, j++)
					{
						if (a[i][j] == 0) k++;
					}
				}
				if ((x1 - x) < 0)
				{
					for (i = y - 1, j = x - 1; (i > y1) && (j > x1); i--, j--)
					{
						if (a[i][j] == 0) k++;
					}
				}
			}
			k++;
			if ((k == (y1 - y)) || (k == (y - y1)) || (k == (x1 - x)) || (k == (x - x1)))
			{
				if (a[y1][x1] != 0)
				{
					if (a[y1][x1] / 7 != a[y][x] / 7) return 2;
					else return 3;
				}
				return 1;
			}
			else return 0;
			break;
		case 5:
			if ((((x1 != x) && (y1 != y)) && ((abs(y1 - y) != abs(x1 - x)))) || (abs(y1 - y) > 7))
			{
				return 0;
				break;
			}
			if (x1 == x)
			{
				if ((y1 - y) > 0)
				{
					for (i = y + 1; i < y1; i++)
					{
						if (a[i][x] == 0) k++;
					}
				}
				if ((y1 - y) < 0)
				{
					for (i = y - 1; i > y1; i--)
					{
						if (a[i][x] == 0) k++;
					}
				}
			}
			if (y1 == y)
			{
				if ((x1 - x) > 0)
				{
					for (i = x + 1; i < x1; i++)
					{
						if (a[y][i] == 0) k++;
					}
				}
				if ((x1 - x) < 0)
				{
					for (i = x - 1; i > x1; i--)
					{
						if (a[y][i] == 0) k++;
					}
				}
			}
			if ((y1 - y) > 0)
			{
				if ((x1 - x) > 0)
				{
					for (i = y + 1, j = x + 1; i < y1; i++, j++)
					{
						if (a[i][j] == 0) k++;
					}
				}
				if ((x1 - x) < 0)
				{
					for (i = y + 1, j = x - 1; (i < y1) && (j > x1); i++, j--)
					{
						if (a[i][j] == 0) k++;
					}
				}
			}
			if ((y1 - y) < 0)
			{
				if ((x1 - x) > 0)
				{
					for (i = y - 1, j = x + 1; i > y1; i--, j++)
					{
						if (a[i][j] == 0) k++;
					}
				}
				if ((x1 - x) < 0)
				{
					for (i = y - 1, j = x - 1; (i > y1) && (j > x1); i--, j--)
					{
						if (a[i][j] == 0) k++;
					}
				}
			}
			k++;
			//cout << k << endl;
			if (((x == x1) && (abs(y - y1) == k)) || ((y == y1) && (abs(x - x1) == k))
				|| ((k == abs(y1 - y)) && ((x1 != x) && (y1 != y)) || ((k == abs(x1 - x)) && ((x1 != x) && (y1 != y)))))
			{
				if (a[y1][x1] != 0)
				{
					if (a[y1][x1] / 7 != a[y][x] / 7) return 2;
					else return 3;
				}
				return 1;
			}
			else return 0;
			break;

		case 6:
			if ((abs(y1 - y) > 1) || (abs(x1 - x) > 1)) return 0;
			if (a[y1][x1] != 0)
			{
				if (a[y1][x1] / 7 != a[y][x] / 7) return 2;
				else return 3;
			}
			return 1;
			break;
		case 7:
			if ((a[y1][x1] == 0) && (y == 2))
			{
				if ((&a[y + 1][x] == &a[y1][x1]) || (&a[y + 2][x] == &a[y1][x1])) return 1;
			}
			else if (a[y1][x1] == 0)
			{
				if ((&a[y + 1][x] == &a[y1][x1])) return 1;
			}
			else if ((&a[y + 1][x + 1] == &a[y1][x1]) || (&a[y + 1][x - 1] == &a[y1][x1]))
			{
				if (((a[y][x] / 7) != (a[y1][x1] / 7))) return 2;
				else return 3;
			}
			return 0;
			break;
		}
	}
	else return 4;
}
*/

void Game(string Saves)
{
	int i = 0, i1, pass, **a;
	char castling[2] = { 3,3 }, parry[2] = { 0,0 }, x_parrying;
	char i_blackk = 1, j_blackk = 5, i_whitek = 8, j_whitek = 4;
	char j = 0, j1 = 0;
	int k = 0, b, w;
	a = new int*[10];
	for (int i = 0; i<10; i++)
		a[i] = new int[10];
	FileToMass(a, 8, Saves, k);
	system("CLS");
	cout << "To exit input 99 to i!!!" << endl;
	system("PAUSE");
	while (1)
	{
		system("CLS");
		if ((k == 1) && (CheckSafetyKing(a, i_blackk, j_blackk)))
		{
			if (b == 1)
			{
				cout << "Whites win!" << endl;
				system("PAUSE");
				break;
			}
			w = 1;
			cout << "CHECK!" << endl;
		}
		else b = 0;
		if ((k == 0) && (CheckSafetyKing(a, i_whitek, j_whitek)))
		{
			if (w == 1)
			{
				cout << "Blacks win!" << endl;
				system("PAUSE");
				break;
			}
			w = 1;
			cout << "CHECK!" << endl;
		}
		else w = 0;
		stdout_chess(a, k);
		cout << endl;
		printf("input number: ");
		cin >> i;
		if (i == 99) break;
		i = 9 - i;
		printf("input char: ");
		cin >> j;
		j -= ('a' - 1);
		if ((a[i][j] / 7) != k)
		{
			while ((a[i][j] / 7) != k)
			{
				system("CLS");
				cout << "Not your figure!" << endl;
				stdout_chess(a, k);
				cout << endl;
				printf("input number: ");
				cin >> i;
				i = 9 - i;
				printf("input char: ");
				cin >> j;
				j -= ('a' - 1);
			}
		}
		cout << endl;
		printf("input number to: ");
		cin >> i1;
		printf("input char to: ");
		cin >> j1;
		i1 = 9 - i1;
		j1 -= ('a' - 1);
		if ((i > 0) && (i < 9) && (j > 0) && (j < 9) && (j1 > 0) && (j1 < 9) && (i1 > 0) && (i1 < 9))
		{
			pass = CheckMove(a, i, j, i1, j1);
			if (((a[i][j] == 12) || (a[i][j] == 6)) && (castling[k] > 0) && (pass == 0))
				pass = Castling(a, i, j, i1, j1, castling[k]);
			if ((parry[k] == 1) && (j1 == x_parrying))
			{
				if (((a[i][j] == 1) || (a[i][j] == 7)) && (pass == 0))
				{
					pass = Attack(a, i, j, i1, j1);
					parry[k] = 0;
				}
				else
					parry[k] = 0;
			}
			if (((a[i][j] == 1) || (a[i][j] == 7)) && (pass != 0))
			{
				parry[1 - k] = Charge(a, i, j, i1, j1);
				if (parry[1 - k] != 0) x_parrying = j1;
			}
		}
		else pass = 4;
		//cout << "pass= " << pass << endl;
		if (pass == 0) printf("Wrong Move\n");
		if (pass == 3) printf("FRIEND!\n");
		if (pass == 1)
		{
			if ((a[i][j] == 2) && (castling[k] != 0))
			{
				if (j == 1) castling[k] = 2;
				else if (j == 8) castling[k] = 1;
			}
			if (((a[i][j] == 12) || (a[i][j] == 6)) && (castling[k] != 0)) castling[k] = 0;
			k = 1 - k;
			SwapMove(&a[i][j], &a[i1][j1]);
			cout << i << " " << j << endl;
			Change(a, i1, j1);
			system("Pause");
		}
		if (pass == 2)
		{
			if ((a[i][j] == 2) && (castling[k] != 0))
			{
				if (j == 1) castling[k] = 2;
				else if (j == 8) castling[k] = 1;
			}
			if (((a[i][j] == 12) || (a[i][j] == 6)) && (castling[k] != 0)) castling[k] = 0;
			k = 1 - k;
			SwapMove(&a[i][j], &a[i1][j1]);
			Change(a, i, j);
		}
		if (pass == 4) printf("Choose Figure\n");
		if (pass == 5)
		{
			printf("U are on the true way\n");
			SwapMove(&a[i][j], &a[i1][j1]);
			if (j1>j)
				SwapMove(&a[i1][8], &a[i1][j1 - 1]);
			else
				SwapMove(&a[i1][1], &a[i1][j1 + 1]);
			castling[k] = 0;
			k = 1 - k;
		}
		if (pass == 6)
		{
			printf("U can!\n");
			SwapMove(&a[i][j1], &a[i1][j1]);
			SwapMove(&a[i][j], &a[i1][j1]);
			k = 1 - k;
		}
		if ((pass == 6) || (pass == 1) || (pass == 2) || (pass == 5))
		{
			system("CLS");
			stdout_chess(a, 1 - k);
		}
		system("Pause");
	}
	MassToFile(a, 8, "1", k);
}

int main()
{
	char ch = 0;
	string str;
	ifstream file;
	while (ch != '5')
	{
		system("CLS");
		cout << "1. Continue" << endl;
		cout << "2. New Game" << endl;
		cout << "3. Save Game" << endl;
		cout << "4. Load Game" << endl;
		cout << "5. Exit" << endl;
		cout << "Input: "; cin >> ch;
		switch (ch)
		{
		case '1':
			file.open("1.txt");
			if (!file.is_open()) cout << "There isn't such file" << endl;
			else Game("1");
			break;
		case '2':
			Game("0");
			break;
		case '3':
			cout << "Enter the name file:" << endl;
			cin >> str;
			FileToFile("1", str, 8);
			break;
		case '4':
			cout << "Enter the name file:" << endl;
			cin >> str;
			file.open(str + ".txt");
			if (!file.is_open()) cout << "There isn't such file" << endl;
			else Game(str);
			system("Pause");
		}
	}
	return 0;
}
