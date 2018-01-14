#include <cstdio>
#include <vector>

#define max(a, b) (a > b ? a : b)
using namespace std;

void solve()
{
    int length;
    scanf("%d", &length);

    vector <int> upper(length);
    for(int i = 1; i < length; i++)
        scanf("%d", &upper[i]);

    vector <int> lower(length + 1);
    for(int i = 1; i < length; i++)
        scanf("%d", &lower[i]);

    for(int i = length - 1; i >= 1; i--)
    {
        int remaining_length = length - i;
        upper[i] = max(0, upper[i] - remaining_length);
        lower[i] = max(0, lower[i] - remaining_length);
    }

    int extra_time = 0;
    for(int i = 1; i < length; i++)
    {
        extra_time = max(extra_time, upper[i]);
        extra_time= max(extra_time, lower[i]);
    }

    int ans = length + extra_time;
    printf("%d\n", ans);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
