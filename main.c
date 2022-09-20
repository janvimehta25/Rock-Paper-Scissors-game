//Mini - Project: Rock, Paper & Scissors Game
//Player 1: rock
//Player 2(computer): scissors-->player 1 gets 1 point
//rock vs scissors - rock wins
//paper vs scissors - paper wins
//paper vs rock - paper wins
//Write a C program to allow user to play game any number of times with computer. Log the scores of computer and the player.
//Display the name of the winner at the end.
//Any code can be used for implememtation.

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>

#define ROCK 1
#define PAPER 2
#define SCISSOR 3
#define PLAYER1_WIN 1
#define PLAYER2_WIN 2
#define DRAW 0

int rock_paper_scissor(int player1, int player2)
{
    int result;
    if (player1 == ROCK && player2 == PAPER)
    {
        result = PLAYER2_WIN;
    }
    else if (player1 == ROCK && player2 == SCISSOR)
    {
        result = PLAYER1_WIN;
    }
    else if (player1 == PAPER && player2 == ROCK)
    {
        result = PLAYER1_WIN;
    }
    else if (player1 == PAPER && player2 == SCISSOR)
    {
        result = PLAYER2_WIN;
    }
    else if (player1 == SCISSOR && player2 == ROCK)
    {
        result = PLAYER2_WIN;
    }
    else if (player1 == SCISSOR && player2 == PAPER)
    {
        result = PLAYER1_WIN;
    }
    else
    {
        result = DRAW;
    }
    return result;
}

int get_user_input()
{
    int choice;
    do
    {
        printf("\n1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissor\n");
        printf("\nPlease input [1, 2, 3]: ");
        scanf("%d", &choice);
        if (!(choice>=1 && choice<=3))
        {
            printf("-->ERROR -- Invalid input, should be 1 or 2 or 3");
        }
    }
    while (!(choice>=1 && choice<=3));
    return choice;
}

void print_word(int v)
{
    if (v == ROCK)
    {
        printf("Rock\n");
    }
    else if (v == PAPER)
    {
        printf("Paper\n");
    }
    else if (v == SCISSOR)
    {
        printf("Scissor\n");
    }
}
int main()
{
    int user_score = 0;
    int computer_score = 0;
    srand(time(NULL));
    printf("*** Welcome to the Rock, Paper, Scissors Game ***\n");

    int quit = 0;
    while(!quit)
    {
        int user_input = get_user_input();
        int computer_choice = (rand() % 3)+1;
        printf("User chose: ");
        print_word(user_input);
        printf("Computer chose: ");
        print_word(computer_choice);
        printf("\n");

        int result = rock_paper_scissor(user_input, computer_choice);
        if (result == DRAW)
        {
            printf("-->It is a draw!\n");
        }
        else if (result == PLAYER1_WIN)
        {
            printf("-->User Wins and Computer Lost the Round!\n");
            user_score++;
        }
        else if (result == PLAYER2_WIN)
        {
            printf("-->Computer Wins and User Lost the Round!\n");
            computer_score++;
        }

        printf("\n");
        printf("-------------------------------------\n");
        printf("User Score: %d\n", user_score);
        printf("Computer Score: %d\n", computer_score);
        printf("-------------------------------------\n");
        printf("\n\n");
        printf("-->If you want to continue, input any integer, 0 to terminate.\n");
        int response;
        scanf("%d", &response);
        if (response == 0)
        {
            quit = 1;
        }
    }// end of while
    printf("\n");
    printf("FINAL SCORE...\n");
    printf("-------------------------------------\n");
    printf("User Score: %d\n", user_score);
    printf("Computer Score: %d\n", computer_score);
    printf("-------------------------------------\n");
    printf("\n\n");

    if (user_score == computer_score)
    {
        printf("***************************************************************\n");
        printf("\t\tGAME WAS DRAW!!!\n");
        printf("***************************************************************\n");
    }
    else if (user_score > computer_score)
    {
        printf("***************************************************************\n");
        printf("\t\tUSER WINS THE GAME!!!\n");
        printf("***************************************************************\n");
    }
    else
    {
        printf("***************************************************************\n");
        printf("\t\tCOMPUTER WINS THE GAME!!!\n");
        printf("***************************************************************\n");
    }
    return 0;
}

