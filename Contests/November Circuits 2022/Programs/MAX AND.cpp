#include <iostream>
#include <vector>
using namespace std;
 
int is_bit_set(int n, int bit)
{
	return ( (n&(1<< bit)) != 0 );
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
 
	vector <int> B(no_of_elements + 1);
	for(int i = 1; i <= no_of_elements; i++)
	{
		cin >> B[i];
	}
 
	const int NO_OF_BITS = 30;
	vector <int> is_set(NO_OF_BITS, true);
	for(int i = 1; i <= no_of_elements; i++)
	{
		for(int bit = 0; bit < NO_OF_BITS; bit++)
		{
			is_set[bit] &= (is_bit_set(A[i], bit));
			is_set[bit] &= (is_bit_set(B[i], bit));
		}
	}
 
	int answer = 0;
	for(int bit = 0; bit < NO_OF_BITS; bit++)
	{
		if(is_set[bit])
		{
			answer |= (1 << bit);
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
