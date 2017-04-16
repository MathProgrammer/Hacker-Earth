#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

void count_no_of_even_characters(unsigned int *, char[]);
void display(unsigned int *,int);

int main()
{
    char string[MAX_SIZE];
    scanf("%s",string);
    unsigned int *no_of_even_characters_from_here_to_end = malloc(strlen(string)*sizeof(unsigned int));
    count_no_of_even_characters(no_of_even_characters_from_here_to_end, string);
    display(no_of_even_characters_from_here_to_end, strlen(string));
    free(no_of_even_characters_from_here_to_end);
    return 0;
}

void count_no_of_even_characters(unsigned int *no_of_even_characters_from_here_to_end,char string[])
{
    int length = strlen(string), i;

    /*Start from the right end of the string. Let f(i) denote the number of even characters from i till the end of the array.

    f(length) = 0, if str[length] is odd
              = 1, if str[length] is even, (We are starting from the end since we start from the rightmost end.)

    For i = length to 1, do -
    f(i) = f(i + 1),     if str[i] is odd
         = 1 + f(i + 1), if str[i] is even*/
    *(no_of_even_characters_from_here_to_end + length - 1) = ( ( (string[length-1] - '0')%2 == 0) ? 1 : 0 ); //First character is even or odd

    for(i = length - 2; i >= 0 ; i--)
    {
        *(no_of_even_characters_from_here_to_end + i) = *(no_of_even_characters_from_here_to_end + i + 1);

        if( (string[i] - '0')%2 == 0)
        {
            *(no_of_even_characters_from_here_to_end + i) = *(no_of_even_characters_from_here_to_end + i) + 1;
        }
    }
}

void display(unsigned int *numbers, int no_of_numbers)
{
    int i;
    for(i =0; i < no_of_numbers; i++)
    {
        printf("%u ", *(numbers + i));
    }
}
