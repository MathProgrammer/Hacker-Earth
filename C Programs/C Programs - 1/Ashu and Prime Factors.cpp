#include <stdio.h>
#include <vector>

#define UNMARKED 0


vector <int> no_of_numbers_with_least_prime_factor(1e6 + 1, 0);

void precompute_prime_factors()
{
    vector <int> least_prime_factor(1e6 + 1, UNMARKED);

    for(int i = 2; i <= 1e6; i++)
    {
        if(least_prime_factor[i] == UNMARKED)
        {

            for(int j = i ; j <= 1e6; j += i)
            {
                if(least_prime_factor[j] == UNMARKED)
                {
                    least_prime_factor[j] = i;
                     no_of_numbers_with_least_prime_factor[i]++;
                }
            }
        }
    }

}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    precompute_prime_factors();

    while(no_of_test_cases--)
    {
        int query;
        scanf("%d", &query);

        printf("%d\n", no_of_numbers_with_least_prime_factor[query]);
    }

    return 0;
}

