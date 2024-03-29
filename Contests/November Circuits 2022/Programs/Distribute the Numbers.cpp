#include <iostream>
using namespace std;

int possible(long long n, long long n1, long long n2, long long x, long long y)
{
	long long x_multiples = n/x, y_multiples = n/y;
	long long xy_multiples = n/(x*y);

	long long non_multiples = n - x_multiples - y_multiples + xy_multiples;

	long long n1_stack = y_multiples - xy_multiples; 
	long long n2_stack = x_multiples - xy_multiples; 

	non_multiples -= max(0LL, n1 - n1_stack);
	n1_stack = max(n1, n1_stack);

	non_multiples -= max(0LL, n2 - n2_stack);
	n2_stack = max(n2, n2_stack);

	return (non_multiples >= 0);
}

void solve()
{
	long long n1, n2, x, y;
	cin >> n1 >> n2 >> x >> y;

	long long left = 0, right = 1e15; 
	while(right - left > 1)
	{
		long long mid = (left + right)/2;

		if(possible(mid, n1, n2, x, y))
		{
			right = mid;
		}
		else 
		{
			left = mid;
		}
	}

	cout << right << "\n";
}
int main() 
{
	int no_of_test_cases; 
	cin >> no_of_test_cases; 

	while(no_of_test_cases--)
		solve();

	return 0;
}
