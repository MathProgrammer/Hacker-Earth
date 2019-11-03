#include <iostream>
#include <vector>
#include <algorithm>
 
#define all(v) (v).begin(), (v).end()
using namespace std;
 
int main()
{
    int no_of_elements, no_of_queries; 
    cin >> no_of_elements >> no_of_queries; 
    
    int array_gcd;
    for(int i = 1; i <= no_of_elements; i++)
    {
        int x;
        cin >> x;
        array_gcd = (i == 1 ? x : __gcd(array_gcd, x));
    }
    
    for(int i = 1; i <= no_of_queries; i++)
    {
        int P;
        cin >> P;
        cout << (P%array_gcd == 0 ? "YES\n" : "NO\n");
    }
    
    return 0;
}
