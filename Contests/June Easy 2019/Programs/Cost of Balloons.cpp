#include <iostream>
 
using namespace std;
 
void solve()
{
    int green, purple, no_of_participants;
    cin >> green >> purple >> no_of_participants;
    
    long long first_solves = 0, second_solves = 0;
    for(int i = 1; i <= no_of_participants; i++)
    {
        int answer_1, answer_2;
        cin >> answer_1 >> answer_2;
        
        first_solves += answer_1;
        second_solves += answer_2;
    }
    
    long long price = min(green*first_solves + purple*second_solves, 
                        purple*first_solves + green*second_solves);
    cout << price << "\n";
}
 
int main() 
{
	int no_of_tests;
	cin >> no_of_tests;
	
	while(no_of_tests--)
	    solve();
	    
	return 0;
}
