#include<CppUnitTest.h>
#include<iostream>
#include<string>
#include<stdlib.h>
#include<fstream>
#include "../main/Functions.h"

//using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void FillMass(int **a)
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
	a[4][4] = 0; a[5][4] = 0;
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

namespace Tests
{
	TEST_CLASS(TCheckMove)
	{
	public:

		TEST_METHOD(Empty)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			const int i = 4;
			const int j = 4;
			const int i1 = 6;
			const int j1 = 6;
			const int result = CheckMove(s, i, j, i1, j1);
			const int expected = 4;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(NoField)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[4][4] = 11;
			const int i = 4;
			const int j = 4;
			const int i1 = 55;
			const int j1 = 4;
			const int result = CheckMove(s, i, j, i1, j1);
			const int expected = 0;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Friend1)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[4][4] = 5;
			s[6][6] = 1;
			const int i = 4;
			const int j = 4;
			const int i1 = 6;
			const int j1 = 6;
			const int result = CheckMove(s, i, j, i1, j1);
			const int expected = 3;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Friend2)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[4][4] = 5;
			s[5][5] = 1;
			const int i = 4;
			const int j = 4;
			const int i1 = 6;
			const int j1 = 6;
			const int result = CheckMove(s, i, j, i1, j1);
			const int expected = 0;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Enemy1)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[4][4] = 5;
			s[6][6] = 11;
			const int i = 4;
			const int j = 4;
			const int i1 = 6;
			const int j1 = 6;
			const int result = CheckMove(s, i, j, i1, j1);
			const int expected = 2;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Enemy2)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[4][4] = 5;
			s[5][5] = 11;
			const int i = 4;
			const int j = 4;
			const int i1 = 6;
			const int j1 = 6;
			const int result = CheckMove(s, i, j, i1, j1);
			const int expected = 0;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(QNormal)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[4][4] = 5;
			const int i = 4;
			const int j = 4;
			const int i1 = 6;
			const int j1 = 6;
			const int result = CheckMove(s, i, j, i1, j1);
			const int expected = 1;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(QNormal2)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[4][4] = 11;
			const int i = 4;
			const int j = 4;
			const int i1 = 1;
			const int j1 = 4;
			const int result = CheckMove(s, i, j, i1, j1);
			const int expected = 1;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(QError)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i < 10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[4][4] = 5;
			const int i = 4;
			const int j = 4;
			const int i1 = 2;
			const int j1 = 5;
			const int result = CheckMove(s, i, j, i1, j1);
			const int expected = 0;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(PNormal)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[4][4] = 1;
			const int i = 4;
			const int j = 4;
			const int i1 = 3;
			const int j1 = 4;
			const int result = CheckMove(s, i, j, i1, j1);
			const int expected = 1;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(PRushT)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[7][1] = 1;
			const int i = 7;
			const int j = 1;
			const int i1 = 5;
			const int j1 = 1;
			const int result = CheckMove(s, i, j, i1, j1);
			const int expected = 1;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(PRushF)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[7][1] = 1;
			const int i = 7;
			const int j = 1;
			const int i1 = 4;
			const int j1 = 1;
			const int result = CheckMove(s, i, j, i1, j1);
			const int expected = 0;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(PError)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[4][4] = 1;
			const int i = 4;
			const int j = 4;
			const int i1 = 3;
			const int j1 = 3;
			const int result = CheckMove(s, i, j, i1, j1);
			const int expected = 0;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(HNormal)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[4][4] = 3;
			const int i = 4;
			const int j = 4;
			const int i1 = 2;
			const int j1 = 3;
			const int result = CheckMove(s, i, j, i1, j1);
			const int expected = 1;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(HError)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[4][4] = 9;
			const int i = 4;
			const int j = 4;
			const int i1 = 3;
			const int j1 = 3;
			const int result = CheckMove(s, i, j, i1, j1);
			const int expected = 0;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(KNormal1)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[4][4] = 6;
			const int i = 4;
			const int j = 4;
			const int i1 = 3;
			const int j1 = 4;
			const int result = CheckMove(s, i, j, i1, j1);
			const int expected = 1;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(KNormal2)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[4][4] = 12;
			const int i = 4;
			const int j = 4;
			const int i1 = 3;
			const int j1 = 3;
			const int result = CheckMove(s, i, j, i1, j1);
			const int expected = 1;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(KError)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[4][4] = 12;
			const int i = 4;
			const int j = 4;
			const int i1 = 6;
			const int j1 = 6;
			const int result = CheckMove(s, i, j, i1, j1);
			const int expected = 0;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(ENormal)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[4][4] = 4;
			const int i = 4;
			const int j = 4;
			const int i1 = 2;
			const int j1 = 2;
			const int result = CheckMove(s, i, j, i1, j1);
			const int expected = 1;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(EError)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[4][4] = 10;
			const int i = 4;
			const int j = 4;
			const int i1 = 3;
			const int j1 = 1;
			const int result = CheckMove(s, i, j, i1, j1);
			const int expected = 0;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(RNormal)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[4][4] = 8;
			const int i = 4;
			const int j = 4;
			const int i1 = 1;
			const int j1 = 4;
			const int result = CheckMove(s, i, j, i1, j1);
			const int expected = 1;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(RError)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[4][4] = 2;
			const int i = 4;
			const int j = 4;
			const int i1 = 3;
			const int j1 = 3;
			const int result = CheckMove(s, i, j, i1, j1);
			const int expected = 0;
			Assert::AreEqual(expected, result);
		}

	};

	TEST_CLASS(TCharge)
	{
	public:

		TEST_METHOD(NormalW)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[3][2] = 1;
			s[1][2] = 7;
			const int i = 3;
			const int j = 2;
			const int i1 = 1;
			const int j1 = 1;
			const int result = Charge(s, i, j, i1, j1);
			const int expected = 1;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(NormalB)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[1][2] = 7;
			s[3][2] = 1;
			const int i = 1;
			const int j = 2;
			const int i1 = 3;
			const int j1 = 1;
			const int result = Charge(s, i, j, i1, j1);
			const int expected = 1;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(ErrorW)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i < 10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[3][2] = 2;
			s[1][2] = 8;
			const int i = 3;
			const int j = 2;
			const int i1 = 1;
			const int j1 = 1;
			const int result = Charge(s, i, j, i1, j1);
			const int expected = 0;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(ErrorB)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i < 10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[1][2] = 11;
			s[3][2] = 1;
			const int i = 1;
			const int j = 2;
			const int i1 = 3;
			const int j1 = 1;
			const int result = Charge(s, i, j, i1, j1);
			const int expected = 0;
			Assert::AreEqual(expected, result);
		}
	};

	TEST_CLASS(TAttak)
	{
	public:

		TEST_METHOD(NormalW)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[1][1] = 1;
			s[1][2] = 7;
			const int i = 1;
			const int j = 1;
			const int i1 = 1;
			const int j1 = 2;
			const int result = Attack(s, i, j, i1, j1);
			const int expected = 6;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(NormalB)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[1][1] = 7;
			s[1][2] = 1;
			const int i = 1;
			const int j = 1;
			const int i1 = 1;
			const int j1 = 2;
			const int result = Attack(s, i, j, i1, j1);
			const int expected = 6;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(ErrorW)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i < 10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[1][1] = 1;
			s[1][2] = 11;
			const int i = 1;
			const int j = 1;
			const int i1 = 1;
			const int j1 = 2;
			const int result = Attack(s, i, j, i1, j1);
			const int expected = 0;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(ErrorB)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i < 10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[1][1] = 7;
			s[1][2] = 5;
			const int i = 1;
			const int j = 1;
			const int i1 = 1;
			const int j1 = 2;
			const int result = Attack(s, i, j, i1, j1);
			const int expected = 0;
			Assert::AreEqual(expected, result);
		}
	};

	TEST_CLASS(TCastling)
	{
	public:

		TEST_METHOD(NormalS)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[1][1] = 2;
			s[1][4] = 6;
			const int i = 1;
			const int j = 4;
			const int i1 = 1;
			const int j1 = 2;
			const int result = Castling(s, i, j, i1, j1, 3);
			const int expected = 5;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(ErrorW1)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[1][1] = 2;
			s[1][4] = 6;
			const int i = 1;
			const int j = 4;
			const int i1 = 5;
			const int j1 = 5;
			const int result = Castling(s, i, j, i1, j1, 3);
			const int expected = 0;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(ErrorW2)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i < 10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[1][1] = 2;
			s[1][4] = 6;
			const int i = 1;
			const int j = 4;
			const int i1 = 1;
			const int j1 = 8;
			const int result = Castling(s, i, j, i1, j1, 3);
			const int expected = 0;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(ErrorW3)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[1][1] = 2;
			s[1][4] = 6;
			s[1][2] = 1;
			const int i = 1;
			const int j = 4;
			const int i1 = 1;
			const int j1 = 2;
			const int result = Castling(s, i, j, i1, j1, 3);
			const int expected = 0;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(NormalB)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[1][8] = 2;
			s[1][4] = 6;
			const int i = 1;
			const int j = 4;
			const int i1 = 1;
			const int j1 = 6;
			const int result = Castling(s, i, j, i1, j1, 3);
			const int expected = 5;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(ErrorB1)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[8][5] = 12;
			s[8][1] = 8;
			const int i = 8;
			const int j = 5;
			const int i1 = 8;
			const int j1 = 7;
			const int result = Castling(s, i, j, i1, j1, 3);
			const int expected = 0;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(ErrorB2)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[8][5] = 12;
			s[5][5] = 8;
			const int i = 8;
			const int j = 5;
			const int i1 = 8;
			const int j1 = 7;
			const int result = Castling(s, i, j, i1, j1, 3);
			const int expected = 0;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(ErrorB3)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[8][5] = 12;
			s[8][1] = 8;
			s[8][2] = 7;
			const int i = 8;
			const int j = 5;
			const int i1 = 8;
			const int j1 = 2;
			const int result = Castling(s, i, j, i1, j1, 3);
			const int expected = 0;
			Assert::AreEqual(expected, result);
		}

	};

	TEST_CLASS(TChSKing)
	{
	public:

		TEST_METHOD(Clean)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[1][1] = 12;
			const int i = 1;
			const int j = 1;
			const int result = CheckSafetyKing(s, i, j);
			const int expected = 0;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Check)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i < 10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[1][1] = 6;
			const int i = 1;
			const int j = 1;
			s[3][3] = 11;
			const int result = CheckSafetyKing(s, i, j);
			const int expected = 1;
			Assert::AreEqual(expected, result);
		}
	};

	TEST_CLASS(TSwapMove)
	{
	public:

		TEST_METHOD(Swap)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[1][1] = 1;
			const int i = 1;
			const int j = 1;
			const int i1 = 2;
			const int j1 = 2;
			int result = 0;
			SwapMove(&s[i][j], &s[i1][j1]);
			if ((s[i][j] == 0) && (s[i1][j1] == 1)) result = 1;
			const int expected = 1;
			Assert::AreEqual(expected, result);
		}

	};

	TEST_CLASS(TChange)
	{
	public:

		TEST_METHOD(SwapB)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[7][1] = 7;
			const int l = 10;
			const int y = 7;
			const int x = 1;
			if ((l >= 7) && (l <= 11)) s[y][x] = l;
			int result = 0;
			if (s[y][x] == 10)  result = 1;
			const int expected = 1;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(SwapW)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[1][1] = 1;
			const int l = 3;
			const int y = 1;
			const int x = 1;
			if ((l >= 1) && (l <= 5)) s[y][x] = l;
			int result = 0;
			if (s[y][x] == 3)  result = 1;
			const int expected = 1;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(ErrorB)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[7][1] = 7;
			const int l = 3;
			const int y = 7;
			const int x = 1;
			if ((l >= 7) && (l <= 11)) s[y][x] = l;
			int result = 0;
			if (s[y][x] == 9)  result = 1;
			const int expected = 0;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(ErrorW)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[1][1] = 1;
			const int l = 10;
			const int y = 1;
			const int x = 1;
			if ((l >= 1) && (l <= 5)) s[y][x] = l;
			int result = 0;
			if (s[y][x] == 4)  result = 1;
			const int expected = 0;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Error)
		{
			int **s;
			s = new int*[10];
			for (int i = 0; i<10; i++)
				s[i] = new int[10];
			FillMass(s);
			s[1][1] = 1;
			const int l = 12;
			const int y = 1;
			const int x = 1;
			if ((l >= 1) && (l <= 5)) s[y][x] = l;
			int result = 0;
			if (s[y][x] == 12)  result = 1;
			const int expected = 0;
			Assert::AreEqual(expected, result);

		}

	};

}