#include <stdio.h>

int main()
{
    long answer = 1L, base, exponent;
    const int MOD = 1e9 + 7;

    scanf("%ld %ld",&base, &exponent);

    for( ;exponent > 0; exponent = exponent >> 1)
    {
        if(exponent%2 == 1)
            answer = (answer*base)%MOD;

        base = (base*base)%MOD;
    }

    printf("%ld\n",answer);
    return 0;
}
