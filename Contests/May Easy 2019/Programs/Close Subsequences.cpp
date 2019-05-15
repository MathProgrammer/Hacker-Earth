#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const int MAX_N = 1e5 + 5, MOD = 1e9 + 7;
    
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    vector <long long> good_sequences_ending_at(MAX_N, 0);
    vector <long long> bad_sequences_ending_at(MAX_N, 0);
    
    long long good_sequences = 0, bad_sequences = 0;
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        long long bad_sequences_turned_good = (bad_sequences_ending_at[A[i] - 1] + bad_sequences_ending_at[A[i]] + bad_sequences_ending_at[A[i] + 1])%MOD;
        
        long long new_good_sequences = (bad_sequences_turned_good + good_sequences)%MOD;
        
        good_sequences_ending_at[A[i]] = (good_sequences_ending_at[A[i]] + new_good_sequences)%MOD;
        
        good_sequences = (good_sequences + new_good_sequences)%MOD;
        
        long long new_bad_sequences = (bad_sequences + 1 - bad_sequences_turned_good + MOD)%MOD;
        
        bad_sequences_ending_at[A[i]] = (bad_sequences_ending_at[A[i]] + new_bad_sequences)%MOD;
        
        bad_sequences = (bad_sequences + new_bad_sequences)%MOD;
    }
    
    cout << good_sequences;
    return 0;
}
