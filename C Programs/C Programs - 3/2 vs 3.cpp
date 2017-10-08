#include <cstdio>

using namespace std;

const int MAX_SIZE = 1e5;

int tree[4*MAX_SIZE];
int string[MAX_SIZE + 5];
int power_of_2[MAX_SIZE];

void precompute()
{
    power_of_2[0] = 1;

    for(int i = 1; i < MAX_SIZE; i++)
        power_of_2[i] = (power_of_2[i - 1]*2)%3;
}

void build(int node, int start, int end)
{
    if(start == end)
    {
        tree[node] = string[start];
        return;
    }

    int mid = (start + end)/2;

    build(2*node, start, mid);
    build(2*node + 1, mid + 1, end);

    int no_of_right_bits = (end - mid);
    int no_of_shifted_positions = power_of_2[no_of_right_bits];

    tree[node] = (no_of_shifted_positions*tree[2*node] + tree[2*node + 1])%3;
}

void update_and_flip(int node, int start, int end, int index)
{
    if(start == end)
    {
        tree[node] = string[index] = 1;
        return;
    }

    int mid = (start + end)/2;

    if(index >= start && index <= mid)
    {
        update_and_flip(2*node, start, mid, index);
    }

    if(index > mid && index <= end)
    {
        update_and_flip(2*node + 1, mid + 1, end, index);
    }

    int no_of_right_bits = (end - mid);
    int no_of_shifted_positions = power_of_2[no_of_right_bits];

    tree[node] = (no_of_shifted_positions*tree[2*node] + tree[2*node + 1])%3;
}

int query(int node, int start, int end, int query_start, int query_end)
{
    if(query_start > end || query_end < start)
        return 0;

    if(query_start <= start && query_end >= end)
    {
        int right_bits = query_end - end;

        return (tree[node]*power_of_2[right_bits])%3;
    }

    int mid = (start + end)/2;

    int left_answer  = query(2*node, start, mid, query_start, query_end);
    int right_answer = query(2*node + 1, mid + 1, end, query_start, query_end);

    return (left_answer + right_answer)%3;
}

int main()
{
    precompute();

    int length;
    scanf("%d", &length);

    for(int i = 1; i <= length; i++)
        scanf("%1d", &string[i]);

    build(1, 1, length);

    int no_of_queries;
    scanf("%d", &no_of_queries);

    while(no_of_queries--)
    {
        int type;
        scanf("%d", &type);

        if(type == 0)
        {
            int left, right;
            scanf("%d %d", &left, &right);

            left++, right++;

            int answer = query(1, 1, length, left, right);

            printf("%d\n", answer);
        }
        else if(type == 1)
        {
            int index;
            scanf("%d", &index);

            index++;
            update_and_flip(1, 1, length, index);
        }
    }

    return 0;
}

