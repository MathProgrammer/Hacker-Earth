#include <iostream>
#include <algorithm>
#include <vector>

#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)

#define min(a, b) (a < b ? a : b)
#define max_3(a, b, c) max(a, max(b, c))
#define min_3(a, b, c) min(a, min(b, c))

#define all(v) (v).begin(), (v).end()

using namespace std;

int is_bit_set(int n, int position)
{
    return ( (n & (1LL << position)) != 0);
}

struct node
{
    int sum;
    int max_sum, max_left_sum, max_right_sum;
    int min_sum, min_left_sum, min_right_sum;

    node(){}

    node(int value)
    {
        sum = value;
        max_sum = max_left_sum = max_right_sum = value;
        min_sum = min_left_sum = min_right_sum = value;
    }

    void flip()
    {
        sum *= -1;
        swap(max_sum, min_sum);
        swap(max_left_sum, min_left_sum);
        swap(max_right_sum, min_right_sum);

        max_sum *= -1; min_sum *= -1;
        max_left_sum *= -1; min_left_sum *= -1;
        max_right_sum *= -1; min_right_sum *= -1;
    }
};

const int MAX_N = 1e5 + 5, MAX_BIT = 20;
node tree[4*MAX_N];
int bit[MAX_N], lazy[4*MAX_N], A[MAX_N];

node merge(node &A, node &B)
{
    node C;

    C.sum = A.sum + B.sum;

    C.max_left_sum = max(A.sum + B.max_left_sum, A.max_left_sum);
    C.max_right_sum = max(B.sum + A.max_right_sum, B.max_right_sum);

    C.min_left_sum = min(A.sum + B.min_left_sum, A.min_left_sum);
    C.min_right_sum = min(B.sum + A.min_right_sum, B.min_right_sum);

    C.max_sum = max_3(A.max_sum, B.max_sum, A.max_right_sum + B.max_left_sum);
    C.min_sum = min_3(A.min_sum, B.min_sum, A.min_right_sum + B.min_left_sum);

    return C;
}

void display(int n, int left, int right)
{
    cout << "N = " << n << " [" << left << "," << right << "]" << endl;
    cout << "S = " << tree[n].sum << " Mx = " << tree[n].max_sum << " MxL = " << tree[n].max_left_sum << " MxR = "
    << tree[n].max_right_sum << " Mn = "  << tree[n].min_sum << " MnL = " << tree[n].min_left_sum
    << " , MnR = " << tree[n].min_right_sum << endl;


    if(left == right)
        return;

    int mid = (left + right)/2;
    display(LEFT(n), left, mid);
    display(RIGHT(n), mid + 1, right);
}

void build(int n, int left, int right)
{
    lazy[n] = false;

    if(left == right)
    {
        tree[n] = node(bit[left]);
        return;
    }

    int mid = (left + right)/2;
    build(LEFT(n), left, mid);
    build(RIGHT(n), mid + 1, right);

    tree[n] = merge(tree[LEFT(n)], tree[RIGHT(n)]);
}

void propagate(int n, int left, int right)
{
    tree[n].flip();

    if(left != right)
    {
        lazy[LEFT(n)] ^= 1;

        lazy[RIGHT(n)] ^= 1;
    }

    lazy[n] = false;
}

void update(int n, int left, int right, int query_left, int query_right)
{
    if(query_right < left || right < query_left)
        return;

    if(lazy[n])
        propagate(n, left, right);

    if(query_left <= left && right <= query_right)
    {
        tree[n].flip();

        if(left != right)
        {
            lazy[LEFT(n)] ^= 1;
            lazy[RIGHT(n)] ^= 1;
        }

        return;
    }

    int mid = (left + right)/2;

    update(LEFT(n), left, mid, query_left, query_right);
    update(RIGHT(n), mid + 1, right, query_left, query_right);
    tree[n] = merge(tree[LEFT(n)], tree[RIGHT(n)]);
}

int get_left(int n, int left, int right, int sum)
{
    if(lazy[n])
        propagate(n, left, right);

    if(tree[n].sum == sum)
        return left;

    int mid = (left + right)/2;

    if(tree[RIGHT(n)].max_right_sum == sum)
        return get_left(RIGHT(n), mid + 1, right, sum);
    else
        return get_left(LEFT(n), left, mid, sum - tree[RIGHT(n)].sum);

}

int get_right(int n, int left, int right, int sum)
{
    if(lazy[n])
        propagate(n, left, right);

    if(tree[n].sum == sum)
        return right;

    int mid = (left + right)/2;

    if(tree[LEFT(n)].max_left_sum == sum)
        return get_right(LEFT(n), left, mid, sum);
    else
        return get_right(RIGHT(n), mid + 1, right, sum - tree[LEFT(n)].sum);
}

pair <int, int> get_range(int n, int left, int right, int sum)
{
    if(lazy[n])
        propagate(n, left, right);

    if(tree[n].sum == sum)
        return make_pair(left, right);

    int mid = (left + right)/2;

    if(tree[LEFT(n)].max_sum == sum)
        return get_range(LEFT(n), left, mid, sum);

    if(tree[RIGHT(n)]. max_sum == sum)
        return get_range(RIGHT(n), mid + 1, right, sum);

    int range_left = get_left(LEFT(n), left, mid, sum - tree[RIGHT(n)].max_left_sum);
    int range_right = get_right(RIGHT(n), mid + 1, right, sum - tree[LEFT(n)].max_right_sum);

    return make_pair(range_left, range_right);
}

int main()
{
    int no_of_elements, no_of_operations;
    cin >> no_of_elements >> no_of_operations;

    for(int i = 1; i <= no_of_elements; i++)
        cin >> A[i];

    long long sum = 0;
    for(int i = 1; i <= no_of_elements; i++)
        sum += A[i];

    vector <int> operations;
    for(int b = MAX_BIT; b >= 0; b--)
    {
        for(int i = 1; i <= no_of_elements; i++)
        {
            bit[i] = (is_bit_set(A[i], b) ? 1 : -1);
        }

        build(1, 1, no_of_elements);

        while(tree[1].max_sum > 0)
        {
            long long weight = (1LL << b);

            long long operation_effect = tree[1].max_sum*weight;
            operations.push_back(operation_effect);

            pair <int, int> range = get_range(1, 1, no_of_elements, tree[1].max_sum);

            update(1, 1, no_of_elements, range.first, range.second);
        }
    }

    sort(all(operations));
    reverse(all(operations));

    for(int i = 0; i < min(no_of_operations, operations.size()); i++)
    {
        sum -= operations[i];
    }

    cout << sum;
    return 0;
}
