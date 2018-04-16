#include <cstdio>
#include <vector>
#include <algorithm>

#define max_3(a, b, c) max(a, max(b, c))

const int N = 1e5 + 1;
int A[N], ones[N], twos[N], threes[N], no_of_elements;

using namespace std;

int is_possible(int x)
{
    for(int i = 1; i + x - 1 <= no_of_elements; i++)
    {
        int ones_here = ones[i + x - 1] - ones[i - 1];
        int twos_here = twos[i + x - 1] - twos[i - 1];
        int threes_here = threes[i + x - 1] - threes[i - 1];

        if( (ones_here == x || twos_here == x || threes_here == x) && no_of_elements - x >= 2) return true;

        if(ones_here == x - 1 && twos_here == 1 && no_of_elements - x >= 1) return true;

        if(twos_here == x - 1 && (ones_here = 1 || threes_here == 1) && no_of_elements - x >= 1) return true;

        if(twos_here == x - 2  && ones_here == 1 && threes_here == 1) return true;

        if(threes_here == x - 1 && twos_here == 1 && no_of_elements - x >= 1) return true;
    }

    return false;
}

void solve()
{
    scanf("%d", &no_of_elements);

    ones[0] = twos[0] = threes[0] = 0;

    for(int i = 1; i <= no_of_elements; i++)
    {
        scanf("%d", &A[i]);

        ones[i] = (A[i] == 1) + ones[i - 1];
        twos[i] = (A[i] == 2) + twos[i - 1];
        threes[i] = (A[i] == 3) + threes[i - 1];
    }

    int start = 1, end = no_of_elements, answer;

    while(start <= end)
    {
        int mid = (start + end) >> 1;

        if(is_possible(mid))
        {
            if(!is_possible(mid + 1))
            {
                answer = mid;
                break;
            }
            else
            {
                start = mid + 1;
            }
        }
        else
        {
            end = mid - 1;
        }
    }

    printf("%d\n", answer);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
