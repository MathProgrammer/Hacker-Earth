#include <iostream>
#include <map>
#include <vector>

using namespace std;

void solve()
{
	int no_of_elements;
	cin >> no_of_elements;

	vector <int> A(no_of_elements + 1);
	for(int i = 1; i <= no_of_elements; i++)
	{
		cin  >> A[i];
	}

	map <int, int> taken;
	vector <int> answer;
	for(int i = 1; i <= no_of_elements; i++)
	{
		if(!taken[A[i]])
		{
			answer.push_back(i);
			taken[A[i]] = true;
		}
	}

	cout << answer.size() << "\n";
	for(int index : answer)
	{
		cout << index << " ";
	}
	cout << "\n";
}

int main()
{
	int no_of_test_cases;
	cin >> no_of_test_cases; 

	while(no_of_test_cases--)
		solve();
	
	return 0;
}

