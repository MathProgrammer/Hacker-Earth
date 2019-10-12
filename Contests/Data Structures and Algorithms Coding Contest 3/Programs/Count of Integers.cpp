#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
    const int MAX_N = 1e6 + 5;
    vector <int> no_of_factors(MAX_N, 0);
    
    for(int i = 1; i < MAX_N; i++)
    {
        for(int m = i; m < MAX_N; m += i)
        {
            no_of_factors[m]++;
        }
    }
    
    vector <int> largest_prime_factor(MAX_N, 0);
    vector <int> euler_totient(MAX_N, 0);
    euler_totient[1] = 1;
    for(int i = 2; i < MAX_N; i++)
    {
        if(largest_prime_factor[i] == 0)
        {
            for(int m = i; m < MAX_N; m += i)
            {
                largest_prime_factor[m] = i;
            }
        }
        
        int p_power_n = 1, reduced_i = i;
        
        while(reduced_i%largest_prime_factor[i] == 0)
        {
            reduced_i /= largest_prime_factor[i];
            
            p_power_n *= largest_prime_factor[i];
        }
        
        euler_totient[i] = (p_power_n - p_power_n/largest_prime_factor[i])*euler_totient[reduced_i];
        
    }
    
    int no_of_queries;
    cin >> no_of_queries;
    
    while(no_of_queries--)
    {
        int n;
        cin >> n;
        
        cout << (n - no_of_factors[n] - euler_totient[n] + 1) << "\n";
    }
    
    return 0;
}
