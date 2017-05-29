#include <stdio.h>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int gcd(int a, int b)
{
    if(a == 0 || b == 0)
        return (a+b);

    if(a == b)
        return a;

    if(a%2 == 0)
        if(b%2 == 0)
            return 2*gcd(a >> 1, b >> 1);
        else
            return gcd(a >> 1, b);
    else
        if(b%2 == 0)
            return gcd(a, b >> 1);
        else
            return gcd(min(a, b), (max(a, b) - min(a, b) )/2 );
}

long find_power(long base, long exponent)
{
    long answer = 1L;
    const int MOD = 1e9 + 7;

    for( ;exponent > 0; exponent = exponent >> 1)
    {
        if(exponent%2 == 1)
            answer = (answer*base)%MOD;

        base = (base*base)%MOD;
    }

    return answer;
}

int main()
{
    int no_of_numbers, current_number, i;
    const int MOD = 1e9 + 7;
    long base = 1L , exponent, answer;
    scanf("%d", &no_of_numbers);

    for(i = 1; i <= no_of_numbers; i++)
    {
        scanf("%d",&current_number);
        exponent = (i == 1 ? current_number : gcd(exponent, current_number) );
        base = (base*current_number)%MOD;
    }

    answer = find_power(base, exponent);
    printf("%ld\n",answer);
    return 0;
}
