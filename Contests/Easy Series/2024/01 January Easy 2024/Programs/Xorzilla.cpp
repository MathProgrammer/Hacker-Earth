#include <iostream>
#include <vector> 
using namespace std;
 
const int MAX_N = 1e5 + 5, MAX_L = 21, MAX_BITS = 31;
vector <int> tree[MAX_N], height(MAX_N); 
int parent[MAX_N][MAX_L];
int bit_sum[MAX_BITS][MAX_N];
int A[MAX_N], xor_till[MAX_N];
 
int is_bit_set(int n, int bit)
{
	return ( (n&(1 << bit)) != 0 );
}
 
void initialize(int no_of_vertices)
{
	for(int v = 1; v <= no_of_vertices; v++)
	{
		tree[v].clear();
	}
}
 
void dfs(int v, int parent_v)
{
	height[v] = height[parent_v] + 1; 
	parent[v][0] = parent_v;

	xor_till[v] = A[v]^xor_till[parent_v];
 
	for(int child_v : tree[v])
	{
		if(child_v == parent_v)
		{
			continue;
		}
 
		dfs(child_v, v);
	}
}
 
void compute_parents(int no_of_vertices)
{
	for(int l = 1; l < MAX_L; l++)
	{
		for(int v = 1; v <= no_of_vertices; v++)
		{
			int ancestor = parent[v][l - 1]; 
			parent[v][l] = parent[ancestor][l - 1];
		}
	}
}
 
int lca(int u, int v)
{
	if(height[u] > height[v])
	{
		swap(u, v);
	}
 
	int difference = height[v] - height[u];
	for(int bit = MAX_L - 1; bit >= 0; bit--)
	{
		if(is_bit_set(difference, bit))
		{
			v = parent[v][bit];
		}
	}
 
	if(u == v)
	{
		return v; 
	}
 
	for(int bit = MAX_L - 1; bit >= 0; bit--)
	{
		if(parent[u][bit] != parent[v][bit])
		{
			u = parent[u][bit];
			v = parent[v][bit];
		}
	}
	
	return parent[v][0];
}
 
int distance(int u, int v)
{
	int l = lca(u, v); 

	int total_distance = height[u] + height[v] - 2*height[l] + 1;
 
	return total_distance;
}
 
void solve()
{
	int no_of_vertices; 
	cin >> no_of_vertices; 
 
	initialize(no_of_vertices);
	int no_of_edges = no_of_vertices - 1;
	for(int i = 1; i <= no_of_edges; i++)
	{
		int u, v; 
		cin >> u >> v; 
 
		tree[u].push_back(v); 
		tree[v].push_back(u);
	}
 
	for(int i = 1; i <= no_of_vertices; i++)
	{
		cin >> A[i];
	}
 
	xor_till[0] = 0;
	height[0] = 0;
	dfs(1, 0);
 
	compute_parents(no_of_vertices);
 
	int no_of_queries; 
	cin >> no_of_queries; 
 
	for(int i = 1; i <= no_of_queries; i++)
	{
		int X, u, v; 
		cin >> X >> u >> v; 
 
		int l = lca(u, v); 
 
		int answer = xor_till[u]^xor_till[v]^A[l]; 
		int d = height[u] + height[v] - 2*height[l] + 1;
 
		for(int bit = MAX_BITS - 1; bit >= 0; bit--)
		{
			if(X >= (1 << bit) && !is_bit_set(answer, bit) && d%2 == 1)
			{
				answer |= (1 << bit); 
				X -= (1 << bit);
			}
		}
 
		cout << answer << "\n";
	}
}
 
int main() 
{	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int no_of_test_cases; 
	cin >> no_of_test_cases; 
 
	while(no_of_test_cases--)
		solve(); 
 
	return 0;
}
