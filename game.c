#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"
#include "game.h"

static Array *random_tiles(Array *arr, int amount) 
{
    int posrow, poscol, tile = -1, tempr = -1, tempc = -1;

    for (int i = 0; i < amount; i++) {
        posrow = rand() % 4;
        poscol = rand() % 4;

        do {
            posrow = rand() % 4;
            poscol = rand() % 4;
        } while ((posrow == tempr && poscol == tempc) || array_get(arr, posrow, poscol) != 0);

       
            if (rand() % 10 == 0) {
                tile = 4;

            } else {
                tile = 2;

            }
        

        array_set(arr, posrow, poscol, tile);
        tempr = posrow;
        tempc = poscol;
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

static bool checkOut(Array *ar)
{
   bool ch = false;
   for ( int r = 1; r < 4; r++)
   {
      for (int c = 0; c < 4; c++)
      {
         //printf("fast vid andra for\n" );
         if(array_get(arr, r, c) ){
         if ( array_get(arr , r - 1, c ) == 0 && array_get(arr , r , c))
         {
            ch = true;
         }

         else if (array_get(arr , r - 1, c ) == array_get(arr , r , c))
         {
            ch = true;
         }
      }
      }
   }
   return ch;
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
void game_slide_up(void) {
int cnt;
do {
   cnt = 0;
printf("fast vid do, i slide up\n" );
for (int r = 1; r < 4; r++)
{
   for(int c = 0; c < 4; c++)
   {
      if (array_get(arr , r - 1, c ) == 0 && array_get(arr , r , c) )
      {
         array_set(arr , r - 1 , c ,array_get(arr , r , c) );
         array_set(arr , r , c , 0);

      }

      else if ((array_get(arr , r - 1, c ) == array_get(arr , r , c)
   )&& (array_get(arr , r - 1, c ) != 0))
      {
         array_set(arr , r - 1 , c ,2 * array_get(arr , r , c) );
         array_set(arr , r  , c , 0);
         cnt = 3;

      }
   }
}

} while (checkOut(arr) && cnt != 3 );

random_tiles(arr, 1);
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
