#include <iostream>
#include <vector> 
using namespace std;

void dfs_down(int parent_v, int v, vector <vector <int> > &T,vector <int> &down_P)
{
	if(T[v].size() == 1)
	{
		down_P[v] = (v%2);
	}

	for(int child_v : T[v])
	{
		if(child_v == parent_v)
		{
			continue;
		}

		dfs_down(v, child_v, T, down_P);
		down_P[v] += (down_P[child_v] > 0);
	}

	//cout << "Down Potential " << v << " = " << down_P[v] << "\n";
}

void dfs_up_down(int parent_v, int v, vector <vector <int> > &T,vector <int> &down_P, vector <int> &P)
{
	int parent_potential_without_v = 0;

	if(parent_v != -1)
	{
		if(T[parent_v].size() == 1)
		{
			parent_potential_without_v = (parent_v%2);
		}
		else 
		{
			parent_potential_without_v = P[parent_v] - (down_P[v] > 0);
		}
	}

	if(T[v].size() == 1)
	{
		if(v == 0)
		{
			P[v] = down_P[v];
		}
		else 
		{
			P[v] = (parent_potential_without_v > 0);
		}
	}
	else 
	{
		P[v] = down_P[v] + (parent_potential_without_v > 0);
	}

	for(int child_v : T[v])
	{
		if(child_v == parent_v)
		{
			continue;
		}

		dfs_up_down(v, child_v, T, down_P, P);
	}

	//cout << "V = " << v << " Parent = " << parent_v << " Parent without v = " << parent_potential_without_v << " Potential = " << P[v] << "\n";
}

void solve()
{
	int no_of_elements; 
	cin >> no_of_elements; 

	int no_of_edges = no_of_elements - 1;
	vector <vector <int> > tree(no_of_elements);
	for(int i = 1; i <= no_of_edges; i++)
	{
		int u, v; 
		cin >> u >> v;

		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	vector <int> potential(no_of_elements), down_potential(no_of_elements);
	dfs_down(-1, 0, tree, down_potential);
	dfs_up_down(-1, 0, tree, down_potential, potential);

	for(int i = 0; i < no_of_elements; i++)
	{
		cout << potential[i] << " ";
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
