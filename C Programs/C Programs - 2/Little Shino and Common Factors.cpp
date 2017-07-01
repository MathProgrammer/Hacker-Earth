#include <cstdio>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b)
{
    if(b == 0)
        return a;
    else
        return gcd(a, a%b);
}

long long no_of_factors(long long n)
{
    int no_of_factors = 0;
    for(long long i = 1; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            no_of_factors += (i*i == n ? 1 : 2);
        }
    }
    return no_of_factors;
}

int main()
{
    long long a, b;
    scanf("%lld %lld", &a, &b);

    printf("%lld\n", no_of_factors(gcd(max(a, b), min(a, b) ) ) );
    return 0;
}

