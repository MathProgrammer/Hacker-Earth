#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int no_of_elements;
	cin >> no_of_elements;

	vector <long long> A(no_of_elements + 1);
	for(int i = 1; i <= no_of_elements; i++)
	{
		cin >> A[i];

		A[i] %= 2;
	}

	const int MOD = 1e9 + 7;
	vector <vector <int> > no_of_sequences(no_of_elements + 1, vector <int> (2, 0));
	for(int i = 1; i <= no_of_elements; i++)
	{
		no_of_sequences[i][A[i]] = 1;

		for(int m = 0; m < 2; m++)
		{
			no_of_sequences[i][m] += no_of_sequences[i - 1][m];
			no_of_sequences[i][m] %= MOD;

			int new_m = (A[i] + m)%2;
			no_of_sequences[i][new_m] += no_of_sequences[i - 1][m];
			no_of_sequences[i][new_m] %= MOD;
		}
	}

	cout << no_of_sequences[no_of_elements][0] << "\n";
	return 0;
}
