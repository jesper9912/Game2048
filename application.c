#include <stdio.h>
#include "application.h"
#include "game.h"

void app_run(void)
{
    int value = 0;
    game_new();
  
   printf("0: quit\n 1: slide up\n 2: slide right\n");
   printf("3: slide down \n4: slide left\n");
    
     
    for( int y = 0;  y < 4; y++ )
    {   
        printf("+--------+--------+--------+--------+\n");
        
        printf( "|        |        |        |        |\n" );
        printf( "|" );
        for( int x = 0; x < 4; x++ )
        {
            value =  arr[x,y] ->data;
            printf( "%*d   |", 5, value);
            
        }
        printf( "\n|        |        |        |        |\n" );

    }
    
    printf("+--------+--------+--------+--------+\n");
   

    
}
