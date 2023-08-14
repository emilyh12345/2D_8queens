//Emily Haller
#include<iostream>
using namespace std;

int main(){
    int b[8][8]{0}, r, c=0; //initialize board to 0 so no queens on board to start, column to 0, no row value yet
    int solutions=0; //initialie counter to 0 to keep track of solution number
    b[0][0]=1;//place queen in top left space 

NC: 
	c++; //go to next column
	if(c==8) goto print; //reach column 8 you found a solution so print solution
	r=-1;

NR: 
    r++; //increment row by 1 to get to next row
    if(r==8) goto backtrack; //out of rows bc none worked so backtrack
	for(int i=0; i<c; i++){ //row test
        if(b[r][i]==1) goto NR; //if has queen in a row(1) goes to next row
	}
	for(int i=1; (r-i)>=0 && (c-i)>=0; i++){ //up diagonal test 
        if(b[r-i][c-i]==1) goto NR; //if there is a queen in that up diagonal(1 box to the left and one box up) then go to next row
	}
	for(int i=1; (r+i)<8 && (c-i)>=0; i++) // down diagonal test
        if (b[r+i][c-i]==1) goto NR; //as row increases column decreases and if there is a queen there then go to next row
    b[r][c]=1; // valid placement of queen bc all 3 tests passed
    goto NC; // then go to next column

backtrack: 
	c--; // go back a column
    if(c==-1) return 0; //off board, done with all solutions so terminate program
    r=0; 
	while (b[r][c]!=1) r++; //loops so if no queen in that position it goes to next row until it finds a queen
	b[r][c]=0; //when finds a queen, erases it
    goto NR; //go to next row
	
print:
    solutions++; //increment number of solution counter to keep track of amount of solutions
    cout<< "Solution " << solutions << endl;
    for(int r=0; r<8; r++){ //prints a 2D array of each possible solution by looping through columns and rows
        for(int c=0; c<8; c++){
            cout << b[r][c];
        }
		cout << endl;
    }
    cout << endl; 
	goto backtrack; //continues looping to find next solution
	return 0;
}
