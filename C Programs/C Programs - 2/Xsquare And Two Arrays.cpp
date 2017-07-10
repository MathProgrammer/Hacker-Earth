#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_queries, no_of_elements;
    scanf("%d %d", &no_of_elements, & no_of_queries);

    vector <int> a(no_of_elements + 1), b(no_of_elements);
    vector <long long> query_1(no_of_elements + 1, 0), query_2(no_of_elements + 1, 0);

    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &a[i]);

    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &b[i]);

    for(int i = 1; i <= no_of_elements; i++)
    {
        //Query 1 has all Odd index A and even index B, and query 2 has the others.
        if(i%2 == 1)
        {
            query_1[i] = query_1[i - 1] + a[i];
            query_2[i] = query_2[i - 1] + b[i];
        }
        else
        {
            query_2[i] = query_2[i - 1] + a[i];
            query_1[i] = query_1[i - 1] + b[i];
        }
    }

    while(no_of_queries--)
    {
        int query_type, left, right;
        scanf("%d %d %d", &query_type, &left, &right);

        long long answer;
        //Query 1 has all odd index A, and even index B ... Query 2 has even index A and odd index B
        if( (query_type == 1 && left%2 == 1) || (query_type == 2 && left%2 == 0) )
        {
            answer = query_1[right] - query_1[left - 1];
        }
        else
        {
            answer = query_2[right] - query_2[left - 1];
        }

        printf("%lld\n", answer);
    }

    return 0;
}

