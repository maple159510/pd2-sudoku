#include<iostream>
using namespace std;
class Sudoku{
public:
	void giveQuestion();
	void readIn();
	void solve();
	void changeNum(int,int);
	void changeRow(int,int);
	void changeCol(int,int);
	void rotate(int);
	void flip(int);
	void transform();
	void change();
	void printOut(bool);
	int answer[1];
	int map[9][9];
	int ans[9][9];
};
