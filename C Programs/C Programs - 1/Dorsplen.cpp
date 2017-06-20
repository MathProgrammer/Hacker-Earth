#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    long long red, green, blue, max_colour, min_colour, mid_colour, no_of_artifacts;
    cin >> red >> green >> blue;

    min_colour = min(red, min(green, blue));

    red -= min_colour;
    green -= min_colour;
    blue -= min_colour;

    no_of_artifacts = min_colour + (red + green + +blue)/2 + (red + green + +blue)%2;

    cout << no_of_artifacts << endl;
    return 0;
}
