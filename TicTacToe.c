// TicTacToe.c
// Created by Mohamed Abid at 8:44 PM, 10/24/2014
// This program plays a game of TicTacToe against the user
#include <stdio.h>
#include <stdlib.h>

#define size 3
void info(void);
void map(char board[size][size]);
void check(char board[size][size]);
void Game(char board[size][size]);
void print(char board[size][size]);
void playerMove(char board[size][size]);
void compMove(char board[size][size]);
void horizontalcompcheck(char board[size][size]);
void diagonalcompcheck(char board[size][size]);
void verticalcompcheck(char board[size][size]);
void horizontalusercheck(char board[size][size]);
void verticalusercheck(char board[size][size]);
void diagonalusercheck(char board[size][size]);
void initialize(char board[size][size]);
void win(int whoWon);
char com = 'X';
char user = 'O';
main()
{
    char board[size][size];
    initialize(board);
    info();
    map(board);
    Game(board);
}
void info(void)// Gives player info on how to play
{
    printf("--------------\n");
    printf(" |Tic|Tac|Toe|\n");
    printf("--------------\n");
    printf("Welcome to Tic Tac Toe\n");
    printf("To play, enter coordinates of the point you would like to fill\n");
    printf("Keep in mind, the coordinates start from 0\n");
    printf("Computer = %c\n Player = %c\n",com,user);
}
void map(char board[size][size])// Shows player a map of the board and the corresponding coordinates
{
    int x,y;
    printf("Here is a map of the board and it's coordinates\n");
    for(x=0;x<size;x++)
    {
        for(y=0;y<size;y++)
        {
            printf("(%d,%d)   ",x,y);
            board[x][y] = 32;
        }
        printf("\n");
    }
}
void Game(char board[size][size]) //Loop calls functions that operate the game
{
    int moves,count=0;
    while(1)
    {
        printf("Your turn\n");
        playerMove(board);
        count++;
        if(count==9)break;
        print(board);
        check(board);
        printf("Computer's turn\n");
        compMove(board);
        count++;
         if(count==9)break;
        print(board);
        check(board);
    }
    printf("It's a draw!\n");
}
void print(char board[size][size]) // prints the board with the current markers
{
    int x,y;
    for(x=0;x<size;x++)
    {
        for(y=0;y<size;y++)
        {
            printf("%c ",board[x][y]);
        }
        printf("\n");
        
    }
}
void check(char board[size][size]) //checks if someone has won
{
    horizontalcompcheck(board);
    verticalcompcheck(board);
    diagonalcompcheck(board);
    horizontalusercheck(board);
    verticalusercheck(board);
    diagonalusercheck(board);
}
void playerMove(char board[size][size])
{
    int x,y;
    printf("Enter the x coordinate of the point\n");
    x = scanf("%d", &x);
    printf("Enter the y coordinate of the point\n");
    y = scanf("%d", &y);
    if(board[x][y]!=32)
    {
        printf("That spot is already taken. Try again\n");
        printf("Enter the x coordinate of the point\n");
        x = scanf("%d", &x);
        printf("Enter the y coordinate of the point\n");
        y = scanf("%d", &y);;
    }
    board[x][y] = user;
}
void win(int whoWon) //Displays win or lose message and exits program
{
    if(whoWon == 0)
    {
        printf("-----GAME-----\n");
        printf("-----OVER-----\n");
        printf("Better luck next time!");
        exit(0);
    }
    else
    {
        printf("-----YOU-----\n");
        printf("-----WIN-----\n");
        exit(0);
    }
}
void compMove(char board[size][size])
{
    int x,y,count,locx,locy;
    for(y=0;y<size;y++) // checks vertical columns
    {
        for(x=0,count=0;x<size;x++)
        {
            if(board[x][y]==user) count--;
            if(board[x][y]==com) count++;
            if(board[x][y]==32) //if empty, mark location in case the comp can win by filling that spot in
            {
                locx = x;
                locy = y;
            }
        }
        if(count==2||count==-2)
        {
            board[locx][locy] = com; //if a win is possible, fill in and return
            return;
        }
        
    }
    for(x=0;x<size;x++) // checks horizontal columns
    {
        for(y=0,count=0;y<size;y++)
        {
            if(board[x][y]==user) count--;
            if(board[x][y]==com) count++;
            if(board[x][y]==32) //if empty, mark location in case the comp can win by filling that spot in
            {
                locx = x;
                locy = y;
            }
        }
        if(count==2||count==-2)
        {
            board[locx][locy] = com; //if a win is possible, fill in and return
            return;
        }
    }
    //checks diagonal columns
    for(x=0,y=0,count=0;x<size;x++,y++)
    {
        if(board[x][y]==user) count--;
        if(board[x][y]==com) count++;
        if(board[x][y]==32) //if empty, mark location in case the comp can win by filling that spot in
        {
            locx = x;
            locy = y;
        }
    }
    if(count==2||count==-2)
    {
        board[locx][locy] = com; //if a win is possible, fill in and return
        return;
    }
    for(x=0,y=2,count=0;x<size;x++,y--)
    {
        if(board[x][y]==user) count--;
        if(board[x][y]==com) count++;
        if(board[x][y]==32) //if empty, mark location in case the comp can win by filling that spot in
        {
            locx = x;
            locy = y;
        }
    }
    if(count==2||count==-2)
    {
        board[locx][locy] = com; //if a win is possible, fill in and return
        return;
    }
    //Cycle through to look for a empty spot
    for(x=0;x<size;x++)
    {
        for(y=0;y<size;y++)
        {
            if(board[x][y]==32)
            {
                board[x][y] = com;
                return;
            }
        }
        
    }
    
}
void horizontalcompcheck(char board[size][size])
{
    int x,y,count;
    for(x=0,count=0;x<size;x++) // This checks horizontally to see if the computer has won.
    {
        for(y=0;y<size;y++)
        {
            if(board[x][y]==com) count++;
        }
        if(count==3) win(0);
        count = 0;
    }
}
void diagonalcompcheck(char board[size][size])
{
    int x,y,count;
    for(x=0,y=0,count=0;x<size;x++,y++) // This checks for a top-left to bottom-right diagonal win
    {
        if(board[x][y]==com) count++;
    }
    if(count==3) win(0);
    for(x=0,y=2,count=0;x<size;x++,y--) // This checks for a top-right to bottom-left diagonal win
    {
        if(board[x][y]==com) count++;
    }
    if(count==3) win(0);
}
void verticalcompcheck(char board[size][size])
{
    int x,y,count;
    for(y=0,count=0;y<size;y++) // This checks vertically to see if the computer has won.
    {
        for(x=0;x<size;x++)
        {
            if(board[x][y]==com) count++;
        }
        if(count==3) win(0);
        count = 0;
    }
}
void horizontalusercheck(char board[size][size])
{
    int x,y,count;
    for(x=0,count=0;x<size;x++) // This checks horizontally to see if the player has won.
    {
        for(y=0;y<size;y++)
        {
            if(board[x][y]==user) count++;
        }
        if(count==3) win(1);
        count = 0;
    }
}
void verticalusercheck(char board[size][size])
{
    int x,y,count;
    for(y=0,count=0;y<size;y++) // This checks vertically to see if the player has won.
    {
        for(x=0;x<size;x++)
        {
            if(board[x][y]==user) count++;
        }
        if(count==3) win(1);
        count = 0;
    }
}
void diagonalusercheck(char board[size][size])
{
    int x,y,count,sentinel=0;
    for(x=0,y=0,count=0;x<size;x++,y++) // This checks for a top-left to bottom-right diagonal win(player)
    {
        if(board[x][y]==user) count++;
    }
    if(count==3) win(1);
    for(x=0,y=2,count=0;x<size;x++,y--) // This checks for a top-right to bottom-left diagonal win(player)
    {
        if(board[x][y]==user) count++;
    }
    if(count==3) win(1);
}
void initialize(char board[size][size])
{
    int x,y;
    for(x=0;x<size;x++)
    {
        for(y=0;y<size;y++)
        {
            board[x][y] = 32;
        }
        
    }
}
