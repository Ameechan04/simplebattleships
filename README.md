# Simple Battleships in C
## HOW TO RUN:

## Recommended
### Due to C compiling differently on different devices, the recommended usage is through the online C compiler
1. Open [battleships.c](https://github.com/Ameechan04/simplebattleships/blob/main/battleships.c)
2. Click `Copy raw file`
3. Open [Online C Compiler](https://www.programiz.com/c-programming/online-compiler/)
4. Paste in the copied and hit run

## Linux Machine (unstable) using GCC
1. Open [battleships.c](https://github.com/Ameechan04/simplebattleships/blob/main/battleships.c)
2. Click `Download raw file`
3. Open Terminal
4. Run `gcc -o battleships simplebattleships.c` or equivalent in desired compiler
5. Execute the compiled code with `./battleships` or equivalent

## How does it work:
The board is represented using a 2D array. The user is asked to place their ships and validation ensures they are on the board and not overlapping.
To ensure they are on the board it:
1. Checks the first square the user choses is inside the bounds of the board
2. Finds the length of the ship and the orientation the user selected to calculate the end position of the ship and check if that is also in the bounds
3. Using the start and end coordiante, the middle squares are calculated. Those squares are checked against the grid to see if it is already marked and if it is then the orientation is invalid. If all 4 orientations are invalid then the user is forced to select a starting square.

When playing a bot the initial position and orientation are random, and the generation continues until the random placements are all legal.

The firing mechanism is very simple; the user input is taken and converted into the 2D array format and on the target screen and opponents board it is marked as an X.
On the opponents board is the position was =/= 0, then it was a hit.

When all squares on the board are either 0 or X the game is over.
