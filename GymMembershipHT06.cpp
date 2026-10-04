#include <stdio.h>

#define POOL     1   /* bit 0 */
#define SAUNA    2   /* bit 1 */
#define TRAINER  4   /* bit 2 */
#define ALLDAY   8   /* bit 3 (24-Hour Access) */
#define SENTINEL 9999

int main(void)
{
    int access, hour;
    int lateNight, allowed, hasTrainer;
    const char *mode;

    printf("Everline Gym Access Gate\n");
    printf("Enter stored access number (9999 to end shift): ");
    scanf("%d", &access);

    while (access != SENTINEL)
    {
        printf("Enter current hour (0-23): ");
        scanf("%d", &hour);

        /* Decision 1: conditional operator selects the mode */
        mode = (hour >= 22 || hour < 6) ? "LATE NIGHT MODE" : "STANDARD MODE";
        lateNight = (hour >= 22 || hour < 6);

        /* Decision 2: bitwise operators, no if-chain.
           Standard: any one of Pool | Sauna | Trainer.
           Late night: must have 24-Hour Access, other bits ignored. */
        allowed = lateNight ? ((access & ALLDAY) != 0)
                            : ((access & (POOL | SAUNA | TRAINER)) != 0);

        /* Information line: Personal Trainer Access, independent of entry */
        hasTrainer = (access & TRAINER) != 0;

        printf("Mode: %s\n", mode);
        printf("Entry: %s\n", allowed ? "GRANTED" : "DENIED");
        printf("Personal Trainer Access: %s\n", hasTrainer ? "YES" : "NO");

        printf("\nEnter stored access number (9999 to end shift): ");
        scanf("%d", &access);
    }

    printf("Shift ended.\n");
    return 0;
}
