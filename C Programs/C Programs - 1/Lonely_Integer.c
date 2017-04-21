#include <stdio.h>

int main()
{
    int i, current_number, bitwise_xor_all_numbers = 0, no_of_elements;
    scanf("%d",&no_of_elements);

    for(i = 1; i <= no_of_elements; i++)
    {
        scanf("%d",&current_number);
        bitwise_xor_all_numbers = bitwise_xor_all_numbers^current_number;
    }

    printf("%d\n",bitwise_xor_all_numbers);
    return 0;
}
