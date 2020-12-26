#include <stdio.h>

int main(void)
{
    for( int y = 0;  y < 4; y++ )
    {   
        printf("+--------+--------+--------+--------+\n");
        
        printf( "|        |        |        |        |\n" );
        printf( "|" );
        for( int x = 0; x < 4; x++ )
        {
            printf( "%*d   |", 5, x );
            
        }
        printf( "\n|        |        |        |        |\n" );

    }
    
    printf("+--------+--------+--------+--------+\n");
    return 0;
}