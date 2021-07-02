/* 
* Repeatedly asks users to enter the price of an item until they enter zero.
* Prices less than zero will be ignored.
* The program will then print the number of items purchased, the subtotal of the prices, 
* the sales tax charged (at a rate of 7.5%), and the grand total.
* 
* M. Ivanov June 18, 2021
*/

#include <stdio.h>

int main(void)
{  
    //state all of the variables
    double price = 0; //input price
    int num_items = 0; //total number of items
    double total_price = 0; //sum of all the accepted inputs
    double tax = 0; //tax, to be calculated after the system

    //utilizing the “n-and-a-half” loop
    printf("Enter a price, or zero when finished: $");
    scanf("%lf", &price);
    while (price != 0) 
    {
        if (price < 0) 
        {
            printf("Negative price ignored\n");
        }
        else
        {
            num_items += 1;
            total_price += price;
        }
        printf("Enter a price, or zero when finished: $");
        scanf("%lf", &price);
    }

    //calculate the tax after total price
    tax = total_price * 0.075;

    //print all the values
    printf("\nNumber of items purchased: %i\n",num_items);
    printf("Subtotal        $%0.2f\n",total_price);
    printf("Sales tax 7.5   $%0.2f\n",tax);

    //do not want to make a seperate variable for the total value wtih, will just make total price itself added to tax
    total_price += tax;
    printf("Total           $%0.2f",total_price);
}