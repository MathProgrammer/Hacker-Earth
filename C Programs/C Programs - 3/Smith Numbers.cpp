#include <cstdio>
#include <vector>
using namespace std;

inline int digit_sum(int n)
{
    int sum = 0;

    while(n > 0)
    {
        sum += n%10;
        n = n/10;
    }

    return sum;
}

void precompute(vector <int> &smith_numbers_till, int LIMIT)
{
    vector <int> largest_prime_factor(LIMIT + 1, 0);

    vector <int> prime_factor_digit_sum(LIMIT + 1, 0);

    for(int i = 2; i <= LIMIT; i++)
    {
        if(largest_prime_factor[i] == 0)
        {
            largest_prime_factor[i] = i;

            for(int multiple = i; multiple <= LIMIT; multiple+= i)
                largest_prime_factor[multiple] = i;
        }

        prime_factor_digit_sum[i] = digit_sum(largest_prime_factor[i]) + prime_factor_digit_sum[i/largest_prime_factor[i]];
    }

    for(int i = 1; i <= LIMIT; i++)
        smith_numbers_till[i] = (digit_sum(i) == prime_factor_digit_sum[i]) + smith_numbers_till[i - 1];
}

int main()
{
    const int LIMIT = 1e7;
    vector <int> smith_numbers_till(LIMIT + 1, 0);
    precompute(smith_numbers_till, LIMIT);

    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
    {
        int left, right;
        scanf("%d %d", &left, &right);

        printf("%d\n", smith_numbers_till[right] - smith_numbers_till[left - 1]);
    }

    return 0;
}

