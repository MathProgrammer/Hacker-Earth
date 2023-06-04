#include <iostream>
#include <vector>

using namespace std;

int is_bit_set(int n, int bit)
{
	return ( (n&(1 << bit)) != 0 );
}

int get_submask_subsequence(vector <int> &A, int m)
{
	int count = 0;
	for(int i = 1; i < A.size(); i++)
	{
		if((m&A[i]) == m)
		{
			count++;
		}
	}

	return count;
}

void solve()
{
	int no_of_elements, X;
	cin >> no_of_elements >> X;

	vector <int> A(no_of_elements + 1);
	for(int i = 1; i <= no_of_elements; i++)
	{
		cin >> A[i];
	}

	const int NO_OF_BITS = 30;
	int prefix_mask = 0, largest_subsequence = get_submask_subsequence(A, X);
	for(int bit = NO_OF_BITS; bit >= 0; bit--)
	{
		if(!is_bit_set(X, bit))
		{
			int larger_mask = (prefix_mask|(1 << bit));
			int subsequence_here = get_submask_subsequence(A, larger_mask);

			largest_subsequence = max(largest_subsequence, subsequence_here);
		}
		else
		{
			prefix_mask |= (1 << bit);
		}
	}

	int answer = (largest_subsequence == 0 ? -1 : largest_subsequence);
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
