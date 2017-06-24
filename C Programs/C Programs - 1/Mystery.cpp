#include <iostream>

using namespace std;

void solve()
{
    int number, number_of_divisors = 0;
    cin >> number;

    for(int divisor = 1; divisor*divisor <= number; divisor++)
        if(number%divisor == 0)
            number_of_divisors += (divisor*divisor == number ? 1 : 2);

    cout << number_of_divisors << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
