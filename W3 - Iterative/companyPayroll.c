#include <stdio.h>

/*Compute the payroll for a company*/
int main(void)
{
    /* Variable Declaration */
    double total_pay; // company payroll
    int count_emp;    // current employee
    int number_emp;   // number of employees
    double hours;     // hours worked
    double rate;      // hourly rate
    double pay;       // pay for this period

    /* Get number of employees. */
    printf("Enter number of employees> ");
    scanf("%d", &number_emp);

    /* Compute each employee's pay and add it to the payroll. */
    total_pay = 0.0;
    /*Update*/
    for (count_emp = 0; count_emp < number_emp; count_emp += 1)
    {
        printf("Hours> ");
        scanf("%lf", &hours);
        printf("Rate> ");
        scanf("%lf", &rate);
        pay = hours * rate;
        printf("Pay is $%6.2f\n\n", pay);
        total_pay += pay; // Add next pay
    }

    printf("All employees processed.\nTotal payroll is $%8.2f", total_pay);
    return 0;
}