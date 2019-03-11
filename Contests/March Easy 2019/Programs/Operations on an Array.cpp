#include <iostream>
#include <vector>
 
using namespace std;
 
long long moves_if_equal_to(vector <int> &A, int x)
{
    long long moves = 0;
    
    for(int i = 0; i < A.size(); i++)
    {
        long long moves_here = min(A[i], abs(x - A[i]));
        
        moves += moves_here;
    }
    
    return moves;
}
 
int main()
{
    int n;
    cin >> n;
    
    vector <int> A(n);
    for(int i = 0; i < n; i++)
        cin >> A[i];
        
    const long long oo = 1e15;
    long long minimum_moves = oo;
    for(int i = 0; i < n; i++)
        minimum_moves = min(minimum_moves, moves_if_equal_to(A, A[i]));
        
    cout << minimum_moves;
    return 0;
}
