#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int length, no_of_queries;
    cin >> length >> no_of_queries;

    char house[length + 1]; cin >> (house + 1);

    vector <int> no_of_changes_till(length + 1, 0);
    for(int i = 2; i <= length; i++)
    {
        no_of_changes_till[i] = no_of_changes_till[i - 1] + (house[i] != house[i - 1]);
    }

    while(no_of_queries--)
    {
        int left, right;
        cin >> left >> right;

        if(left > right) swap(left, right);

        int clockwise_answer = no_of_changes_till[right] - no_of_changes_till[left];

        int anti_clockwise_answer = (no_of_changes_till[length] - no_of_changes_till[right])
                                +  (no_of_changes_till[left] - no_of_changes_till[1])
                                +  (house[length] != house[1]);

        int answer = min(clockwise_answer, anti_clockwise_answer);
         cout << answer << "\n";
    }
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
