#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> permutation(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        cin >> permutation[i];

    const int oo = 1e9 + 9;
    vector <int> answer(no_of_elements + 1, oo);

    deque <int> Q;
    Q.push_back(1);
    answer[1] = 0;

    while(Q.size())
    {
        int x = Q.front();
        Q.pop_front();

        if(answer[permutation[x]] > answer[x])
        {
            answer[permutation[x]] = answer[x];
            Q.push_front(permutation[x]);
        }
        if(x - 1 > 0 && answer[x - 1] > answer[x] + 1)
        {
            answer[x - 1] = answer[x] + 1;
            Q.push_back(x - 1);
        }
        if(x + 1 <= no_of_elements && answer[x + 1] > answer[x] + 1)
        {
            answer[x + 1] = answer[x] + 1;
            Q.push_back(x + 1);
        }
    }

    cout << answer[no_of_elements] << "\n";
}

int main()
{
	int no_of_tests;
	cin >> no_of_tests;

	while(no_of_tests--)
	    solve();

	return 0;
}
