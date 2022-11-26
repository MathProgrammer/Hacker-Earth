#include <iostream>
#include <vector>
using namespace std;

long long power(long long x, long long p, long long mod)
{
	long long answer = 1; 

	while(p > 0)
	{
		if(p%2 == 1)
			answer = (answer*x)%mod;

		x = (x*x)%mod;
		p = p/2;
	}

	return answer;
}

long long choose(long long n, long long r)
{
	long long numerator = 1, denominator = 1; 
	for(int i = 1; i <= r; i++)
	{
		numerator *= (n - i + 1);
		denominator *= i;
	}

	return numerator/denominator;
}

void solve()
{
	long long no_of_elements; 
	cin >> no_of_elements; 

	long long answer = 0;
	const int MOD = 1e9 + 7, NO_OF_ROWS = 4;
	for(int column_1 = 0; column_1 <= NO_OF_ROWS; column_1++)
	{
		for(int column_2 = 0; column_2 <= NO_OF_ROWS; column_2++)
		{
			for(int column_3 = 0; column_3 <= NO_OF_ROWS; column_3++)
			{
				for(int column_4 = 0; column_4 <= NO_OF_ROWS; column_4++)
				{
					long long answer_square = 1;

					vector <long long> no_of_ways(NO_OF_ROWS + 1);
					no_of_ways[1] = choose(NO_OF_ROWS, column_1);
					no_of_ways[2] = choose(NO_OF_ROWS, column_2);
					no_of_ways[3] = choose(NO_OF_ROWS, column_3);
					no_of_ways[4] = choose(NO_OF_ROWS, column_4);
					
					vector <long long> no_of_columns(NO_OF_ROWS + 1);
					no_of_columns[1] = no_of_elements/4 + (no_of_elements%4 >= 1);
					no_of_columns[2] = no_of_elements/4 + (no_of_elements%4 >= 2);
					no_of_columns[3] = no_of_elements/4 + (no_of_elements%4 >= 3);
					no_of_columns[4] = no_of_elements/4;
				
					for(int i = 1; i <= NO_OF_ROWS; i++)
					{
						answer_square *= power(no_of_ways[i], no_of_columns[i], MOD);
						answer_square %= MOD;
					}

					answer += answer_square;
					answer %= MOD;
				}
			}
		}
	}

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
