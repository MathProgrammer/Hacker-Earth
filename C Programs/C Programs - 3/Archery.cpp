#include <cstdio>
#include <vector>

using namespace std;

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

inline void factorise(int n, vector <int> &highest_exponent)
{
    for(int i = 2; i*i <=n; i++)
    {
        if(n%i == 0)
        {
            int exponent = 0;

            while(n%i == 0)
            {
                n = n/i;
                exponent++;
            }

            highest_exponent[i] = max(highest_exponent[i], exponent);
        }
    }

    if(n > 1)
        highest_exponent[n] = max(highest_exponent[n], 1);
}

inline int power(int n, int power)
{
    int result = 1, y = n;

    while(power > 0)
    {
        if(power%2 == 1)
            result = result*y;

        y = y*y;
        power = power >> 1;
    }

    return result;
}

void solve()
{
    int no_of_numbers;
    scanf("%d", &no_of_numbers);

    const int MAX_NUM = 48;
    vector <int> highest_exponent(MAX_NUM + 1, 0);

    for(int i = 1; i <= no_of_numbers; i++)
    {
        int number_i;
        scanf("%d", &number_i);

        factorise(number_i, highest_exponent);
    }

    unsigned long long product = 1;

    for(int i = 2; i <= MAX_NUM; i++)
    {
        product = product*power(i, highest_exponent[i]);
    }

    printf("%llu\n", product);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}

