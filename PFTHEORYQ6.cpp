
#include <stdio.h>

int main()
{
    char type, member, disabled, avail;
    float soc, req, hours;
    int hh, mm;

    /* charging/priority/message codes instead of strings */
    int charging = 0, emergency = 0, peak = 0, msg = 0, priority = 0;
    float units = 0, rate = 0, chargeCost = 0, chargeDisc = 0;
    float parkCost = 0, parkDisc = 0, discount = 0, total = 0;
    int now;

    printf("Vehicle type (E = electric, H = hybrid): ");
    scanf(" %c", &type);
    printf("Current battery level (%%): ");
    scanf("%f", &soc);
    printf("Required charging level (%%): ");
    scanf("%f", &req);
    printf("Expected parking duration (hours): ");
    scanf("%f", &hours);
    printf("Current time (hour minute, 24-hour): ");
    scanf("%d %d", &hh, &mm);
    printf("Parking membership? (Y/N): ");
    scanf(" %c", &member);
    printf("Disabled-person priority? (Y/N): ");
    scanf(" %c", &disabled);
    printf("Charging station available? (Y/N): ");
    scanf(" %c", &avail);

    /* ---------- validation ---------- */
    if (type != 'E' && type != 'H')
        printf("\nInvalid vehicle type.\n");
    else if (soc < 0 || soc > 100 || req < 0 || req > 100)
        printf("\nBattery percentages must be between 0 and 100.\n");
    else if (hours <= 0)
        printf("\nDuration must be greater than 0.\n");
    else if (hh < 0 || hh > 23 || mm < 0 || mm > 59)
        printf("\nInvalid time.\n");
    else if ((member != 'Y' && member != 'N') ||
             (disabled != 'Y' && disabled != 'N') ||
             (avail != 'Y' && avail != 'N'))
        printf("\nY/N answers must be Y or N.\n");
    else
    {
        /* ---------- peak / off-peak (5 PM - 10 PM) ---------- */
        now = hh * 60 + mm;
        if (now >= 17 * 60 && now <= 22 * 60)
            peak = 1;

        /* ---------- charging eligibility ---------- */
        switch (type)
        {
            case 'E':
                if (avail == 'N')
                    msg = 1;                 /* no slot */
                else
                {
                    if (req <= soc)
                        msg = 2;             /* no charging required */
                    else
                        charging = 1;
                }
                break;

            case 'H':
                if (avail == 'N')
                    msg = 3;                 /* parking only */
                else
                {
                    if (soc >= 40)
                        msg = 4;             /* does not qualify */
                    else
                    {
                        if (req <= soc)
                            msg = 2;
                        else
                            charging = 1;
                    }
                }
                break;
        }

        /* ---------- charging cost ---------- */
        if (charging == 1)
        {
            units = req - soc;

            if (soc <= 15 && req >= 80)
            {
                priority = 3;                /* emergency */
                emergency = 1;
            }
            else
            {
                if (disabled == 'Y')
                    priority = 2;            /* priority */
                else
                {
                    if (member == 'Y' && soc <= 30)
                        priority = 2;
                    else
                        priority = 1;        /* normal */
                }
            }

            if (peak == 1)
                rate = 50;
            else
                rate = 35;

            chargeCost = units * rate;

            /* member discount on charging (not for emergency) */
            if (member == 'Y')
            {
                if (emergency == 0)
                {
                    if (peak == 1)
                        chargeDisc = chargeCost * 0.10;
                    else
                        chargeDisc = chargeCost * 0.20;
                }
            }
        }

        /* ---------- parking cost ---------- */
        if (hours <= 2)
            parkCost = 200;
        else
        {
            if (hours <= 5)
                parkCost = 400;
            else
                parkCost = 700;
        }

        if (disabled == 'Y')
            parkDisc = parkCost;             /* free parking */
        else
        {
            if (member == 'Y')
                parkDisc = parkCost * 0.20;
        }

        discount = chargeDisc + parkDisc;
        total = chargeCost + parkCost - discount;

        /* ---------- bill ---------- */
        printf("\n===== EV Charging & Parking Bill =====\n");

        if (type == 'E')
            printf("Vehicle type       : Electric\n");
        else
            printf("Vehicle type       : Hybrid\n");

        printf("Battery level      : %.1f%%\n", soc);
        printf("Required level     : %.1f%%\n", req);

        switch (priority)
        {
            case 0: printf("Charging priority  : None\n"); break;
            case 1: printf("Charging priority  : Normal Charging\n"); break;
            case 2: printf("Charging priority  : Priority Charging\n"); break;
            case 3: printf("Charging priority  : Emergency Charging Priority\n"); break;
        }

        if (peak == 1)
            printf("Time period        : Peak\n");
        else
            printf("Time period        : Off-peak\n");

        printf("Charging cost      : Rs. %.2f\n", chargeCost);
        printf("Parking cost       : Rs. %.2f\n", parkCost);
        printf("Total discount     : Rs. %.2f\n", discount);
        printf("Final payable      : Rs. %.2f\n", total);

        switch (msg)
        {
            case 1: printf("Note: No charging slot available.\n"); break;
            case 2: printf("Note: No charging required.\n"); break;
            case 3: printf("Note: Charging unavailable - Parking only.\n"); break;
            case 4: printf("Note: Vehicle does not qualify for EV charging.\n"); break;
        }

        if (hours > 8)
            printf("Long-stay warning: Please relocate your vehicle after charging.\n");
        else
            printf("Standard parking duration.\n");
    }

    return 0;
}
 
