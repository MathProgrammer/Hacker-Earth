#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 2e5 + 5;
int forward_or_cross_edge = false;
vector <int> graph[MAX_N];
vector <int> visited(MAX_N, false);
vector <int> on_stack(MAX_N, false);
vector <int> covering_back_edges(MAX_N, 0);

void dfs(int v)
{
    visited[v] = true;
    on_stack[v] = true;

    for(int i = 0; i < graph[v].size(); i++)
    {
        int child = graph[v][i];

        if(visited[child])
        {
            if(on_stack[child])
            {
                covering_back_edges[child]--;
                covering_back_edges[v]++;
            }
            else if(!on_stack[child])
            {
                forward_or_cross_edge = true;
            }
        }
        else
        {
            dfs(child);

            covering_back_edges[v] += covering_back_edges[child];
        }
    }

    on_stack[v] = false;
}

void solve()
{
    int no_of_vertices, no_of_edges;
    scanf("%d %d", &no_of_vertices, &no_of_edges);

    forward_or_cross_edge = false;
    for(int i = 1; i <= no_of_vertices; i++)
    {
        graph[i].clear();

        visited[i] = false;
        on_stack[i] = false;
        covering_back_edges[i] = 0;
    }

    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        if(u != v)
        {
            graph[u].push_back(v);
        }
    }

    int root = 1;
    dfs(root);

    int no_of_visited_vertices = 0;
    for(int i = 1; i <= no_of_vertices; i++)
    {
        no_of_visited_vertices += (visited[i] == true);
    }

    int edges_with_back_path = 0;
    for(int i = 2; i <= no_of_vertices; i++)
    {
        if(i == root)
        {
            continue;
        }

        edges_with_back_path += (covering_back_edges[i] == 1);
    }

    printf("%s", no_of_visited_vertices == no_of_vertices && forward_or_cross_edge == false
            && edges_with_back_path == no_of_vertices - 1 ? "Yes\n" : "No\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
    {
        solve();
    }

    return 0;
}
