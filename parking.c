/*
 * This program calculates parking charges. It asks the user
 * for the time a vehicle entered and exited the parking lot in
 * 24-hour format (such as 1029 or 1453).
 * 
 * It calculates the number of hours and minutes the vehicle was parked,
 * and uses that to figure out the cost:
 *      $2.00 for the first three hours
 *      $0.50 for each additional hour or fraction thereof
 * 
 * The program then asks the user if they wish to enter another set
 * of data (Y for yes or N for no), and then repeats the process if
 * the user enters Y, or ends the program if they enter N.
 * 
 * M. Ivanov, Jun 28 2021
 */
 
#include <stdio.h>
#include <ctype.h>  // utilities for characters
#include <stdbool.h> // for easier use of booleans

/*
 * Write a function named valid_time() that takes an integer
 * representing a time in 24-hour format, such as 1329 or 0945 and
 * returns a boolean.
 * 
 * This function checks that the hours part (the first two digits)
 * are in the range 0-23. If not, the function prints an error message.
 * 
 * It then checks that the minutes part (the last two digits)
 * are in the range 0-59. If not, the function prints an error message.
 * 
 * If both the hours and minutes are OK, the function returns true;
 * otherwise it returns false 
 */

//===============================================
bool valid_time(int time)
{
    if (time<0)
    {
        printf("Time cannot be negative.\n");
        return false;
    }
    if((time / 100 <= 23 && time / 100 >= 0) && (time % 100 <= 59 && time % 100 >= 0))
    {
        return true;
    }
    if (time / 100 > 23 || time / 100 < 0)
    {
        printf("Hours must be from 0-23\n");
    }
    if (time % 100 > 59 || time % 100 < 0)
    {
        printf("Minutes must be from 0-59\n");
    }
    return false;
}
/*
 * Write a function named calculate_charges() that takes two integers
 * representing the number of hours and the number of minutes that a person
 * was parked. 
 * 
 * This function returns a double for the parking charge:
 * $2.00 minimum fee to park for up to three hours
 * and an additional $0.50 per hour for each hour or part thereof
 * over three hours.
 */

//===============================================

double calculate_charges(int hours, int minutes)
{
    double final_charge = 2.00;
    if (hours >= 0 && minutes >= 0) //i want to make sure that it will not work with negatives
    {
        if((hours == 3 && minutes == 0) || (hours <= 2 && minutes <= 59))
        //it is exactly 3 hours or less than/ equal to 2 hours and 59 minutes
        {
            final_charge = 2;
        }
        else if(minutes == 0) //in the case that it is an exact hour
        {
            final_charge = 2 + (hours - 3) * 0.5;
        }
        else 
        //if it is even one minute over an hour it adds an hour of price.
        //no cases of 0 minutes to worry about so i know there will always be added hour of price
        {
            final_charge = 2 + (hours - 2) * 0.5;
        }

        if(final_charge > 10)
        {
            final_charge = 10;
        }

        return final_charge;
    }
}

/*
 * Write a function named get_time() that takes an array of
 * characters as its argument - this is the prompt string.
 * 
 * The function will display the prompt and input a
 * time in 24-hour format as an integer. It will do this
 * repeatedly as long as the input is not a valid time;
 * once the time is valid, it returns the time as an integer.
 * 
 * This function *must* call the valid_time() function to determine
 * if the time the user gave is valid or not.
 */


//===============================================

int get_time(char prompt[])
{    
    int result = 0;
    do
    {
        printf("%s", prompt);
        scanf("%i", &result);
    }
    while(valid_time(result) != true);
    return result;
}
/*
 * This function takes no input and returns no value;
 * it is a utility function to clear out the input buffer.
 */
void clear_keyboard(void) {
    while (getchar() != '\n') {
        // keep going
    }
}

/*
 * Write a function named get_yes_no() that takes an array of
 * characters as its argument - this is the input prompt.
 * 
 * This function will repeatedly display the prompt and get a
 * single-character response until the user enters either Y or N
 * in upper or lower case. If the user enters a character other than
 * Y or N, the function prints an appropriate error message.
 * 
 * It returns true if the user entered Y or y, false otherwise.
 * 
 * Hint: use a do/while loop, and call clear_keyboard() at the beginning
 * of the loop before displaying the input prompt. 
 */

//===============================================
bool get_yes_no(char prompt[])
{
    bool input = true;
    char answer = 0;
    char upper_answer = 0;

    bool result = false;

    printf("%s", prompt);
    clear_keyboard();
    scanf("%c", &answer);
    do
    {
        upper_answer = toupper(answer);
        if (upper_answer == 'Y')
        {
            result = true;
            input = false;
        }
        else if (upper_answer == 'N')
        {
            result = false;
            input = false;
        }
        else
        {
            printf("Please enter Y for yes or N for no.\n%s" , prompt);
            clear_keyboard();
            scanf("%c", &answer);
        }

    } while (input);

    return result;
    
}

// Leave the main() function exactly as it is here.

int main(void)
{
    int start_time = 0;
    int end_time = 0;
    bool proceed = false;
     
    do
    {
        do
        {
            start_time = get_time("Enter starting time in 24-hour format: ");
            end_time = get_time("Enter ending time in 24-hour format: ");
        } while (start_time > end_time);
        
        
        // Split the starting and ending times into their hours and minutes
        int start_hr = start_time / 100;
        int start_min = start_time % 100;
        
        int end_hr = end_time / 100;
        int end_min = end_time % 100;
        
        // Calculate the total number of minutes the vehicle was parked
        int duration = (end_hr - start_hr) * 60 + (end_min - start_min);
        
        // And split that into hours and minutes
        int duration_hr = duration / 60;
        int duration_min = duration % 60;
        
        // Then calculate the charge for parking and print the result
        double charge = calculate_charges(duration_hr, duration_min);
        printf("Charge for parking %i hr %i min: $%.2f\n", duration_hr, duration_min, charge);
        
        proceed = get_yes_no("Enter more data? (Y/N): ");
        printf("\n"); // for spacing
        
    } while (proceed);
    return 0;
}
