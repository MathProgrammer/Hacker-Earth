#include <cstdio>
#include <vector>

using namespace std;

vector <int> no_of_prime_primes_till(1e6 + 1, 0);

void precompute_primes()
{
    vector <int> is_prime(1e6 + 1, true);
    vector <int> no_of_primes_till(1e6 + 1, 0);

    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= 1e6; i++)
    {
        if(is_prime[i])
        {
            for(int multiple = 2*i; multiple <= 1e6; multiple +=i)
            {
                is_prime[multiple] = false;
            }
        }
    }

    for(int i = 2; i <= 1e6; i++)
    {
        no_of_primes_till[i] = no_of_primes_till[i - 1] + (is_prime[i] == true);

        no_of_prime_primes_till[i] = no_of_prime_primes_till[i - 1] + (is_prime[no_of_primes_till[i] ] == true);

    }
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    precompute_primes();

    while(no_of_test_cases--)
    {
        int left, right;
        scanf("%d %d", &left, &right);
        printf("%d\n", (no_of_prime_primes_till[right] - no_of_prime_primes_till[left - 1]) );
    }

    return 0;
}

