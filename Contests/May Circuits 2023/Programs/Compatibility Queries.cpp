#include <iostream>
#include <vector>

using namespace std;

int is_bit_set(int n, int bit)
{
	return ( (n&(1 << bit)) != 0 );
}

int main()
{
	int no_of_elements;
	cin >> no_of_elements;

	const int NO_OF_BITS = 20;
	const int MAX_MASK = (1 << NO_OF_BITS);
	vector <long long> mask_sum(MAX_MASK, 0);
	vector <int> A(no_of_elements + 1);
	for(int i = 1; i <= no_of_elements; i++)
	{
		cin >> A[i];
		mask_sum[A[i]] += A[i];
	}

	for(int bit = 0; bit < NO_OF_BITS; bit++)
	{
		for(int m = 0; m < MAX_MASK; m++)
		{
			if(!is_bit_set(m, bit))
			{
				int future_mask = m|(1 << bit);
				mask_sum[future_mask] += mask_sum[m];
			}
		}
	}

	int no_of_queries;
	cin >> no_of_queries;

	for(int i = 1; i <= no_of_queries; i++)
	{
		int x;
		cin >> x;

		int complement = MAX_MASK - 1 - x;
		cout << mask_sum[complement] << "\n";
	}

	return 0;
}
