#include <iostream>
#include <vector> 
#include <queue>

using namespace std;

void bfs(int source, vector <vector <int> > &G, vector <int> &D)
{
	const int oo = 1e9;
	int no_of_vertices = D.size() - 1;

	for(int v = 1; v <= no_of_vertices; v++)
	{
		D[v] = oo;
	}
	D[source] = 0;

	queue <int> Q; 
	Q.push(source);
	while(!Q.empty())
	{
		int v = Q.front(); 
		Q.pop();

		for(int u : G[v])
		{
			if(D[v] + 1 < D[u])
			{
				D[u] = D[v] + 1; 
				Q.push(u);
			}
		}
	}
}

void solve()
{
	long long no_of_vertices, no_of_edges, X, Y; 
	cin >> no_of_vertices >> no_of_edges >> X >> Y;

	vector <vector <int> > graph(no_of_vertices + 1);
	for(int i = 1; i <= no_of_edges; i++)
	{
		int u, v; 
		cin >> u >> v; 

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	vector <int> X_distance(no_of_vertices + 1);
	bfs(X, graph, X_distance);

	vector <int> Y_distance(no_of_vertices + 1);
	bfs(Y, graph, Y_distance);

	vector <int> vertices_with_Y_distance_of(2*no_of_vertices + 1);
	vector <int> vertices_with_total_distance_of(2*no_of_vertices + 1);
	for(int v = 1; v <= no_of_vertices; v++)
	{
		vertices_with_Y_distance_of[Y_distance[v]]++;
		vertices_with_total_distance_of[X_distance[v] + Y_distance[v]]++;
	}

	vector <int> vertices_with_Y_distance_at_most(2*no_of_vertices + 2);
	vertices_with_Y_distance_at_most[0] = vertices_with_Y_distance_of[0];
	vector <int> vertices_with_total_distance_at_most(2*no_of_vertices + 2);
	vertices_with_total_distance_at_most[0] = vertices_with_total_distance_of[0];
	for(int d = 1; d <= 2*no_of_vertices; d++)
	{
		vertices_with_Y_distance_at_most[d] = vertices_with_Y_distance_at_most[d - 1] 
										 + vertices_with_Y_distance_of[d];

		vertices_with_total_distance_at_most[d] = vertices_with_total_distance_at_most[d - 1] 
		  									 + vertices_with_total_distance_of[d];
	}

	long long answer = (no_of_vertices*(no_of_vertices - 1))/2 - no_of_edges;
	long long bad_edges = 0, doubly_counted_edges = 0;
	int total_distance = X_distance[Y];
	for(int v = 1; v <= no_of_vertices; v++)
	{
		//(u, v) is bad if 
		//X[u] + 1 + Y[v] < D 
		//Y[v] < D - X[u] - 1
		int minimum_Y_distance_required = total_distance - X_distance[v] -1 -1;
		if(minimum_Y_distance_required >= 0)
		{
			bad_edges += vertices_with_Y_distance_at_most[minimum_Y_distance_required];
		}

        //(u, v) and (v, u) are both bad if 
		// X[u] + 1 + Y[v] < D 
		// X[v] + 1 + Y[u] < D
		// X[u] + Y[u] < 2D - Y[v] - X[v] - 2
		int total_distance_required =  2*total_distance - X_distance[v] - Y_distance[v] - 2 -1;
		if(total_distance_required >= 0)
		{
			doubly_counted_edges += vertices_with_total_distance_at_most[total_distance_required];
		}
	}

	bad_edges -= doubly_counted_edges;
	answer -= bad_edges;
	cout << answer << "\n";
}

int main() 
{
	int no_of_test_cases; 
	cin >> no_of_test_cases; 

	while(no_of_test_cases--)
		solve();

	return 0;
}
