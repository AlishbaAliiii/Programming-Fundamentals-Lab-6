#include <stdio.h>
#include <string.h>

int main() {
    int n, marks, sum;
    float avg;
    char stdname[50], Grade[4];

    printf("\n\n ====WELCOME TO SUNDALE SCHOOL'S GRADE CALCULATOR==== \n\n");
    printf("Enter Total Strength Of Class: ");
    scanf("%d", &n);

    for (int index = 1; index <= n; index++) {
        sum = 0;
        int failed = 0;

        printf("Enter Student Name: ");
        scanf(" %49[^\n]", stdname);

        printf("Enter 3 marks, one by one (range 0-100)\n");
        for (int i = 1; i <= 3; i++) {
            do {
                printf("Subject %d: ", i);
                scanf("%d", &marks);
                if (marks < 0 || marks > 100)
                    printf("Invalid, enter 0-100.\n");
            } while (marks < 0 || marks > 100);

            if (marks < 40)
                failed = 1;
            sum += marks;
        }

        if (failed) {
            printf("The candidate fails the policy of passing every subject\n");
            printf("NOT QUALIFIED FOR RESULT\n\n");
            continue;
        }

        avg = sum / 3.0;

        switch ((int)avg / 10) {
            case 10:
            case 9: strcpy(Grade, "A+"); break;
            case 8: strcpy(Grade, "A");  break;
            case 7: strcpy(Grade, "B");  break;
            case 6: strcpy(Grade, "C");  break;
            default: strcpy(Grade, "U"); break;
        }

        printf("Student:        %s\n", stdname);
        printf("Average:        %.2f\n", avg);
        printf("Assigned Grade: %s\n\n", Grade);
    }
    return 0;
}
