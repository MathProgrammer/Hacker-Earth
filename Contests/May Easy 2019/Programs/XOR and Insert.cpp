#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 5e5 + 5, LOG_MAX = 30;
int trie[MAX_N*LOG_MAX][2], overall_xor = 0, largest = 1;

int is_bit_set(long long n, long long position)
{
    return ( (n& (1LL << position)) != 0);
}

void insert(int x)
{
    int p = 0;

    for(int bit = 30; bit >= 0; bit--)
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

int get_minimum_xor_with(int x)
{
    int answer = 0, p = 0;

    for(int bit = 30; bit >= 0; bit--)
    {
        int current_bit = is_bit_set(x, bit);
        int other_bit = !current_bit;

        if(trie[p][current_bit] != 0)
        {
            p = trie[p][current_bit];
        }
        else
        {
            p = trie[p][other_bit];
            answer |= (1 << bit);
        }
    }

    return answer;
}

void answer()
{
    const int INSERT = 1, XOR_ALL = 2, FIND_MINIMUM = 3;
    int query_type;
    cin >> query_type;

    switch(query_type)
    {
        case INSERT : int element;
                      cin >> element;
                      element ^= overall_xor;
                      insert(element);
                      break;

        case XOR_ALL : int x;
                       cin >> x;
                       overall_xor ^= x;
                       break;

        case FIND_MINIMUM : cout << get_minimum_xor_with(overall_xor) << "\n";
                            break;

        default : cout << "Invalid Query\n";
    }
}

int main()
{
    memset(trie, 0, sizeof(trie));
    insert(0);

	int no_of_queries;
	cin >> no_of_queries;

	while(no_of_queries--)
	    answer();

	return 0;
}
