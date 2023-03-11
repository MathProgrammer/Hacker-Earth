#include <iostream>
#include <vector> 
using namespace std;

int is_bit_set(int n, int bit)
{
	return ( (n & (1 << bit)) != 0 );
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

	long long total_segments = 0;
	vector <int> last_unequal(no_of_elements + 1);
	for(int i = 1; i <= no_of_elements; i++)
	{
		last_unequal[i] = (A[i] != A[i - 1] ? i - 1 : last_unequal[i - 1]);

		total_segments += (i - last_unequal[i]);
	}
	
	total_segments -= no_of_elements;
	cout << total_segments << "\n";
}

int main() 
{
	int no_of_test_cases; 
	cin >> no_of_test_cases; 

	while(no_of_test_cases--)
		solve();

	return 0;
}
