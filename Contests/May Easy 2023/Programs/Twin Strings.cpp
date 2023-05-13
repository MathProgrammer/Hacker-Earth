#include <iostream>
#include <map> 

using namespace std;

void solve()
{
	int length;
	string S; 
	cin >> length >> S;

	map <int, int> prefix_frequency;
	int prefix_mask = 0;
	prefix_frequency[0] = 1;

	long long answer = 0;
	for(int i = 0; i < S.size(); i++)
	{
		int alpha = (S[i] - 'a');
		int bit = (1 << alpha);

		prefix_mask ^= bit; 
		answer += prefix_frequency[prefix_mask];

		prefix_frequency[prefix_mask]++;
	}

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
