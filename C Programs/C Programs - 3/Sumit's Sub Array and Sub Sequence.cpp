#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> A(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &A[i]);

    int positive_sum = 0, smallest_negative_number = -1e5;
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(A[i] > 0)
            positive_sum += A[i];
        else
            smallest_negative_number = max(smallest_negative_number, A[i]);
    }
    int largest_sum = (positive_sum == 0 ? smallest_negative_number : positive_sum);

    int largest_sum_ending_here = 0, largest_subarray_sum = A[1];
    for(int i = 1; i <= no_of_elements; i++)
    {
        largest_sum_ending_here = max(A[i], A[i] + largest_sum_ending_here);
        largest_subarray_sum = max(largest_sum_ending_here, largest_subarray_sum);
    }

    printf("%d %d\n", largest_subarray_sum, largest_sum);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
