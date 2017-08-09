#include <cstdio>
#include <vector>

#define max(a, b) (a > b ? a : b)
using namespace std;

void solve()
{
    int no_of_slips, minimum_gap;
    scanf("%d %d", &no_of_slips, &minimum_gap);

    vector <int> time_slip(no_of_slips + 1);
    for(int i = 1; i <= no_of_slips; i++)
        scanf("%d", &time_slip[i]);

    vector <long long> maximum_time_starting_from(no_of_slips, 0);
    for(int slip_i = no_of_slips; slip_i >= 1; slip_i--)
    {
        if(slip_i + minimum_gap >= no_of_slips)
        {
            if(slip_i == no_of_slips)
                maximum_time_starting_from[slip_i] = max(0, time_slip[slip_i]);
            else
                maximum_time_starting_from[slip_i] = max(maximum_time_starting_from[slip_i + 1],
                                                            time_slip[slip_i]);
        }
        else
        {
            maximum_time_starting_from[slip_i] = max(maximum_time_starting_from[slip_i + 1],
                    time_slip[slip_i] + maximum_time_starting_from[slip_i + minimum_gap + 1]);
        }
    }

    printf("%lld\n", maximum_time_starting_from[1]);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}

