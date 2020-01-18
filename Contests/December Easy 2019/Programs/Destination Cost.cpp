#include <iostream>
#include <vector>
#include <algorithm>
 
#define all(v) (v).begin(), (v).end()
using namespace std;
 
struct info
{
    int car, bus;
    
    info(){}
    
    info(int C, int B)
    {
        car = C, bus = B;
    }
};
 
int sort_by_minimum(info &A, info &B)
{
    return (min(A.car, A.bus) < min(B.car, B.bus));
}
 
int sort_by_car_bus_difference(info &A, info &B)
{
    return ((A.car - A.bus) < (B.car - B.bus));
}
 
int sort_by_bus_car_difference(info &A, info &B)
{
    return ( (A.bus - A.car) < (B.bus - B.car) );
}
 
int main()
{
    int no_of_cities;
    cin >> no_of_cities;
    
    vector <info> cost(no_of_cities);
    for(int i = 0; i < no_of_cities; i++)
    {
        cin >> cost[i].car;
    }
    
    for(int i = 0; i < no_of_cities; i++)
    {
        cin >> cost[i].bus;
    }
    
    sort(all(cost), sort_by_minimum);
    long long total_cost = 0;
    int buses = 0, cars = 0;
    for(int i = 0; i < no_of_cities; i++)
    {
        if(cost[i].car < cost[i].bus)
        {
            cars++;
            
            total_cost += cost[i].car;
        }
        else
        {
            buses++;
            
            total_cost += cost[i].bus;
        }
    }
    
    if(min(buses, cars) == no_of_cities/2)
    {
        cout << total_cost << "\n";
        
        return 0;
    }
    
    vector <int> difference;
    for(int i = 0; i < no_of_cities; i++)
    {
        if(cars < buses)
        {
            if(cost[i].car > cost[i].bus)
            {
                difference.push_back(cost[i].car - cost[i].bus);
            }
        }
        else
        {
            if(cost[i].bus > cost[i].car)
            {
                difference.push_back(cost[i].bus - cost[i].car);
            }
        }
    }
    
    sort(all(difference));
    
    for(int i = 0; i < difference.size() && min(cars, buses) < no_of_cities/2; i++)
    {
        total_cost += difference[i];
        
        if(cars < buses)
        {
            cars++;
            buses--;
        }
        else
        {
            cars--;
            buses++;
        }
    }
    
    cout << total_cost << "\n";
    
    return 0;
}
