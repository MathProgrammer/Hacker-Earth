#include <stdio.h>

void solve()
{
   int i, no_of_elements;
   long current_number, bitwise_xor_all_numbers = 0, answer;
   scanf("%d",&no_of_elements);

    for(i = 1; i <= no_of_elements; i++)
    {
        scanf("%ld",&current_number);
        bitwise_xor_all_numbers = bitwise_xor_all_numbers^current_number;
    }

    answer = (bitwise_xor_all_numbers > 0 ? bitwise_xor_all_numbers : -1);
    printf("%ld\n",answer);
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
