/* 
* prints a table of estimated population from 2011 to 2020 (inclusive) knowing that:
* one birth every 9 seconds
* one death every 10 seconds
* one net international migrant every 47 seconds
* M. Ivanov June 18, 2021
*/

#include <stdio.h>

int main(void)
{  
    //variables
    int population = 308401808; //initial populiation
    int year = 2010; //the year (used for the table)
    int add_to_pop = 0; //amount to add to initial population

    //table label
    printf("Year    Estimated Population\n");

    //the actual chart
    for (int year_past_2011 = 0; year_past_2011 <= 9; year_past_2011++)
    {
        for (int day = 0; day <= 365; day++)
        {
            for (int hour = 0; hour <= 24; hour++)
            {
                //to have a more accurate additions, I thought it would be better to calculate
                //the modulo of the number of seconds in an hour instead of in every minute
                for (int second = 0; second <= 3600; second++) 
                {
                    if(second % 9 == 0)
                    {
                        add_to_pop +=1;
                    }
                    if(second % 10 == 0)
                    {
                        add_to_pop -=1;
                    }
                    if(second % 47 == 0)
                    {
                        add_to_pop +=1;
                    }
                }
            }
        }

        //adds the amount summed over the year
        population += add_to_pop;
        year ++;
        printf("%i      %i\n",year,population);

        //resets it back to 0 because the last year of the population was already added
        add_to_pop = 0;
        
    }
}