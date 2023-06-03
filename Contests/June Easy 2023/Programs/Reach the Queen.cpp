#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int main()
{
	int no_of_vertices, no_of_edges;
	cin >> no_of_vertices >> no_of_edges;

	vector <int> indegree(no_of_vertices + 1);
	vector <vector <int> > graph(no_of_vertices + 1);
	for(int i = 1; i <= no_of_edges; i++)
	{
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		indegree[v]++;
	}

	queue <int> Q;
	for(int i = 1; i <= no_of_vertices; i++)
	{
		if(indegree[i] == 0)
		{
			Q.push(i);
		}
	}

	const int MOD = 1e9 + 7;
	vector <int> no_of_ways(no_of_vertices + 1);
	no_of_ways[1] = 1;
	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();

		for(int child_v : graph[v])
		{
			no_of_ways[child_v] += no_of_ways[v];
			no_of_ways[child_v] %= MOD;

			indegree[child_v]--;
			if(indegree[child_v] == 0)
			{
				Q.push(child_v);
			}
		}
	}

	cout << no_of_ways[no_of_vertices] << "\n";

	return 0;
}
