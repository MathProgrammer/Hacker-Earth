#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int no_of_piles;
    scanf("%d", &no_of_piles);

    vector <int> xor_of_all_piles_till(no_of_piles + 1, 0);
    for(int i = 1; i <= no_of_piles; i++)
    {
        int stones_i;
        scanf("%d", &stones_i);

        xor_of_all_piles_till[i] = xor_of_all_piles_till[i - 1]^stones_i;
    }

    int no_of_queries;
    scanf("%d", &no_of_queries);

    for(int i = 1; i <= no_of_queries; i++)
    {
        int left, right;
        scanf("%d %d", &left, &right);

        int bitwise_xor_piles = xor_of_all_piles_till[right]^ xor_of_all_piles_till[left - 1];

        printf(bitwise_xor_piles == 0 ? "Ferb\n" : "Phineas\n");
    }

    return 0;
}
