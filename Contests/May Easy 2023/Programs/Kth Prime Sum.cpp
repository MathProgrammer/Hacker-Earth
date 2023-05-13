#include <iostream>
#include <vector> 
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_D = 20, MAX_N = 200;
vector <int> primes; 
long long no_of_ways[MAX_D][MAX_N];

string convert_to_string(long long n)
{
	string N; 
	while(n > 0)
	{
		N += (char)('0' + n%10);
		n /= 10;
	}

	reverse(N.begin(), N.end());
	return N;
}

void sieve()
{
	vector <int> is_prime(MAX_N, true);
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

void precompute_no_of_ways()
{
	memset(no_of_ways, 0, sizeof(no_of_ways));
	no_of_ways[0][0] = 1;

	for(int digits = 1; digits < MAX_D; digits++)
	{
		for(int sum = 0; sum < MAX_N; sum++)
		{
			for(int last_digit = 0; last_digit <= 9; last_digit++)
			{
				if(last_digit <= sum)
				{
					no_of_ways[digits][sum] += no_of_ways[digits - 1][sum - last_digit];
				}
			}
		}
	}
}

long long get_count_with_leading_zero(string S)
{
	long long answer = 0;
	for(int digits = 1; digits < S.size(); digits++)
	{
		for(int prime_sum : primes)
		{
			for(int first_digit = 1; first_digit <= 9; first_digit++)
			{
				if(first_digit <= prime_sum)
				{
					answer += no_of_ways[digits - 1][prime_sum - first_digit];
				}
			}
		}
	}
	
	return answer;
}

long long get_count_without_leading_zero(string S)
{
	long long answer = 0;
	int prefix_sum = 0;
	for(int i = 0; i < S.size(); i++)
	{
		for(int current_digit = 0; current_digit + '0' < S[i]; current_digit++)
		{
			if(i == 0 && current_digit == 0)
			{
				continue;
			}
			int prefix_sum_now = prefix_sum + current_digit;
			
			int suffix_length = (S.size() - 1 - i);

			for(int prime_sum : primes)
			{
				if(prime_sum < prefix_sum_now)
				{
					continue;
				}

				int suffix_sum = prime_sum - prefix_sum_now; 

				answer += no_of_ways[suffix_length][suffix_sum];
			}
		}
		
		prefix_sum += (S[i] - '0');
	}
	return answer;
}

long long get_count(long long n)
{
	string N = convert_to_string(n); 

	return get_count_with_leading_zero(N) + get_count_without_leading_zero(N);
}

long long binary_search_answer(long long left, long long right, long long k)
{
	//[1, L - 1] < k <= [1, R - 1]
	while(right - left > 1)
	{
		long long mid = (left + right)/2;
	
		//Measures [1, M - 1]
		if(get_count(mid) < k)
		{
			left = mid;
		}
		else 
		{
			right = mid;
		}
	}

	long long first_integer_having_k_smaller_good_numbers = right; 
	long long kth_good_number = right - 1;

	return kth_good_number;
}

void solve()
{
	long long left, right, k; 
	cin >> left >> right >> k; 

	if(get_count(right + 1) - get_count(left) < k)
	{
		cout << "-1\n";
		return;
	}

	k += get_count(left);

	long long answer = binary_search_answer(left, right + 1, k);
	cout << answer << "\n";
}

int main() 
{
	sieve();
	precompute_no_of_ways();

	int no_of_queries; 
	cin >> no_of_queries; 

	while(no_of_queries--)
		solve();

	return 0;
}
