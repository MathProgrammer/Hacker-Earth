#include <iostream>
#include <vector> 

using namespace std; 

void solve()
{
	const int N = 3;
	vector <vector <int> > grid(N + 1, vector <int> (N + 1));
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cin >> grid[i][j]; 
		}
	}

	vector <long long> A(N + 1), B(N + 1);
	A[1] = 0; 
	B[1] = grid[1][1] - A[1]; 
	A[2] = grid[2][1] - B[1];
	B[2] = grid[2][2] - A[2]; 
	A[3] = grid[3][2] - B[2];
	B[3] = grid[3][3] - A[3];
	
	int possible = true;
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			if(A[i] + B[j] != grid[i][j])
			{
				possible = false;
			}
		}
	}

	cout << (possible ? "YES" : "NO") << "\n";
}

int main()
{
	int no_of_test_cases; 
	cin >> no_of_test_cases; 

	while(no_of_test_cases--)
		solve();

	return 0;
}
