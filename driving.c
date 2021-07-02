
/* 
* calculates daily driving cost so that i can estimate how much money could be saved via carpool
* sorry if i misinterpret the alleged values of the parking fees per day or the tolls per day, i am legally not able to drive yet, im not even 16
* m. ivanov 06 16 21
*/

#include <stdio.h>

int main(void)
{  
    //initializing the variables
    //any prices are in double format simply because it only needs two decimal points

    int total_miles = 29.2; //value taken as average total miles driven per day
    double cost_per_gallon = 3.08; //value taken as average gas price
    float miles_per_gallon = 25; //value taken as average MPG
    double parking_fee = 1; //average price per hour * assumed 1 hour
    double toll_fee = 0.6; //assuming user goes through 2 tolls (there and back), price of toll *2
    
    //calculate
    double price_gallons_used = total_miles/miles_per_gallon * cost_per_gallon; 
    //calculates the total number of gallons used, multiplies by cost per gallon
    double total_price = price_gallons_used + parking_fee + toll_fee;

    //print
    printf("Miles driven per day: %i\n", total_miles); 
    printf("Cost per gallon of gasoline: $%0.2f\n", cost_per_gallon);
    printf("Miles per gallon: %g\n",miles_per_gallon);
    printf("Daily parking fees: $%0.2f\n", parking_fee);
    printf("Daily toll fees: $%0.2f\n", toll_fee);
    printf("\nThe total amount you will save is: $%0.2f\n",total_price);

    return 0;
}