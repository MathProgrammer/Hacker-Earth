#include <stdio.h>

#define swap(a, b) {a = a^b; b = b^a; a = a^b;}
#define SIZE 1000000
int is_Prime[SIZE + 1], sum_of_primes_till[SIZE + 1];

int main()
{
    int no_of_queries, left, right, i, multiple;

    for(i = 0; i <= SIZE; is_Prime[i++] = 1);

    //Sieve of Erathosthenes
    is_Prime[0] = is_Prime[1] = 0;
    for(i = 2; i*i <= SIZE; i++)
        if(is_Prime[i] == 1)
            for(multiple = 2; i*multiple <= SIZE; multiple++)
                is_Prime[i*multiple] = 0;


    sum_of_primes_till[0] = 0;
    for(i = 1; i <= SIZE; i++)
        sum_of_primes_till[i] = is_Prime[i] + sum_of_primes_till[i-1];

    scanf("%d", &no_of_queries);

    while(no_of_queries-- != 0)
    {
        scanf("%d %d",&left, &right);

        if(left > right)
            swap(left, right);

        printf("%d\n", sum_of_primes_till[right] - sum_of_primes_till[left - 1]);
    }
}
