#include <stdio.h>
#include <stdlib.h>

#define max(a, b) a > b ? a : b

void solve()
{
    int no_of_stacks, i, maximum_height;
    long overall_max_gain;
    scanf("%d %d", &no_of_stacks, &maximum_height);

    int *no_of_coins = malloc(no_of_stacks*sizeof(int));
    long *maximum_gain = malloc(no_of_stacks*sizeof(long));

    for(i = 0; i < no_of_stacks; i++)
    {
        scanf("%d", (no_of_coins + i));
    }

    /*f(1) = C(1), if C(1) <= max_height
           = 0, otherwise

       f(i) = f(i - 1) + C(i) , if C(i) <= max_height
            = 0, otherwise

        Answer is max{f(i}}         */

    *(maximum_gain + 0) = (*(no_of_coins + 0) <= maximum_height ? *(no_of_coins + 0) : 0);
    overall_max_gain = *(maximum_gain + 0);

    for(i = 1; i < no_of_stacks; i++)
    {
        *(maximum_gain + i) = 0;
        if( *(no_of_coins + i) <= maximum_height )
        {
            *(maximum_gain + i) = *(maximum_gain + i - 1) + *(no_of_coins + i);
            overall_max_gain = max( *(maximum_gain + i), overall_max_gain);
        }
    }

    printf("%ld\n", overall_max_gain);
    free(no_of_coins);
    free(maximum_gain);
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
