#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


char encrypt_letter(char letter, int key);


int main(int argc, string argv[]) 
{
    // Print error if no command-line argument or more than one argument was given
    if (argc != 2)
    {
        printf("Wrong use of command-line arguments. You should enter one command-line arg.\n");
        return 1;
    }
    else
    {
        // Verify that any character of the command-line argument is a decimal digit
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            // This function returns 0 if the character is not a digit
            if (isdigit(argv[1][i]) == 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
    }
    
    // Convert key into an integer
    int key = atoi(argv[1]);

    // Get text input from the user 
    string plaintext = get_string("plaintext: ");
    
    // Create the encrypted version of the input
    int n = strlen(plaintext);
    char ciphertext[n];

    // Encrypt each character of plain text in the new string ciphertext
    for (int i = 0; i < n; i++)
    {
        ciphertext[i] = encrypt_letter(plaintext[i], key);

    }
    
    // Add marker for string end 
    ciphertext[n] = '\0';
    // Print cyphertext
    printf("ciphertext: %s", ciphertext);
    printf("\n");
    return 0;


}


char encrypt_letter(char letter, int key)
{
    // Transform letter into its ASCII code
    int ascii_code = (int) letter;
    int encrypted_ascii = 0;
    
    // Encrypt the ASCII code
    // Uppercase letters
    if (ascii_code >= 65 & ascii_code <= 90)
    {
        encrypted_ascii = ((ascii_code - 65 + key) % 26) + 65;
        
    }
    // Lowercase letters
    else if (ascii_code >= 97 & ascii_code <= 122)
    {
        encrypted_ascii = ((ascii_code - 97 + key) % 26) + 97;
    }
    // Non-alphabetical characters don't change
    else
    {
        encrypted_ascii = ascii_code;
    }
    
    // Get back the alphabetical letter from encrypted ASCII code
    return (char) encrypted_ascii;
}