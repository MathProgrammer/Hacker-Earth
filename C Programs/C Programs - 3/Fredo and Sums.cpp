#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

void solve()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> element(no_of_elements);
    for(int i = 0; i < no_of_elements; i++)
        scanf("%d", &element[i]);

    sort(all(element));

    long long minimum_s = 0, maximum_s = 0;
    for(int i = 0; i < no_of_elements; i+= 2)
        minimum_s += element[i + 1] - element[i];

    for(int front_i = 0, back_i = no_of_elements - 1; front_i < back_i; front_i++, back_i--)
        maximum_s += element[back_i] - element[front_i];

    printf("%lld %lld\n", minimum_s, maximum_s);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}

