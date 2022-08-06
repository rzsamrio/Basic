#include <stdio.h>
#include "/data/data/com.termux/files/home/clibrary/cs50.h"

// Declaration of user defined functions and variables
float remit (void);
char day;
float uber_e;
float net_e;
float fines;
float p_due;
float moove_e;
float cash_accept;
float bal_uber;
float rem_daily;
float booking;
float bal_moove;
float due;
float t_rem;
float remit_c;
void print_inv (void);

int main(void)
{
    // Greet User
    printf("Welcome to Moove Invoice Calculator v1.0.1\nPlease Input the following (Enter 0 if unapplicable):\n");

    // Get User input 
    uber_e = get_float("\nUber Earnings: ");
    cash_accept = get_float("Total Cash Collected: ");
    booking = get_float("Booking Fee: ");
    fines = get_float("Fines and Replacement cost: ");
    p_due = get_float("Outstanding payments/dues (negative for dues): ");
    
    //Remit?
    remit();
    
    //Calculate Net Earnings
    net_e = uber_e - booking;
    
    //Calculate Uber balance
    bal_uber = uber_e - cash_accept;
    
    // Calculate Earnings made from Moove
    if (day != 'y')
    {
        moove_e = 12000 - net_e;
	if (moove_e < 0)
	{
		moove_e = 0;
	}
    }
    else
    {
        moove_e = 0;
    }
    
    // Calculate the cumulative balance with Moove
    bal_moove = moove_e + bal_uber;
    
    // Calculate the Total amount due for payment
    due = (bal_moove + p_due) - (rem_daily + fines);
    
    //Calculate the amount to be remitted today irrespective of past debts or payouts 
    t_rem = bal_moove - (rem_daily + fines);
    
     // Print Invoice
     
     print_inv();
}


//Defined Functions
float remit (void)
{

    while (true)
    {
        day = get_char("Kindly confirm what day of the week it is (respond with a 'y' or 'n')\nSunday? ");
        if (day == 'y' || day == 'n')
        {
            break;
        }
    }
    
    // Use the char input to determine the required remittance for the day
    if (day == 'y')
    {
        rem_daily = 0;
     }
     else
     {
         rem_daily = 7000;
     }
     
    // Return the remittance value
    return rem_daily;
}

void print_inv (void)
{
    printf("\nYour Moove Invoice has been successfully generated...\n\n");
    printf("Net Earnings:                 %.2f\n", net_e);
    printf("Cash Collected:               %.2f\n", cash_accept);
    printf("Uber Balance:                 %.2f\n",bal_uber);
    
    // Create a border
    for (int r = 0 ; r < 2 ; r++)
    {
        for(int k = 0 ; k <= 36 ; k++)
        {
            printf("*");
        }
        printf("\n");
    }
    
    printf("Moove Earning:                %.2f\n", moove_e);
    printf("Net Balance with Moove:       %.2f\n", bal_moove);

    // Create a border segment: 2
    for (int r = 0 ; r < 2 ; r++)
    {
        for(int k = 0 ; k <= 36 ; k++)
        {
            printf("*");
        }
        printf("\n");
    }
    
    printf("Daily Remittance:             %.2f\n", rem_daily);
    printf("Fines and Replacements:       %.2f\n", fines);
    printf("Outstanding Payout/Due:       %.2f\n", p_due);
    printf("Today's Remittance:           %.2f\n", t_rem);
    printf("Total Payout/Due:             %.2f\n", due);
    
    // Create a border segment: 3
    for (int r = 0 ; r < 2 ; r++)
    {
        for(int k = 0 ; k <= 36 ; k++)
        {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
    
    // Get Cash remitted
    float remit_c = get_float("Enter Cash Remitted: ");
    float bal_net = remit_c + due;
    
    // Print border segment balance
        for (int r = 0 ; r < 1 ; r++)
    {
        for (int k = 0 ; k <= 36 ; k++)
        {
            printf("*");
        }
        printf("\n");
    }
    // Print cash remitted
    printf("Cash Remitted:                %.2f\n", remit_c);
    
    // Print balance
    if (bal_net < 0)
    {
        printf("Balance (due):                %.2f\n", -1*bal_net);
    }
    else
    {
        printf("Balance (payout):             %.2f\n", bal_net);
    }
    
    // Create a bottom border
    for (int r = 0 ; r < 1 ; r++)
    {
        for(int k = 0 ; k <= 36 ; k++)
        {
            printf("*");
        }
        printf("\n");
    }
}
