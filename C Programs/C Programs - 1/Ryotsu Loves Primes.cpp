#include <iostream>
#include <vector>

using namespace std;

vector <int> is_prime(1000000 + 1, true);

void precompute_primes()
{
    for(int i = 2; i <= 1000000; i++)
    {
        if(is_prime[i])
        {
            for(int composite = 2*i; composite <= 1000000; composite += i)
                is_prime[composite] = false;
        }
    }
}

void solve()
{
    int prime_sum = 0, no_of_elements, k,  prime_count = 0;
    cin >> no_of_elements >> k;

    for(int i = 1 ; i <= no_of_elements; i++)
    {
        int element_i;
        cin >> element_i;

        if(is_prime[element_i] && element_i >= 2)
            prime_count++;


        if(prime_count == k)
        {
            prime_sum += element_i;
            prime_count = 0;
        }

    }

    cout << prime_sum << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    precompute_primes();

    while(no_of_test_cases--)
        solve();

    return 0;
}
