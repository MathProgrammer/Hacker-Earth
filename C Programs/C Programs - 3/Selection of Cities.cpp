#include <cstdio>
using namespace std;

long long power_mod(int x, long long power, int mod)
{
    long long result = 1, y = x;

    while(power > 0)
    {
        if(power%2 == 1)
            result = (result*y)%mod;

        y = (y*y)%mod;
        power = power >> 1;
    }

    return result;
}

void solve()
{
    long long no_of_cities;
    scanf("%lld", &no_of_cities);

    const int mod = 1e9 + 7;
    long long no_of_choices = power_mod(2, no_of_cities, mod) + (mod - 1); //Adding -1
    no_of_choices %= mod;

    printf("%lld\n", no_of_choices);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}

