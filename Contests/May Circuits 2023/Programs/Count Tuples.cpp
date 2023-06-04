#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)

int sort_descending_equals_left_to_right(pair <int, int> &P, pair <int, int> &Q)
{
	if(P.first == Q.first)
	{
		return (P.second < Q.second);
	}

	return (P.first > Q.first);
}

long long choose_3(long long n)
{
	return (n*(n - 1)*(n - 2))/6;
}

void update(vector <int> &T, int n, int left, int right, int position, int value)
{
	if(position < left || right < position)
	{
		return;
	}

	if(left == right)
	{
		T[n] = value;
		return;
	}

	int mid = (left + right)/2;

	update(T, LEFT(n), left, mid, position, value);
	update(T, RIGHT(n), mid + 1, right, position, value);

	T[n] = T[LEFT(n)] + T[RIGHT(n)];
}

int get_sum(vector <int> &T, int n, int left, int right, int query_left, int query_right)
{
	if(right < left || query_right < left || right < query_left || query_right < query_left)
	{
		return 0;
	}

	if(query_left <= left && right <= query_right)
	{
		return T[n];
	}

	int mid = (left + right)/2;
	int left_sum = get_sum(T, LEFT(n), left, mid, query_left, query_right);
	int right_sum = get_sum(T, RIGHT(n), mid + 1, right, query_left, query_right);

	int answer = left_sum + right_sum;

	return answer;
}

void find(vector <int> &prefix_inserted, vector <int> &suffix_not_inserted, vector <pair <int, int> > &A)
{
	int no_of_elements = A.size() - 1;
	vector <int> sum_tree(4*no_of_elements + 1);

	for(int i = 1; i <= no_of_elements; i++)
	{
		int position = A[i].second;

		prefix_inserted[i] = get_sum(sum_tree, 1, 1, no_of_elements, 1, position - 1);

		int suffix = no_of_elements - position;
		int suffix_inserted = get_sum(sum_tree, 1, 1, no_of_elements, position + 1, no_of_elements);
		suffix_not_inserted[i] = suffix - suffix_inserted;

		update(sum_tree, 1, 1, no_of_elements, position, 1);
	}
}

void solve()
{
	int no_of_elements;
	cin >> no_of_elements;

	map <int, int> frequency;
	vector <pair <int, int>> A(no_of_elements + 1);
	for(int i = 1; i <= no_of_elements; i++)
	{
		cin >> A[i].first;
		A[i].second = i;

		frequency[A[i].first]++;
	}
	sort(A.begin() + 1, A.end());

	vector <int> prefix_smaller(no_of_elements + 1), suffix_larger(no_of_elements + 1);
	find(prefix_smaller, suffix_larger, A);

	sort(A.begin() + 1, A.end(), sort_descending_equals_left_to_right);
	vector <int> suffix_smaller(no_of_elements + 1), prefix_larger(no_of_elements + 1);
	find(prefix_larger, suffix_smaller, A);

	long long answer = 0;
	for(int i = 1; i <= no_of_elements; i++)
	{
		answer += prefix_smaller[i]*suffix_larger[i];
		answer += prefix_larger[i]*suffix_smaller[i];
	}

	long long equal_triplets = 0;
	for(auto it = frequency.begin(); it != frequency.end(); it++)
	{
		equal_triplets += choose_3(it->second);
	}

	answer -= equal_triplets;

	cout << answer << "\n";
}

int main()
{
	int no_of_test_cases;
	cin >> no_of_test_cases;

	while(no_of_test_cases--)
		solve();

	return 0;
}
