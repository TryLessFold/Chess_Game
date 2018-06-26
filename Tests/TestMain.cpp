#include<CppUnitTest.h>
#include<iostream>
#include<string>
#include<stdlib.h>
#include<fstream>
#include "../main/Functions.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void FillMass(int a[8][8])
{
	a[7][0] = 0; a[6][0] = 0;
	a[7][1] = 0; a[6][1] = 0;
	a[7][2] = 0; a[6][2] = 0;
	a[7][3] = 0; a[6][3] = 0;
	a[7][4] = 0; a[6][4] = 0;
	a[7][5] = 0; a[6][5] = 0;
	a[7][6] = 0; a[6][6] = 0;
	a[7][7] = 0; a[6][7] = 0;

	a[2][0] = 0; a[3][0] = 0;
	a[2][1] = 0; a[3][1] = 0;
	a[2][2] = 0; a[3][2] = 0;
	a[2][3] = 0; a[3][3] = 0;
	a[2][4] = 0; a[3][4] = 0;
	a[2][5] = 0; a[3][5] = 0;
	a[2][6] = 0; a[3][6] = 0;
	a[2][7] = 0; a[3][7] = 0;

	a[4][0] = 0; a[5][0] = 0;
	a[4][1] = 0; a[5][1] = 0;
	a[4][2] = 0; a[5][2] = 0;
	a[4][3] = 0; a[5][3] = 0;
	a[4][4] = 5; a[5][4] = 0;
	a[4][5] = 0; a[5][5] = 0;
	a[4][6] = 0; a[5][6] = 0;
	a[4][7] = 0; a[5][7] = 0;

	a[0][0] = 0; a[1][0] = 0;
	a[0][1] = 0; a[1][1] = 0;
	a[0][2] = 0; a[1][2] = 0;
	a[0][3] = 0; a[1][3] = 0;
	a[0][4] = 0; a[1][4] = 0;
	a[0][5] = 0; a[1][5] = 0;
	a[0][6] = 0; a[1][6] = 0;
	a[0][7] = 0; a[1][7] = 0;
};

int CheckMove(int a[8][8], int y, int x, int y1, int x1)
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


namespace Tests
{
	TEST_CLASS(TestTest)
	{
	public:

		TEST_METHOD(Test1)
		{
			int s[8][8];
			FillMass(s);
			const int i = 4;
			const int j = 4;
			const int i1 = 6;
			const int j1 = 6;
			const int result = CheckMove(s, i, j, i1, j1);
			const int expected = 1;
			Assert::AreEqual(expected, result);
		}


	};

}