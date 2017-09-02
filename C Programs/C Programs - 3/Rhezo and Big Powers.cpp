#include <cstdio>

#define MAX_SIZE 100000 + 3
using namespace std;

long long power_mod(int x, int power, int mod)
{
    long long result = 1LL, y = x;
    
    while(power > 0)
    {
        if(power%2 == 1)
            result = (result*y)%mod;
            
        y = (y*y)%mod;
        power = power >> 1;
    }
    
    return result;
}

int get_remainder(char exponent[], int mod)
{
    int remainder = 0;
    for(int i = 0; exponent[i] != '\0'; i++)
    {
        remainder = (remainder*10LL + exponent[i] - '0')%mod;
    }
    return remainder;
}

int main()
{
    int a;
    char exponent[MAX_SIZE];
    scanf("%d %s", &a, exponent);
    
    const int MOD = 1e9 + 7;
    int net_exponent = get_remainder(exponent, MOD - 1);
    
    long long answer = power_mod(a, net_exponent, MOD);
    printf("%lld\n", answer);
    
    return 0;
}
