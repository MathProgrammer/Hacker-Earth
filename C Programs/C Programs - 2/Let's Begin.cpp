#include <cstdio>
#include <vector>
#define min_4(a, b, c, d) min( (min(a, b)), (min(c, d)) )

using namespace std;

int main()
{
    vector <int> minimum_number_of_summands(1e6 + 1, 0);
    minimum_number_of_summands[0] = 0, minimum_number_of_summands[1] = -1;
    //Primes
    minimum_number_of_summands[2] = minimum_number_of_summands[3] = 1;
    minimum_number_of_summands[5] = minimum_number_of_summands[7] = 1;

    minimum_number_of_summands[6] = minimum_number_of_summands[4] = 2;
    minimum_number_of_summands[8] = 2;

    for(int i = 9; i <= 1e6; i++)
    {
        minimum_number_of_summands[i] =1 +  min_4(minimum_number_of_summands[i - 2], minimum_number_of_summands[i - 3],
                                            minimum_number_of_summands[i - 5], minimum_number_of_summands[i -7]);
    }

    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
    {
        int number;
        scanf("%d", &number);

        printf("%d\n", minimum_number_of_summands[number]);
    }

    return 0;
}

