#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int no_of_elements; 
    cin >> no_of_elements; 

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    set <int> LIS;
    for(int i = no_of_elements; i >= 1; i--)
    {
        if(LIS.size() == 0 || A[i] > *(LIS.rbegin()) )
        {
            LIS.insert(A[i]);
        }
        else 
        {
            auto first_greater_it = LIS.lower_bound(A[i]);

            LIS.erase(first_greater_it);

            LIS.insert(A[i]);
        }
    }

    cout << LIS.size() << "\n";
}

int main() 
{
    int no_of_test_cases; 
    cin >> no_of_test_cases; 

    while(no_of_test_cases--)
        solve();

    return 0;
}
