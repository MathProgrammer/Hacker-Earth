#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	int no_of_elements; 
	cin >> no_of_elements; 

	vector <long long> A(no_of_elements + 1);
	for(int i = 1; i <= no_of_elements; i++)
	{
		cin >> A[i];
	}

	int max_frequency = 0;
	map <long long, int> frequency;
	for(int i = 1; i <= no_of_elements; i++)
	{
		frequency[A[i]]++;

		max_frequency = max(max_frequency, frequency[A[i]]);
	}

	int max_frequency_count = 0;
	for(auto it = frequency.begin(); it != frequency.end(); it++)
	{
		if(it->second == max_frequency)
		{
			max_frequency_count++;
		}
	}

	cout << max_frequency_count << "\n";

	return 0;
}
