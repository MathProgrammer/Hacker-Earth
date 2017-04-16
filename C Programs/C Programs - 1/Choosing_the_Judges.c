#include <stdio.h>
#include <stdlib.h>

unsigned int max(unsigned int, unsigned int);
void read(unsigned int *, unsigned int);
unsigned int find_maximum_score(unsigned int *, unsigned int);

int main()
{
    short no_of_test_cases, i;
    unsigned int no_of_judges, maximum_score;
    scanf("%hu",&no_of_test_cases);
    for(i = 1; i <= no_of_test_cases; i++)
    {
        scanf("%u",&no_of_judges);
        unsigned int *score_given = malloc(no_of_judges*sizeof(no_of_judges));
        read(score_given, no_of_judges);
        maximum_score = find_maximum_score(score_given, no_of_judges);
        printf("Case %u: %u\n",i, maximum_score);
        free(score_given);
    }
    return 0;
}

unsigned int find_maximum_score(unsigned int *score_given, unsigned int no_of_judges)
{
    unsigned int i, maximum_score_i, maximum_score_i_minus_1, maximum_score_i_minus_2;

    /*Let f(x) be the maximum score that can be gotten till judge x.
    f(0) = 0  - If there are no judges, no point can be scored.
    f(1) = A[1] - If there is one judge, his score is the maximum.
    f(i) = max{f(i-1), f(i-2) + A[i]}
    Either the i-th judge is not selected. Then f(i) = f(i-1)
    Or the i-th judge is selected. Then f(i) = A[i] + f(i - 2)
    We choose the greater of these values.
    Answer is f(n), n is the number of judges.*/
    maximum_score_i_minus_2 = 0; //If the number of judges is 0, 0 points can be gotten
    maximum_score_i_minus_1 = *(score_given + 0); //If the number of judges is 1, 1 point can be gotten
    maximum_score_i = *(score_given + 0);

    for(i = 1; i < no_of_judges; i++)
    {
        maximum_score_i = max(maximum_score_i_minus_1, maximum_score_i_minus_2 + *(score_given + i));

        maximum_score_i_minus_2 = maximum_score_i_minus_1;
        maximum_score_i_minus_1 = maximum_score_i;
    }
    return maximum_score_i;
}

void read(unsigned int *score_given, unsigned int no_of_judges)
{
    unsigned int i;
    for(i = 0; i < no_of_judges; i++)
    {
        scanf("%u", (score_given + i));
    }
}

unsigned int max(unsigned int a, unsigned int b)
{
    return (a > b ? a : b);
}
