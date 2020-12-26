#include <stdio.h>
#include <stdbool.h>
#include "array.h"
#include "game.h"


// Start a new game. 
void game_new(void) 
{
  
    array *arr = array_create(4,4);

   int san, san_plats1, san_plats2 = -1;
   san =  rand () % 10;
   san_plats1 = rand() % 16;
   if ( san == 0)
   {
      arr[san_plats1]->data = 4;
   }
   else
   {
      arr[san_plats1]->data = 2
   }

   while (sna_plats1 != sanplats2)
   {
      san_plats2 = rand() % 16;
   }

   san =  rand () % 10;

   if ( san == 0)
   {
      arr[san_plats2]->data = 4;
   }
   else
   {
      arr[san_plats2]->data = 2
   }
   
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
