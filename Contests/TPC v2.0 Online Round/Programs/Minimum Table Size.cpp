#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    const long long oo = 1e6;
    
    set <long long> powers;
    
    
    int no_of_elements, power;
    cin >> no_of_elements >> power;
    
    for(long long p = power; p <= oo; p *= power)
    {
        powers.insert(p);
    }
    
    long long total_cost = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        int x;
        cin >> x;
        
        auto it = upper_bound(powers.begin(), powers.end(), x - 1);
    
        total_cost += *it;
    }
    
    cout << total_cost << "\n";
    
    return 0;
}
