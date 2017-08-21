#include <cstdio>
#include <vector>
#include <cstring>

#define MAX_LENGTH 1000 + 2
using namespace std;

void solve()
{
    char string[MAX_LENGTH];
    scanf("%s", string);

    int string_length = strlen(string);
    typedef vector <int> v_int;
    vector <v_int> is_palindrome(string_length, v_int(string_length, false));

    long long strength = 0;
    for(int i = 0; string[i] != '\0'; i++)
    {
        is_palindrome[i][i] = true;
        strength += 1*1;
    }

    for(int length = 2; length <= string_length; length++)
    {
        for(int start = 0, end = start + (length - 1); end < string_length; start++, end++)
        {
            if(string[start] == string[end])
            {
                if(start + 1 == end || is_palindrome[start + 1][end - 1])
                {
                    is_palindrome[start][end] = true;
                    strength += length*length;
                }
            }
        }
    }

    printf("%lld\n", strength);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}

