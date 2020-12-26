#include <stdio.h>
#include <stdbool.h>
#include "array.h"
#include "game.h"

#define SIZE 4
// Start a new game. 
void game_new(void) 
{
    Array *arr = array_create(SIZE, SIZE);
    
}

// Quit the current game.
void game_quit(void);

// Return the value of the specified piece (0 if empty).
int game_get_square(int row, int column);

// Slide all pieces up, right, down, or left. 
void game_slide_up(void);
void game_slide_right(void);
void game_slide_down(void);
void game_slide_left(void);

// Return true if the game is over (2048 reached or no empty squares).
bool game_is_game_over(void);
