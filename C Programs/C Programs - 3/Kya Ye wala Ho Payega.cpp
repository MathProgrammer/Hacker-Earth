#include <cstdio>
#include <vector>
using namespace std;

int power_of_2_that_divides(long long n)
{
    int power = 0;

    while(n%2 == 0)
    {
        n = n/2;
        power++;
    }
    return power;
}

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> sum_of_power_of_2_till(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        long long element_i;
        scanf("%lld", &element_i);

        sum_of_power_of_2_till[i] = sum_of_power_of_2_till[i - 1] + power_of_2_that_divides(element_i);
    }

    int no_of_queries;
    scanf("%d", &no_of_queries);

    while(no_of_queries--)
    {
        int left, right;
        scanf("%d %d", &left, &right);

        printf("%d\n", sum_of_power_of_2_till[right] - sum_of_power_of_2_till[left - 1]);
    }
    return 0;
}

