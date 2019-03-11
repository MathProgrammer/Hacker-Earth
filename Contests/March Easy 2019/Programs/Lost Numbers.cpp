#include <iostream>

using namespace std;
typedef long long LL;

int is_bit_set(LL n, int position)
{
    return ( ( n & (1LL << position) ) != 0);
}

void set_bit(LL &n, int position)
{
    n |= (1LL << position);
}

int main()
{
    LL OR, XOR, AND;
    cin >> OR >> XOR >> AND;

    LL A = 0, B = 0;
    int possible = true;
    const int MAX_BITS = 63;

    for(int i = 0; i < MAX_BITS; i++)
    {
        if(is_bit_set(AND, i))
        {
            if(!is_bit_set(XOR, i) && is_bit_set(OR, i))
            {
                set_bit(A, i);
                set_bit(B, i);
            }
            else
            {
                possible = false;
            }
        }
        else
        {
            if(is_bit_set(XOR, i))
            {
                if(is_bit_set(OR, i))
                {
                    set_bit(A, i);
                }
                else
                {
                    possible = false;
                }
            }
            else
            {
                if(is_bit_set(OR, i))
                {
                    possible = false;
                }
            }
        }
    }

    if(!possible)
        cout << "-1\n";
    else
        cout << A << " " << B;

    return 0;
}
