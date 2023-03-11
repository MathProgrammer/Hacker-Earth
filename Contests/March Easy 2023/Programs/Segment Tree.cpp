#include <iostream>
#include <vector> 

using namespace std;
int main() 
{
	int no_of_elements; 
	cin >> no_of_elements; 

	vector <long long> A(no_of_elements + 1);
	for(int i = 0; i < no_of_elements; i++)
	{
		cin >> A[i];
	}

	int no_of_queries; 
	cin >> no_of_queries;

	long long total_subtracted = 0;
	for(int i = 1; i <= no_of_queries; i++)
	{
		const int UPDATE = 1, QUERY = 2;
		int query_type;
		cin >> query_type;

		switch(query_type)
		{
			case UPDATE: 
			{
				int index, add, subtract; 
				cin >> index >> add >> subtract; 

				total_subtracted += subtract;
				add += subtract; 

				A[index] += add;
				break;
			}
			case QUERY: 
			{
				int index; 
				cin >> index; 

				cout << A[index] - total_subtracted << "\n";
				break;
			}
		}
	}

	return 0;
}
