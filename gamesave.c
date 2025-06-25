#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gamesave.h"

void saveGame(FILE *fp, gameState_t *gamestate) {
    fprintf(fp, "%s,%d,%d\n", gamestate->name, gamestate->money, gamestate->current_phase);
}

/* Text File contains a line like this:
    My Name, 15000, 1
    Another Player, 22000, 2
*/

gameState_t * loadGame(FILE *fp, char name[50]) {
    char line[100];
    gameState_t *gamestate = malloc(sizeof(gameState_t));
    while (fgets(line, sizeof(line), fp) != NULL) {
        int i = 0;
        char *myPtr = strtok(line, ",");
        while(myPtr != NULL) {
            switch(i) {
                case 0:
                    strcpy(gamestate->name, myPtr);
                    break;
                case 1:
                    gamestate->money = atoi(myPtr);
                    break;
                case 2:
                    gamestate->current_phase = atoi(myPtr);
            }
            myPtr = strtok(NULL, ",");
            i++;
        }  
        /* Check to see if it's the current player */
        if (!strcmp(gamestate->name, name )) {
            return gamestate;
        } 
    }
    strcpy(gamestate->name, name);
    gamestate->money = 1000;
    gamestate->current_phase = come_out;
    return gamestate;
}


gameState_t * getHighScorer(FILE *fp) {
    char line[50];
    int current_highscore = 0;
    gameState_t *highScorer = malloc(sizeof(gameState_t));
    gameState_t *currentPlayer = malloc(sizeof(gameState_t));
    while (fgets(line, sizeof(line), fp) != NULL) {
        int i = 0;
        char *myPtr = strtok(line, ",");
        while(myPtr != NULL) {
            switch(i) {
                case 0:
                    strcpy(currentPlayer->name, myPtr);
                    break;
                case 1:
                    currentPlayer->money = atoi(myPtr);
                    break;
                case 2:
                    currentPlayer->current_phase = atoi(myPtr);
            }
            myPtr = strtok(NULL, ",");
            i++;
        }
        if (currentPlayer->money > current_highscore) {
            /* Assign currentPlayer to highScorer using POINTER */
            highScorer = currentPlayer;
            
            /* Assign currentPlayer to highScorer using a local struct */
            // strcpy(highScorer->name,currentPlayer.name);
            // highScorer->money = currentPlayer.money;
            // highScorer->current_phase = currentPlayer.current_phase;
        }   
    }
    return highScorer;

}