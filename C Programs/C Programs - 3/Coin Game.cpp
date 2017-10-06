#include <cstdio>

int rightmost_zero_bits(int n)
{
    int rightmost_zeroes = 0;

    while(n%2 == 0)
    {
        rightmost_zeroes++;
        n = n >> 1;
    }

    return rightmost_zeroes;
}

void solve()
{
    int no_of_cards;
    scanf("%d", &no_of_cards);

    int no_of_moves = 0;
    for(int i = 1; i <= no_of_cards; i++)
    {
        int card_i;
        scanf("%d", &card_i);

        no_of_moves += rightmost_zero_bits(card_i);
    }

    printf(no_of_moves%2 == 0 ? "Alan\n" : "Charlie\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}

