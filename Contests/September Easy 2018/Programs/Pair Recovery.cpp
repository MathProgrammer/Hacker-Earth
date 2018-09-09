#include <iostream>

using namespace std;

int main()
{
	int a_3, a_4;
	cin >> a_3 >> a_4;

	/*a1 + a2 = a3
	a2 + a3 = a4

	a1 + 2a2 = a4*/

	int a_2 = a_4 - a_3;
	int a_1 = a_3 - a_2;
	cout << a_1 << " " << a_2;

	return 0;
}
