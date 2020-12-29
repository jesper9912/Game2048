#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"
#include "game.h"

static Array *random_tiles(Array *arr, int amount) 
{
    int tilepos, tile = -1, tempp = -1;

    for (int i = 0; i < amount; i++) {
        tilepos = rand() % 16;

        do {
            tilepos = rand() % 16;

        } while (tilepos == tempp || arr->data[tilepos] != 0);

       
            if (rand() % 10 == 0) {
                tile = 4;

            } else {
                tile = 2;

            }
        

        arr->data[tilepos] = tile;
        tempp = tilepos;
    }
    
    return arr;
}

static Array *arr;

// Start a new game. 
void game_new(void) 
{  
    Array *temp = array_create(4, 4);
    arr = random_tiles(temp, 2);
}

// Quit the current game.
void game_quit(void)
{   
    array_destroy(arr);
}

// Return the value of the specified piece (0 if empty).
int game_get_square(int row, int column) 
{
    return array_get(arr, row, column);
}

// Slide all pieces up, right, down, or left. 
void game_slide_up(void) 
{
    Array *temp = random_tiles(arr, 1);
    arr = temp;
}
void game_slide_right(void)
{
    Array *temp = random_tiles(arr, 1);
    arr = temp;
} 
void game_slide_down(void)
{
    Array *temp = random_tiles(arr, 1);
    arr = temp;
}
void game_slide_left(void)
{
    Array *temp = random_tiles(arr, 1);
    arr = temp;
}

// Return true if the game is over (2048 reached or no empty squares).
bool game_is_game_over(void)
{
    bool gameover = false;
    int zerocount;

    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (array_get(arr, y, x) == 2048) {
                gameover = true;

            }
            if (array_get(arr, y, x) == 0) {
                zerocount++;

            }
        }
    }

    if (zerocount == 0) {
        gameover = true;

    }
    
    return gameover;
}