#include <stdio.h>

int main()
{
    int fuel_available, petrol_at_current_milestone, furthest_milestone_travelled, no_of_milestones, i;
    scanf("%d %d", &no_of_milestones , &fuel_available);

    furthest_milestone_travelled = no_of_milestones;
    for(i = 1; i <= no_of_milestones; i++)
    {
        scanf("%d", &petrol_at_current_milestone);
        fuel_available = fuel_available - petrol_at_current_milestone;
        if(fuel_available < 0)
        {
            furthest_milestone_travelled = i;
            break;
        }
    }

    printf("%d\n",furthest_milestone_travelled);
    return 0;
}
