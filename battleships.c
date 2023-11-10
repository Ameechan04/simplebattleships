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

 //Create the board
  char board[9][10] = 
	{{'10', ' ', '\0', '\0','\0','\0','\0','\0','\0','\0', '\0', '\0'},	//0
  {'9', '  ', '\0', '\0','\0','\0','\0','\0','\0','\0', '\0', '\0'},	//1
  {'8', '  ', '\0', '\0','\0','\0','\0','\0','\0','\0', '\0', '\0'},	//2
	 {'7', '  ', '\0', '\0','\0','\0','\0','\0','\0','\0', '\0', '\0'},	//3
		{'6', '  ', '\0', '\0','\0','\0','\0','\0','\0','\0', '\0', '\0'},	//4
		{'5', '  ', '\0', '\0','\0','\0','\0','\0','\0','\0', '\0', '\0'},	//5
		{'4', '  ', '\0', '\0','\0','\0','\0','\0','\0','\0', '\0', '\0'},	//6
		{'3', '  ', '\0', '\0','\0','\0','\0','\0','\0','\0', '\0', '\0'},	//7
		{'2', '  ', '\0', '\0','\0','\0','\0','\0','\0','\0', '\0', '\0'},	//8
	 {'1', '  ', '\0', '\0','\0','\0','\0','\0','\0','\0', '\0', '\0'},	//9
		{' ', '  ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}};	//10

 printf("\n SIMPLE CHESS BY ANDREW MEECHAN \n \n");

 //print the board
		for (int r = 0; r < 11; r++) {
			for (int c = 0; c < 11; c++) {
				printf("%c", board[r][c]);
			}
			printf("\n");
		}


return 0;
}
