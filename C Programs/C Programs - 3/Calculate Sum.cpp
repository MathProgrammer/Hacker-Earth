#include <cstdio>

const int MOD = 1e9 + 7;

long long power(long long x, long long power)
{
    long long result = 1;

    while(power)
    {
        if(power%2 == 1)
            result = (result*x)%MOD;

        x = (x*x)%MOD;
        power = power >> 1;
    }

    return result;
}

long long inverse(long long x)
{
    return power(x, MOD - 2);
}

long long cube_sum(long long n)
{
    long long sum = ((n*(n + 1)%MOD)*inverse(2))%MOD;

    return (sum*sum)%MOD;
}

long long square_sum(long long n)
{
    return ( ( (n*(n + 1)%MOD )* ( (2*n + 1)%MOD )%MOD )*inverse(6) )%MOD;
}

void solve()
{
    long long n;
    scanf("%lld", &n);

    n %= MOD;

    long long answer = square_sum(n)*inverse(2) + cube_sum(n)*inverse(2);
    answer %= MOD;

    printf("%lld\n", answer);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
