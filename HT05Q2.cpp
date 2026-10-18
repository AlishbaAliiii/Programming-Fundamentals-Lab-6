#include <stdio.h>

int main(void) {
    int dept_choice = 0;
    int theory = 0;
    int practical = 0;
    int attendance = 0;

    int req_theory = 0;
    int req_practical = 0;
    int req_attendance = 0;

    int is_passed = 0;
    int is_distinction = 0;
    int remainder = 0;

    /* Input department selection */
    printf("=== University Examination Result Processing System ===\n");
    printf("Select Student Department:\n");
    printf("1. Computer Science (CS)\n");
    printf("2. Electrical Engineering (EE)\n");
    printf("3. Business Administration (BBA)\n");
    printf("4. Mathematics (MATH)\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &dept_choice);

    /* Input student data */
    printf("Enter Theory Marks: ");
    scanf("%d", &theory);
    printf("Enter Practical Marks: ");
    scanf("%d", &practical);
    printf("Enter Attendance Percentage: ");
    scanf("%d", &attendance);

    /* Process department requirements using switch */
    switch (dept_choice) {
        case 1: /* Computer Science */
            req_theory = 50;
            req_practical = 40;
            req_attendance = 75;
            break;

        case 2: /* Electrical Engineering */
            req_theory = 55;
            req_practical = 45;
            req_attendance = 75;
            break;

        case 3: /* Business Administration */
            req_theory = 50;
            req_practical = 35;
            req_attendance = 80;
            break;

        case 4: /* Mathematics */
            req_theory = 60;
            req_practical = 40;
            req_attendance = 75;
            break;

        default:
            printf("\nInvalid department selected.\n");
            return 1;
    }

    /* Determine Pass/Fail status using logical operators */
    is_passed = (theory >= req_theory) && (practical >= req_practical) && (attendance >= req_attendance);

    /* Determine Distinction eligibility */
    is_distinction = (theory >= 85) && (practical >= 80) && (attendance >= 90);

    /* Determine Seat Category using modulus operator */
    remainder = theory % 3;

    /* Display Final Examination Report */
    printf("\n================ FINAL EXAMINATION REPORT ================\n");
    printf("Department             : %s\n", 
           (dept_choice == 1) ? "Computer Science" :
           (dept_choice == 2) ? "Electrical Engineering" :
           (dept_choice == 3) ? "Business Administration" : "Mathematics");

    printf("Theory Marks           : %d (Minimum Required: %d)\n", theory, req_theory);
    printf("Practical Marks        : %d (Minimum Required: %d)\n", practical, req_practical);
    printf("Attendance Percentage  : %d%% (Minimum Required: %d%%)\n", attendance, req_attendance);
    printf("----------------------------------------------------------\n");

    /* Seat Category display using conditional operator */
    printf("Seat Category          : Seat Category %c\n", 
           (remainder == 0) ? 'A' : ((remainder == 1) ? 'B' : 'C'));

    /* Distinction eligibility display using conditional operator */
    printf("Distinction Eligibility: %s\n", 
           is_distinction ? "Eligible for Distinction" : "Not Eligible for Distinction");

    /* Final result display using conditional operator */
    printf("Final Result           : %s\n", is_passed ? "Passed" : "Failed");
    printf("==========================================================\n");

    return 0;
}
