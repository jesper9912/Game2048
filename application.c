#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"
#include "game.h"
#include "application.h"

static void game_print(void)
{   
    int value = 0;
    
    for( int y = 0;  y < 4; y++ )
    {   
        printf("+--------+--------+--------+--------+\n");
        
        printf( "|        |        |        |        |\n" );
        printf( "|" );
        for( int x = 0; x < 4; x++ )
        {
            value =  game_get_square(y, x);
            printf( "%*d   |", 5, value);
            
        }
        printf( "\n|        |        |        |        |\n" );

    }
    
    printf("+--------+--------+--------+--------+\n");    

    printf("0: quit\n1: slide up\n2: slide right\n");
    printf("3: slide down \n4: slide left\n");
    
}

static bool read_int(int choice)
{   
    bool status = false;

    if (choice >= 0 && choice < 5) {
        status = true;
    }

    return status;
}

void app_run(void)
{   
    int choice;
    bool quit = false;
    srand(time(NULL));

    game_new(); 
    
    while (!game_is_game_over() && !quit) {
        do {

        game_print();
        if (scanf("%d", &choice) == EOF) {
            choice = 6;
        }
        printf("%d", choice);
        } while (!read_int(choice));

        switch (choice)
        {
        case 0:
            game_quit();
            quit = true;
            break;

        case 1:
            game_slide_up();
            break;

        case 2:
            game_slide_right();
            break;

        case 3:
            game_slide_down();
            break;

        case 4:
            game_slide_left();
            break;
        
        default:
            break;
        }

    }

 

}
