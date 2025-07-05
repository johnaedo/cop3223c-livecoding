#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "bets.h"

void flushInput(void) {
    scanf("%*[^\n]"); // Discards characters until newline
    scanf("%*c");     // Discards the newline
}


int rollDie()
{
    return (rand() % 6) + 1;
}

void printState(bet_t player_bet, phase_t game_phase) {
    char phase_string[15];
    char bet_string[50];
    switch (game_phase) {
        case come_out:
            strcpy(phase_string, "COME OUT");
            break;
        case points: 
            strcpy(phase_string, "POINTS");
            break;
    }
    switch (player_bet) {
        case come:
            strcpy(bet_string, "Come");
            break;
        case pass:
            strcpy(bet_string, "Pass");
            break;
        case dont_pass:
            strcpy(bet_string, "Don't Pass");
            break;
        case dont_come:
            strcpy(bet_string, "Don't Come");
            break;
        case field:
            strcpy(bet_string, "Field");
            break;
        case proposition:
            strcpy(bet_string, "Proposition");
            break;
        default:
            strcpy(bet_string, "Error, no such bet type.");
    }
    printf("Bet:  %s\tPhase:  %s\n", bet_string, phase_string);
}

int placeBet(void)
{
    int choice = 0;
    printf("What type of bet will you make?\n");
    printf("1 - Pass\n");
    printf("2 - Don't Pass\n");
    printf("3 - Come\n");
    printf("4 - Don't Come\n");
    printf("5 - Field\n");
    printf("6 - Proposition\n");
    printf("Choice> ");
    scanf("%d", (&choice - 1));
    return choice;
}

int setBetAmount(int money)
{
    int betAmount = 0;
    do
    {
        printf("How much will you wager? ");
        scanf("%d", &betAmount);
        if (betAmount > money)
        {
            printf("Bet amount must be less than your current wallet.\n");
        }
    } while (betAmount > money);
    return betAmount;
}

/*

    The game begins with the come-out roll. The shooter rolls the dice, and the outcome determines what happens next.
    Winning Outcomes (on Come-Out Roll):
        7 or 11: Pass Line bets win.
        2, 3, or 12 (Craps): Pass Line bets lose, and Don’t Pass Line bets win
         (except on a 12, which is a push on Don’t Pass).
    Establishing the Point: If the shooter rolls any number other than 2, 3, 7, 11, or 12, that number becomes the point. 
    The shooter must now continue rolling until they either roll the point number again or roll a 7 (which ends the round).
*/

void evaluateBet(int bet, int total, phase_t *game_phase, int betAmount, int *money, int *point)
{
    if (*game_phase == come_out)
    {
        switch (bet)
        {
        case pass:
            if (total == 7 || total == 11)
            {
                *money += betAmount;
                printf("Pass WIN\n");
                printState(bet, *game_phase);
            }
            else if (total == 2 || total == 3 || total == 12)
            {
                *money -= betAmount;
                printf("Pass LOSE\n");
                printState(bet, *game_phase);
            }
            else
            {
                *point = total;
                *game_phase = points;
                printf("Now in points phase.  Point value: %d\n", *point);
                printState(bet, *game_phase);
            }
            break;
        case dont_pass:
            if (total == 2 || total == 3 || total == 12)
            {
                *money += betAmount;
                printf("Don't pass WIN\n");
                printState(bet, *game_phase);
            }
            else if (total == 7 || total == 11)
            {
                *money -= betAmount;
                printf("Don't pass LOSE\n");
                printState(bet, *game_phase);
            }
            else
            {
                *point = total;
                *game_phase = points;
                printf("Now in points phase.  Point value: %d\n", *point);
                printState(bet, *game_phase);
            }
            break;
        }
    } else {
        switch (bet) {
            case pass:
                if (total == *point) {
                    // win
                    *money = *money + (betAmount * 2);
                    *game_phase = come_out;
                    printf("Now in back to come out phase.\n");
                    printState(bet, *game_phase);
                } else if (total == 7) {
                    // lose
                    *money = *money - (betAmount * 2);
                    (*money < 0) ? *money = 0 : *money;
                    *game_phase = come_out;
                    printf("Now in back to come out phase.\n");
                    printState(bet, *game_phase);
                } else {
                    printf("PASS while it is NOT come_out\n");
                    printState(bet, *game_phase);
                }
                break;
            case dont_pass:
                if (total == 7) {
                    *money = *money + (betAmount * 2);
                    *game_phase = come_out;
                    printf("Now in back to come out phase.\n");
                    printState(bet, *game_phase);
                } else if (total == *point) {
                    *money = *money - (betAmount * 2);
                    // Evil is in the building!
                    (*money < 0) ? *money = 0 : *money;
                    *game_phase = come_out;
                    printf("Now in back to come out phase.\n");
                    printState(bet, *game_phase);
                } else {
                    printf("DONT_PASS while it is NOT come_out\n");
                    printState(bet, *game_phase);
                }
                break;
        }
    }
}
