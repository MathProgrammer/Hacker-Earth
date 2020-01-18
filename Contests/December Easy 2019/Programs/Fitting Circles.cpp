#include <iostream>
 
using namespace std;
 
void solve()
{
    long long length, width;
    cin >> length >> width;
    
    if(width > length)
    {
        swap(width, length);
    }
    
    cout << length/width << "\n";
}
 
int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
        
    return 0;
}
