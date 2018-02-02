#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    scanf("%d", &n);

    int sum_of_odd_divisors = 0;

    while(n%2 == 0)
        n = n/2;

    for(int i = 1; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            sum_of_odd_divisors += (i*i == n ? i : i + n/i);
        }
    }

    printf("%d\n", sum_of_odd_divisors);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}

