#include <cstdio>
using namespace std;

long long power(int x, int n, int MOD)
{
    long long result = 1LL;

    while(n > 0)
    {
        if(n%2 == 1)
            result = (result*1LL*x)%MOD;

        x = (x*1LL*x)%MOD;
        n = n/2;
    }
    return (result%MOD);
}

void solve()
{
    const int MOD = 1e9 + 7;
    long long maximum, minimum;
    int no_of_players;
    scanf("%d", &no_of_players);

    //Max = sum of first n-1 squares ... Write it in a form to avoid overflow
    long long six_inverse = power(6, MOD - 2, MOD);
    maximum =  (no_of_players - 1)*1LL*(no_of_players) %MOD;
    maximum = ( maximum*(2LL*no_of_players - 1) ) %MOD;
    maximum = ( maximum*six_inverse) %MOD;


    int no_of_matches = no_of_players - 1; //Play everyone but yourself.
    int wins = no_of_matches/2; //Everyone wins half their matches
    long long wins_squared = (wins*1LL*wins) % MOD;

    minimum = (no_of_players*wins_squared) % MOD;

    printf("%lld %lld\n",minimum, maximum);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}

