int main()
{
	int no_of_horses;
	cin >> no_of_horses;

	vector <horse> H(no_of_horses + 1);
	for(int i = 1; i <= no_of_horses; i++)
	{
	    cin >> H[i].velocity;
	}

	for(int i = 1; i <= no_of_horses; i++)
	{
	    cin >> H[i].position;
	}

	sort(all(H));

	memset(sum_tree, 0, sizeof(sum_tree));

	long long inversions = 0;
	for(int i = 1; i <= no_of_horses;)
	{
	    int j;

	    for(j = i; j <= no_of_horses && H[j].velocity == H[i].velocity; j++)
	    {
	        inversions += get_sum(1, 1, no_of_horses, 1, H[j].position - 1);
	    }

	    for(j = i; j <= no_of_horses && H[j].velocity == H[i].velocity; j++)
	    {
	        update(1, 1, no_of_horses, H[j].position, 1);
	    }

	    i = j;

	}

	cout << inversions << "\n";
	return 0;
}
