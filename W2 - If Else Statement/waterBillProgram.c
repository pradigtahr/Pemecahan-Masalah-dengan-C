#include <stdio.h>

#define DEMAND_CHG 35.00   // basic water demand charge
#define PER_1000_CHG 1.10  // charge per thousand gallons used
#define LATE_CHG 2.00      // surchange assessed on unpaid balance
#define CONSERV_CHG 95     // conservation guidelines
#define OVERUSE_CHG_RATE 2 // charge per thousand gallons if customers don't meet the guidelines, charged twice

/*Function prototypes*/
void instruct_water(void);

double comp_use_charge(int previous, int current, int use_last_year);

double comp_late_charge(double unpaid);

void display_bill(double late_charge, double bill, double unpaid);

/*Main function*/
int main(void)
{
    /*Variables declaration*/
    int previous;       // input - meter reading from previous quarter in thousand of gallons
    int current;        // input - meter reading from current quarter
    double unpaid;      // input - unpaid balance of previous bill
    double bill;        // output - water bill
    int used;           // thousand of gallons used this quarter
    double use_charge;  // charge for actual water use
    double late_charge; // charge for non-payment of part of previous balance
    int use_last_year;  // input - water gallons used in previous payment

    /*Display user instruction*/
    instruct_water();

    /*Get data: unpaid balance, previous, current meter reading, and gallons used last year.*/
    printf("Enter unpaid balance> $");
    scanf("%lf", &unpaid);

    printf("Enter previous meter reading> ");
    scanf("%d", &previous);

    printf("Enter current meter reading> ");
    scanf("%d", &current);

    printf("Enter last gallons used in previous payment> ");
    scanf("%d", &use_last_year);

    /*Compute user's charge*/
    use_charge = comp_use_charge(previous, current, use_last_year);

    /*Determines applicable late charge*/
    late_charge = comp_late_charge(unpaid);

    /*Figure bill*/
    bill = DEMAND_CHG + use_charge + late_charge + unpaid;

    /*Print bill*/
    display_bill(late_charge, bill, unpaid);

    return (0);
}

/*Function prototypes realization*/

// A. Display user instruction
void instruct_water(void)
{
    printf("This program figures a water bill based on the demand charge\n");
    printf("$ %.2f and a $ %.2f per 1000 gallons use charge.\n\n", DEMAND_CHG, PER_1000_CHG);
    printf("A $ %.2f surcharge is added to accounts with unpaid balance.\n", LATE_CHG);
    printf("\nEnter unpaid balance, previous, and current meter readings on seperate lines after the prompts.\n");
    printf("Press <return> or <enter> after typing each number. \n\n");
}

// B. Computes use charge with conservation requirements
// Pre: previous, current, and use_last_year are defined.
double comp_use_charge(int previous, int current, int use_last_year)
{
    int used;          // Gallons of water used (in thousand)
    double use_charge; // Charge for actual water use

    used = current - previous;
    if (used <= CONSERV_CHG / 100.0 * use_last_year)
    {
        /* conservartion guidelines met */
        use_charge = used * PER_1000_CHG;
    }

    else
    {
        printf("Use charge is at %.2f times of normal rate since use of units exceeds %d units exceeds %d percent of last year's %d-unit use.\n", OVERUSE_CHG_RATE, used, CONSERV_CHG, use_last_year);
        use_charge = used * OVERUSE_CHG_RATE * PER_1000_CHG;
    }

    return (use_charge);
}

// C. Computes late charge
// Pre: unpaid is defined
double comp_late_charge(double unpaid)
{
    double late_charge;

    /*Charge for non-payment of part of previous balance*/
    if (unpaid > 0)
    {
        late_charge = LATE_CHG;
    }
    /*Assess late charge on unpaid balance*/
    else
    {
        late_charge = 0.0;
    }
    return (late_charge);
}

// D. Display late charge if any and bill
// Pre: late_charge, bill, and unpaid are defined.
void display_bill(double late_charge, double bill, double unpaid)
{
    if (late_charge > 0.0)
    {
        printf("\nBill includes $%.2f late charge, on unpaid balance of $%.2f\n", late_charge, unpaid);
    }
    printf("\nTotal due = $%.2f\n", bill);
}