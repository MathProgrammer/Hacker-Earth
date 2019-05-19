#include <iostream>
 
using namespace std;
 
const int MAX_N = 1005, MAX_SUM = 1e5, MAX_LOG = 25;
int trie[MAX_SUM*MAX_LOG][2], largest = 1;
int sum[MAX_N], A[MAX_N];
 
int is_bit_set(long long x, long long position)
{
    return ( (x & (1LL << position) ) != 0);
}
 
void insert(int x)
{
    int p = 0;
    
    for(int bit = MAX_LOG; bit >= 0; bit--)
    {
        int current_bit = is_bit_set(x, bit);
        
        if(trie[p][current_bit] == 0)
        {
            trie[p][current_bit] = largest;
            
            largest++;
        }
        
        p = trie[p][current_bit];
    }
}
 
int maximum_xor_with(int x)
{
    int maximum_xor = 0, p = 0;
    
    for(int bit = MAX_LOG; bit >= 0; bit--)
    {
        int x_bit = is_bit_set(x, bit);
        int opposite_x_bit = !x_bit;
        
        if(trie[p][opposite_x_bit] != 0)
        {
            maximum_xor |= (1LL << bit);
            
            p = trie[p][opposite_x_bit];
        }
        else 
        {
            p = trie[p][x_bit];
        }
    }
    
    return maximum_xor;
}
 
int main() 
{
	int no_of_elements;
	cin >> no_of_elements;
	
	for(int i = 1; i <= no_of_elements; i++)
	    cin >> A[i];
	    
	sum[0] = 0;
	for(int i = 1; i <= no_of_elements; i++)
	    sum[i] = A[i] + sum[i - 1];
	
	insert(0);
	
	int answer = 0;
	for(int i = 2; i <= no_of_elements; i++)
	{
	    int second_left = i;
	    for(int second_right = second_left; second_right <= no_of_elements; second_right++)
	    {
	        int sum_here = sum[second_right] - sum[second_left - 1]; 
	        
	        answer = max(answer, maximum_xor_with(sum_here)); 
	    }
	    
	    int first_right = i;
	    for(int first_left = 1; first_left <= first_right; first_left++)
	    {
	        int sum_here = sum[first_right] - sum[first_left - 1];
	        
	        insert(sum_here);
	    }
	}
	
	cout << answer;
	return 0;
}
