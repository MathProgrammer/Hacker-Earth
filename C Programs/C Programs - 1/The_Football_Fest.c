#include <stdio.h>
#include <stdlib.h>

#define swap(a,b)({a = a + b; b = a - b; a = a - b;})
unsigned int find_final_possesser(unsigned int, unsigned int);
int main()
{
    short no_of_test_cases, i;
    unsigned int no_of_passes, final_possesser, first_possesser;

    scanf("%hu",&no_of_test_cases);
    for(i = 1; i <= no_of_test_cases; i++)
    {
        scanf("%u %u",&no_of_passes, &first_possesser);
        final_possesser = find_final_possesser(no_of_passes, first_possesser);
        printf("Player %u\n",final_possesser);
    }
    return 0;
}

unsigned int find_final_possesser(unsigned int no_of_passes, unsigned int first_possesser)
{
    char current_action;
    unsigned int previous_possesser, current_possesser; //This is a stack
    unsigned int  pass_count;

    current_possesser = first_possesser;

    for(pass_count = 0; pass_count < no_of_passes; pass_count++)
    {
        scanf(" %c",&current_action);

        if(current_action == 'P')
        {
            previous_possesser = current_possesser;
            scanf("%u",&current_possesser); //Pushing an element onto the stack
        }
        else//Pass it back
        {
            swap(current_possesser, previous_possesser);
        }
    }

    return current_possesser;
}
