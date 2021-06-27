#include <stdio.h>
#include <cs50.h>

int get_height(void);

int main(void)
{
    // Prompt user for height
    int n = get_height();
    
    // Build a pyramid with n rows
    // Start with rows
    for (int row = 0; row < n; row++)
    {
        // For each row, we build a column made of:
        // (1) Blocks - the first row will have 1 block, the second row 2 blocks and so on..
        int row_blocks = row + 1;
        
        // (2) White spaces - the number of white spaces for each column is equal to (n - row_blocks)
        int white_space = 0;
        
        // Print white spaces
        while (white_space < (n - row_blocks))
        {
            printf(" ");
            white_space++;
        }
        
        // Print row blocks 
        for (int j = 0; j < row_blocks ; j++)
        {
            printf("#");
        }
        
        // Move to next row
        printf("\n");
    }
}


int get_height(void)
{
    int n;
    do 
    {
        n = get_int("Height: ");
    }
    
    // Rejects integers that are not between 1 and 8 (inclusive)
    while ((n < 1) || (n > 8));
    return n;
}

