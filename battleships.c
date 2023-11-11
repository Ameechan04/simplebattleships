#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_board(char B[10][12]);
int check_empty_spot(char board[10][12], int row, int column);
int validate_orientation(char board[10][12], int r, int c, int end_R, int end_C, char orientation);
void ai_create_board(char bot_board[10][12]);
int shoot(int row, int column, char b[10][12]);

/* 
 * A simple game of battleships
 * Author: Andrew Meeehan <andrew.meechan.2022@uni.strath.ac.uk>
 * Program is to create a 2D Array to represent a battleship board for two players
 * Each turn the player will choose a target to shoot at and will be told if it hits or not
 * Last updated: 07/10/23
 */
 

int main (void) {
     srand(time(NULL));
    int rows = 10;
    int columns = 12;
    int valid = 0;
    char character;
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

char bot_board[10][12] = 
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

 ai_create_board(bot_board);



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
		
for (int i = 0; i < 5; i++) {
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
        end_C = C - 2;
        end_R = R;
        valid = 1;
        break;
    case 'R':
        end_C = C + 2;
        end_R = R;
        valid = 1;
        break;
    case 'U':
        end_R = R - 2;
          end_C = C;
        valid = 1;
        break;
    case 'D':
       
        end_R = R + 2;
          end_C = C;
        valid = 1;
        break;
    default:
        printf("Invalid. Enter L, R, U or D: ");
        valid = 0;
        break;
}
    if (!validate_orientation(board, R, C, end_R, end_C, input)) {
    printf("The orientation %c is invalid. Enter another: ", input);
    valid = 0;
} else {
    valid = 1;
}
} while (!valid);

//validate_orientation(board, R, C, end_R, end_C, input);


print_board(board);
}//FOR LOOP


int game_over = 0;
int player = 1; //player 1 = human
int target_row;
int target_column;
int bot_X_counter;
int X_counter;     
do {
    if (player = 1) {
        
        //TODO input validation and conversion
        printf("Enter the target row!");
        scanf("%d", target_row);
        printf("Enter the target column!");
        scanf("%d", target_column);
        shoot(target_row, target_column, bot_board);    //human shoots at bot board
        
    } else {
        target_row = rand() % (8 + 1); 
        target_column  = rand() % (11 - 2 + 1) + 2;
        shoot(target_row, target_column, board);    //bot shoots at human board
    }
    X_counter = 0;
    bot_X_counter = 0;
    for (int r = 0; r < 10; r++) {
		for (int c = 0; c < 12; c++) {
			if (board[r][c] == 'X') {
			    X_counter++;
			}
			if (bot_board[r][c] == 'X') {
			    bot_X_counter++;
			}
		}
	}
	
	if (bot_X_counter == 0) {
	    game_over = 1;
	    printf("THE BOT IS VICTORIOUS!");
	}
	if (X_counter == 0) {
	    game_over = 1;
	    printf("YOU ARE VICTORIOUS!");
	}
    
    
    
    
} while (!game_over);


return 0;
} //END OF MAIN
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
		    printf("changing...");
		    	
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
		    printf("This orientation makes the ship fall off the board.");
		    return 0;
		    
		}
		

}

void ai_create_board(char bot_board[10][12]) {
    int max_R = 8;
    int max_C = 11;
    int valid = 0;
    int R, C;
    for (int i = 0; i < 5; i++) {
    
do {
    

//input for R must be => 0 AND <= 8


do {
//convert row entered into usable format for the 2D array:
  R = rand() % (max_R + 1); 
  printf("R IS: %d \n", R );
if (R >= 0 && R <=8) {
    valid = 1;
} else {
    printf("invalid. Re-enter a correct row: ");
}
} while (!valid);
//input for C must be => 2 AND =< 11
valid = 0; //reset valid to false

do {

//Converted the input into array form
C  = rand() % (max_C - 2 + 1) + 2;  
printf("C IS: %d \n", C );
if (C >= 2 && C <= 11) {
    valid = 1;
} else {
  //  printf("invalid. Re-enter a correct column: ");
}
} while (!valid);
valid = 0;
if (!check_empty_spot(bot_board, R, C)) {
  
    valid = 0;
} else {
    valid = 1;
}
} while (!valid);





bot_board[R][C] = 'X';
valid = 0;
int end_C = -1;
int end_R = -1;
char input;

//printf("Enter the ships orientation. \n");
//printf("Enter L, R, U or D: ");

int upper_bound = 4;
int lower_bound = 1;
do {
    //scanf(" %c", &input);
    int value = rand() % (upper_bound - lower_bound + 1) 
                    + lower_bound; 
                    
    switch (value)      {
        case 1:
            input = 'L';
            break;
         case 2:
            input = 'R';
            break;
        case 3:
            input = 'U';
            break;
         case 4:
            input = 'D';
            break;
    }         
                    
    
    switch (input) {
    case 'L':
      
        end_C = C - 2;
        end_R = R;
        valid = 1;
       
        break;
    case 'R':
        
        end_C = C + 2;
        end_R = R;
        valid = 1;
        
        break;
    case 'U':
    
        end_R = R - 2;
          end_C = C;
        valid = 1;
           
        break;
    case 'D':
      
        end_R = R + 2;
          end_C = C;
        valid = 1;
         
        break;
    default:
        printf("Invalid. Enter L, R, U or D: ");
        valid = 0;
        break;
}
  if (!validate_orientation(bot_board, R, C, end_R, end_C, input)) {
    printf("The orientation %c is invalid. Enter another: ", input);
    valid = 0;
} else {
    valid = 1;
}
} while (!valid);

print_board(bot_board);

}//FOR LOOP
    
}

int shoot(int row, int column, char b[10][12]) {
    if (b[row][column] == 'X') {
        //target hit then:
        printf("\n The shot at %d %d was a hit! \n", row, column);
        b[row][column] = 'H';
        return 1;
    } else {
        printf("\n MISS! \n");
        return 0;
    }
    
}
