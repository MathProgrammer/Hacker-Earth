#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements; 

    int sum = 0;
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];

        sum += A[i]; //cout << "Sum = " << sum << "\n";
    }

    vector <int> reachable(sum + 1, false);
    vector <int> reachable_before(sum + 1, false);
    reachable[0] = true;

    for(int i = 1; i <= no_of_elements; i++)
    {   //cout << "i = " << i << "\n";
        for(int j = 0; j <= sum; j++)
        {
            reachable_before[j] = reachable[j];
        }

        for(int s = A[i]; s <= sum; s++)
        {
            if(reachable_before[s - A[i]])
            {
                reachable[s] = true;
                //cout << s << " is reachable\n";
            }
        }
    }

    for(int i = 1; i <= no_of_elements; i++)
    {
        int possible = false;

        for(long long p = A[i]; p <= sum/A[i]; p *= A[i])
        {   //cout << "P = " << p << "\n";
            if(reachable[p*A[i]])
            {
                possible = true;
            }

            if(possible || A[i] == 1)
            {
                break;
            }
        }

        cout << (possible ? 1 : 0) << " ";
    }

    cout << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
