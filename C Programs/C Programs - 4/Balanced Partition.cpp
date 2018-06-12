#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void solve()
{
    int no_of_houses;
    scanf("%d", &no_of_houses);

    map <int, int> no_of_people_at_x;

    for(int i = 1; i <= no_of_houses; i++)
    {
        int x, y, no_of_people;
        scanf("%d %d %d", &x, &y, &no_of_people);

        int new_x = x - y; //new_y = x + y

        no_of_people_at_x[new_x] += no_of_people;
    }

    vector <int> sum_till;
    sum_till.push_back(0);

    const int oo = 2e3;
    int first_x = -oo, last_x = oo;

    for(int x = first_x; x <= last_x; x++)
    {
        if(no_of_people_at_x.find(x) != no_of_people_at_x.end())
        {
            int sum_till_here = sum_till.back() + no_of_people_at_x[x];

            sum_till.push_back(sum_till_here);
        }
    }

    int total_sum = sum_till.back();

    int partition_possible = false;
    for(int i = 1; i < sum_till.size(); i++)
    {
        if(sum_till[i] == total_sum - sum_till[i])
            partition_possible = true;

        // Line passes through house i, so it neither falls left nor right.
        if(sum_till[i - 1] == total_sum - sum_till[i])
            partition_possible = true;
    }

    printf(partition_possible ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}

