#include <iostream>
#include <vector>
 
using namespace std;
 
const int MAX_N = 1e3 + 5;
int cost[MAX_N][MAX_N];
long long sum_till[MAX_N][MAX_N];
 
void solve()
{
    int rows, columns, K;
    cin >> rows >> columns >> K;
    
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            cin >> cost[i][j];
        }
    }
    
    for(int i = 0; i <= rows; i++)
    {
        for(int j = 0; j <= columns; j++)
        {
            if(i == 0 || j == 0)
            {
                sum_till[i][j] = 0;
                
                continue;
            }
            
            sum_till[i][j] = cost[i][j] + sum_till[i - 1][j] + sum_till[i][j - 1] - sum_till[i - 1][j - 1];
        }
    }
    
    const long long oo = 1e18;
    long long minimum_cost = oo;
    for(int i = 2; i <= rows; i++)
    {
        for(int j = K; j <= columns; j++)
        {
            //Bottom(i, j) Top(i - 1, j - K + 1)
            
            long long cost = sum_till[i][j] - sum_till[i - 2][j] - sum_till[i][j - K]
                            + sum_till[i - 2][j - K];
                            
            minimum_cost = min(cost, minimum_cost);
        }
    }
    
    for(int i = K; i <= rows; i++)
    {
        for(int j = 2; j <= columns; j++)
        {
            //Bottom(i, j) Top(i - K + 1, j - 1)
            
            long long cost = sum_till[i][j] - sum_till[i - K][j] - sum_till[i][j - 2]
                           + sum_till[i - K][j - 2];
                           
            minimum_cost = min(cost, minimum_cost);
        }
    }
    
    cout << (minimum_cost == oo ? -1 : minimum_cost) << "\n";
}
 
int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
        
    return 0;
}
