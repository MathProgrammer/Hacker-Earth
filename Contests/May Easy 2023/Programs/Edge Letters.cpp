#include <iostream>
#include <vector>

using namespace std;
int main() 
{
	string S; 
	cin >> S; 

	const int NO_OF_ALPHABETS = 26;
	vector <int> suffix_frequency(NO_OF_ALPHABETS, 0);
	vector <vector <long long> > answer(NO_OF_ALPHABETS, vector <long long> (NO_OF_ALPHABETS, 0));
	for(int i = S.size() - 1; i >= 0; i--)
	{
		suffix_frequency[S[i] - 'a']++;

		int left_alpha = S[i] - 'a';
		for(int right_alpha = 0; right_alpha < NO_OF_ALPHABETS; right_alpha++)
		{
			int new_segments = suffix_frequency[right_alpha];

			answer[left_alpha][right_alpha] += new_segments;
		}
	}

	int no_of_queries; 
	cin >> no_of_queries; 

	for(int i = 1; i <= no_of_queries; i++)
	{
		char L, R; 
		cin >> L >> R; 
		
		int left = L - 'a', right = R - 'a'; 
		cout << answer[left][right] << "\n";
	}

	return 0;
}
