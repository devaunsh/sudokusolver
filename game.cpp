#include<iostream>
#include<stdio.h>
using namespace std;
bool findUnassigned (int grid[9][9], int &row, int &col);
bool isSafe( int grid[9][9], int row , int col, int i);

bool solve(int grid[9][9]){
	int row, col;

	if(findUnassigned(grid,row, col)==false){
		return true;
	}

	for( int i=0; i<=9;i++){
		if(isSafe(grid,row,col,i)==true){
			grid[row][col]= i;		
			
			if(solve(grid)==true)
				return true;

			grid[row][col] = 0;
		}	
	}
	return false;
}

bool findUnassigned(int grid[9][9], int &row, int &col){
	for(row =0; row<9;row++){
		for(col=0;col<9;col++){
			if(grid[row][col]== 0)
				return true;
		}
	}
	return false;
}

bool usedRow ( int grid[9][9], int row, int i ){
	for( int col=0;col<9;col++){
		if(grid[row][col]== i){
			return true;
		}
	}
	return false;
}

bool usedCol (int grid[9][9], int col, int i){
	for(int row =0; row<9;row++){
		if(grid[row][col] == i)
			return true;
	}
	return false;
}

bool usedBox (int grid[9][9], int row,int col,int i){
	row = row - row%3;
	col = col - col%3;
	for(int j = row; j< row+3;j++){
		for(int k = col; k<col+3;k++){
			if(grid[j][k]==i)
				return true;
		}
	}
	return false;
}

bool isSafe (int grid[9][9], int row, int col, int i){
	if( usedRow(grid,row,i) == false && usedCol (grid, col,i) == false && usedBox(grid, row,col,i) == false)
		return true;
}

void printGrid(int grid[9][9]){
	for(int i =0;i<9;i++){
		cout<<endl;
		for(int j=0;j<9;j++){
			cout<<grid[i][j]<<" ";
		}
	}
	cout<<endl;
}

int main(){
/*	int grid[9][9] = {{3,0,6,5,0,8,4,0,0},
			  {5,2,0,0,0,0,0,0,0},
			  {0,8,7,0,0,0,0,3,1},
			  {0,0,3,0,1,0,0,8,0},
			  {9,0,0,8,6,3,0,0,5},
			  {0,5,0,0,9,0,6,0,0},
			  {1,3,0,0,0,0,2,5,0},
			  {0,0,0,0,0,0,0,7,4},
			  {0,0,5,2,0,6,3,0,0}};
*/
	int grid[9][9];

	cout<<"Please enter the grid in 9 x 9 format:"<<endl;
	cout<<"Enter 0 for missing numbers in the grid"<<endl;

	for(int i =0;i<9;i++){
		for(int j =0;j<9;j++){
			cin>>grid[i][j];
		}
	}
	cout<<"Original grid.";
	printGrid(grid);

	if(solve(grid)==true){
		cout<<"Solution.";
		printGrid(grid);
	}	
	else
		cout<<"No solution."<<endl;
	
	return 0;
}
