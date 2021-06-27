#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompts for start size
    int pop_start;
    do
    {
        pop_start = get_int("Start size: ");
    }
    while (pop_start < 9);
  

    // Prompts for end size
    int pop_end;
    do
    {
        pop_end = get_int("End size: ");
    }
    while (pop_end < pop_start);
    
    // Calculate number of years until we reach threshold
    int n = 0;
    
    while (pop_start < pop_end)
    {
        int newborns = pop_start / 3;
        int deads = pop_start / 4;
        
        pop_start = pop_start + newborns - deads;
        n++;
    }


    // Prints number of years
    printf("Years: %i\n", n);
}