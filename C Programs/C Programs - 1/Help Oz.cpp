#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()

using namespace std;

int gcd(int a, int b)
{
    if(a == 0 || b == 0)
        return (a + b);
    else
        return gcd(min(a, b), (max(a, b)%min(a, b)) );
}

int main()
{
    int number_of_elements;
    cin >> number_of_elements;

    vector <int> number (number_of_elements);
    for(int i = 0; i < number_of_elements; i++)
        cin >> number[i];


    vector <int> difference_array;
    for(int i = 1; i < number_of_elements; i++)
        difference_array.push_back( abs(number[i] - number[i - 1]) );

    int difference_array_gcd;
    for(int i = 0; i < number_of_elements - 1; i++)
        difference_array_gcd = (i == 0 ? difference_array[i] : gcd(difference_array_gcd, difference_array[i]));

    vector <int> factors_of_gcd;
    for(int i = 2; i*i <= difference_array_gcd; i++)
        if(difference_array_gcd%i == 0)
        {
            if(i*i == difference_array_gcd)
                factors_of_gcd.push_back(i);
            else
            {
                factors_of_gcd.push_back(i);
                factors_of_gcd.push_back(difference_array_gcd/i);
            }
        }

    factors_of_gcd.push_back(difference_array_gcd);

    sort(all(factors_of_gcd));

    for(unsigned int i = 0; i < factors_of_gcd.size(); i++)
        cout << factors_of_gcd[i] << " ";

    return 0;
}
