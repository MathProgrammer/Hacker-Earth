#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5, MAX_L = 21, MAX_BITS = 20;
vector <int> tree[MAX_N];
int A[MAX_N];
int height[MAX_N], xor_till[MAX_N], bit_sum[MAX_N][MAX_BITS];
int parent[MAX_N][MAX_L];

int is_bit_set(int n, int bit)
{
	return( ( n & (1 << bit) ) != 0 );
}

void compute_parents(int no_of_vertices)
{
	for(int l = 1; l < MAX_L; l++)
	{
		for(int i = 1; i <= no_of_vertices; i++)
		{
			int ancestor = parent[i][l - 1];

			parent[i][l] = parent[ancestor][l - 1];
		}
	}
}

void dfs(int parent_v, int v)
{
	parent[v][0] = parent_v;

	height[v] = height[parent_v] + 1;
	xor_till[v] = xor_till[parent_v]^A[v];

	for(int bit = 0; bit < MAX_BITS; bit++)
	{
		bit_sum[v][bit] = bit_sum[parent_v][bit] + is_bit_set(A[v], bit);
	}

	for(int child_v : tree[v])
	{
		if(child_v == parent_v)
		{
			continue;
		}


		dfs(v, child_v);
	}
}

int lca(int u, int v)
{
	if(height[u] > height[v])
	{
		swap(u, v);
	}

	for(int bit = MAX_L - 1; bit >= 0 && height[u] < height[v]; bit--)
	{
		int ancestor = parent[v][bit];

		if(height[ancestor] >= height[u])
		{
			v = ancestor;
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

int get_or(int left, int right)
{
	int segment_or = 0;
	for(int bit = 0; bit < MAX_BITS; bit++)
	{
		if(bit_sum[right][bit] - bit_sum[left][bit] > 0)
		{
			segment_or |= (1 << bit);
		}
	}

	return segment_or;
}

int main()
{
	int no_of_vertices, no_of_queries;
	cin >> no_of_vertices >> no_of_queries;

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

	height[0] = 0, xor_till[0] = 0;
	dfs(0, 1);
	compute_parents(no_of_vertices);

	for(int i = 1; i <= no_of_queries; i++)
	{
		int u, v;
		cin >> u >> v;

		if(height[u] > height[v])
		{
			swap(u, v);
		}

		int l = lca(u, v);

		int xor_uv = 0, or_uv = 0;
		if(l == u)
		{
			xor_uv = xor_till[v]^xor_till[u]^A[u];
			or_uv = get_or(u, v)|A[u];
		}
		else
		{
			int xor_lu = xor_till[u]^xor_till[l], xor_lv = xor_till[v]^xor_till[l];
			xor_uv = xor_lu^xor_lv^A[l];

			int or_lu = get_or(l, u), or_lv = get_or(l, v);
			or_uv = or_lu|or_lv|A[l];
		}

		int answer = xor_uv + or_uv;
		cout << answer << "\n";
	}

	return 0;
}
