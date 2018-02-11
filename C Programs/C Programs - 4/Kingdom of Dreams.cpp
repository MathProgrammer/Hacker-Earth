#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()

using namespace std;

void solve()
{
    int no_of_people;
    scanf("%d", &no_of_people);

    vector <int> cost(no_of_people + 1, 0);
    for(int i = 0; i < no_of_people; i++)
        scanf("%d", &cost[i]);

    sort(all(cost));

    long long total_cost = 0;

    while(no_of_people >= 4)
    {
        total_cost += min(cost[2] + cost[1] + cost[no_of_people] + cost[2],
                          cost[no_of_people] + cost[1] + cost[no_of_people - 1] + cost[1]);

        no_of_people -= 2;
    }

    if(no_of_people == 3) total_cost += cost[3] + cost[1] + cost[2];

    if(no_of_people == 2) total_cost += cost[2];

    if(no_of_people == 1) total_cost += cost[1];

    printf("%lld\n", total_cost);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
