#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Ask the user his/her name
    string name = get_string("What's your name? ");
    // Print user name on the screen
    printf("hello, %s\n", name);
}