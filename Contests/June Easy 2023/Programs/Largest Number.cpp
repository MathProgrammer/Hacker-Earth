#include <iostream>
using namespace std;

int is_bit_set(int n, int bit)
{
	return ( (n&(1 << bit)) != 0 );
}

int main()
{
	string N;
	int no_of_deletions;
	cin >> N >> no_of_deletions;

	long long answer = 0;
	const int MAX_MASK = (1 << N.size());
	for(int m = 0; m < MAX_MASK; m++)
	{
		if(__builtin_popcount(m) != N.size() - no_of_deletions)
		{
			continue;
		}

		long long n_here = 0;
		for(int bit = 0; bit < N.size(); bit++)
		{
			if(is_bit_set(m, bit))
			{
				n_here = (n_here*10) + (N[bit] - '0');
			}
		}

		answer = max(answer, n_here);
	}

	cout << answer << "\n";
	return 0;
}
