#include <iostream>
#include <map>
#include <vector>

using namespace std;

void solve()
{
	int no_of_names;
	cin >> no_of_names;

	int last_label = 1;
	map <string, int> label;
	vector <int> source(no_of_names + 1), target(no_of_names + 1);
	vector < vector <int> > graph(2*no_of_names + 1);
	for(int i = 1; i <= no_of_names; i++)
	{
		string S, T;
		cin >> S >> T; 

		if(label[S] == 0) 
			label[S] = last_label++;
		
		if(label[T] == 0)
			label[T] = last_label++;

		source[i] = label[S], target[i] = label[T];
		graph[source[i]].push_back(target[i]); 
	}

	int cost = 0;
	vector <int> visited(2*no_of_names + 1, false);
	for(int i = 1; i <= no_of_names; i++)
	{
		int v = source[i];

		if(visited[v] || graph[v][0] == v)
		{
			continue;
		}

		int component_length = 0, is_cycle = false;
		while(!visited[v] && graph[v].size() > 0)
		{
			visited[v] = true;
			component_length++; 

			if(graph[v].size() > 0)
			{
				int child_v = graph[v][0];
				v = child_v;

				if(v == i)
				{
					is_cycle = true; 
					break;
				}
			}
		}
		
		cost += (is_cycle ? component_length + 1 : component_length);
	}

	cout << cost << "\n";
}

int main()
{
	int no_of_test_cases;
	cin >> no_of_test_cases; 

	while(no_of_test_cases--)
		solve();
	
	return 0;
}

