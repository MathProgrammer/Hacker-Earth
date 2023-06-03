#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    const int MAX_A = 1e3 + 5;
    vector <int> frequency(MAX_A);
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];

        frequency[A[i]]++;
    }

    vector <int> final_A;
    final_A.push_back(0);
    const int ALICE = 0, BOB = 1;
    vector <vector <int> > difference(MAX_A, vector <int> (2, 0));
    for(int i = 1; i < MAX_A; i++)
    {
        if(frequency[i] == 1)
        {
            difference[i][ALICE] = difference[i - 1][BOB] + i;
            difference[i][BOB] =  difference[i - 1][ALICE] - i;
        }
        else
        {
            difference[i][ALICE] = difference[i - 1][ALICE];
            difference[i][BOB] =  difference[i - 1][BOB];
        }
    }

    cout << (difference[MAX_A - 1][ALICE] > 0 ? "Alex" : "Bob") << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
