// made by alireza 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#define N 9
using namespace  std;
int PUZZLE[N][N];

int check(int a[]){
	//Checks an array for duplicate values. If there are duplicates, return 1, else return 0.
	int i, j;

	for(i=0;i<8;i++){
		for(j=i;j<8;j++){
			if(a[i] != 0){
				if(a[i] == a[j+1]){
					return 1; //Duplicate
				}
			}
		}
	}

	return 0; //No Duplicate
}

int conflictCheck(int a[]){
	//Same functionality as check(), but returns actual value of conflicted point. Used to specify invalid blocks.
	int i, j;

	for(i=0;i<8;i++){
		for(j=i;j<8;j++){
			if(a[i] != 0){
				if(a[i] == a[j+1]){
					return a[i]; //Return value of duplicate
				}
			}
		}
	}

	return 0; //No Duplicate
}

int checkBox(int row, int col, int num){
	//Converts box into a single dimension array based on location of point.
	//Checks box and returns value.

	int boxtmp[N];
	int x, y, count = 0;

	if(row<3 && col<3){
		for(x=0; x<3; x++){
			for(y=0; y<3; y++){
				if(row == x && col == y){
					boxtmp[count++] = num;
				}else{
					boxtmp[count++] = PUZZLE[x][y];
				}
			}
		}
	}
	else if(row<3 && col<6){
		for(x=0; x<3; x++){
			for(y=3; y<6; y++){
				if(row == x && col == y){
					boxtmp[count++] = num;
				}else{
					boxtmp[count++] = PUZZLE[x][y];
				}
			}
		}
	}
	else if(row<3 && col<N){
		for(x=0; x<3; x++){
			for(y=6; y<N; y++){
				if(row == x && col == y){
					boxtmp[count++] = num;
				}else{
					boxtmp[count++] = PUZZLE[x][y];
				}
			}
		}
	}
	else if(row<6 && col<3){
		for(x=3; x<6; x++){
			for(y=0; y<3; y++){
				if(row == x && col == y){
					boxtmp[count++] = num;
				}else{
					boxtmp[count++] = PUZZLE[x][y];
				}
			}
		}
	}
	else if(row<6 && col<6){
		for(x=3; x<6; x++){
			for(y=3; y<6; y++){
				if(row == x && col == y){
					boxtmp[count++] = num;
				}else{
					boxtmp[count++] = PUZZLE[x][y];
				}
			}
		}
	}
	else if(row<6 && col<N){
		for(x=3; x<6; x++){
			for(y=6; y<N; y++){
				if(row == x && col == y){
					boxtmp[count++] = num;
				}else{
					boxtmp[count++] = PUZZLE[x][y];
				}
			}
		}
	}
	else if(row<N && col<3){
		for(x=6; x<N; x++){
			for(y=0; y<3; y++){
				if(row == x && col == y){
					boxtmp[count++] = num;
				}else{
					boxtmp[count++] = PUZZLE[x][y];
				}
			}
		}
	}
	else if(row<N && col<6){
		for(x=6; x<N; x++){
			for(y=3; y<6; y++){
				if(row == x && col == y){
					boxtmp[count++] = num;
				}else{
					boxtmp[count++] = PUZZLE[x][y];
				}
			}
		}
	}
	else if(row<N && col<N){
		for(x=6; x<N; x++){
			for(y=6; y<N; y++){
				if(row == x && col == y){
					boxtmp[count++] = num;
				}else{
					boxtmp[count++] = PUZZLE[x][y];
				}
			}
		}
	}

	return check(boxtmp);
}

void printPuzzle(){
	//This program prints an input file in a Sudoku format. [NxN Grid]
	//Prints spaces (0) as x's for clarity.

	int row, col;

	for(row = 0; row < N; row++){
		for(col = 0; col < N; col++){
			if(PUZZLE[row][col] == 0){
				cout<<"x ";
			}else{
				cout<<PUZZLE[row][col]<<" ";
			}
		}
	cout<<endl;
	}

}

void readPuzzle()
{	//Reads input fule puzzle into global variable PUZZLE[N][N]
	int row, col, num;
   cout<<"Enter 9*9 Value In Matrix"<<endl;
	//Initializes board as 0's (empty spaces)
	for(row = 0; row < N; row++){
		for(col = 0; col < N; col++){
			cout<<"["<<row<<","<<col<<"]:";
			cin>>PUZZLE[row][col];
		}
	}
}

