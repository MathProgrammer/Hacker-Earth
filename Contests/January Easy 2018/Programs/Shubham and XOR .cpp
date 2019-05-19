#include <map>
#include <cstdio>

using namespace std;

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);
    
    map <int, int> frequency;
    
    while(no_of_elements--)
    {
        int element;
        scanf("%d", &element);
        
        frequency[element]++;
    }
    
    long long no_of_pairs = 0;
    
    for(map <int, int> :: iterator i = frequency.begin(); i != frequency.end(); i++)
    {
        long long frequency_i = i->second;
        
        no_of_pairs += (frequency_i*(frequency_i - 1))/2;
    }
    
    printf("%lld\n", no_of_pairs);
    return 0;
}
