#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve()
{
    string S;
    cin >> S;

    const int NO_OF_ALPHABETS = 26;
    vector <int> frequency(NO_OF_ALPHABETS, 0);
    for(int i = 0; i < S.size(); i++)
        frequency[S[i] - 'a']++;

    const int MOD = 1e9 + 7;
    long long no_of_subsequences = 1;

    for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
        if(frequency[alpha] != 0)
            no_of_subsequences = (no_of_subsequences*frequency[alpha])%MOD;

    cout << no_of_subsequences << endl;
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
