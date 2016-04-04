#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<ctime>
#include<string>
#include<fstream>
#include"Sudoku.h"
using namespace std;
int i,j;
int map[9][9];
int ans[9][9];
int answer[0];
void giveQuestion();
void readIn();
void solve();
void changeNum(int,int);
void changeRow(int,int);
void changeCol(int,int);
void rotate(int);
void flip(int);
void transform();
void solve_sudoku();
void print_ans();
void change();
void printOut();
int checkRow(int,int);
int checkCol(int,int);
int checkSquare(int,int,int);
int main(){
	giveQuestion();
	Sudoku hey;
	hey.solve();
	system("pause");
	return 0;
}

void giveQuestion(){
	int Question_Num=5;
	srand(time(NULL));
	int n;
	n=rand()%Question_Num;
	switch(n){
		case 0:
			printf("0 3 0 0 0 0 0 0 0\n");
			printf("0 4 0 0 0 0 0 0 6\n");
			printf("0 0 2 8 0 0 0 0 0\n");
			printf("0 0 0 0 5 0 7 0 0\n");
			printf("0 0 0 0 0 0 8 2 0\n");
			printf("0 0 0 0 3 1 0 0 0\n");
			printf("0 0 0 0 0 0 0 5 4\n");
			printf("0 0 7 0 6 0 0 0 1\n");
			printf("0 0 8 0 0 0 0 0 0\n");
			break;
		case 1:
			printf("0 0 0 0 0 0 0 0 0\n");
			printf("8 0 0 2 0 0 0 0 1\n");
			printf("0 9 0 0 0 0 0 7 0\n");
			printf("0 0 0 0 0 7 0 0 0\n");
			printf("0 0 2 0 5 0 0 0 8\n");
			printf("4 0 0 0 0 0 2 0 6\n");
			printf("0 0 0 8 0 9 4 0 0\n");
			printf("0 5 7 0 6 0 0 0 0\n");
			printf("0 0 0 0 0 0 0 0 0\n");
			break;
		case 2:
			printf("0 0 0 0 3 0 0 0 0\n");
			printf("0 0 0 0 8 5 0 0 0\n");
			printf("0 7 0 0 0 0 0 0 4\n");
			printf("0 0 0 0 0 0 0 0 6\n");
			printf("0 0 3 0 9 0 0 0 0\n");
			printf("0 6 0 0 0 0 0 7 1\n");
			printf("0 0 0 0 0 0 8 0 0\n");
			printf("0 1 0 6 0 0 0 0 0\n");
			printf("0 0 5 9 0 0 3 0 0\n");
			break;
		case 3:
			printf("2 0 5 0 0 0 0 0 0\n");
			printf("0 0 0 0 0 0 0 0 6\n");
			printf("0 0 1 0 0 0 0 0 0\n");
			printf("0 0 0 0 0 5 0 0 0\n");
			printf("0 0 9 0 0 2 0 4 0\n");
			printf("0 7 0 0 0 0 0 0 8\n");
			printf("0 6 0 0 8 0 0 0 0\n");
			printf("0 0 0 0 0 0 5 0 1\n");
			printf("0 4 0 0 7 0 0 9 0\n");
			break;
		case 4:
			printf("0 0 0 0 0 0 0 0 0\n");
			printf("0 0 1 0 0 4 0 8 0\n");
			printf("0 0 0 0 0 0 0 7 3\n");
			printf("0 0 0 0 3 0 0 0 0\n");
			printf("0 0 9 0 0 0 4 0 0\n");
			printf("0 0 8 6 0 0 0 0 2\n");
			printf("3 0 0 0 0 0 0 5 0\n");
			printf("2 0 0 0 0 0 0 0 0\n");
			printf("0 7 0 0 0 9 8 0 0\n");
			break;
	}
}



void Sudoku::changeNum(int a,int b){
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
				if(map[i][j]==a){
					map[i][j]==b;
					return;
				}
				if(map[i][j]==b){
					map[i][j]==a;
					return;
				}
		}
	}
}
void Sudoku::changeRow(int a,int b){
	int x;
	if(a!=b){
		for(i=0;i<3;i++){
			for(j=0;j<9;j++){
				x=map[a*3+i][j];
				map[a*3+i][j]=map[b*3+i][j];
				map[b*3+i][j]=x;
				return;
			}
		}
	}
	else return;
}

void Sudoku::changeCol(int a,int b){
	int x;
	if(a!=b){
		for(j=0;j<3;j++){
			for(i=0;i<9;i++){
				x=map[i][a*3+j];
				map[i][a*3+j]=map[i][b*3+j];
				map[i][b*3+j]=x;
				return;
			}
		}
	}
	else return;
}

void Sudoku::rotate(int n){
	if(n%4==0) return;
	if(n%4==1){
		/*90 degrees*/
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				map[j][8-i]=map[i][j];
				return;
			}
		}	
	}
	if(n%4==2){
		/*180 degrees*/
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				map[8-i][8-j]=map[i][j];
				return;
			}
		}	
	}
	if(n%4==3){
		/*270 degrees*/
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				map[8-j][i]=map[i][j];
				return;
			}
		}
	}
}

void Sudoku::flip(int n){
	int x,y;
	if(n==0){
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				x=map[8-i][j];
				map[8-i][j]=map[i][j];
				map[i][j]=x;
				return;
			}
		}
	}
	if(n==1){
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				y=map[i][8-j];
				map[i][8-j]=map[i][j];
				map[i][j]=y;
				return;
			}
		}
	}
}

void Sudoku::transform(){
	readIn();
	change();
	printOut(false);
}

void Sudoku::change(){
	srand(time(NULL));
	changeNum(rand()%9+1,rand()%9+1);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
}

void Sudoku::printOut(bool isAns){
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}
	/*if(!isAns){
		for(i=0;i<9;++i){
			for(j=0;j<9;++j){
				cout<<map[i][j];
			}
		}
	}
	else{
		for(i=0;i<9;++i){
			for(j=0;j<9;++j){
				cout<<ans[i][j];
			}
		}
	}*/
}

void Sudoku::solve(){
	readIn();
	solve_sudoku();
	if(answer[0]==0) cout<<"0"<<endl;
	else if(answer[0]==1){
		cout<<"1"<<endl;
		print_ans();
	}
}

void Sudoku::readIn(){	
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			cin>>map[i][j];
		}
	}
}

void print_ans(){
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}

void solve_sudoku(){
	int num=0;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(map[i][j]!=0) num++;
		}
	}
	if(num==81){
		answer[0]++;
		if(answer[0]==2){
			printf("2\n");
			return;
		}
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				ans[i][j]=map[i][j];
			}
		}
		return;
	}
	int input;
	for(i=8;i>=0;i--){
		for(j=8;j>=0;j--){
			if(map[i][j]==0){
				for(input=1;input<=9;input++){
					if(checkRow(input,i)==1&&checkCol(input,j)==1&&checkSquare(input,i,j)==1){
						map[i][j]=input;
						solve_sudoku();
						map[i][j]=0;
					}
				}
				return;
			}
		}
	}
}

int checkRow(int row,int r){
	for(j=0;j<9;j++){
		if(map[r][j]==row)
		return 0;
	}
	return 1;
}

int checkCol(int col,int c){
	for(i=0;i<9;i++){
		if(map[i][c]==col)
		return 0;
	}
	return 1;
}

int checkSquare(int square,int s1,int s2){
	int x=s1-(s1%3),y=s2-(s2%3);
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(map[x+i][y+j]==square)
			return 0;
		}
	}
	return 1;
}
