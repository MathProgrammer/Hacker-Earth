#include <iostream>
#include <vector>
 
using namespace std;
 
const int MAX_N = 1e6 + 5;
long long answer[MAX_N], line[MAX_N], value[2*MAX_N];
 
int get_value(int n)
{
    int even = 0, odd = 0;
 
    while(n)
    {
        int digit = n%10;
 
        if(digit%2 == 0)
        {
            even += digit;
        }
        else 
        {
            odd += digit;
        }
 
        n /= 10;
    }
 
    int value = abs(even - odd);
 
    return value;
}
 
void precompute_answer()
{
    for(int i = 1; i < 2*MAX_N; i++)
    {
        value[i] = get_value(i);
    }
 
    line[1] = 2;
    line[2] = 2*value[3] + value[4];
    for(int i = 3; i < MAX_N; i++)
    {
        /* Line (i - 1) ranges from [i, 2i - 3] and (2i - 2)
           Line (i) ranges from [i + 1, 2i - 1] and (2i)*/
 
        line[i] = line[i - 1] + 
                2*(-value[i] + value[2*i - 2] + value[2*i - 1])
                + (-value[2*i - 2] + value[2*i]);
    }
 
    answer[1] = 2;
    for(int i = 2; i < MAX_N; i++)
    {
        answer[i] = answer[i - 1] + line[i];
    }
}
 
void solve()
{
    int n;
    cin >> n;
 
    cout << answer[n] << "\n";
}
 
int main()
{
    precompute_answer();
 
    int no_of_test_cases;
    cin >> no_of_test_cases;
 
    while(no_of_test_cases--)
    {
        solve();
    }
 
    return 0;
}
