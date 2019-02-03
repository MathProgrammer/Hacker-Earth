#include <iostream>
#include <string>
#include <cstring>

#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)

using namespace std;

const int MAX_N = 2e5 + 5, oo = 1e9;
string S;
int length, sum[MAX_N], min_tree[3*MAX_N], lazy[3*MAX_N];

void build(int n, int left, int right)
{
    if(left == right)
    {
        min_tree[n] = sum[right];
        return;
    }

    int mid = (left + right)/2;

    build(LEFT(n), left, mid);
    build(RIGHT(n), mid + 1, right);
    min_tree[n] = min(min_tree[LEFT(n)], min_tree[RIGHT(n)]);
}

void propagate(int n, int left, int right)
{
    if(left == right)
    {
        sum[right] += lazy[n];
    }

    if(left != right)
    {
        lazy[LEFT(n)] += lazy[n];
        lazy[RIGHT(n)] += lazy[n];
    }

    min_tree[n] += lazy[n];
    lazy[n] = 0;
}

int minimum(int n, int left, int right, int query_left, int query_right)
{
    if(lazy[n])
        propagate(n, left, right);

    if(right < query_left || query_right < left)
        return oo;

    if(query_left <= left && right <= query_right)
        return min_tree[n];

    int mid = (left + right)/2;
    int left_min = minimum(LEFT(n), left, mid, query_left, query_right);
    int right_min = minimum(RIGHT(n), mid + 1, right, query_left, query_right);

    return min(left_min, right_min);
}

void update(int n, int left, int right, int query_left, int query_right, int value)
{
    if(lazy[n])
        propagate(n, left, right);

    if(right < query_left || query_right < left)
        return;

    if(query_left <= left && right <= query_right)
    {
        lazy[n] += value;

        propagate(n, left, right);

        return;
    }

    int mid = (left + right)/2;

    update(LEFT(n), left, mid, query_left, query_right, value);
    update(RIGHT(n), mid + 1, right, query_left, query_right, value);

    min_tree[n] = min(min_tree[LEFT(n)], min_tree[RIGHT(n)]);
}

int find_first_lesser(int left, int right, int key)
{
    while(left < right)
    {
        int mid = (left + right)/2;

        if(minimum(1, 1, length, left, mid) >= key)
        {
            left = mid + 1;
        }
        else if(minimum(1, 1, length, left, mid) < key)
        {
            right = mid;
        }
    }

    return right;
}

int find_last_equal(int left, int right, int key)
{
    while(left < right)
    {
        int mid = (left + right + 1)/2;

        if(minimum(1, 1, length, mid, right) == key)
        {
            left = mid;
        }
        else if(minimum(1, 1, length, mid, right) > key)
        {
            right = mid - 1;
        }
    }

    return left;
}

void solve()
{
    const char CHANGE = 'C', QUERY_LENGTH = 'Q';
    char query;
    int position;
    cin >> query >> position;

    if(query == CHANGE)
    {
        int change_value;

        if(S[position - 1] == ')')
        {
            S[position - 1] = '(';
            change_value = 2;
        }
        else if(S[position - 1] == '(')
        {
            S[position - 1] = ')';
            change_value = -2;
        }

        update(1, 1, length, position, length, change_value);


    }
    else if(query == QUERY_LENGTH)
    {
        int sequence_length;

        // sum[position - 1] updated value. If we directly call sum[position - 1], we might be using an old value that has not propagated.
        int previous = (position - 1 == 0 ? 0 : minimum(1, 1, length, position - 1, position - 1));

        if(minimum(1, 1, length, position, length) < previous)
        {
            int ending = find_first_lesser(position, length, previous) - 1;

            sequence_length = ending - (position - 1);
        }
        else if(minimum(1, 1, length, position, length) == previous)
        {
            int ending = find_last_equal(position, length, previous);

            sequence_length = ending - (position - 1);
        }
        else
        {
            sequence_length = 0;
        }

        cout << sequence_length << "\n";
    }
}

int main()
{
    cin >> S;

    length = S.size();
    sum[0] = 0;
    for(int i = 0; i < length; i++)
        sum[i + 1] = sum[i] + (S[i] == '(' ? 1 : -1);

    build(1, 1, length);

    memset(lazy, 0, sizeof(lazy));

    int no_of_queries;
    cin >> no_of_queries;

    while(no_of_queries--)
        solve();

    return 0;
}
