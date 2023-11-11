#include <stdio.h>
#include <stdlib.h>

void print_board(char B[10][12]);
int check_empty_spot(char board[10][12], int row, int column);
int validate_orientation(char board[10][12], int r, int c, int end_R, int end_C, char orientation);

/* 
 * A simple game of battleships
 * Author: Andrew Meeehan <andrew.meechan.2022@uni.strath.ac.uk>
 * Program is to create a 2D Array to represent a battleship board for two players
 * Each turn the player will choose a target to shoot at and will be told if it hits or not
 * Last updated: 07/10/23
 */
 

int main (void) {
    int rows = 10;
    int columns = 12;
    int valid = 0;
    char character;
    int R, C;
    int numberOrientationFails = 0;
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

 



 printf("\n SIMPLE BATTLESHIPS BY ANDREW MEECHAN \n \n");

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
		
for (int i = 0; i < 3; i++) {
printf("Enter a position to mark as your ship. \n");

do {

//input for R must be => 0 AND <= 8
printf("enter row: ");

do {
scanf(" %d", &R);
//convert row entered into usable format for the 2D array:
R = 9 - R;
if (R >= 0 && R <=8) {
    valid = 1;
} else {
    printf("invalid. Re-enter a correct row: ");
}


} while (!valid);
//input for C must be => 2 AND =< 11
valid = 0; //reset valid to false
printf("enter column: ");


do {
scanf(" %c", &character);
//Converted the input into array form
 C = character - 63;  
if (C >= 2 && C <= 11) {
    valid = 1;
} else {
    printf("invalid. Re-enter a correct column: ");
}
} while (!valid);
valid = 0;
if (!check_empty_spot(board, R, C)) {
    printf("\n The selected spot is already taken. \n");
    valid = 0;
} else {
    valid = 1;
}
} while (!valid);
board[R][C] = 'X';

valid = 0;
int end_C = -1;
int end_R = -1;
char input;

printf("Enter the ships orientation. \n");
printf("Enter L, R, U or D: ");
do {
    scanf(" %c", &input);
    switch (input) {
    case 'L':
        //printf("C: %d ", C);
        end_C = C - 2;
        end_R = R;
        valid = 1;
        //printf("END C: %d", end_C);
        break;
    case 'R':
         //printf("C: %d ", C);
        end_C = C + 2;
        end_R = R;
        valid = 1;
        //printf("END C: %d", end_C);
        break;
    case 'U':
     //printf("R: %d ", R);
        end_R = R - 2;
          end_C = C;
        valid = 1;
       //    printf("END R: %d", end_R);
        break;
    case 'D':
    //    printf("R: %d ", R);
        end_R = R + 2;
          end_C = C;
        valid = 1;
      //     printf("END R: %d", end_R);
        break;
    default:
        printf("Invalid. Enter L, R, U or D: ");
        valid = 0;
        break;
}
  //  printf("\n \n R: %d END R: %d C: %d END C: %d", R, end_R, C, end_C);
    if (!validate_orientation(board, R, C, end_R, end_C, input)) {
    printf("The orientation %c is invalid. Enter another: ", input);
    valid = 0;
} else {
    valid = 1;
}
    
    
    
} while (!valid);




print_board(board);
}//FOR LOOP

return 0;
}
void print_board(char B[10][12]) {
    printf("\n \n");
    for (int r = 0; r < 10; r++) {
			for (int c = 0; c < 12; c++) {
				printf("%c", B[r][c]);
			}
			printf("\n");
		}
		printf("\n");
    

}
int check_empty_spot(char board[10][12], int row, int column) {
    if (board[row][column] != 'X')   {
        //empty board position
        return 1;   //returns true if empty
     } else {
         return 0;
     }
    
}

int validate_orientation(char board[10][12], int R, int C, int end_R, int end_C, char orientation) {
    
    char temp_arr[10][12] = {'\0'};
    	for (int R = 0; R < 10; R++) {
			for (int C = 0; C < 12; C++) {
				temp_arr[R][C] = board[R][C];
			}
		}
		//input for R must be => 0 AND <= 8
		if ((end_C >= 2 && end_C <= 11) && (end_R >= 0 && end_R <= 8)) {
		    
		    //VALID!
		    	
		    	if (board[end_R][end_C] == 'X') {
		    	    printf("Space is already occupied! 0");
		    	    return 0;
		    	}
		    	board[end_R][end_C] = 'X';
		    	switch (orientation) {
		    	    case 'L':   
		    	          
		    	          	if (board[R][C - 1] == 'X') {
		    	                printf("Space is already occupied! 1");
		    	                return 0;
		                	}
		                	 board[R][C - 1] = 'X';
		                	break;
		    	    case 'R':   
		    	           
		    	            if (board[R][C + 1] == 'X') {
		    	                printf("Space is already occupied! 2");
		    	                return 0;
		                	}
		                	 board[R][C + 1] = 'X';
		    	           break;
		    	    case 'U':
		    	            
		    	          
		    	            if (board[R - 1][C] == 'X') {
		    	                printf("Space is already occupied! 3");
		    	                return 0;
		                	}
		                	  board[R - 1][C] = 'X';
		    	           break;
		    	    case 'D':  
		    	    
		    	            
		    	            	if (board[R + 1][C] == 'X') {
		    	                printf("Space is already occupied! 4");
		    	                return 0;
		                	}
		                	board[R + 1][C] = 'X';
		    	           break;
		    	    default:
		    	        printf("something went wrong !");
		    	    
		    	}
		  
		    return 1;
		}  else {
		   printf("\nThis orientation makes the ship fall off the board. \n");
		    return 0;
		    
		}
		

}

