#include <stdio.h>

long long find_no_of_workouts(long long);
void raise_matrix_power(long long[][2], long long);
void multiply(long long [][2], long long [][2]);
void copy(long long [][2], long long [][2]);

const long mod = 1e9 + 7;

int main()
{
    int no_of_test_cases, i;
    long long no_of_days, no_of_workouts;

    scanf("%d",&no_of_test_cases);
    for(i = 1; i <= no_of_test_cases; i++)
    {
        scanf("%lld",&no_of_days);
        no_of_workouts = find_no_of_workouts(no_of_days);
        printf("%I64d\n",no_of_workouts);
    }
    return 0;
}

long long find_no_of_workouts(long long no_of_days)
{
    //If the first day is a rest day, remaining is T(n-1) days. If the first day is working, second has to be rest = T(n-2) days
    //T(n) = T(n-1) + T(n-2)
    /*
    | T(n)   | = |1  1| |T(n-1)|
    | T(n-1) |   |1  0| |T(n-2)|

    There is a correspondence in between T(n) and the Fibonacci number F(n+2) since T(0) = F(2) and T(1) = F(3) and both series follow the same recurrence.
    This allows us to formally define T(-1) = F(1) even if it does not make sense in our problem.
    | T(n)  | = A^{n} |T(0) |
    | T(n-1)| =       |T(-1) |,
    T(1) = 2, T(0) = 1, T(-1) = F(1) = 1*/

    long long dp_matrix[2][2];
    dp_matrix[0][0] = dp_matrix[0][1] = dp_matrix[1][0] = 1;
    dp_matrix[1][1] = 0;

    raise_matrix_power(dp_matrix, no_of_days);
    return (dp_matrix[0][0]*1LL + dp_matrix[0][1]*1LL)%mod;
}

//Binary exponentiation
void raise_matrix_power(long long matrix[][2], long long exponent)
{
    long long answer[2][2];

    /*Initialise it to identity Answer = I_2*/
    answer[0][0] = answer[1][1] = 1LL;
    answer[0][1] = answer[1][0] = 0LL;

    while(exponent > 0)
    {
        if(exponent%2 == 1)
        {
            multiply(answer, matrix);//Answer = Answer*A
        }
        multiply(matrix, matrix); //A = A*A
        exponent = exponent >> 1;
    }

    copy(matrix, answer);
}

void multiply(long long matrix_1[][2], long long matrix_2[][2])
{
    short i, j, k;
    long long product[2][2];

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            product[i][j] = 0;
            for(k = 0; k < 2; k++)
            {
                product[i][j] += (matrix_1[i][k]*matrix_2[k][j])%mod;
                product[i][j] = (product[i][j]% mod);
            }
        }
    }

    copy(matrix_1, product);
}

void copy(long long matrix_1[][2], long long matrix_2[][2])
{
    short i, j;

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            matrix_1[i][j] = matrix_2[i][j];
        }
    }
}
