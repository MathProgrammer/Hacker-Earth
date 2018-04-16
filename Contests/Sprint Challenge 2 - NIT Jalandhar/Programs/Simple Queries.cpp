#include <iostream>
#include <cstdio>

#define LEFT(n) ((n << 1))
#define RIGHT(n) ((n << 1) | 1)

using namespace std;

const int MAX_NODES = 5e5 + 5, NOT_POSSIBLE = -1;

int all_ones[3*MAX_NODES];

char input[MAX_NODES];

void build(int n, int left, int right)
{
    if(left == right)
    {
        all_ones[n] = (input[left] == '1');
        return ;
    }

    int mid = (left + right) >> 1;
    build(LEFT(n), left, mid);
    build(RIGHT(n), mid + 1, right);

    all_ones[n] = all_ones[LEFT(n)]&all_ones[RIGHT(n)];
}

void flip(int n, int left, int right, int index)
{
    if(right < index || left > index)
        return;

    if(left == right)
    {
        all_ones[n] = !(all_ones[n]);
        return;
    }

    int mid = (left + right) >> 1;

    flip(LEFT(n), left, mid, index);
    flip(RIGHT(n), mid + 1, right, index);

    all_ones[n] = all_ones[LEFT(n)]&all_ones[RIGHT(n)];
}

int get(int n, int left, int right, int query_left, int query_right)
{
    if(query_left > right || query_right < left || all_ones[n])
        return NOT_POSSIBLE;

    if(left == right) //Leaf and not all 1's so it has to be 0.
        return left;

    int mid = (left + right) >> 1;

    int answer_in_left_subtree = get(LEFT(n), left, mid, query_left, query_right);

    if(answer_in_left_subtree != NOT_POSSIBLE)
        return answer_in_left_subtree;

    int answer_in_right_subtree = get(RIGHT(n), mid + 1, right, query_left, query_right);

    return answer_in_right_subtree;
}

int main()
{
    int length, no_of_queries;
    scanf("%d %s %d", &length, (input + 1), &no_of_queries);

    build(1, 1, length);

    while(no_of_queries--)
    {
        const int FLIP = 1, GET = 2;
        int query_type;
        cin >> query_type;

        if(query_type == FLIP)
        {
            int index;
            cin >> index;

            flip(1, 1, length, index);
        }
        else if(query_type == GET)
        {
            int left, right;
            cin >> left >> right;

            int answer = get(1, 1, length, left, right);
            cout << answer << "\n";
        }
    }

    return 0;
}

