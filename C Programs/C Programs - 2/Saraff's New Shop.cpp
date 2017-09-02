#include <cstdio>

void solve()
{
    long long number;
    int k;
    scanf("%d %lld", &k, &number);

    int no_of_digits_n_in_base_k_plus_1 = 0;

    while(number > 0)
    {
        number = number/(k + 1);
        no_of_digits_n_in_base_k_plus_1++;
    }
    printf("%d\n", no_of_digits_n_in_base_k_plus_1);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
