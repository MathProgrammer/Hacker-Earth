#include <stdio.h>
#include <vector>

using namespace std;

vector <long long> prime_sum(1e6 + 1, 0);

void precompute_prime_sum()
{
    vector <int> is_prime(1e6 + 1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= 1e6; i++)
    {
        if(is_prime[i])
        {
            for(int j = 2*i ; j <= 1e6; j += i)
            {
                is_prime[j] = false;

            }
        }
    }

    for(int i = 2; i <= 1e6; i++)
    {
        prime_sum[i] = prime_sum[i - 1] + (is_prime[i] ? i : 0);
    }

}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    precompute_prime_sum();

    while(no_of_test_cases--)
    {
        int left, right;
        scanf("%d %d", &left, &right);

        printf("%lld\n", prime_sum[right] - prime_sum[left - 1]);
    }

    return 0;
}

