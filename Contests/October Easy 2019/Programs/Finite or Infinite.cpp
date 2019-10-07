#include <iostream>
#include <algorithm>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    int array_gcd;
    for(int i = 1; i <= no_of_elements; i++)
    {
        int element;
        cin >> element;
        
        array_gcd = (i == 1 ? element : __gcd(array_gcd, element));
    }
    
    cout << (array_gcd == 1 ? "FINITE\n" : "INFINITE\n");
}

int main() 
{
	int no_of_test_cases;
	cin >> no_of_test_cases;
	
	while(no_of_test_cases--)
	    solve();
	
	return 0;
}
