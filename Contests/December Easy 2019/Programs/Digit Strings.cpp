#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
 
using namespace std;
 
void solve()
{
    const int MOD = 1e9 + 7, MAX_N = 1e5 + 5;
    
    int length;
    char S[MAX_N];
    long long K;
    cin >> length >> K;
    scanf("%s", S + 1);
    
    vector <long long> no_of_ways(length + 1, 0);
    no_of_ways[0] = 1;
    
    for(int i = 1; i <= length; i++)
    {
        for(int j = 0; j < 18 && i - j >= 1; j++)
        {
            long long this_segment = 0;
            for(int k = i - j; k <= i; k++)
            {
                this_segment = this_segment*10 + (S[k] - '0');
            }
            
            if(this_segment < K)
            {
                no_of_ways[i] += no_of_ways[i - j - 1];
                
                no_of_ways[i] %= MOD;
            }
            else
            {
                break;
            }
        }
    }
    
    cout << no_of_ways[length] << "\n";
}
 
int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
        
    return 0;
}
