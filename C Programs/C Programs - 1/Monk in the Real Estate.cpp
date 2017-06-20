#include <vector>
#include <stdio.h>

#define MAX 1e4 + 1
using namespace std;

void solve()
{
    int no_of_roads, city_x, city_y, no_of_cities = 0;
    vector <int> visited(MAX, false);
    scanf("%d", &no_of_roads);

    for(int i = 1; i <= no_of_roads; i++)
    {
        scanf("%d %d", &city_x, &city_y);
        visited[city_x] = visited[city_y] = true;
    }

    for(int i = 1; i < MAX; i++)
        if(visited[i] == true)
            no_of_cities++;

    printf("%d\n", no_of_cities);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}

