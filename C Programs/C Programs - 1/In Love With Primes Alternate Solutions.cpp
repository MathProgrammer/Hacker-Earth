#include <cstdio>

int main()
{
    int no_of_cakes;
    scanf("%d", &no_of_cakes);

    while(no_of_cakes--)
    {
        int weight;
        scanf("%d", &weight);

        printf(weight == 2 ?  "Arjit\n": "Deepa\n");
    }

    return 0;
}
