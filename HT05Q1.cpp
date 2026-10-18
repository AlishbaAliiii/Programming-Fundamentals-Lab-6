#include <stdio.h>

int main(void) {
    int status = 0;
    int choice = 0;
    int device_choice = 0;
    int mode_choice = 0;

    /* Bitwise definitions using left-shift operations */
    int door_lock = 1 << 0;     /* Bit 0 = Value 1 */
    int alarm_sys = 1 << 1;     /* Bit 1 = Value 2 */
    int cctv_cam   = 1 << 2;     /* Bit 2 = Value 4 */
    int motion_sen = 1 << 3;     /* Bit 3 = Value 8 */

    /* 1. Operation Selection */
    printf("--- Smart-Home Security Controller ---\n");
    printf("Select Operation:\n");
    printf("1. Activate a device\n");
    printf("2. Deactivate a device\n");
    printf("3. Check status of a device\n");
    printf("4. Toggle a device\n");
    printf("5. Set Security Mode\n");
    printf("Enter choice (1-5): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: /* Activate Device */
            printf("\nSelect Device to Activate:\n");
            printf("1. Main Door Lock (Bit 1)\n");
            printf("2. Alarm System (Bit 2)\n");
            printf("3. CCTV Camera (Bit 4)\n");
            printf("4. Motion Sensor (Bit 8)\n");
            printf("Enter choice (1-4): ");
            scanf("%d", &device_choice);

            nested_activate:
            switch (device_choice) {
                case 1:
                    status |= door_lock;
                    break;
                case 2:
                    status |= alarm_sys;
                    break;
                case 3:
                    status |= cctv_cam;
                    break;
                case 4:
                    status |= motion_sen;
                    break;
                default:
                    printf("Invalid device choice.\n");
                    break;
            }
            break;

        case 2: /* Deactivate Device */
            printf("\nSelect Device to Deactivate:\n");
            printf("1. Main Door Lock (Bit 1)\n");
            printf("2. Alarm System (Bit 2)\n");
            printf("3. CCTV Camera (Bit 4)\n");
            printf("4. Motion Sensor (Bit 8)\n");
            printf("Enter choice (1-4): ");
            scanf("%d", &device_choice);

            switch (device_choice) {
                case 1:
                    status &= ~door_lock;
                    break;
                case 2:
                    status &= ~alarm_sys;
                    break;
                case 3:
                    status &= ~cctv_cam;
                    break;
                case 4:
                    status &= ~motion_sen;
                    break;
                default:
                    printf("Invalid device choice.\n");
                    break;
            }
            break;

        case 3: /* Check Device Status */
            printf("\nSelect Device to Check:\n");
            printf("1. Main Door Lock (Bit 1)\n");
            printf("2. Alarm System (Bit 2)\n");
            printf("3. CCTV Camera (Bit 4)\n");
            printf("4. Motion Sensor (Bit 8)\n");
            printf("Enter choice (1-4): ");
            scanf("%d", &device_choice);

            switch (device_choice) {
                case 1:
                    printf("Main Door Lock is %s.\n", (status & door_lock) ? "ACTIVE" : "INACTIVE");
                    break;
                case 2:
                    printf("Alarm System is %s.\n", (status & alarm_sys) ? "ACTIVE" : "INACTIVE");
                    break;
                case 3:
                    printf("CCTV Camera is %s.\n", (status & cctv_cam) ? "ACTIVE" : "INACTIVE");
                    break;
                case 4:
                    printf("Motion Sensor is %s.\n", (status & motion_sen) ? "ACTIVE" : "INACTIVE");
                    break;
                default:
                    printf("Invalid device choice.\n");
                    break;
            }
            break;

        case 4: /* Toggle Device */
            printf("\nSelect Device to Toggle:\n");
            printf("1. Main Door Lock (Bit 1)\n");
            printf("2. Alarm System (Bit 2)\n");
            printf("3. CCTV Camera (Bit 4)\n");
            printf("4. Motion Sensor (Bit 8)\n");
            printf("Enter choice (1-4): ");
            scanf("%d", &device_choice);

            switch (device_choice) {
                case 1:
                    status ^= door_lock;
                    break;
                case 2:
                    status ^= alarm_sys;
                    break;
                case 3:
                    status ^= cctv_cam;
                    break;
                case 4:
                    status ^= motion_sen;
                    break;
                default:
                    printf("Invalid device choice.\n");
                    break;
            }
            break;

        case 5: /* Security Modes */
            printf("\nSelect Security Mode:\n");
            printf("1. Home Mode (Door Lock + CCTV)\n");
            printf("2. Away Mode (All 4 devices)\n");
            printf("3. Night Mode (Door Lock + Alarm + Motion Sensor)\n");
            printf("Enter choice (1-3): ");
            scanf("%d", &mode_choice);

            switch (mode_choice) {
                case 1: /* Home Mode */
                    status = door_lock | cctv_cam;
                    break;
                case 2: /* Away Mode */
                    status = door_lock | alarm_sys | cctv_cam | motion_sen;
                    break;
                case 3: /* Night Mode (Keep CCTV state unchanged) */
                    status = (status & cctv_cam) | door_lock | alarm_sys | motion_sen;
                    break;
                default:
                    printf("Invalid mode choice.\n");
                    break;
            }
            break;

        default:
            printf("Invalid operation choice.\n");
            break;
    }

    /* Output System Status */
    printf("\n================ SYSTEM STATUS ================\n");
    printf("Binary Representation (Bits 8-4-2-1): %d%d%d%d\n",
           (status & motion_sen) ? 1 : 0,
           (status & cctv_cam)   ? 1 : 0,
           (status & alarm_sys)  ? 1 : 0,
           (status & door_lock)  ? 1 : 0);

    printf("Main Door Lock (1) : %s\n", (status & door_lock) ? "Active" : "Inactive");
    printf("Alarm System   (2) : %s\n", (status & alarm_sys)  ? "Active" : "Inactive");
    printf("CCTV Camera    (4) : %s\n", (status & cctv_cam)   ? "Active" : "Inactive");
    printf("Motion Sensor  (8) : %s\n", (status & motion_sen) ? "Active" : "Inactive");

    /* Evaluation of fully armed condition using logical operators */
    int fully_armed = ((status & door_lock) && (status & alarm_sys) && (status & cctv_cam) && (status & motion_sen));
    printf("System Security Status: %s\n", fully_armed ? "FULLY ARMED" : "PARTIALLY ARMED / UNARMED");
    printf("===============================================\n");

    return 0;
}
