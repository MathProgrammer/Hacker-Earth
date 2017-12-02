#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main()
{
    int no_of_elements, m;
    scanf("%d %d", &no_of_elements, &m);

    vector <int> element(no_of_elements + 1);
    map <int, int> frequency;
    for(int i = 1; i <= no_of_elements; i++)
    {
        scanf("%d", &element[i]);

        frequency[element[i]%m]++;
    }

    int max_frequency = 0, answer_modulus;

    sort(all(element));
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(frequency[element[i]%m] > max_frequency)
        {
            max_frequency = frequency[element[i]%m];
            answer_modulus = element[i]%m;
        }
    }

    vector <int> answer;
    for(int i = 1; i <= no_of_elements; i++)
        if(element[i]%m == answer_modulus)
            answer.push_back(element[i]);


    printf("%u\n", answer.size());
    for(int i = 0; i < answer.size(); i++)
        printf("%d ", answer[i]);

    return 0;
}

