#include <iostream>
#include <vector>
 
using namespace std;
 
const int MAX_N = 1e3 + 5, oo = 1e18;
long long A[MAX_N], B[MAX_N];
long long prefix_A[MAX_N], suffix_A[MAX_N];
long long prefix_B[MAX_N], suffix_B[MAX_N];
long long best_A[MAX_N], best_B[MAX_N];
 
int main()
{
    int no_of_elements, no_of_moves;
    cin >> no_of_elements >> no_of_moves;
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> B[i];
    }
    
    prefix_A[0] = 0;
    prefix_B[0] = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        prefix_A[i] = prefix_A[i - 1] + A[i];
        prefix_B[i] = prefix_B[i - 1] + B[i];
    }
    
    suffix_A[no_of_elements + 1] = 0;
    suffix_B[no_of_elements + 1] = 0;
    for(int i = no_of_elements; i >= 1; i--)
    {
        suffix_A[i] = suffix_A[i + 1] + A[i];
        suffix_B[i] = suffix_B[i + 1] + B[i];
    }
    
    best_A[0] = 0; best_B[0] = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        best_A[i] = -oo;
        best_B[i] = -oo;
        
        for(int prefix = 0, suffix = no_of_elements + 1 - i;
                    prefix <= i; prefix++, suffix++)
        {
            best_A[i] = max(best_A[i], prefix_A[prefix] + suffix_A[suffix]);
            
            best_B[i] = max(best_B[i], prefix_B[prefix] + suffix_B[suffix]);
        }
    }
    
    long long answer = 0;
    for(int part_A = 0, part_B = no_of_moves - part_A;
                part_A <= min(no_of_elements, no_of_moves);
                part_A++, part_B--)
    {
        if(part_B > no_of_elements)
        {
            continue;
        }
        
        answer = max(answer, best_A[part_A] + best_B[part_B]);
    }
    
    
    cout << answer << "\n";
    
    return 0;
}
