#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> element(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &element[i]);

    vector <long long> max_sum_till(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(i == 1)
            max_sum_till[i] = element[i];
        else if(i == 2)
            max_sum_till[i] = element[i]*1LL*element[i - 1];
        else
            max_sum_till[i] = max(element[i] + max_sum_till[i - 1], element[i]*1LL*element[i - 1] + max_sum_till[i - 2]);
    }

    printf("%lld\n", max_sum_till[no_of_elements]);
    return 0;
}
