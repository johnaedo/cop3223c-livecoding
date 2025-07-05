#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "gamesave.h"

char * getString(char *message) {
    char * str = malloc(sizeof(char) * 100);
    printf("%s: ", message);
    if (fgets(str, sizeof(str), stdin) != NULL) {
        // Find the newline character
        char *newline_ptr = strchr(str, '\n');

        // If a newline is found, replace it with the null terminator
        if (newline_ptr != NULL) {
            *newline_ptr = '\0';
        }
    }
    return str;
}

int main(void)
{
    char name[50] = "";
    int die1 = 0, die2 = 0;
    int total = 0;
    int money = 1000;
    char choice = 'x';
    int point = 0;
    int betAmount = 0;
    game_phase = come_out;
    gameState_t *gamestate;
    gameState_t *highScorer;
    FILE *fp;

    gamestate = malloc(sizeof(gameState_t));
    srand(time(0));


    printf("Welcome to COP3223C Gambling Night!\n");
    strcpy(name, getString("What's your name? "));
    flushInput();
    fp = fopen("gamesave.txt", "w+");
    gamestate = loadGame(fp, name);
    fclose(fp);
    fp = fopen("gamesave.txt", "r");
    highScorer = getHighScorer(fp);
    fclose(fp);

    printf("===================================\n");
    printf("Current High Scorer:  %s\n", highScorer->name);
    printf("Winnings: %d\n", highScorer->money);
    printf("===================================\n");

    free(highScorer);

    printf("You have a starting pot of %d\n", money);
    do
    {
        if (game_phase == come_out) {
            player_bet = placeBet();
            betAmount = setBetAmount(money);
        }
        die1 = rollDie();
        die2 = rollDie();
        total = die1 + die2;
        printf("DIE 1:  %d\tDIE 2: %d\n", die1, die2);
        printf("TOTAL: %d\n", total);
        // (int bet, int total, int *game_phase, int betAmount, int *money, int *point)
        evaluateBet(player_bet, total, &game_phase, betAmount, &money, &point);
        if (money == 0) {
            printf("I'm sorry, you've lost all your money!\n");
        } else {
            printf("Current winnings: %d\n", money);
            printf("Do you wish to roll again? (y/n) ");
            scanf(" %c", &choice);
        }
    } while (money > 0 && choice == 'y');
    fp = fopen("gamesave.txt", "a");
    saveGame(fp, gamestate);
    fclose(fp);

    free(gamestate);
}