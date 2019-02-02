#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve()
{
    int pile_1, pile_2;
    cin >> pile_1 >> pile_2;

    cout << (pile_1%2 == 1 && pile_2%2 == 1 ? "Jeel\n" : "Ashish\n");
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}

