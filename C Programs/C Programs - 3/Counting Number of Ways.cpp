#include <cstdio>

const int MAX_X = 1e4, MAX_K = 100;
int no_of_ways[MAX_X + 1][MAX_K + 1];

void precompute()
{
    const int MOD = 1e9 + 7;

    for(int k = 1; k <= MAX_K; k++)
    {
        no_of_ways[0][k] = no_of_ways[1][k] = 1;

        for(int x = 2; x <= MAX_X; x++)
        {
            if(x <= k)
                no_of_ways[x][k] = (2LL*no_of_ways[x - 1][k])%MOD;
            else
                no_of_ways[x][k] = (2LL*no_of_ways[x - 1][k] + MOD - no_of_ways[x - k - 1][k])%MOD;
        }
    }
}

int main()
{
    precompute();

    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
    {
        int distance, k;
        scanf("%d %d", &distance, &k);
        printf("%d\n", no_of_ways[distance][k]);
    }

    return 0;
}
