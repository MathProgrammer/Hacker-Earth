#include <iostream>
using namespace std;

void solve()
{
    int number, sum = 1;
    cin >> number;

    if(number == 1)
        sum = 0;

    for(int divisor = 2; divisor*divisor <= number; divisor++)
        if(number%divisor == 0)
            sum += (divisor*divisor == number ? divisor : divisor + number/divisor);

    cout << sum << "\n";
}
int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
