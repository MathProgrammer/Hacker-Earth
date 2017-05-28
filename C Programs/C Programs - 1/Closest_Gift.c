#include <stdio.h>

#define true 1
#define false 0

int isPrime(int n)
{
    int i;

    if(n < 2)
        return false;

    for(i = 2; i*i <= n; i++)
        if(n%i == 0)
            return false;

    return true;
}

int main()
{
    int number, distance;
    scanf("%d", &number);

    for(distance = 0; ; distance++)
    {
        if(isPrime(number + distance))
            break;
    }

    printf("%d\n",distance);
    return 0;
}