void verifyPuzzle(){
	//Verifies puzzle based on number, row, column, and box validity.

	int i, j, tmp[N] = {0};

	//Check Number
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(PUZZLE[i][j] != 0){
				if(PUZZLE[i][j] < 1 || PUZZLE[i][j] > N){
					cout<<"Number conflict found:"<<i+1<<" "<<j+1<<" "<<PUZZLE[i][j]<<" "<<endl;
					return;
				}
			}
		}
	}

	//Check Rows
	for(i=0; i<N; i++){
		int tmp[N] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
		for(j=0; j<N; j++){
			tmp[j] = PUZZLE[i][j];
			if(check(tmp) != 0){
				cout<<"Row conflict found:"<<i+1<<" "<<j+1<<" "<<conflictCheck(tmp)<<endl;
				return;
			}
		}
	}

	//Check Columns
	for(i=0; i<N; i++){
		int tmp[N] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
		for(j=0; j<N; j++){
			tmp[j] = PUZZLE[j][i];
			if(check(tmp) != 0){
				cout<<"Column conflict found:"<<j+1<<" "<<i+1<<" "<<conflictCheck(tmp)<<" "<<endl;
				return;
			}
		}
	}

	//Check Boxes
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(checkBox(i, j, PUZZLE[i][j]) == 1){
				cout<<"Box conflict found:"<<" "<< i+1<<" "<< j+1<<" "<< PUZZLE[i][j]<<" "<<endl;
				return;
			}
		}
	}

	cout<<"The instance is valid"<<endl;
}

void generatePuzzle(int n){
	//Generates random unsolved, but technically valid Sudoku puzzle
	//Puzzles may be unsolvable.

	int row, col, i, x, y, num;
	int rowtmp[N] = {0}, coltmp[N] = {0};
	int verify = 0, counter;

	srand(time(NULL));

	for(row=0;row<N;row++){
		for(col=0;col<N;col++){
			PUZZLE[row][col] = 0;
		}
	}

	printf("Generating...");

	for(counter=0;counter<n;counter++){ //Produces n amount of givens.
		while(verify == 0 && counter<n){
			x = rand() % N;
			y = rand() % N;
			num = rand() % N + 1;

			//Stores row to be checked
			for(i=0;i<N;i++){
				if(i==y){
					rowtmp[i] = num;
				}else{
					rowtmp[i] = PUZZLE[x][i];
				}
			}

			//Stores columns to be checked
			for(i=0;i<N;i++){
				if(i==x){
					coltmp[i] = num;
				}else{
					coltmp[i] = PUZZLE[i][y];
				}
			}

		//Checks if random point is valid. If not continues loop. When a random point is valid, break loop, adds to counter, and re-enters loop.
			if(PUZZLE[x][y] == 0 && check(rowtmp) == 0 && check(coltmp) == 0 && checkBox(x, y, num) == 0){
				verify = 1;
			}
		}
		PUZZLE[x][y] = num; //Assigns valid point to puzzle.
		verify = 0;
	}



	cout<<"Done!"<<endl;
	printPuzzle();
}

void solvePuzzle (){	//Not sure if this is better than the simple solver.
	int row, col;
	int i, n, guesscount, position;
	int rowtmp[N], coltmp[N];
	int guess[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int iterations = 0;

	cout<<"Solving..."<<endl;

	while(iterations < 50){
		//Runs through puzzle 50 times to solve as many boxes.
		//Ideally, this would be while all rows and columns are filled, but their is the possibiliity of unsolvable puzzles.
		//Also, I would have liked to implement a backtracking method if possible or neccesary, but no time.

		for(row=0;row<N;row++){
			for(col=0;col<N;col++){

				guesscount = 0; //Initializes count and position back to 0 for each block.
				position = 0;

				if(PUZZLE[row][col] == 0){//Only check possiblities in on unfilled blocks

					for(n=0;n<N;n++){//Assigns block as 1-9 and checks all for validity.
						PUZZLE[row][col] = guess[n];

						//Assigns value to rowtmp to be checked
						for(i=0;i<N;i++){
							if(i == col){
								rowtmp[i] = guess[n];}
							else{
								rowtmp[i] = PUZZLE[row][i];}
						}

						//Assigns value to coltmp to be checked
						for(i=0;i<N;i++){
							if(i == row){
								coltmp[i] = guess[n];}
							else{
								coltmp[i] = PUZZLE[i][col];}
						}

						//Checks if number is valid in row, col, and box.
						if(check(rowtmp) == 0 && check(coltmp) == 0 && checkBox(row, col, guess[n]) == 0){
							guesscount++; //If number is valid, add to number of possibilities
							position = n; //If there is only one valid number, position will be correct index of guess
						}
					}

					if(guesscount == 1){
						PUZZLE[row][col] = guess[position]; //If there is only one possiblilty, solve the box.
					}else{
						PUZZLE[row][col] = 0; //If there is more than one possiblity, reset back to 0.
					}
				}
			}
		}
		iterations++;
	}

	printPuzzle();

}



int main()
{ int givens; 				// the number of givens when asked to
		cout<<"givens:";
		cin>> givens;
		readPuzzle();
		verifyPuzzle();
		printPuzzle();
		generatePuzzle(givens);
		solvePuzzle();
		getch();
		return 0;
}