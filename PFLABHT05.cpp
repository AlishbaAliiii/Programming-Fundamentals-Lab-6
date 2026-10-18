//PFLAB Hometask 05

#include <stdio.h>
int main() {

    int status = 0;
    int dev, op;
    int door   = 1 << 0;
    int alarm  = 1 << 1;
    int cctv   = 1 << 2;
    int sensor = 1 << 3;

    printf("====SMART HOME SECURITY CONTROLLER====\n");

    printf("Enter Operation:\n");
    printf(" 1. Activate Device\n");
    printf(" 2. Deactivate Device\n");
    printf(" 3. Check Status of a Device\n");
    printf(" 4. Toggle a Device\n");
    scanf("%d", &op);

    printf("Select Device:\n");
    printf(" 1. Main Door\n 2. Alarm\n 3. CCTV Camera\n 4. Sensor\n");
    scanf("%d", &dev);

    switch (op) {
        case 1:
            switch (dev) {
                case 1: status |= door;   break;
                case 2: status |= alarm;  break;
                case 3: status |= cctv;   break;
                case 4: status |= sensor; break;
            }
            break;                      // <-- this was missing

        case 2:
            switch (dev) {
                case 1: status &= ~door;   break;
                case 2: status &= ~alarm;  break;
                case 3: status &= ~cctv;   break;
                case 4: status &= ~sensor; break;
            }
            break;

        case 3:
            switch (dev) {
                case 1: printf("Door is %s\n",  (status & door)   ? "active" : "inactive"); break;
                case 2: printf("Alarm is %s\n", (status & alarm)  ? "active" : "inactive"); break;
                case 3: printf("CCTV is %s\n",  (status & cctv)   ? "active" : "inactive"); break;
                case 4: printf("Sensor is %s\n",(status & sensor) ? "active" : "inactive"); break;
            }
            break;

        case 4:
            switch (dev) {
                case 1: status ^= door;   break;
                case 2: status ^= alarm;  break;
                case 3: status ^= cctv;   break;
                case 4: status ^= sensor; break;
            }
            break;

        default:
            printf("Invalid Operation.\n");
    }

    printf("Status = %d\n", status);    // no & here

    return 0;
}
//status are all set, all bitwise op are applied by case

