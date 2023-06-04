#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1e5 + 5;
vector <int> is_prime(MAX_N, true);
vector <int> primes;

void sieve()
{
	is_prime[0] = is_prime[1] = false;
	for(int i = 2; i < MAX_N; i++)
	{
		if(is_prime[i])
		{
			primes.push_back(i);
		}

		for(int j = 0; j < primes.size() && i*primes[j] < MAX_N; j++)
		{
			is_prime[i*primes[j]] = false;

			if(i%primes[j] == 0)
			{
				break;
			}
		}
	}
}

long long choose_2(long long n)
{
	return (n*(n - 1))/2;
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

	vector <int> prefix_ones(no_of_elements + 1);
	for(int i = 1; i <= no_of_elements; i++)
	{
		prefix_ones[i] = prefix_ones[i - 1] + (A[i] == 1);
	}

	vector <int> suffix_ones(no_of_elements + 2);
	for(int i = no_of_elements; i >= 1; i--)
	{
		suffix_ones[i] = suffix_ones[i + 1] + (A[i] == 1);
	}

	long long answer = 0;
	for(int i = 1; i <= no_of_elements; i++)
	{
		if(is_prime[A[i]])
		{
			long long starting_here = choose_2(suffix_ones[i]);
			long long middle_here = prefix_ones[i]*suffix_ones[i];
			long long ending_here = choose_2(prefix_ones[i]);

			answer += starting_here + middle_here + ending_here;
		}
	}

	cout << answer << "\n";
}

int main()
{
	sieve();

	int no_of_test_cases;
	cin >> no_of_test_cases;

	while(no_of_test_cases--)
		solve();

	return 0;
}
