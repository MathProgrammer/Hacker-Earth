#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_vertices;
    cin >> no_of_vertices;
    
    vector <int> degree(no_of_vertices + 1, 0);
    for(int i = 1; i <= no_of_vertices - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        
        degree[u]++;
        degree[v]++;
    }
    
    vector <int> cost(no_of_vertices + 1, 0);
    for(int i = 1; i <= no_of_vertices; i++)
    {
        cin >> cost[i];
    }
    
    long long answer = 0;
    for(int i = 1; i <= no_of_vertices; i++)
    {
        if(degree[i] > 1 && cost[i] > 0)
        {
            answer++;
        }
    }
    
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
