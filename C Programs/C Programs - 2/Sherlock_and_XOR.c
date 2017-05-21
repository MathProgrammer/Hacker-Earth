#include <stdio.h>

void solve()
{
    int no_of_numbers, no_of_odd_numbers = 0, no_of_even_numbers, i, current_number;
    unsigned int no_of_pairs;

    scanf("%d", &no_of_numbers);
    for(i = 0; i < no_of_numbers; i++)
    {
        scanf("%d",&current_number);
        no_of_odd_numbers += (current_number % 2);
    }
    no_of_even_numbers = no_of_numbers - no_of_odd_numbers;

    no_of_pairs = (no_of_odd_numbers*no_of_even_numbers); //(p, q) gives an odd XOR iff p and q have different parity. We count the pairs up to order
    printf("%u\n",no_of_pairs);
}
int main()
{
    int no_of_test_cases;
    scanf("%d",&no_of_test_cases);

    while(no_of_test_cases-- != 0)
    {
        solve();
    }
    return 0;
}
