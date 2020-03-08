#include <iostream>
#include <vector>
#include <map>

using namespace std;

const long long oo = 1e18;
vector <long long> powers;

void precompute()
{
    powers.push_back(1);
    
    while(powers.back() < oo/3)
    {
        powers.push_back(powers.back()*3);
    }
}

void solve()
{
    long long n, no_of_tribits;
    cin >> n >> no_of_tribits;
    
    long long temp_n = n;
    int tribits = 0;
    
    for(int i = powers.size() - 1; i >= 0; i--)
    {
        while(temp_n >= powers[i])
        {
            temp_n -= powers[i];
            
            tribits++;
        }
    }
    
    if(tribits > no_of_tribits || no_of_tribits > n)
    {
        cout << "NO\n";
        
        return;
    }
    
    cout << (no_of_tribits%2 == tribits%2 ? "YES\n" : "NO\n");
}

int main()
{
    precompute();
    
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
