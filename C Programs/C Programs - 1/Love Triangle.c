#include <stdio.h>

long long base_9(long long num)
{
    if(num < 9)
        return num;
    else
        return num%9 + 10*base_9(num/9);//Multiply by 10 to shift significant digits
}

int main()
{
    long long number;

    while(scanf("%lld", &number) != EOF)
    {
        printf("%lld\n", base_9(number));
    }

    return 0;
}
