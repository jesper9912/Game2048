#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"
#include "game.h"

// Global variables used for keeping track of the board and movement occuring.
static Array *arr;
static bool move = false;

// A help function made to avoid writing uneccesary code in order to add tiles.
static Array *random_tiles(Array *arr, int amount) 
{
    int posrow, poscol, tile = -1, tempr = -1, tempc = -1;

    
    if (move == true) {
        for (int i = 0; i < amount; i++) {
            posrow = rand() % 4;
            poscol = rand() % 4;

            do {
                posrow = rand() % 4;
                poscol = rand() % 4;
            } while ((posrow == tempr && poscol == tempc) || 
                        array_get(arr, posrow, poscol) != 0);


                if (rand() % 10 == 0) {
                    tile = 4;

                } else {
                    tile = 2;

                }


            array_set(arr, posrow, poscol, tile);
            tempr = posrow;
            tempc = poscol;
        }
    }
    

    return arr;
}

// Start a new game. 
void game_new(void) 
{  
    move = true;
    Array *temp = array_create(4, 4);
    arr = random_tiles(temp, 2);
    move = false;
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

// Return true if the game is over (2048 reached or no empty squares).
bool game_is_game_over(void)
{
    bool gameover = false;
    int zerocount = 0;

    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (array_get(arr, y, x) == 2048) {
                gameover = true;
                printf("You have won!\n");

            }
            if (array_get(arr, y, x) == 0) {
                zerocount++;

            }
        }
    }

    if (zerocount == 0) {
        gameover = true;
        printf("Game over\n");

    }
    
    return gameover;
}
// Slide and merge a row on the game board.
static Array *slide(Array *row) {
    for (int i = 3; i >= 0; i--) {
        if (row->data[i] != 0) {
            for (int j = i - 1; j >= 0; j--) {

                if (row->data[j] == 0) {
                    // Move forward

                } else if (row->data[i] == row->data[j]) {
                    // Merge
                    row->data[j] *= 2;
                    row->data[i] = 0;
                    move = true;
                    i = j - 1;
                    j--;

                } else {
                    // Stop
                    j = -1;
                }
            }
        }
    }

    int count = 0;  

    for (int r = 3; r >= 0; r--) { 
        if (row->data[r] == 0) {
            count++;    

        } else if ((row->data[r] != 0) && (count != 0)) {
            row->data[r + count] = row->data[r];
            row->data[r] = 0;
            move = true;

        }   
    }

    return row;
}

void game_slide_left(void)
{
    Array *temp = array_create(1, 4);
    int size = 3;
    for(int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            temp->data[size - c] = game_get_square(r, c);
        }
        temp = slide(temp);

        for (int col = 0; col < 4; col++) {
            array_set(arr, r, col, temp->data[size - col]);
        }
    }   

    array_destroy(temp);
    random_tiles(arr, 1);
    move = false;
}

void game_slide_right(void)
{
    Array *temp = array_create(1, 4);

    for(int r = 0; r < 4; r++) {
       for (int c = 0; c < 4; c++) {
           temp->data[c] = game_get_square(r, c);
       }
       temp = slide(temp);

       for (int col = 0; col < 4; col++) {
           array_set(arr, r, col, temp->data[col]);
       }
   }
   array_destroy(temp);
   random_tiles(arr, 1);
   move = false;
}
void game_slide_up(void)
{   
    Array *temp = array_create(1, 4);
    int size = 3;

    for(int r = 0; r < 4; r++) {
       for (int c = 0; c < 4; c++) {
           temp->data[size - c] = game_get_square(c, r);
       }
       temp = slide(temp);

       for (int col = 0; col < 4; col++) {
           array_set(arr, col, r, temp->data[size - col]);
       }
   }
   array_destroy(temp);
   random_tiles(arr, 1);
   move = false;

}
void game_slide_down(void)
{
    Array *temp = array_create(1, 4);

    for(int r = 0; r < 4; r++) {
       for (int c = 0; c < 4; c++) {
           temp->data[c] = game_get_square(c, r);
       }
       temp = slide(temp);

       for (int col = 0; col < 4; col++) {
           array_set(arr, col, r, temp->data[col]);
       }
   }
   array_destroy(temp);
   random_tiles(arr, 1);
   move = false;
}