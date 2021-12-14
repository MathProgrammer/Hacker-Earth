#include <iostream> 
#include <vector> 
#include <map>

using namespace std; 

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int no_of_elements;
	cin >> no_of_elements; 

	map <int, int> frequency;
	vector <int> A(no_of_elements + 1);
	for(int i = 1; i <= no_of_elements; i++)
	{
		cin >> A[i];

		frequency[A[i]]++;
	}

	vector <long long> frequency_sum(no_of_elements + 1);
	for(auto it = frequency.begin(); it != frequency.end(); it++)
	{
		int element = it->first;

		frequency_sum[frequency[element]] += element*1LL*frequency[element];
	}

	vector <long long> frequency_prefix_sum(no_of_elements + 1);
	for(int i = 1; i <= no_of_elements; i++)
	{
		frequency_prefix_sum[i] = frequency_prefix_sum[i - 1] + frequency_sum[i];
	}

	int no_of_queries; 
	cin >> no_of_queries; 

	while(no_of_queries--)
	{
		int left, right; 
		cin >> left >> right;

		cout << frequency_prefix_sum[right] - frequency_prefix_sum[left - 1] << "\n";
	}

	return 0;
}
