#include <iostream>
#include <vector> 
#include <algorithm>

#define all(v) (v).begin, (v).end()
using namespace std; 

long long calculate(vector <long long> &A, int no_of_elements)
{
	sort(A.begin(), A.end());

	long long sum = 0; 
	for(int i = 1; i <= no_of_elements; i++)
	{
		long long before_contribution = (i - 1)*A[i]; 
		long long after_contribution = (no_of_elements - i)*A[i];

		sum += (before_contribution - after_contribution);
	}

	return sum;
}

void solve()
{
	int no_of_points; 
	cin >> no_of_points; 

	vector <long long> X(no_of_points + 1), Y(no_of_points + 1);
	for(int i = 1; i <= no_of_points; i++)
	{
		cin >> X[i] >> Y[i];
	}

	long long x_answer = calculate(X, no_of_points), y_answer = calculate(Y, no_of_points);
	long long answer = x_answer + y_answer; 

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
