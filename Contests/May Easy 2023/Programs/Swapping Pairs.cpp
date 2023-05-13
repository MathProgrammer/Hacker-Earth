#include <iostream>
#include <vector> 
using namespace std;

void solve()
{
	int no_of_elements, M;
	cin >> no_of_elements >> M;

	vector <int> A(no_of_elements + 1), B(no_of_elements + 1);
	for(int i = 1; i <= no_of_elements; i++)
	{
		cin >> A[i] >> B[i];
	}

	vector <int> reachable(M + 1, false);
	reachable[0] = true;
	for(int i = 1; i <= no_of_elements; i++)
	{
		vector <int> reachable_here(M + 1, false);
		for(int m = 0; m <= M; m++)
		{
			if(m - A[i] >= 0 && reachable[m - A[i]])
			{
				reachable_here[m] = true; //cout << m << " is reachable from " << A[i] << "\n";
			}

			if(m - B[i] >= 0 && reachable[m - B[i]])
			{
				reachable_here[m] = true; //cout << m << " is reachable from " << B[i] << "\n";
			}
		}

		reachable = reachable_here;
	}

	cout << (reachable[M] ? "YES" : "NO") << "\n";
}

int main() 
{
	int no_of_test_cases; 
	cin >> no_of_test_cases; 

	while(no_of_test_cases--)
		solve();

	return 0;
}
