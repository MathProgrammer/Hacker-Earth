#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int is_bit_set(int n, int bit)
{
    return ( (n & (1LL << bit)) != 0);
}

int main()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> A(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    int array_xor = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        array_xor ^= A[i];
    }

    int bit_position = 35;
    for(int bit = 31; bit >= 0; bit--)
    {
        if(is_bit_set(array_xor, bit))
        {
            bit_position = bit;
            break;
        }
    }

    int u = 0, v = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(is_bit_set(A[i], bit_position))
        {
            v ^= A[i];
        }
        else
        {
            u ^= A[i];
        }
    }

    cout << u << " " << v << "\n";

    return 0;
}
