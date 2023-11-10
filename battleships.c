/* 
 * A simple game of battleships
 * Author: Andrew Meeehan <andrew.meechan.2022@uni.strath.ac.uk>
 * Program is to create a 2D Array to represent a battleship board for two players
 * Each turn the player will choose a target to shoot at and will be told if it hits or not
 * Last updated: 07/10/23
 */
 
#include <stdio.h>
#include <stdlib.h>
//#include "functions.h"
int main (void) {
    int rows = 10;
    int columns = 12;
    
    int R, C;
 //Create the board
 char board[10][12] = 
        {{'9', ' ', '\0', '\0','\0','\0','\0','\0','\0','\0', '\0'},	//0
        {'8', ' ','\0','\0','\0','\0','\0','\0','\0', '\0', '\0'},	//1
	    {'7', ' ', '\0','\0','\0','\0','\0','\0','\0', '\0', '\0'},	//2
		{'6', ' ', '\0', '\0','\0','\0','\0','\0','\0','\0', '\0'},	//3
		{'5', ' ', '\0', '\0','\0','\0','\0','\0','\0','\0','\0'},	//4
		{'4', ' ', '\0', '\0','\0','\0','\0','\0','\0','\0', '\0'},	//5
		{'3', ' ', '\0', '\0','\0','\0','\0','\0','\0','\0', '\0'},	//6
		{'2', ' ', '\0', '\0','\0','\0','\0','\0','\0','\0', '\0'},	//7
	 {'1', ' ', '\0', '\0','\0','\0','\0','\0','\0','\0', '\0'},	//8
		{' ', ' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}};	//9

 



 printf("\n SIMPLE CHESS BY ANDREW MEECHAN \n \n");

  print_board(board);

 //print the board
 /*
		for (int r = 0; r < 10; r++) {
			for (int c = 0; c < 12; c++) {
				printf("%c", board[r][c]);
			}
			printf("\n");
		}
		*/
		
printf("Enter a position to mark as your ship. \n");

//input for x must be => 0 AND <= 8
printf("enter row: ");
scanf(" %d", &R);
//input for y must be => 2 AND =< 11
printf("enter column: ");
scanf(" %d", &C);
board[R][C] = 'X';

print_board(board);


return 0;
}

void print_board(char board[10][12]) {
    printf("\n \n");
    for (int r = 0; r < 10; r++) {
			for (int c = 0; c < 12; c++) {
				printf("%c", board[r][c]);
			}
			printf("\n");
		}
		printf("\n");
    

}
