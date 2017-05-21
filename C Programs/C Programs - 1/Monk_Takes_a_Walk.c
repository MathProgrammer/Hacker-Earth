#include <stdio.h>
#define MAX_LENGTH 100000
#define true 1
#define false 0

int isVowel(char ch)
{
    switch(ch)
    {
        case 'A' : case 'a' :
        case 'E' : case 'e' :
        case 'I' : case 'i' :
        case 'O' : case 'o' :
        case 'U' : case 'u' : return true;
    }
    return false;
}

void solve()
{
    int bad_tree_count = 0, i;
    char garden[MAX_LENGTH + 1];
    scanf("%s", garden);

    for(i = 0; garden[i] != '\0'; i++)
    {
        if(isVowel(garden[i]))
        {
            bad_tree_count++;
        }
    }

    printf("%d\n", bad_tree_count);
}
int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases-- != 0)
    {
        solve();
    }
    return 0;
}
