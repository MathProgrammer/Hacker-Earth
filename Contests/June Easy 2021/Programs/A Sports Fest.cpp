#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct sport 
{
	int a, b, sum; 

	sport(){}

	sport(int A, int B)
	{
		a = A; b = B; 
		sum = (A + B);
	}

	const int operator <(const sport &S)
	{
		if(sum == S.sum)
		{
			return (a < S.a);
		}

		return (sum < S.sum);
	}
};

void solve()
{
	int no_of_elements;
	cin >> no_of_elements;

	vector <int> A(no_of_elements + 1), B(no_of_elements + 1);
	for(int i = 1; i <= no_of_elements; i++)
	{
		cin >> A[i];
	}

	for(int i = 1; i <= no_of_elements; i++)
	{
		cin >> B[i];
	}

	vector <sport> S(no_of_elements + 1);
	for(int i = 1; i <= no_of_elements; i++)
	{
		S[i] = sport(A[i], B[i]);
	}
	sort(S.begin() + 1, S.end());

	long long max_difference = 0;
	for(int turn = 1, i = no_of_elements; i >= 1; i--, turn++)
	{
		max_difference += (turn%2 == 1 ? S[i].a : -S[i].b);
	}

	cout << max_difference << "\n";
}

int main()
{
	int no_of_test_cases;
	cin >> no_of_test_cases; 

	while(no_of_test_cases--)
		solve();
	
	return 0;
}

