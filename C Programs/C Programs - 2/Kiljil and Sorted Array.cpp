#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int no_of_numbers, number_i;
	scanf("%d", &no_of_numbers);

	int max_so_far = 0;
	long long added_amount = 0;
	for(int i = 1; i <= no_of_numbers; i++)
	{
		scanf("%d", &number_i);

		if(number_i <= max_so_far)
		{
			added_amount += (max_so_far + 1) - number_i;
		}

		max_so_far = max(max_so_far+1, number_i);
	}
	printf("%lld\n", added_amount);
	return 0;
}
