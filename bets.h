typedef enum bet
{
    pass,
    dont_pass,
    come,
    dont_come,
    field,
    proposition
} bet_t;

bet_t player_bet;

typedef enum phase
{
    come_out,
    points
} phase_t;

phase_t game_phase;

void flushInput(void);
int rollDie(void);
void printState(enum bet, enum phase);
int placeBet(void);
int setBetAmount(int);
void evaluateBet(int, int, phase_t *, int, int *, int *);