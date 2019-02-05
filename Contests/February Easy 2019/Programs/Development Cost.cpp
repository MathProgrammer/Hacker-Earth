#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 555, NO_OF_NEIHBOURS = 4, MAX_M = 5e5 + 5;
int rows, columns, no_of_queries, grid[MAX_N][MAX_N];
int neighbour_x[NO_OF_NEIHBOURS] = {-1, 0, 0, 1};
int neighbour_y[NO_OF_NEIHBOURS] = {0, 1, -1, 0};
int start_x[MAX_M], start_y[MAX_M], end_x[MAX_M], end_y[MAX_M];

struct Point
{
    int x, y;

    Point(int X, int Y)
    {
        x = X, y = Y;
    }
};

struct DSU
{
    int parent[MAX_N*MAX_N];

    DSU() {}

    DSU(int n)
    {
        for(int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }

    }

    int get_parent(int n)
    {
        while(n != parent[n])
        {
            parent[n] = parent[parent[n]];

            n = parent[n];
        }

        return n;
    }

    void unite(int x, int y)
    {
        int parent_x = get_parent(x), parent_y = get_parent(y);

        if(parent_x == parent_y)
            return;

        parent[parent_x] = parent[parent_y];
    }
};

int within_grid_and_legal(int x, int y, int value)
{
    return (x >= 1 && x <= rows && y >= 1 && y <= columns && grid[x][y] <= value);
}

int label(int x, int y)
{
    return (x - 1)*columns + y;
}

int no_of_successes(int max_cost)
{
    DSU dsu(rows*columns + 5);

    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            if(grid[i][j] > max_cost)
                continue;

            for(int n = 0; n < NO_OF_NEIHBOURS; n++)
            {
                int next_x = i + neighbour_x[n];
                int next_y = j + neighbour_y[n];

                if(within_grid_and_legal(next_x, next_y, max_cost))
                {
                    dsu.unite(label(i, j), label(next_x, next_y));
                }
            }
        }
    }

    int successes = 0;
    for(int i = 1; i <= no_of_queries; i++)
    {
        successes += (dsu.get_parent(label(start_x[i], start_y[i])) == dsu.get_parent(label(end_x[i], end_y[i])));
    }

    return successes;
}

int main()
{
    int minimum_successes;
    cin >> rows >> columns >> no_of_queries >> minimum_successes;

    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            cin >> grid[i][j];
        }
    }

    for(int i = 1; i <= no_of_queries; i++)
    {
        cin >> start_x[i] >> start_y[i] >> end_x[i] >> end_y[i];
    }

    const int oo = 1e9;
    int left = 1, right = oo;
    while(left < right)
    {
        int mid = (left + right)/2;

        if(no_of_successes(mid) >= minimum_successes)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    int minimum_cost = right;
    cout << minimum_cost;

    return 0;
}
