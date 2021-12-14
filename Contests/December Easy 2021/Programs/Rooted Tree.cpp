#include <iostream>
#include <vector> 

using namespace std; 

const int MAX_N = 1e5 + 5; 
vector <int> tree[MAX_N], sum(MAX_N, 0), parent(MAX_N, 0);

void clear(int no_of_elements)
{
	for(int i = 1; i <= no_of_elements; i++)
	{
		parent[i] = 0;
		tree[i].clear();
		sum[i] = 0;
	}
}

void dfs_parent(int v, int parent_v)
{
	parent[v] = parent_v; 

	for(int child_v : tree[v])
	{
		if(child_v == parent_v)
		{
			continue;
		}

		dfs_parent(child_v, v);
	}
}

void dfs(int v, int parent_v, int limit, int add)
{
	if(sum[v] >= limit)
	{
		return;
	}

	sum[v] += add;

	for(int child_v : tree[v])
	{
		if(child_v == parent_v)
		{
			continue;
		}

		dfs(child_v, v, limit, add);
	}
}

void solve()
{
	int no_of_vertices, no_of_queries, limit; 
	cin >> no_of_vertices >> no_of_queries >> limit; 

	clear(no_of_vertices);

	for(int i = 1, no_of_edges = no_of_vertices - 1; i <= no_of_edges; i++)
	{
		int u, v; 
		cin >> u >> v; 

		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	dfs_parent(1, 0);

	for(int i = 1; i <= no_of_queries; i++)
	{
		const int ADD = 0, GET_SUM = 1; 
		int query; 
		cin >> query;

		switch(query)
		{
			case ADD : {
						int v, add; 
					  	cin >> v >> add;
					  	dfs(v, parent[v], limit, add); 
					  	break; 
					  }

			case GET_SUM :{
						  int v; 
						  cin >> v; 
						  cout << sum[v] << "\n";
						}
		}
	}
}

int main()
{
	int no_of_test_cases; 
	cin >> no_of_test_cases; 

	while(no_of_test_cases--)
		solve();

	return 0;
}
