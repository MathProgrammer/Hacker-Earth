#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
void solve()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        cin >> A[i];
        
    vector <int> max_till(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
        max_till[i] = max(max_till[i - 1], A[i]);
        
    vector <int> min_from(no_of_elements + 1);
    min_from[no_of_elements] = A[no_of_elements];
    for(int i = no_of_elements - 1; i >= 1; i--)
        min_from[i] = min(min_from[i + 1], A[i]);
    
    int no_of_break_points = 0;
    for(int i = 1; i < no_of_elements; i++)
    {
        no_of_break_points += (max_till[i] < min_from[i + 1]);
    }
    
    cout << (no_of_break_points%2 == 0 ? "Ashish\n" : "Jeel\n");
}
 
int main() 
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
 
    while(no_of_test_cases--)
        solve();
 
    return 0;
}
