#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int MAX_N = 1e3 + 5;
int LPS_A[MAX_N][MAX_N], LPS_B[MAX_N][MAX_N];
int max_palindrome_from[MAX_N], max_palindrome_ending[MAX_N];
int LPS_AB[MAX_N][MAX_N];

void get_LPS(string &S, int LPS[][MAX_N])
{
    memset(LPS, 0, sizeof(LPS));

    for(int length = 1; length < S.size(); length++)
    {
        for(int left = 0, right = left + length - 1; right < S.size(); left++, right++)
        {
            if(length == 1)
            {
                LPS[left][right] = 1;
                continue;
            }

            if(length == 2)
            {
                if(S[left] == S[right])
                    LPS[left][right] = 2;

                continue;
            }

            if(S[left] == S[right] && LPS[left + 1][right - 1] != 0)
            {
                LPS[left][right] = 2 + LPS[left + 1][right - 1];
            }
        }
    }
}

int main()
{
    string A, B;
    cin >> A >> B;

    get_LPS(A, LPS_A);
    get_LPS(B, LPS_B);

    for(int left = 0; left < A.size(); left++)
    {
        max_palindrome_from[left] = 1;

        for(int right = left + 1; right < A.size(); right++)
            max_palindrome_from[left] = max(max_palindrome_from[left], LPS_A[left][right]);

    }

    for(int right = B.size() - 1; right >= 0; right--)
    {
        max_palindrome_ending[right] = 1;

        for(int left = right - 1; left >= 0; left--)
            max_palindrome_ending[right] = max(max_palindrome_ending[right], LPS_B[left][right]);
    }

    for(int left = A.size() - 1; left >= 0; left--)
    {
        for(int right = 0; right < B.size(); right++)
        {
            LPS_AB[left][right] = 0;

            if(A[left] != B[right]) continue;

            if(left == A.size() - 1 || right == 0)
            {
                LPS_AB[left][right] = 2;
            }
            else
            {
                LPS_AB[left][right] = 2 + LPS_AB[left + 1][right - 1];
            }
        }
    }

    int answer = 0;
    for(int left = 0; left < A.size(); left++)
    {
        for(int right = B.size() - 1; right >= 0; right--)
        {
            int palindrome_in_A = max_palindrome_from[left + LPS_AB[left][right]/2];
            int palindrome_in_B = max_palindrome_ending[right - LPS_AB[left][right]/2];

            int larger_length = max(palindrome_in_A, palindrome_in_B);

            LPS_AB[left][right] += larger_length;

            answer = max(answer, LPS_AB[left][right]);
        }
    }

    cout << answer;
    return 0;
}

