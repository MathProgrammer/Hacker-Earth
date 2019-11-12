#include <iostream>
#include <vector>

using namespace std;

long long power_mod(long long x, long long power, long long mod)
{
    long long answer = 1;

    while(power)
    {
        if(power%2 == 1)
            answer = (answer*x)%mod;

        x = (x*x)%mod;

        power = power >> 1;
    }

    return answer;
}

long long inverse(long long n, long long m)
{
    return power_mod(n, m - 2, m);
}

long long choose(long long n, long long r, long long MOD)
{
    long long answer = 1;
    long long numerator = 1, denominator = 1;
    for(int i = r - 1; i >= 0; i--)
    {
        numerator = (numerator*(n - i))%MOD;
        denominator = (denominator*(r - i))%MOD;
    }

    answer = (answer*numerator)%MOD;
    answer = (answer*inverse(denominator, MOD))%MOD;

    return answer;
}

int main()
{
	int left, right, no_of_elements;
	cin >> left >> right >> no_of_elements;

	long long sum = 0;
	vector <int> A(no_of_elements + 1);
	for(int i = 1; i <= no_of_elements - 1; i++)
	{
	    cin >> A[i];

	    A[i] = max(1,A[i]);

	    sum -= A[i];
	}

	sum += right - left;

	if(sum < 0)
	{
	    cout << "0\n";

	    return 0;
	}

	const int MOD = 1e9 + 7;
	long long answer = choose(no_of_elements + 1 + sum - 1, sum, MOD);

	cout << answer;
	return 0;
}



