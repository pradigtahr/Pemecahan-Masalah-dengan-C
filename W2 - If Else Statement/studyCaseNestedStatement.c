#include <stdio.h>

/* Computes the tax due based on a tax table.
 * Pre : salary is defined.
 * Post: Returns the tax due for 0.0 <= salary <= 150,000.00;
 *       returns -1.0 if salary is outside the table range.*/

/* Function Prototypes */
double comp_tax(double salary);

/* Main Fucntion */
int main(){
    // Var declaration
    double salary, tax;
    
    // User input
    printf("Enter your salary>\t\t$");
    scanf("%lf", &salary);

    // Calculating tax based on the salary
    tax = comp_tax(salary);

    // Display the results
    if (tax == -1.0) {
        printf("Salary outside the valid range.\n");
    } else {
        printf("You have to pay>\t\t$%.2f\n", tax);
    }

    return(0);
}

/* Function */
double comp_tax(double salary){
    // Local variable declaration
    double tax;

    // If-Else statement
    if (salary < 0.0){
        tax = -1.0;
    }
    else if (salary < 15000.00){
        tax = 0.15 * salary;                                /* First range */
    }
    else if (salary < 30000.00){
        tax = tax = (salary - 15000.00) * 0.18 + 2250.00;   /* second range */
    }
    else if (salary < 50000.00){
        tax = (salary - 30000.00) * 0.22 + 5400.00;         /* third range */
    }
    else if (salary < 80000.00){
        tax = (salary - 50000.00) * 0.27 + 11000.00;        /* fourth range */
    }
    else if (salary <= 150000.00){
        tax = (salary - 80000.00) * 0.33 + 21600.00;        /* fifth range */
    }
    else{
        tax = -1.0;
    }
    
    return (tax);
}