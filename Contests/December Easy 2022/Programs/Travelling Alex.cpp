#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5, oo = 1e9;
vector <int> graph[MAX_N];
int round_trip[MAX_N], one_trip[MAX_N];

void clear(int n)
{
	for(int i = 1; i <= n; i++)
	{
		graph[i].clear();
		round_trip[i] = 0; 
		one_trip[i] = 0;
	}
}

void dfs(int v, int parent_v)
{
	if(graph[v].size() == 1 && v != 1)
	{
		return;
	}

	int total_child_trip = 0, no_of_children = 0;
	for(int child_v : graph[v])
	{
		if(child_v == parent_v)
		{
			continue;
		}

		dfs(child_v, v);

		round_trip[v] += 2 + round_trip[child_v];

		total_child_trip += round_trip[child_v];

		no_of_children++;
	}

	one_trip[v] = oo;
	for(int child_v : graph[v])
	{
		if(child_v == parent_v)
		{
			continue;
		}

		int remaining_round_trip = 2*(no_of_children - 1) + (total_child_trip - round_trip[child_v]);

		int one_trip_here = 1 + one_trip[child_v] + remaining_round_trip;

		one_trip[v] = min(one_trip[v], one_trip_here);
	}
}

void solve()
{
    int no_of_vertices; 
	cin >> no_of_vertices; 

	clear(no_of_vertices);

	int no_of_edges = no_of_vertices - 1; 
	for(int i = 1; i <= no_of_edges; i++)
	{
		int u, v; 
		cin >> u >> v; 

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

    dfs(1, 0);

	cout << one_trip[1] << "\n";
}

int main() 
{
    int no_of_test_cases; 
    cin >> no_of_test_cases; 

    while(no_of_test_cases--)
        solve();

    return 0;
}
