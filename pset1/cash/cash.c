#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) {
    
    float change_owned;
    
    do 
    {
        change_owned = get_float("Hou much change is owned: \n");
    }
    while (change_owned < 0.00);

    
    int cents = round(change_owned * 100);
    
    int coins = 0;
    
    do
    {
        if (cents - 25 >= 0)
        {
            coins ++;
            cents -= 25;
        }
        else if (cents - 10 >= 0)
        {
             coins ++;
            cents -= 10;
        }
        else if (cents - 5 >= 0)
        {
             coins ++;
            cents -= 5;
        }
        else if (cents - 1 >= 0)
        {
            coins ++;
            cents -= 1;
        }
    }
    while (cents > 0);
    
    printf("%i\n", coins);
    
}