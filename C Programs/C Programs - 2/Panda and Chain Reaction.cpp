#include <cstdio>
#include <vector>

using namespace std;

void precompute_factorial(vector <int> &factorial)
{
    const int MOD = 1e6 + 3;
    for(int i = 1; i < MOD; i++)
        factorial[i] = (factorial[i - 1]*1LL*i)%MOD;
}

void solve(vector <int> &factorial)
{
    long long no_of_chambers, particles_in_chamber_zero;
    scanf("%lld %lld", &no_of_chambers, &particles_in_chamber_zero);

    const int MOD = 1e6 + 3;
    long long answer;

    if(no_of_chambers >= MOD)
    {
        answer = 0;
    }
    else
    {
        answer = (particles_in_chamber_zero*factorial[no_of_chambers])%MOD;
    }

    printf("%lld\n", answer);
}

int main()
{
    vector <int> factorial(1e6 + 3 + 1, 1);
    precompute_factorial(factorial);

    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve(factorial);

    return 0;
}

