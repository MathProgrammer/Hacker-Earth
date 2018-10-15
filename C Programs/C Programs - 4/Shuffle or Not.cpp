#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MOD = 1e9 + 7, MAX_N = 2e5 + 5;

vector <int> graph[MAX_N];

vector <int> visited(MAX_N, false);

void precompute(vector <int> &is_prime, vector <int> &primes)
{
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i < MAX_N; i++)
    {
        if(is_prime[i])
            primes.push_back(i);

        for(int j = 0; j < primes.size() && i*primes[j] < MAX_N; j++)
        {
            is_prime[i*primes[j]] = false;

            if(i%primes[j] == 0) break;
        }
    }
}

long long power(long long base, long long exponent)
{
    long long result = 1;

    while(exponent)
    {
        if(exponent%2 == 1)
            result = (result*base)%MOD;

        exponent = exponent >> 1;
        base = (base*base)%MOD;
    }

    return result;
}

void dfs(int v, int &l)
{
    visited[v] = true;
    l++;

    if(!visited[graph[v][0]])
        dfs(graph[v][0], l);
}

int main()
{
	int n;
	cin >> n;

	vector <int> P(n + 1);
	for(int i = 1; i <= n; i++)
	{
	    cin >> P[i];

	    graph[i].push_back(P[i]);
	}

	set <int> lengths;

	for(int i = 1; i <= n; i++)
	{
	    int cycle_length = 0;

	    if(!visited[i])
	        dfs(i, cycle_length);

	    lengths.insert(cycle_length);
	}

	vector <int> is_prime(MAX_N, true);
	vector <int> primes;
	precompute(is_prime, primes);

	vector <int> exponent(MAX_N, 0);

	for(set <int> :: iterator it = lengths.begin(); it != lengths.end(); it++)
	{
	    int n = *(it);

	    for(int i = 0; primes[i]*primes[i] <= n; i++)
	    {
	        int exp = 0;

	        while(n%primes[i] == 0)
	        {
	            n /= primes[i];

	            exp++;
	        }

	        exponent[primes[i]] = max(exponent[primes[i]], exp);
	    }

	    if(n > 1)
	        exponent[n] = max(exponent[n], 1);
	}

	long long answer = 1;
	for(int i = 0; i < primes.size(); i++)
	{
	    answer = (answer*power(primes[i], exponent[primes[i]]))%MOD;
	}

	cout << answer;
	return 0;
}
