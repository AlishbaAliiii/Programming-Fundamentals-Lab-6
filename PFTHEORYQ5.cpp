#include <stdio.h>
 
int main()
{
    int capA = 20, capB = 40, capC = 15;
    int occA = 0, occB = 0, occC = 0;
    int cars = 0, bikes = 0, vans = 0;
    int accepted = 0, rejected = 0, processed = 0;
    char type, cat, permit, emer = 'N', zone = 'X';
    const char *reason = "";
 
    printf("Vehicle type (C = car, B = bike, V = van): ");
    scanf(" %c", &type);
    printf("User category (F = faculty, S = student, G = guest): ");
    scanf(" %c", &cat);
    printf("Valid parking permit? (Y/N): ");
    scanf(" %c", &permit);
 
    if (type != 'C' && type != 'B' && type != 'V')
        printf("\nInvalid vehicle type. Please run again.\n");
    else if (cat != 'F' && cat != 'S' && cat != 'G')
        printf("\nInvalid user category. Please run again.\n");
    else if (permit != 'Y' && permit != 'N')
        printf("\nInvalid permit value. Please run again.\n");
    else
    {
        if (permit == 'N')
        {
            printf("Is it an emergency vehicle? (Y/N): ");
            scanf(" %c", &emer);
        }
 
        if (emer != 'Y' && emer != 'N')
            printf("\nInvalid emergency value. Please run again.\n");
        else
        {
            processed = 1;
 
            if (permit == 'N' && emer == 'N')
                reason = "Invalid permit";
            else
            {
                switch (cat)
                {
                case 'F':
                    if (occA < capA) { occA++; zone = 'A'; }
                    else reason = "No available space in Zone A";
                    break;
 
                case 'S':
                    if (type == 'V')
                    {
                        if (capC - occC >= 2) { occC += 2; zone = 'C'; }
                        else reason = "No suitable zone (Zone C cannot fit a van)";
                    }
                    else
                    {
                        if (occB < capB) { occB++; zone = 'B'; }
                        else reason = "No available space in Zone B";
                    }
                    break;
 
                case 'G':
                    if (type == 'V')
                    {
                        if (capC - occC >= 2) { occC += 2; zone = 'C'; }
                        else reason = "No available space in Zone C for a van";
                    }
                    else
                    {
                        if (occC < capC) { occC++; zone = 'C'; }
                        else reason = "No available space in Zone C";
                    }
                    break;
                }
            }
 
            if (zone == 'X')
            {
                rejected++;
                printf("\nVehicle rejected: %s\n", reason);
            }
            else
            {
                accepted++;
                if (type == 'C') cars++;
                else if (type == 'B') bikes++;
                else vans++;
 
                printf("\nVehicle parked in Zone %c. ", zone);
                if (zone == 'A') printf("Remaining capacity: %d\n", capA - occA);
                else if (zone == 'B') printf("Remaining capacity: %d\n", capB - occB);
                else printf("Remaining capacity: %d\n", capC - occC);
            }
        }
    }
 
    printf("\n===== Parking Summary =====\n");
    printf("Vehicles processed : %d\n", processed);
    printf("Accepted           : %d\n", accepted);
    printf("Rejected           : %d\n", rejected);
    printf("Cars parked        : %d\n", cars);
    printf("Bikes parked       : %d\n", bikes);
    printf("Vans parked        : %d\n", vans);
    printf("Zone A: occupied %d, remaining %d\n", occA, capA - occA);
    printf("Zone B: occupied %d, remaining %d\n", occB, capB - occB);
    printf("Zone C: occupied %d, remaining %d\n", occC, capC - occC);
 
    if (occA >= occB)
    {
        if (occA >= occC) printf("Highest occupancy: Zone A\n");
        else printf("Highest occupancy: Zone C\n");
    }
    else
    {
        if (occB >= occC) printf("Highest occupancy: Zone B\n");
        else printf("Highest occupancy: Zone C\n");
    }
 
    if (occA == capA)
    {
        if (occB == capB)
        {
            if (occC == capC)
            {
                printf("Campus parking is FULL.\n");
                return 0;
            }
        }
    }
    printf("Campus parking is not full.\n");
 
    return 0;
}
