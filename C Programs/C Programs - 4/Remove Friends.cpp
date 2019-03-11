#include <cstdio>
#include <list>

using namespace std;

void solve()
{
	int no_of_friends, no_of_deletions, current_friend, popularity_i, deletions = 0;
	scanf("%d %d", &no_of_friends, &no_of_deletions);

	list <int> popularity;
	list <int>:: iterator it, it2;

	for(int i = 1; i <= no_of_friends; i++)
	{
		scanf("%d", &popularity_i);
		popularity.push_back(popularity_i);
	}

	for(it = popularity.begin(); it != popularity.end() &&  no_of_deletions > 0; )
    {
        int first_popularity = *(popularity.begin());

        int current_popularity = *(it);

        it++;

        int next_popularity = *(it);

        if(current_popularity < next_popularity)
        {
            it--;
            popularity.erase(it);

            if(current_popularity != first_popularity)
                it--;
            else
                it = popularity.begin();

            no_of_deletions--;
        }
    }

	/*//Delete the end of the list
	while(no_of_deletions-- != 0)
    {
        popularity.pop_back();
        no_of_deletions--;
    }*/

	list <int>:: iterator remaining_friend;
	for(remaining_friend = popularity.begin(); remaining_friend != popularity.end(); remaining_friend++)
		printf("%d ", *remaining_friend);

    printf("\n");
}

int main()
{
	int no_of_test_cases;
	scanf("%d", &no_of_test_cases);

	while(no_of_test_cases--)
		solve();

	return 0;
}
