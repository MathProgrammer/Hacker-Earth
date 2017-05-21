#include <stdio.h>
#define MASK_1 0x5555555555555555
#define MASK_2 0x3333333333333333
#define MASK_3 0x0F0F0F0F0F0F0F0F
#define MASK_4 0x00FF00FF00FF00FF
#define MASK_5 0x0000FFFF0000FFFF
#define MASK_6 0x00000000FFFFFFFF

int population_count(unsigned long long n)
{
    n = (n&MASK_1) + ( (n >> 1) & MASK_1);
    n = (n&MASK_2) + ( (n >> 2) & MASK_2);
    n = (n&MASK_3) + ( (n >> 4) & MASK_3);
    n = (n&MASK_4) + ( (n >> 8) & MASK_4);
    n = (n&MASK_5) + ( (n >> 16) & MASK_5);
    n = (n&MASK_6) + ( (n >> 32) & MASK_6);

    return n;
}

void solve()
{
    long long number_1, number_2;
    int answer;
    scanf("%I64u %I64u", &number_1, &number_2);

    answer = population_count(number_1^number_2);
    printf("%d\n",answer);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases-- != 0)
    {
        solve();
    }
    return 0;
}
