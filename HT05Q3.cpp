#include <stdio.h>

int main(void) {
    int prod_choice = 0;
    int cust_choice = 0;
    int order_num = 0;
    double order_amount = 0.0;
    double distance = 0.0;

    double discount_percent = 0.0;
    double discount_amount = 0.0;
    double final_order_amount = 0.0;
    double delivery_charge = 0.0;
    double priority_charge = 0.0;
    double total_payable = 0.0;

    int free_shipping = 0;
    int priority_delivery = 0;
    int group_remainder = 0;

    /* Inputs */
    printf("=== E-Commerce Order Processing System ===\n");
    printf("Select Product Category:\n");
    printf("1. Electronics\n");
    printf("2. Clothing\n");
    printf("3. Books\n");
    printf("4. Household\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &prod_choice);

    printf("\nSelect Customer Category:\n");
    printf("1. Regular\n");
    printf("2. Premium\n");
    printf("3. Corporate\n");
    printf("Enter choice (1-3): ");
    scanf("%d", &cust_choice);

    printf("Enter Order Number: ");
    scanf("%d", &order_num);

    printf("Enter Original Order Amount (Rs.): ");
    scanf("%lf", &order_amount);

    printf("Enter Delivery Distance (km): ");
    scanf("%lf", &distance);

    /* Switch and Nested Switch for Discount Percentages */
    switch (prod_choice) {
        case 1: /* Electronics */
            switch (cust_choice) {
                case 1: discount_percent = 5.0; break;
                case 2: discount_percent = 10.0; break;
                case 3: discount_percent = 15.0; break;
                default: printf("Invalid customer category.\n"); return 1;
            }
            break;

        case 2: /* Clothing */
            switch (cust_choice) {
                case 1: discount_percent = 10.0; break;
                case 2: discount_percent = 15.0; break;
                case 3: discount_percent = 20.0; break;
                default: printf("Invalid customer category.\n"); return 1;
            }
            break;

        case 3: /* Books */
            switch (cust_choice) {
                case 1: discount_percent = 8.0; break;
                case 2: discount_percent = 12.0; break;
                case 3: discount_percent = 18.0; break;
                default: printf("Invalid customer category.\n"); return 1;
            }
            break;

        case 4: /* Household */
            switch (cust_choice) {
                case 1: discount_percent = 7.0; break;
                case 2: discount_percent = 14.0; break;
                case 3: discount_percent = 20.0; break;
                default: printf("Invalid customer category.\n"); return 1;
            }
            break;

        default:
            printf("Invalid product category.\n");
            return 1;
    }

    /* Discount & Payable Calculations */
    discount_amount = (order_amount * discount_percent) / 100.0;
    final_order_amount = order_amount - discount_amount;

    /* Free Shipping Evaluation using Logical Operators */
    free_shipping = (final_order_amount >= 5000.0) || (cust_choice == 2) || (cust_choice == 3);

    /* Delivery Charge Calculation using Conditional Operators */
    /* Example distance-based rate applied if not eligible for free shipping: Rs. 10/km */
    delivery_charge = free_shipping ? 0.0 : (distance * 10.0);

    /* Priority Delivery Evaluation using Logical & Conditional Operators */
    priority_delivery = ((cust_choice == 2) || (cust_choice == 3)) && (order_amount >= 10000.0);
    priority_charge = priority_delivery ? 500.0 : 0.0;

    /* Total Amount Payable */
    total_payable = final_order_amount + delivery_charge + priority_charge;

    /* Processing Group Classification using Modulus Operator */
    group_remainder = order_num % 4;

    /* Summary Output */
    printf("\n================ ORDER PROCESSING SUMMARY ================\n");
    printf("Order Number           : %d\n", order_num);
    printf("Product Category       : %s\n", 
           (prod_choice == 1) ? "Electronics" :
           (prod_choice == 2) ? "Clothing" :
           (prod_choice == 3) ? "Books" : "Household");

    printf("Customer Category      : %s\n", 
           (cust_choice == 1) ? "Regular" :
           (cust_choice == 2) ? "Premium" : "Corporate");

    printf("Original Order Amount  : Rs. %.2f\n", order_amount);
    printf("Discount Rate          : %.1f%%\n", discount_percent);
    printf("Discount Amount        : Rs. %.2f\n", discount_amount);
    printf("Final Payable Amount   : Rs. %.2f\n", final_order_amount);
    printf("----------------------------------------------------------\n");
    printf("Delivery Distance      : %.1f km\n", distance);
    printf("Shipping Status        : %s\n", free_shipping ? "Free Shipping" : "Standard Shipping Fee Applies");
    printf("Delivery Charges       : Rs. %.2f\n", delivery_charge);
    printf("Priority Delivery      : %s\n", priority_delivery ? "Qualified" : "Not Qualified");
    printf("Priority Charges       : Rs. %.2f\n", priority_charge);
    printf("----------------------------------------------------------\n");
    printf("Processing Group       : Processing Group %c\n", 
           (group_remainder == 0) ? 'A' :
           (group_remainder == 1) ? 'B' :
           (group_remainder == 2) ? 'C' : 'D');

    printf("TOTAL AMOUNT PAYABLE   : Rs. %.2f\n", total_payable);
    printf("==========================================================\n");

    return 0;
}
