/* 
* Ask the user to enter up to twenty values of weights in kilograms, with zero as the sentinel value.
* These numbers will go into an array. Decimals accepted
* Negatives respond with an error, but ask for different value
* prints numbers of weights
* prints averages of weight
* print num of values closest to avg, and said values
* M. Ivanov June 22, 2021
*/

#include <stdio.h>
#include <math.h>

int main(void)
{  
    //initial values
    double weight[20] = {0}; //creates 20 spots to input values
    int total_num = 0; //total number of spots in weight array used
    double total = 0; //the total sum of all the values (used for average)
    double weightresponse = 0; //the value users submit (used in scanf)

    //values used at the end
    double average = 0; //calculated average
    double min_deviation = 0; //minimum deviation, to be calculated/adjusted
    double closest[20] = {0}; //array of values closest to the deviation, to be filled
    int closest_num = 0; //number of values that qualify for the array of values closest to deviation

    //input section
    printf("Enter a weight in kg, or 0 to quit: ");
    scanf("%lf", &weightresponse);
    while (weightresponse != 0) //make sure value input is not 0
    {
        
        if (weightresponse < 0) //ignores any negative values, skips any processes
        {
            printf("Ignoring negative value.\n");
        }
        else
        {
            weight[total_num] = weightresponse; 
            total_num += 1; //adds to total number of values (used for average + printing stuff)
            total += weightresponse; //used for average
        }
        printf("Enter a weight in kg, or 0 to quit: ");
        scanf("%lf", &weightresponse);
    }
    
    //math portion
    average = total / total_num; //calculate average
    min_deviation = fabs(weight[0] - average); //initial devaition, to be changed

    //goes through all values to see if the deviation should be changed
    for (int x = 0; x < total_num; x++)
    {
        if (fabs(weight[x] - average) < min_deviation)
        {
            min_deviation = fabs(weight[x] - average);
        }
    }

    //checks values that qualify for "closest"
    for (int x = 0; x < total_num; x++)
    {
        if (fabs(weight[x] - average) == min_deviation)
        {
            closest[closest_num] = weight[x]; //takes value and uses it in its own array
            closest_num += 1; //adds with each number that qualifies, used for printing statement
        }
    }

    //printing section
    printf("Number of entries: %i\n",total_num);
    printf("Average weight: %0.3f kg\n",average);
    printf("Number of items closest to average: %i\n",closest_num);

    printf("The item(s) - weight in kg:\n");
    //lists all the values that qualified
    for (int x = 0; x < closest_num; x++)
    {
        printf("%0.3f\n",closest[x]);
    }
}