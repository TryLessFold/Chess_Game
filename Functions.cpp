#include<iostream>
#include<string>
#include<stdlib.h>
#include<fstream>
#include "Functions.h"
//#include <stdexcept>
//#include <stdafx.h>

using namespace std;

int CheckMove(int **a, int y, int x, int y1, int x1)
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

int CheckSafetyKing(int **a, int y, int x)
	{
		for (int i = 1; i<9; i++)
			for (int j = 1; j<9; j++)
				if (CheckMove(a, i, j, y, x) == 2) return 1;
		return 0;
	}

int Castling(int **a, int y, int x, int y1, int x1, int cast)
	{
		if ((abs(x - x1) == 2) && (y = y1) && (x1 != x))
		{
			if (CheckSafetyKing(a, y, x) == 0)
			{
				if ((x1 > x) && ((cast == 3) || (cast == 2)))
				{
					for (int i = x + 1; i < 8; i++)
					{
						if ((abs(x - i) <= 2) && (CheckSafetyKing(a, y, i) == 1)) return 0;
						if (a[y][i] != 0) return 0;
					}
					return 5;
				}
				if ((x1 < x) && ((cast == 3) || (cast == 1)))
				{
					for (int i = x - 1; i > 1; i--)
					{
						if ((abs(x - i) <= 2) && (CheckSafetyKing(a, y, i) == 1)) return 0;
						if (a[y][i] != 0) return 0;
					}
					return 5;
				}
				return 0;
			}
		}
		else return 0;
	}

int Charge(int **a, int y, int x, int y1, int x1)
	{
		if ((a[y][x] == 1) && ((y - y1) == 2))
		{
			if ((a[y1][x1 - 1] == 7) || (a[y1][x1 + 1] == 7)) return 1;
		}
		else if ((a[y][x] == 7) && ((y1 - y) == 2))
		{
			if ((a[y1][x1 - 1] == 1) || (a[y1][x1 + 1] == 1)) return 1;
		}
		else return 0;
	}

void Change(int **a, int y, int x)
	{
		int l = 0;
		if ((a[y][x] == 1) && (y == 1))
		{
			cout << "Choose figure for transfer:" << endl;
			cout << "1.Pawn" << endl;
			cout << "2. Rook" << endl;
			cout << "3.Knight" << endl;
			cout << "4. Bishop" << endl;
			cout << "5. Queen" << endl;
			cin >> l;
			if ((l >= 1) && (l <= 5)) a[y][x] = l;
		}
		if ((a[y][x] == 7) && (y == 8))
		{
			cout << "Choose figure for transfer:" << endl;
			cout << "7.Pawn" << endl;
			cout << "8. Rook" << endl;
			cout << "9.Knight" << endl;
			cout << "10. Bishop" << endl;
			cout << "11. Queen" << endl;
			cin >> l;
			if ((l >= 7) && (l <= 11)) a[y][x] = l;
		}
	}

void SwapMove(int *a, int *b)
	{
		*b = *a;
		*a = 0;
	}

void stdout_chess(int **a, int k)
	{
		for (int i = 1; i < 9; i++)
		{
			printf("\n | \n");
			if (k == 0)
				printf("%d|", 9 - i);
			else
				printf("%d|", i);
			for (int j = 1; j < 9; j++)
				if (k == 0) printf("%3d ", a[i][j]);
				else printf("%3d ", a[9 - i][9 - j]);
		}
		printf("\n");
		printf(" ---------------------------------\n");
		if (k == 0)
			printf("  %3c %3c %3c %3c %3c %3c %3c %3c\n", 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h');
		else
			printf("  %3c %3c %3c %3c %3c %3c %3c %3c\n", 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a');
	}

int Attack(int **a, int y, int x, int y1, int x1)
	{
		if (a[y][x] == 1)
		{
			if ((a[y][x - 1] == 7) || (a[y][x + 1] == 7)) return 6;
		}
		if (a[y][x] == 7)
		{
			if ((a[y][x - 1] == 1) || (a[y][x + 1] == 1)) return 6;
		}
		return 0;
	}

