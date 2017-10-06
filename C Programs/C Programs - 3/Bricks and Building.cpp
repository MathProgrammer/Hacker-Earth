#include <cstdio>
#include <vector>
using namespace std;

void get_multiples(int n, vector <int> &no_of_multiples)
{
    for(int i = 1; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            if(i*i == n)
                no_of_multiples[i]++;
            else
            {
                no_of_multiples[i]++;
                no_of_multiples[n/i]++;
            }
        }
    }
}

int main()
{
    const int LIMIT = 1e5;
    vector <int> no_of_multiples(LIMIT + 1, 0);

    int no_of_elements;
    scanf("%d", &no_of_elements);

    for(int i = 1; i <= no_of_elements; i++)
    {
        int element_i;
        scanf("%d", &element_i);

        get_multiples(element_i, no_of_multiples);
    }

    int no_of_queries;
    scanf("%d", &no_of_queries);

    while(no_of_queries--)
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", no_of_multiples[n]);
    }

    return 0;
}

