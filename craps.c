#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum bet
{
    pass,
    dont_pass,
    come,
    dont_come,
    field,
    proposition
} player_bet;

enum phase
{
    come_out,
    points
} game_phase;

int rollDie()
{
    return (rand() % 6) + 1;
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
    scanf("%d", &choice);
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

void evaluateBet(int bet, int total, enum phase *game_phase, int betAmount, int *money, int *point)
{
    if (*game_phase == come_out)
    {
        switch (bet)
        {
        case pass:
            if (total == 7 || total == 11)
            {
                *money += betAmount;
            }
            else if (total == 2 || total == 3 || total == 12)
            {
                *money -= betAmount;
            }
            else
            {
                *point = total;
                *game_phase = points;
            }
            break;
        case dont_pass:
            if (total == 2 || total == 3 || total == 12)
            {
                *money += betAmount;
            }
            else if (total == 7 || total == 11)
            {
                *money -= betAmount;
            }
            else
            {
                *point = total;
                *game_phase = points;
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
                } else if (total == 7) {
                    // lose
                    *money = *money - (betAmount * 2);
                    (*money < 0) ? *money = 0 : *money;
                    *game_phase = come_out;
                }
                break;
            case dont_pass:
                if (total == 7) {
                    *money = *money + (betAmount * 2);
                    *game_phase = come_out;
                } else if (total == *point) {
                    *money = *money - (betAmount * 2);
                    // Evil is in the building!
                    (*money < 0) ? *money = 0 : *money;
                    *game_phase = come_out;
                }
                break;
        }
    }
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

    srand(time(0));

    printf("Welcome to COP3223C Gambling Night!\n");
    printf("What's your name? ");
    scanf("%s", name);
    do
    {
        player_bet = placeBet();
        betAmount = setBetAmount(money);
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
            printf("Do you wish to roll again? (y/n) ");
            scanf(" %c", &choice);
        }
    } while (money > 0 && choice == 'y');
}