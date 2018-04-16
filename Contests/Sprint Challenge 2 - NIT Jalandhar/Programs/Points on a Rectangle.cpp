#include <cstdio>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

void solve()
{
    int x1, y1, x2, y2, no_of_points, no_of_internal_points = 0;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    scanf("%d", &no_of_points);

    while(no_of_points--)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        no_of_internal_points += (x > min(x1, x2) && x < max(x1, x2) && y > min(y1, y2) && y<max(y1, y2));
    }
    printf("%d\n", no_of_internal_points);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
