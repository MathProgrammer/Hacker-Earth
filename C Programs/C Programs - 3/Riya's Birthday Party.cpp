#include <cstdio>
using namespace std;

void solve()
{
    long long n;
    const int mod = 1e9 + 7;

    scanf("%lld", &n);
    n %= mod;

    long long answer = n*(2*n - 1);
    answer %= mod;

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

