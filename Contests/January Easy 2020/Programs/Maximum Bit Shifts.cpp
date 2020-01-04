#include <iostream>
#include <vector>
 
using namespace std;
 
int is_bit_set(long long n, int bit)
{
    return ( (n & (1LL << bit)) != 0 );
}
 
int count_ones(long long n)
{
    int ones = 0;
    
    while(n)
    {
        ones += n%2;
        
        n /= 2;
    }
    
    return ones;
}
 
int count_bits(long long n)
{
    int bits = 0;
    
    while(n)
    {
        bits++;
        
        n /= 2;
    }
    
    return bits;
}
 
int main()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    vector <long long> B(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        int no_of_ones = count_ones(A[i]), total_bits = count_bits(A[i]);
        
        for(int bit = total_bits - 1; bit >= 0; bit--)
        {
            if(no_of_ones > 0)
            {
                B[i] |= (1LL << bit);
                
                no_of_ones--;
            }
        }
    }
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        cout << B[i] << " ";
    }
    
    return 0;
}
