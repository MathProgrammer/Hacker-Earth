#include <cstdio>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

int gcd(int a, int b)
{
    if(a == 0 || b == 0)
        return (a + b);

    return gcd(min(a, b), max(a, b)%min(a, b));
}

void solve()
{
    int A, B;
    scanf("%d %d", &A, &B);

    printf("%d/%d\n", A/gcd(A, B), B/gcd(A, B));
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
