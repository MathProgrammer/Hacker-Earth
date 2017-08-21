#include <cstdio>
#include <vector>
#include <cstring>

#define MAX_LENGTH 50 + 2
using namespace std;

int main()
{
    char string[MAX_LENGTH];
    scanf("%s", string);

    typedef vector <int> v_int;
    vector <v_int> is_palindrome(MAX_LENGTH, v_int(MAX_LENGTH, false));

    int no_of_palindromic_substrings = 0;

    for(int i = 0; string[i] != '\0'; i++)
    {
        is_palindrome[i][i] = true;
        no_of_palindromic_substrings++;
    }

    int string_length = strlen(string);
    for(int length = 2; length <= string_length; length++)
    {
        int start = 0, end = start + (length - 1);
        for(;end < string_length; start++, end++)
        {
            if(string[start] == string[end])
            {
                if(start + 1 == end || is_palindrome[start + 1][end - 1])
                {
                    is_palindrome[start][end] = true;
                    no_of_palindromic_substrings++;
                }
            }
        }
    }

    printf("%d\n", no_of_palindromic_substrings);
    return 0;
}

