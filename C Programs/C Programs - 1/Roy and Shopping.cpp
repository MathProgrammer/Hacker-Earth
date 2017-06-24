#include <iostream>
#include <vector>

#define UNMARKED 0
using namespace std;

vector <int> least_prime_factor(1000000 + 1, UNMARKED);

void precompute_prime_factors()
{
    for(int i = 2; i <= 1e6; i++)
    {
        if(least_prime_factor[i] == UNMARKED) //It is unmarked
        {
            for(int j = i; j <= 1e6; j += i)
            {
                if(least_prime_factor[j] == UNMARKED)
                    least_prime_factor[j] = i;
            }
        }
    }
}

int main()
{
    int no_of_products;
    cin >> no_of_products;

    precompute_prime_factors();

    while(no_of_products--)
    {
        int price;
        cin >> price;

        cout << price - least_prime_factor[price] << "\n";
    }

    return 0;
}
