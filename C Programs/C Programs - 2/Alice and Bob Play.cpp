#include <cstdio>

void solve()
{
    int no_of_rows, no_of_columns;
    scanf("%d %d", &no_of_rows, &no_of_columns);

    printf( no_of_rows%2 == 0 || no_of_columns%2 == 0 || (no_of_columns == 1 && no_of_rows > 1) ? "Bob\n" : "Alice\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
