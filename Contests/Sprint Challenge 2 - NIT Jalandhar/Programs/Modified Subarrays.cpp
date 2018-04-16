#include <iostream>
#include <vector>
#include <algorithm>

typedef long long LL;
using namespace std;

void solve()
{
    int no_of_elements, no_of_segments;
    cin >> no_of_elements >> no_of_segments;

    vector <LL> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        cin >> A[i];

    vector <int> ending(no_of_segments + 1);
    ending[0] = 0;
    for(int i = 1; i <= no_of_segments; i++)
        cin >> ending[i];

    const LL oo = 1e16;
    vector <LL> max_starting_from(no_of_elements + 1);
    vector <LL> best_add_option(no_of_segments + 2, -oo);
    vector <LL> best_subtract_option(no_of_segments + 2, -oo);

    best_add_option[no_of_segments + 1] = best_subtract_option[no_of_segments + 1] = 0;

    for(int i = ending[no_of_segments]; i > ending[no_of_segments - 1]; i--)
    {
        max_starting_from[i] = A[i];
        best_add_option[no_of_segments] = max(best_add_option[no_of_segments], A[i]);
        best_subtract_option[no_of_segments] = max(best_subtract_option[no_of_segments], -A[i]);
    }

    for(int segment = no_of_segments - 1; segment > 0; segment--)
    {
        for(int i = ending[segment]; i > ending[segment - 1]; i--)
        {
            max_starting_from[i] = max(A[i] + best_subtract_option[segment + 1], -A[i] + best_add_option[segment + 1]);

            best_add_option[segment] = max(best_add_option[segment], A[i] + max_starting_from[i]);
            best_subtract_option[segment] = max(best_subtract_option[segment], -A[i] + max_starting_from[i]);
        }
    }

    LL answer = -oo;

    for(int i = 1; i <= ending[1]; i++)
        answer = max(answer, max_starting_from[i]);

    cout << answer << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
