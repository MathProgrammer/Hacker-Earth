#include <iostream>
using namespace std;

void solve()
{
	long long x, y, z; 
	cin >> x >> y >> z; 

	long long need = y - x; 
	long long max_addition = (z*1LL*(z + 1))/2;

	cout << (max_addition >= need ? "YES" : "NO") << "\n";
}

int main() 
{
	int no_of_test_cases; 
	cin >> no_of_test_cases; 

	while(no_of_test_cases--)
		solve();

	return 0;
}
