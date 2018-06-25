#include <cstdio>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7, LIMIT = 2e5 + 15;

vector <long long> factorial(LIMIT);
void precompute()
{
    factorial[0] = 1;

    for(int i = 1; i < LIMIT; i++)
        factorial[i] = (i*factorial[i - 1])%MOD;
}

long long square(long long n)
{
    return (n*n)%MOD;
}

long long power(long long x, long long power)
{
    long long answer = 1;

    while(power)
    {
        if(power%2 == 1)
            answer = (answer*x)%MOD;

        x = (x*x)%MOD;
        power = power >> 1;
    }

    return answer;
}

long long inverse(long long n)
{
    return power(n, MOD - 2);
}

long long choose(int n, int r)
{
    long long numerator = factorial[n];
    long long denominator = (factorial[r]*factorial[n - r])%MOD;

    return (numerator*inverse(denominator))%MOD;
}

int main()
{
    precompute();

    int n, no_of_holes;
    scanf("%d %d", &n, &no_of_holes);

    vector <int> is_free(n + 1, true);
    for(int i = 1; i <= no_of_holes; i++)
    {
        int top, size;
        scanf("%d %d", &top, &size);

        for(int j = top + 1; j < top + size ; j++)
            is_free[j] = false;
    }

    long long no_of_paths = 0;

    for(int i = 0; i <= n; i++)
    {
        if(is_free[i])//Square (i, i) is not in a mesh.
        {
            no_of_paths += square(choose(n, i));
            no_of_paths %= MOD;
        }
    }

    printf("%lld\n", no_of_paths);
    return 0;
}
