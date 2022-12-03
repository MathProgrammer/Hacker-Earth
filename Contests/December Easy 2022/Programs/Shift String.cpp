#include <iostream>
#include <vector> 
using namespace std;

int is_set(int n, int bit)
{
	return ( (n&(1 << bit)) != 0 );
}

int distance(string S, string T)
{
	int difference = 0;
	for(int i = 0; i < S.size(); i++)
	{
		if(S[i] > T[i])
		{
			swap(S[i], T[i]);
		}

		int minimum_steps = min(T[i] - S[i], (S[i] - 'a') + 1 + ('z' - T[i]));
		
		difference += minimum_steps;
	}

	return difference; 
}

void display(int n)
{
	for(int b = 2; b >= 0; b--)
	{
		cout << (is_set(n, b) ? "1" : "0");
	}
}

int main()
{
	int length; 
	cin >> length; 

	string S; 
	cin >> S;

	int no_of_strings; 
	cin >> no_of_strings;
	vector <string> strings(no_of_strings + 1);
	for(int i = 0; i < no_of_strings; i++)
	{
		cin >> strings[i];
	}

	vector <vector <int> > matrix(no_of_strings + 1, vector <int> (no_of_strings + 1));
	for(int i = 0; i < no_of_strings; i++)
	{
		for(int j = 0; j < no_of_strings; j++)
		{
			matrix[i][j] = distance(strings[i], strings[j]);
		}
	}

	const int oo = 1e9, MAX_MASK = (1 << no_of_strings);
	vector <vector <int> > no_of_moves(MAX_MASK, vector <int> (no_of_strings + 1, oo));
	vector <int> best_finish(MAX_MASK);
	for(int m = 0; m < MAX_MASK; m++)
	{
		for(int bit = 0; bit <= no_of_strings; bit++)
		{
			if(!is_set(m, bit))
			{
				continue;
			}

			if(__builtin_popcount(m) == 1)
			{
				no_of_moves[m][bit] = distance(S, strings[bit]);
				continue;
			}

			for(int second_last_bit = 0; second_last_bit <= no_of_strings; second_last_bit++)
			{
				if(!is_set(m, second_last_bit))
				{
					continue;
				}

				int before_m = m^(1 << bit);

				no_of_moves[m][bit] = min(no_of_moves[m][bit], 
				no_of_moves[before_m][second_last_bit] + matrix[second_last_bit][bit]);
			}
		}
	}

	int answer = oo; 
	for(int i = 0; i < no_of_strings; i++)
	{
		answer = min(answer, no_of_moves[MAX_MASK - 1][i]);
	}

	cout << answer << "\n";

	return 0;
}
