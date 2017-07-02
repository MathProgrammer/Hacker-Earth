#include <cstdio>

void solve()
{
    int no_of_leaves, leaf_i;
    scanf("%d", &no_of_leaves);

    int root = 0;
    for(int i = 1; i <= no_of_leaves; i++)
    {
        scanf("%d", &leaf_i);
        root = root^leaf_i;
    }

    printf("%d\n",root);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
