//#pragma once
#ifndef GG
#define GG

void SwapMove(int *a, int *b);
void stdout_chess(int **a, int k);
int Attack(int **a, int y, int x, int y1, int x1);
int CheckMove(int **a, int y, int x, int y1, int x1);
int CheckSafetyKing(int **a, int y, int x);
int Castling(int **a, int y, int x, int y1, int x1, int cast);
int Charge(int **a, int y, int x, int y1, int x1);
void Change(int **a, int y, int x);
#endif
