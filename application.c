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
    int check = 0;

    for (int i = 0; i < 5; i++) {
        if (choice == i) {
            check++;

        }
    }

    if (check > 0) {
        status = true;
    }

    return status;
}

void app_run(void)
{   
    int choice;
    srand(time(NULL));

    game_new(); 
    
    while (!game_is_game_over() || choice == 0) {
        do {

        game_print();
        scanf("%d", &choice);

        } while (!read_int(choice));

    }

    game_quit();

}
