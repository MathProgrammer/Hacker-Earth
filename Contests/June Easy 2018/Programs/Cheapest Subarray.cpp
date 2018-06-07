#include <cstdio>
#include <vector>

using namespace std;

void solve()
{
    int n;
    scanf("%d", &n);

    vector <int> A(n);
    for(int i = 0; i < n; i++) scanf("%d", &A[i]);

    const int oo = 2e9;
    int answer = oo;

    for(int i = 0; i + 1 < n; i++)
    {
        answer = min(answer, A[i] + A[i + 1]);
    }

    printf("%d\n", answer);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}

