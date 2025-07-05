#include <stdio.h>
#include "bets.h"

typedef struct gameState {
    char name[50];
    int money;
    phase_t current_phase;
    int points;
} gameState_t;

void saveGame(FILE *, gameState_t *);
gameState_t *  loadGame(FILE *, char [50]);
gameState_t * getHighScorer(FILE *fp);