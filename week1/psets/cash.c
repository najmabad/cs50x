// Find the fewest coins to give a customer's change

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Prompt user for change
    float dollars;
    do
    {
        dollars = get_float("Change owned: ");
    }
    // Repeat prompt until the input is non-negative
    while (dollars < 0);
    
    
    // Cast change into cents
    int cents = round(dollars * 100);
    // printf("Cents %i", cents);

    // Compute the fewest number of coins to give. Possible coins (cents): 25, 10, 5, 1.
    int number_of_coins = 0;
    
    while (cents > 0) 
    {
        if (cents >= 25)
        {
            cents -= 25;
            number_of_coins++;
        }
        else if (cents >= 10)
        {
            cents -= 10;
            number_of_coins++;
        }
        else if (cents >= 5)
        {
            cents -= 5;
            number_of_coins++;
        }
        else 
        {
            cents -= 1;
            number_of_coins++;
        }
    }
    
    printf("%i\n", number_of_coins);
    
}
