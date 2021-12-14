#include <iostream>

using namespace std;

void solve()
{
	int no_of_elements; 
	cin >> no_of_elements; 

	long long sum = 0;
	for(int i = 1; i <= no_of_elements; i++)
	{
		int x; 
		cin >> x; 
		sum += (x - 1);
	}

	cout << sum << "\n";
}

int main()
{
	int no_of_test_cases;
	cin >> no_of_test_cases;

	while(no_of_test_cases--)
		solve();

	return 0;
}
