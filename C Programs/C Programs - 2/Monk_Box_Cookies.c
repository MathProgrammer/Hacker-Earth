#include <stdio.h>

void solve()
{
    int no_of_balls, number, i;
    int no_of_bits[32] = {0}, current_bit_position, most_set_bit_position = 0;

    scanf("%d", &no_of_balls);

    for(i = 1; i <= no_of_balls; i++)
    {
        scanf("%d", &number);

        for(current_bit_position = 0; number != 0; current_bit_position++)
        {
            no_of_bits[current_bit_position] += (number & 1) ;
            number = number >> 1;
        }
    }

    for(i = 0; i < 32; i++)
    {
        most_set_bit_position = (no_of_bits[i] > no_of_bits[most_set_bit_position] ? i : most_set_bit_position);
    }

    printf("%d\n",most_set_bit_position);
}

int main()
{
    int no_of_test_cases;


    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases-- != 0)
    {
        solve();
    }

    return 0;
}
