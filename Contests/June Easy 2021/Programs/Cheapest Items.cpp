#include <iostream>
#include <map>
#include <vector>

using namespace std;

void solve()
{
	int no_of_elements;
	cin >> no_of_elements;

	vector <int> value(no_of_elements + 1), price(no_of_elements + 1);
	for(int i = 1; i <= no_of_elements; i++)
	{
		cin >> value[i] >> price[i];
		value[i]++;
	}

	const long long oo = 1e18;
	vector < vector <long long> > minimum_price(no_of_elements + 1, vector <long long> (no_of_elements + 1, oo));
	minimum_price[0][0] = 0;
	for(int i = 1; i <= no_of_elements; i++)
	{
		for(int v = 0; v <= no_of_elements; v++)
		{
			minimum_price[i][v] = minimum_price[i - 1][v];
		}

		for(int previous_value = 0; previous_value <= no_of_elements; previous_value++)
		{
			int value_here = min(previous_value + value[i], no_of_elements);

			minimum_price[i][value_here] = min(minimum_price[i][value_here], 
						price[i] + minimum_price[i - 1][previous_value]);
		}
	}
	
	cout << minimum_price[no_of_elements][no_of_elements] << "\n";
}

int main()
{
	int no_of_test_cases;
	cin >> no_of_test_cases; 

	while(no_of_test_cases--)
		solve();
	
	return 0;
}

