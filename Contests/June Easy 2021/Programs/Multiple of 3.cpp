#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
	int n;
	cin >> n; 

	if(n%3 == 0)
	{
		cout << n << "\n";

		return;
	}

	int extra_digit = (3 - n%3);

	vector <int> digits; 
	while(n > 0)
	{
		digits.push_back(n%10);

		n /= 10;
	}
	reverse(digits.begin(), digits.end());

	int position = digits.size();
	for(int i = 0; i < digits.size(); i++)
	{
		if(digits[i] > extra_digit)
		{
			position = i; 
			break;
		}
	}

	for(int i = 0; i < position; i++)
	{
		cout << digits[i];
	}
	cout << extra_digit;
	for(int i = position; i < digits.size(); i++)
	{
		cout << digits[i];
	}

	cout << "\n";
}

int main()
{
	int no_of_test_cases;
	cin >> no_of_test_cases; 

	while(no_of_test_cases--)
		solve();
	
	return 0;
}
