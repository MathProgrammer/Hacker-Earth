#include <iostream>
#include <string>

using namespace std;

int main()
{
    int length;
    string A;

    cin >> length >> A;

    const int NO_OF_ALPHABETS = 26;
    int max_frequency[NO_OF_ALPHABETS];

    for(int i = 0; i < NO_OF_ALPHABETS; i++)
        cin >> max_frequency[i];

    int left_ans = -1, right_ans = -1, max_length = 0;

    int window_start = 0, window_end = -1;

    char excess_character = 'a';

    int frequency[NO_OF_ALPHABETS] = {0};

    while(window_end < length)
    {
        while(frequency[excess_character - 'a'] > max_frequency[excess_character - 'a'])
        {
            frequency[A[window_start] - 'a']--;
            window_start++;
        }

        int window_length = window_end - window_start + 1;

        if(window_length > max_length)
        {
            left_ans = window_start, right_ans = window_end;
            max_length = window_length;
        }

        window_end++;

        frequency[A[window_end] - 'a']++;

        if(frequency[A[window_end] - 'a'] > max_frequency[A[window_end] - 'a'])
            excess_character = A[window_end];
    }

    if(left_ans == -1)
        cout << "No Solution";
    else
        cout << left_ans + 1 << " " << right_ans + 1;

    return 0;
}
