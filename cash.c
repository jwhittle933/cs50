#include <cs50.h>
#include <stdio.h>
#include <math.h>

int coins(float change)
{
    int coins = 0;
    while ( change - 0.25 > 0.24)
    {
        change -= 0.25; 
        coins++;
    }
    
    while ( change - 0.10 > 0.9 )
    {
        change -= 0.10;
        coins++;
    }
    
    while ( change - 0.5 > 0.4)
    {
        change -= 0.5;
        coins++;
    }
    
    while ( change - 0.1 > 0.0 )
    {
        change -= 0.1;
        coins++;
    }
    
    printf("%i\n", coins);
    return coins;
}

int main(void)
{
    float change = 0;
    do {
        change = get_float("Change owed: ");
    } while ( change <= 0.1 );
    
    coins(change);
}

