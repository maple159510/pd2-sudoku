#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<ctime>
#include<string>
#include<fstream>
#include"Sudoku.h"
using namespace std;

int map[9][9];
int ans[9][9];
int answer[0];

void giveQuestion();
void readIn();

void transform();
void changeNum(int,int);
void changeRow(int,int);
void changeCol(int,int);
void rotate(int);
void flip(int);

void solve();
void solve_sudoku();

void printOut();

int checkRow(int,int);
int checkCol(int,int);
int checkSquare(int,int,int);

void Sudoku::giveQuestion(){
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

void Sudoku::readIn(){//right
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cin>>map[i][j];
		}
	}
}

void Sudoku::changeNum(int a,int b){//right	
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
					if(map[i][j]==a){
						map[i][j]=b;
					}	
					else if(map[i][j]==b){
						map[i][j]=a;
					}
			}
		}	
}
void Sudoku::changeRow(int a,int b){//right
	int x;
	if(a!=b){
		for(int i=0;i<3;i++){
			for(int j=0;j<9;j++){
				x=map[a*3+i][j];
				map[a*3+i][j]=map[b*3+i][j];
				map[b*3+i][j]=x;
			}
		}
		return;
	}
	else cout<<"Failed"<<endl;
}

void Sudoku::changeCol(int a,int b){//right
	int x;
	if(a!=b){
		for(int j=0;j<3;j++){
			for(int i=0;i<9;i++){
				x=map[i][a*3+j];
				map[i][a*3+j]=map[i][b*3+j];
				map[i][b*3+j]=x;
			}
		}
		return;
	}
	else cout<<"Failed"<<endl;
}

void Sudoku::rotate(int n){//right
	int ww[9][9]={0};
	if(n%4==0) return;
	if(n%4==1){
		/*90 degrees*/
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				ww[j][8-i]=map[i][j];
			}
		}
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				map[i][j]=ww[i][j];
			}
		}
		return;	
	}
	if(n%4==2){
		/*180 degrees*/
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				ww[8-i][8-j]=map[i][j];
			}
		}
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				map[i][j]=ww[i][j];
			}
		}	
		return;
	}
	if(n%4==3){
		/*270 degrees*/
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				ww[8-j][i]=map[i][j];
			}
		}
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				map[i][j]=ww[i][j];
			}
		}
		return;
	}
}

void Sudoku::flip(int n){//right
	int x,y;
	if(n==0){
		for(int j=0;j<9;j++){
			for(int i=0;i<5;i++){
				x=map[8-i][j];
				map[8-i][j]=map[i][j];
				map[i][j]=x;
			}
		}
		return;
	}
	if(n==1){
		for(int i=0;i<9;i++){
			for(int j=0;j<5;j++){
				y=map[i][8-j];
				map[i][8-j]=map[i][j];
				map[i][j]=y;
			}
		}
		return;
	}
}

void Sudoku::transform(){
	srand(time(NULL));
	changeNum(rand()%9+1,rand()%9+1);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
	printOut();
}

void Sudoku::printOut(){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<map[i][j]<<" ";
		}
		cout<<endl;	
	}
}

void Sudoku::solve(){
	solve_sudoku();
	if(answer[0]==0) cout<<"0"<<endl;
	else if(answer[0]==1){
		cout<<"1"<<endl;
		printOut();
	}
}

void solve_sudoku(){
	/*int q=0,input=0;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(map[i][j]!=0) q++;
		}
		if(q==8){
			for(j=0;j<9;j++){
				if(map[i][j]==0){
					for(input=1;input<=9;input++){
						if((checkRow(input,i)==1)&&(checkCol(input,j)==1)&&(checkSquare(input,i,j)==1)){
							map[i][j]=input;
						}	
					}
				}
			}
		}
	}*/
	
	
	
	
	answer[0]=0;
	int num=0,t=0;
	int a[9]={0},b[9]={0};
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(map[i][j]!=0) num++;
			if(map[i][j]==0){
				a[t]=i;
				b[t]=j;
				t++;
			}
		}
	}
	if(num==81){
		answer[0]++;
		return;
	}
	else{
		int input;
		for(int k=0;k<81;k++){
			for(input=1;input<=9;input++){
				if((checkRow(input,a[k])==1)&&(checkCol(input,b[k])==1)&&(checkSquare(input,a[k],b[k])==1)){
					map[a[k]][b[k]]=input;
					break;
				}	
			}
			if(map[a[k]][b[k]]==0){	
				if(k==0){
					answer[0]=0;
					return;
				}
				else{
					for(input=map[a[k-1]][b[k-1]]+1;input<=9;input++){
						if((checkRow(input,a[k-1])==1)&&(checkCol(input,b[k-1])==1)&&(checkSquare(input,a[k-1],b[k-1])==1)){
							map[a[k-1]][b[k-1]]=input;
							break;
						}	
					}
					k--;
				}		
			}
		}
	}
	num=0;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(map[i][j]!=0) num++;
		}
	}
	if(num==81){
		answer[0]++;
		if(answer[0]==2){
			cout<<"2"<<endl;
			return;
		}
		return;
	}
}

int checkRow(int row,int r){
	for(int j=0;j<9;j++){
		if(map[r][j]==row)
		return 0;
	}
	return 1;
}

int checkCol(int col,int c){
	for(int i=0;i<9;i++){
		if(map[i][c]==col)
		return 0;
	}
	return 1;
}

int checkSquare(int square,int s,int ss){
	int x=s-(s%3),y=ss-(ss%3);
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(map[x+i][y+j]==square)
			return 0;
		}
	}
	return 1;
}
