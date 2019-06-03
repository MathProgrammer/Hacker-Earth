#include <iostream>
 
using namespace std;
 
void solve()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    const int oo = 1e9 + 9;
    int maximum = -oo, minimum = oo;
    
    while(no_of_elements--)
    {
        int element;
        cin >> element;
        
        maximum = max(maximum, element);
        minimum = min(minimum, element);
    }
    
    cout << maximum + minimum << "\n";
}
 
int main() 
{
	int no_of_tests;
	cin >> no_of_tests;
	
	while(no_of_tests--)
	    solve();
	    
	return 0;
}
