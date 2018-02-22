#include <cstdio>

#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)

const int MAX_N = 1e7 + 7;

int A[MAX_N];
int no_of_odd_numbers[3*MAX_N];

void build(int n, int left, int right)
{
    if(left == right)
    {
        no_of_odd_numbers[n] = (A[left]%2 == 1);
        return;
    }

    int mid = (left + right) >> 1;
    build(LEFT(n), left, mid);
    build(RIGHT(n), mid + 1, right);

    no_of_odd_numbers[n] = no_of_odd_numbers[LEFT(n)] + no_of_odd_numbers[RIGHT(n)];
}

void update(int n, int left, int right, int index)
{
    if(right < index || index < left)
        return;

    if(left == right)
    {
        A[left] = (A[left]+1)%2;
        no_of_odd_numbers[n] = (A[left]%2 == 1);
        return;
    }

    int mid = (left + right) >> 1;
    update(LEFT(n), left, mid, index);
    update(RIGHT(n), mid + 1, right, index);

    no_of_odd_numbers[n] = no_of_odd_numbers[LEFT(n)] + no_of_odd_numbers[RIGHT(n)];
}

int get(int n, int left, int right, int k)
{
    if(k == 0)
        return (A[1]%2 == 1 ? -1 : 1);

    if(no_of_odd_numbers[n] < k)
        return -1;

    if(left == right)
        return left;

    int mid = (left + right) >> 1;
    if(no_of_odd_numbers[LEFT(n)] >= k)
    {
        int answer = get(LEFT(n), left, mid, k);
        return answer;
    }
    else
    {
        int answer = get(RIGHT(n), mid + 1, right, k - no_of_odd_numbers[LEFT(n)]);
        return answer;
    }
}

int main()
{
    int no_of_elements, no_of_queries;
    scanf("%d %d", &no_of_elements, &no_of_queries);

    for(int i = 1; i <= no_of_elements; i++) scanf("%d", &A[i]);

    for(int i = 1; i <= no_of_elements; i++) A[i] %= 2;

    build(1, 1, no_of_elements);

    while(no_of_queries--)
    {
        const int UPDATE = 1, GET = 2;
        int query_type;

        scanf("%d", &query_type);

        if(query_type == UPDATE)
        {
            int index;
            scanf("%d", &index);

            update(1, 1, no_of_elements, index);
        }
        if(query_type == GET)
        {
            int k;
            scanf("%d", &k);

            int answer = get(1, 1, no_of_elements, k);
            printf("%d\n", answer);
        }
    }
}
