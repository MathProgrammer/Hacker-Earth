#include <cstdio>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
    if(a == 0 || b == 0)
        return (a + b);
    else
        return gcd(min(a, b), max(a, b)%min(a, b));
}

int main()
{
    int no_of_numbers;
    scanf("%d", &no_of_numbers);

    vector <int> number(no_of_numbers + 1, 0);
    for(int i = 1; i <= no_of_numbers; i++)
        scanf("%d", &number[i]);

    int suffix_gcd = number[no_of_numbers], removable_prefix_length = 0;
    for(int i = no_of_numbers - 1; i >= 1; i--)
    {
        suffix_gcd = gcd(suffix_gcd, number[i]);

        if(suffix_gcd != number[no_of_numbers])
        {
            removable_prefix_length = i;
            break;
        }
    }

    printf("%d\n", removable_prefix_length);
    return 0;
}
