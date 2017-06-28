#include <cstdio>
#include <vector>

using namespace std;

vector <int> is_prime(1e5 + 1, true);
vector <int> prime;

void precompute_primes()
{
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i < 1e5; i++)
    {
        if(is_prime[i])
        {
            for(int multiple = 2*i; multiple < 1e5; multiple +=i)
            {
                is_prime[multiple] = false;
            }
            prime.push_back(i);
        }
    }
}

void solve()
{
    bool two_prime_sum_possible = false;
    int weight;
    scanf("%d", &weight);

    for(int i = 0; prime[i] < weight; i++)
    {
        if(is_prime[weight - prime[i]])
        {
            two_prime_sum_possible = true;
            break;
        }
    }
    printf(two_prime_sum_possible ? "Deepa\n" : "Arjit\n");
}

int main()
{
    int no_of_cakes;
    scanf("%d", &no_of_cakes);

    precompute_primes();

    while(no_of_cakes--)
        solve();

    return 0;
}

