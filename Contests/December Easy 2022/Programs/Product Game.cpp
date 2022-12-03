#include<bits/stdc++.h>
using namespace std;

long long power_mod(long long x, long long p, long long m)
{
	long long answer = 1;

	while(p > 0)
	{
		if(p%2 == 1)
			answer = (answer*x)%m;

		x = (x*x)%m;
		p = p >> 1;
	}

	return answer;
}

long long inverse(long long x, long long m)
{
	return power_mod(x, m - 2, m);
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

	const int MOD = 1e9 + 7;
	vector <long long> product_till(no_of_elements + 1, 1);
	for(int i = 1; i <= no_of_elements; i++)
	{
		product_till[i] = A[i]*product_till[i - 1];
		product_till[i] %= MOD;
	}

    int no_of_queries; 
	cin >> no_of_queries; 

	long long maximum = 0, minimum = MOD;
	for(int i = 1; i <= no_of_queries; i++)
	{
		int left, right; 
		cin >> left >> right; 

		long long product = product_till[right]*inverse(product_till[left - 1], MOD);
		product %= MOD;

		maximum = max(product, maximum);
		minimum = min(product, minimum);
	}

	long long answer = maximum - minimum + MOD;
	answer %= MOD;

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
