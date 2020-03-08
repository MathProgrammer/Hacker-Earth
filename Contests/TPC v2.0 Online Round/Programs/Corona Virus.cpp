#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int length;
    string S;
    cin >> length >> S;
    
    const int MOD = 1e9 + 7;
    vector <long long> no_of_ways(length + 1);
    for(int i = 0; i < length; i++)
    {
        int ones_here = 0;
        
        for(int j = i; j >= 0 && ones_here <= 2; j--)
        {
            ones_here += (S[j] == '1');
            
            if(ones_here == 2)
            {
                if(j >= 1)
                {
                    no_of_ways[i] += no_of_ways[j - 1];
                }
                else
                {
                    no_of_ways[i]++;
                }
            }
        }
        
        no_of_ways[i] %= MOD;
    }
    
    long long answer = no_of_ways[length - 1];
    
    if(no_of_ways[length - 1] == 0)
    {
        answer = -1;
    }
    
    cout << answer << "\n";
    
    return 0;
}
