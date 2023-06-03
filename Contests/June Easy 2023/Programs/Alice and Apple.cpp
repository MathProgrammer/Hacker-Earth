#include <iostream>
#include <vector>
#include <set>
using namespace std;

int normalise(int n)
{
	while(n%2 == 0)
	{
		n /= 2;
	}

	while(n%3 == 0)
	{
		n /= 3;
	}

	return n;
}

void solve()
{
	int no_of_elements;
	cin >> no_of_elements;

	set <int> normalised_value;
	vector <int> A(no_of_elements + 1);
	for(int i = 1; i <= no_of_elements; i++)
	{
		cin >> A[i];

		normalised_value.insert(normalise(A[i]));
	}

	cout << (normalised_value.size() == 1 ? "Yes" : "No") << "\n";
}

int main()
{
	int no_of_test_cases;
	cin >> no_of_test_cases;

	while(no_of_test_cases--)
		solve();

	return 0;
}
