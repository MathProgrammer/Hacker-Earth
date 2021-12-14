#include <iostream>

using namespace std; 

long long ceil(long long numerator, long long denominator)
{
	return (numerator/denominator) + (numerator%denominator != 0);
}

long long max_min_difference(long long a, long long b, long long c)
{
	long long maximum = max(a, max(b, c));
	long long minimum = min(a, min(b, c));

	return (maximum - minimum);
}

void solve()
{
	long long height, width; 
	cin >> height >> width; 

	const long long oo = 1e18;
	long long answer = oo;

	for(long long i = 1; i <= height; i++)
	{
		long long remaining_height = (height - i);

		long long other_2_perpendicular = max_min_difference(i*width,remaining_height*ceil(width, 2), remaining_height*(width/2));

		long long all_3_parallel = (remaining_height == 1 ? oo : max_min_difference(i, ceil(remaining_height, 2), remaining_height/2)*width);

		long long min_here = min(all_3_parallel, other_2_perpendicular);

		answer = min(answer, min_here);
	}

	for(int i = 1; i <= width; i++)
	{
		long long remaining_width = (width - i);

		long long other_2_perpendicular = max_min_difference(i*height, remaining_width*ceil(height, 2), remaining_width*(height/2));

		long long all_3_parallel = (remaining_width == 1 ? oo : max_min_difference(i, ceil(remaining_width, 2), remaining_width/2)*height);

		long long min_here = min(all_3_parallel, other_2_perpendicular);

		answer = min(answer, min_here);
	}
	
	cout << answer << "\n";
}

int main()
{
	int no_of_test_cases; 
	cin >> no_of_test_cases;

	while(no_of_test_cases--)
		solve();

	return 0;
}
