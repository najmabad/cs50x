#include <stdio.h>
#include <cs50.h>
#include <math.h>


bool validate_number(long);
int get_first_digit(long);
int get_first_two_digits(long);


int main(void)
{
    // Prompt user for credit card number
    long card = get_long("Number: ");
    
    // Get card length, first and second digits
    int length = (int)(card ? log10(card) + 1 : 1);
    int first_two_digits = get_first_two_digits(card);
    int first_digit = get_first_digit(card);
    
    // Check for card type
    
    // American Express uses 15-digit numbers and starts with 34 or 35
    if ((length == 15) & (first_two_digits == 34 || first_two_digits == 37)) 
    {
        // The number combination needs also to be valid
        if (validate_number(card))
        {
            printf("AMEX\n");   
        }
        else
        {
            printf("INVALID\n");
        }
       
    }
    
    // MasterCard uses 16-digit numbers and starts with 51, 52, 53, 54, or 55
    else if ((length == 16) & (first_two_digits == 51 || first_two_digits == 52 || first_two_digits == 53 || first_two_digits == 54
                               || first_two_digits == 55))
    {
        // The number combination needs also to be valid
        if (validate_number(card))
        {
            printf("MASTERCARD\n");   
        }
        else
        {
            printf("INVALID\n");
        }
    }
    
    // Visa uses 16-digit or 13-digit numbers and starts with 4
    else if ((length == 16 || length == 13) & (first_digit == 4))
    {
        if (validate_number(card))
        {
            printf("VISA\n");
        }
        
        else
        {
            printf("INVALID\n");
        }
       
    }
    
    else
    {
        printf("INVALID\n");
    }
}


// Validate credit card number
bool validate_number(long card)
{
    int digit;  
    int inner_digit;
    int index = 0;
    int sum_odds = 0;
    int sum_evens = 0;
    
    // Loop over digits of card number
    while (card)
    {
        digit = card % 10;

        // Consider odd digits, starting from second to last
        if (index % 2)
        {
            // Multiply the digit by two
            int double_digit = digit * 2;
         
            // Loop over the product to sum each digit together
            while (double_digit)
            {
                inner_digit = double_digit % 10;
                sum_odds += inner_digit;
                double_digit /= 10;
            }
        }
        // Sum even digits
        else
        {
            sum_evens += digit;
        }
        
        card /= 10;
        index++;
    }
    
    
    int total_sum = sum_odds + sum_evens;

    if (total_sum % 10)
    {
        return false;
    }
    else
    {
        return true;
    }
    
}


int get_first_digit(long card)
{
    while (card >= 10) 
    {
        card /= 10;
    }
    return card;
}


int get_first_two_digits(long card)
{
    while (card >= 100) 
    {
        card /= 10;
    }
    return card;
}
