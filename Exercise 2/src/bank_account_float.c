#include <stdio.h>


/*
 * N. Dario initially has a small amount of swiss francs: 10 CHF. Later he receives a big amount equal to 200Mio CHF.
 * Adding 200Mio to 10 result in 200`000`016 CHF, so he got 6 additional francs for free.
 * This happens because of float point number precision.
 *
 * A possible solution would be to use double point precision
 */

int main()
{
    //We define the variables
    double balance = 0; 			//initial balance (to be read from user)
    double increase = 0;			//increase (to be read from user)
    double newbalance = 0;		//new balance (we will calculate this)

    printf("Enter starting balance in Swiss Francs\n");
    scanf("%lf", &balance); //reading the initial balance from user
    //VERY IMPORTANT: Notice the & in front of the variable
    //read slides from 28.2.2017, slide 10 for explanation

    printf("Enter increased to be credited to account in swiss Francs\n");
    scanf("%lf", &increase); //reading the increase

    newbalance = balance + increase; //calculating the nes balance

    printf("Account balance (Francs): %.2lf\n", newbalance); //printing the result

    return 0;
}
