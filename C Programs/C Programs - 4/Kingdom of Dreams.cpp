#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()

using namespace std;

void solve()
{
    int no_of_people;
    scanf("%d", &no_of_people);

    vector <int> cost(no_of_people);
    for(int i = 0; i < no_of_people; i++)
        scanf("%d", &cost[i]);

    no_of_people--;

    sort(all(cost));

    long long total_cost = 0;

    while(no_of_people >= 3)
    {
        total_cost += min(cost[1] + cost[0] + cost[no_of_people] + cost[1],
                          cost[no_of_people] + cost[0] + cost[no_of_people - 1] + cost[0]);

        no_of_people -= 2;
    }

    if(no_of_people == 2) total_cost += cost[2] + cost[0] + cost[1];

    if(no_of_people == 1) total_cost += cost[1];

    if(no_of_people == 0) total_cost += cost[0];

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
