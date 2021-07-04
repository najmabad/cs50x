#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>


int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{
    // Get input string from user 
    string text = get_string("Text: ");

    // Count total number of letters, words, and sentences
    int total_letters = count_letters(text);
    int total_words = count_words(text);
    int total_sentences = count_sentences(text);
 
    // Get verage number of letters per 100 words
    float L = (float) total_letters / total_words * 100.0;
    
    // Get average number of sentences per 100 words
    float S = (float) total_sentences / total_words * 100.0;

    
    // Coleman-Liau index
    int index = round((0.0588 * L) - (0.296 * S) - 15.8);
    
    if (index < 1) 
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
    


}


int count_letters(string text)
{
    // Count number of letters cointained in a string of text
    int total_letters = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Convert letter into ascii
        int ascii_code = (int) text[i];
        
        // Uppercase letters are between 65 and 90 while lowercase letters are between 97 and 122
        if ((ascii_code >= 65 && ascii_code <= 95) || (ascii_code >= 97 && ascii_code <= 122))
        {
            total_letters += 1;            
        }
        else 
        {
            total_letters += 0;
        }
        
    }
    return total_letters;
}

int count_words(string text)
{
    int total_words = 1;
    
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            total_words += 1;
        }
        else 
        {
            total_words += 0;
        }
    }
    return total_words;
}

int count_sentences(string text)
{
    int total_sentences = 0;
    
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            total_sentences += 1;
        }
        else 
        {
            total_sentences += 0;
        }
    }
    return total_sentences;
}





