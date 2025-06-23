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

void flushInput(void);
int rollDie(void);
void printState(enum bet, enum phase);
int placeBet(void);
int setBetAmount(int);
void evaluateBet(int, int, enum phase *, int, int *, int *);