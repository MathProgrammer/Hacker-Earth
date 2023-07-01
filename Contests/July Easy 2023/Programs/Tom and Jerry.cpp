#include <iostream>
#include <vector>
using namespace std;

struct node 
{
	long long sum, largest_prefix_sum, largest_suffix_sum, answer; 
	int lazy;

	node()
	{
		lazy = 0;
		sum = largest_prefix_sum = largest_suffix_sum = answer = 0;
	}

	node(long long n)
	{
		lazy = 0; 
		sum = largest_prefix_sum = largest_suffix_sum = answer = n;
	}
};

#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)

const int MAX_N = 2e5 + 5; 
const long long oo = 1e15;
vector <node> tree(3*MAX_N);

node merge(node &L, node &R)
{
	node segment; 

	segment.sum = L.sum + R.sum;

	segment.largest_prefix_sum = max(L.largest_prefix_sum, L.sum + R.largest_prefix_sum);
	segment.largest_suffix_sum = max(R.largest_suffix_sum, R.sum + L.largest_suffix_sum);
	segment.answer = max(L.answer, R.answer);

	segment.answer = max(segment.answer, L.largest_suffix_sum + R.largest_prefix_sum);

	return segment;
}

void set_lazy(node &N, int left, int right, long long value)
{
	N.lazy = value;

	int segment_size = right - left + 1;
	N.sum = segment_size*value; 

	N.largest_prefix_sum = (value > 0 ? segment_size*value : value);
	N.largest_suffix_sum = (value > 0 ? segment_size*value : value);
	N.answer = (value > 0 ? segment_size*value : value);
}

void propagate(int n, int left, int right)
{
	//cout << "Propagating Lazy from " << n << "\n";
	if(left != right)
	{
		int mid = (left + right)/2;
		set_lazy(tree[LEFT(n)], left, mid, tree[n].lazy);
		set_lazy(tree[RIGHT(n)], mid + 1, right, tree[n].lazy);
	}

	tree[n].lazy = 0;
}

void build(vector <int> &A, int n, int left, int right)
{
	if(left == right)
	{
		tree[n] = node(A[left]);
		return;
	}

	int mid = (left + right)/2;
	build(A, LEFT(n), left, mid);
	build(A, RIGHT(n), mid + 1, right);

	tree[n] = merge(tree[LEFT(n)], tree[RIGHT(n)]);
}

void update(int n, int left, int right, int query_left, int query_right, long long value)
{
	if(right < query_left || query_right < left)
	{
		return;
	}

	if(tree[n].lazy != 0)
	{
		propagate(n, left, right);
	}

	if(query_left <= left && right <= query_right)
	{
		set_lazy(tree[n], left, right, value);
		return;
	}

	int mid = (left + right)/2; 
	update(LEFT(n), left, mid, query_left, query_right, value);
	update(RIGHT(n), mid + 1, right, query_left, query_right, value);

	tree[n] = merge(tree[LEFT(n)], tree[RIGHT(n)]);
}

node get_max(int n, int left, int right, int query_left, int query_right)
{
	if(tree[n].lazy != 0)
	{
		propagate(n, left, right);
	}

	if(query_right < left || right < query_left)
	{
		return node(-oo);
	}

	if(query_left <= left && right <= query_right)
	{
		return tree[n];
	}

	int mid = (left + right)/2;
	node left_answer = get_max(LEFT(n), left, mid, query_left, query_right);
	node right_answer = get_max(RIGHT(n), mid + 1, right, query_left, query_right);
	node answer = merge(left_answer, right_answer);

	return answer;
}

void solve()
{
	int no_of_elements; 
	cin >> no_of_elements; 

	vector <int> A(no_of_elements + 1);
	for(int i = 1; i <= no_of_elements; i++)
	{
		cin >> A[i];
	}

	build(A, 1, 1, no_of_elements);

	int no_of_queries;
	cin >> no_of_queries; 

	for(int i = 1; i <= no_of_queries; i++)
	{
		const int RANGE_UPDATE = 1, GET_MAX = 2; 
		int query; 
		cin >> query; 

		switch(query)
		{
			case RANGE_UPDATE : 
			{
				int left, right; 
				long long X; 
				cin >> left >> right >> X;

				update(1, 1, no_of_elements, left, right, X);
				break;
			}

			case GET_MAX : 
			{
				int left, right; 
				cin >> left >> right; 

				cout << get_max(1, 1, no_of_elements, left, right).answer << "\n";
				break;
			}
		}
	}
}

int main() 
{
	int no_of_test_cases; 
	cin >> no_of_test_cases; 

	while(no_of_test_cases--)
		solve();

	return 0;
}
