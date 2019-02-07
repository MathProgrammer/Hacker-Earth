#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MAX_N = 5e5 + 5, MAX_COLOURS = 5e5 + 5, LOG_MAX = 25;
int parent[MAX_N][LOG_MAX];
vector <int> depth(MAX_N, 0);
vector <int> visited(MAX_N, false);
vector <int> tree[MAX_N];
vector <int> vertices_coloured[MAX_N];
vector <int> diameter[MAX_N];

int is_bit_set(int n, int position)
{
    return ( ( n & (1 << position) ) != 0);
}

void dfs_depth(int v_parent, int v)
{
    if(visited[v])
        return;

    visited[v] = true;

    depth[v] = depth[v_parent] + 1;

    parent[v][0] = v_parent;

    for(int i = 0; i < tree[v].size(); i++)
    {
        int child = tree[v][i];

        dfs_depth(v, child);
    }
}

void precompute_parents()
{
    for(int l = 1; l < LOG_MAX; l++)
    {
        for(int i = 1; i <= MAX_N; i++)
        {
            if(parent[i][l - 1] != 0)
            {
                int ancestor = parent[i][l - 1];

                parent[i][l] = parent[ancestor][l - 1];
            }
        }
    }
}

int lca(int u, int v)
{
    if(depth[u] < depth[v])
        swap(u, v);


    int difference = depth[u] - depth[v];

    for(int bit = 0; bit < LOG_MAX; bit++)
    {
        if(is_bit_set(difference, bit))
        {
            u = parent[u][bit];
        }
    }

    if(u == v)
        return u;

    for(int bit = LOG_MAX - 1; bit >= 0; bit--)
    {
        if(parent[u][bit] != 0 && parent[u][bit] != parent[v][bit])
        {
            u = parent[u][bit];
            v = parent[v][bit];
        }
    }

    return parent[u][0];
}

int distance_tree(int u, int v)
{
    return (depth[u] + depth[v] - 2*depth[lca(u, v)]);
}

void precompute_diameter()
{
    for(int c = 0; c < MAX_COLOURS; c++)
    {
        if(vertices_coloured[c].size() <= 2)
        {
            for(int i = 0; i < vertices_coloured[c].size(); i++)
            {
                int v = vertices_coloured[c][i];

                diameter[c].push_back(v);
            }

            continue;
        }

        int u = vertices_coloured[c][0];

        int furthest = u, furthest_distance = 0;

        for(int i = 1; i < vertices_coloured[c].size(); i++)
        {
            int v = vertices_coloured[c][i];

            if(distance_tree(u, v) > furthest_distance)
            {
                furthest = v;
                furthest_distance = distance_tree(u, v);
            }
        }

        int v = furthest;

        diameter[c].push_back(v);


        furthest = v, furthest_distance = 0;

        for(int i = 0; i < vertices_coloured[c].size(); i++)
        {
            int w = vertices_coloured[c][i];

            if(distance_tree(v, w) > furthest_distance)
            {
                furthest_distance = distance_tree(v, w);

                furthest = w;
            }
        }

        diameter[c].push_back(furthest);
    }
}

void solve()
{
    int k, colour;
    cin >> k >> colour;

    if(vertices_coloured[colour].size() == 0)
    {
        cout << "-1\n";
    }
    else
    {
        int maximum_distance = 0;

        for(int i = 0; i < diameter[colour].size(); i++)
        {
            int v = diameter[colour][i];

            maximum_distance = max(maximum_distance, distance_tree(k, v));
        }

        cout << maximum_distance << "\n";
    }

}

int main()
{
    int no_of_vertices, no_of_queries;
    cin >> no_of_vertices >> no_of_queries;

    for(int i = 1; i <= no_of_vertices; i++)
    {
        int colour;

        cin >> colour;

        vertices_coloured[colour].push_back(i);
    }

    int no_of_edges = no_of_vertices - 1;
    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    memset(parent, 0, sizeof(parent));

    dfs_depth(0, 1);

    precompute_parents();

    precompute_diameter();

    while(no_of_queries--)
    {
        solve();
    }

    return 0;
}
