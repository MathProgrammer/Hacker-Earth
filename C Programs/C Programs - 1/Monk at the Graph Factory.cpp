#include <iostream>
using namespace std;

int main()
{
    int no_of_vertices, no_of_edges = 0;
    cin >> no_of_vertices;

    for(int i = 1; i <= no_of_vertices; i++)
    {
        int degree_i;
        cin >> degree_i;

        no_of_edges += degree_i;
    }

    cout << (no_of_edges == 2*(no_of_vertices - 1) ? "Yes\n" : "No\n");
    return 0;
}
