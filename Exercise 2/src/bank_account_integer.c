#include <stdio.h>

/*
 * In this example we get integer overflow - undefined behaviour which is according
 * to standard should prevent normal execution flow of an application.
 * As soon as account balance exceeds INT_MAX program fails.
 *
 * A possible solution would be to use long instead of integers
 */

int main()
{

    //We define the variables
    long balance = 0; 			//initial balance (to be read from user)
    long increase = 0;			//increase (to be read from user)
    long newbalance = 0;		//new balance (we will calculate this)

    printf("Enter starting balance in Swiss centimes\n");
    scanf("%ld", &balance); //reading the initial balance from user
    //VERY IMPORTANT: Notice the & in front of the variable
    //read slides from 28.2.2017, slide 10 for explanation

    printf("Enter increased to be credited to account in swiss centimes\n");
    scanf("%ld", &increase); //reading the increase

    newbalance = balance + increase; //calculating the nes balance

    printf("Account balance (cents): %ld\n", newbalance); //printing the result

    return 0;
}
