#include <cstdio>
#include <vector>

using namespace std;

vector <int> prime;

void precompute_primes()
{
    vector <int> is_prime(1e4 + 11, true);

    for(int i = 2; i <= 1e4 + 10; i++)
    {
        if(is_prime[i])
        {
            for(int multiple = 2*i; multiple <= 1e4 + 10; multiple +=i)
            {
                is_prime[multiple] = false;
            }
            prime.push_back(i);
        }

    }
}

int main()
{
    int left, right;
    scanf("%d %d", &left, &right);

    precompute_primes();

    int i = 0;
    while(prime[i] < left)
        i++;

    for(; prime[i] <= right; i++)
    {
        printf("%d ",prime[i]);
    }
    return 0;
}

